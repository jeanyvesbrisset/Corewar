/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stock_first_half.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:38:17 by floblanc          #+#    #+#             */
/*   Updated: 2019/07/01 14:54:22 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/asm.h"

int		stock_command(char **line, t_cdata **start, t_label **lab, char tmp)
{
	int				i;
	int				tabi;
	int				s_name;
	static int		index = 0;

	i = 0;
	ft_printf("\nINDEX_WAY : line : %s && index = %d\n\n", *line, index);
	ft_jump_white_spaces(*line, &i);
	if (!(gest_lab(lab, index, line, &i)))
		return (ft_error("NOT GEST LAB"));
	ft_jump_white_spaces(*line, &i);
	if (!((*line)[i]))
		return (1);
	s_name = 0;
	while ((*line)[s_name + i] && (*line)[s_name + i] != ' '
		&& (*line)[s_name + i] != '\t')
		s_name++;
	tabi = 0;
	tmp = (*line)[s_name + i];
	(*line)[s_name + i] = 0;
	while (tabi < 16 && (ft_strcmp(g_f_tab[tabi].name, *line + i) != 0))
		tabi++;
	(*line)[s_name + i] = tmp;
	start_to_command(start);
	ft_printf("le TABI pour lancer la fonction = %d\n", tabi);
	if (index + 3 < CHAMP_MAX_SIZE && tabi != 16
	&& g_f_tab[tabi].f(*line + i + s_name, start, lab, &index))
		return (1);
	return (ft_error("NOT COMMAND"));
}

int		is_comment(char **line, t_cdata **start, int *reader)
{
	int	i;

	i = 0;
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (ft_strncmp(*line + i, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)
	!= 0))
		return (ft_error("BUG COMMENT CMD"));
	i += 8;
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (!((*line)[i]) || (*line)[i] != '"')
		return (ft_error("not a comment1"));
	i++;
	if (comment_stocker(line, &i, start, reader[1]) == 0)
		return (0);
	if (!((*line)[i]) && reader[1] == 1)
		if (!(gnl_find_mod(line, start, reader, 'c')))
			return (ft_error("BUG SUR GNLFIND MOD COMMENT"));
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (!((*line)[i]) || (*line)[i] == '"')
		return (1);
	return (ft_error("not a comment2"));
}

int		is_name(char **line, t_cdata **start, int *reader)
{
	int	i;

	i = 0;
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (ft_strncmp(*line + i, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) != 0)
		return (ft_error("BUG NAME CMD"));
	i += 5;
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (!((*line)[i]) || (*line)[i] != '"')
		return (ft_error("not a name1"));
	i++;
	if (name_stocker(line, &i, start, reader[1]) == 0)
		return (ft_error("BUG SUR NAME_STOCKER"));
	if (!((*line)[i]) && reader[1] == 1)
	{
		if (!(gnl_find_mod(line, start, reader, 'n')))
			return (ft_error("BUG SUR GNL_FIND_MOD NAME"));
	}
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;

	if (!((*line)[i]) || (*line)[i] == '"')
		return (1);
	return (ft_error("not a name2"));
}

void	init_cor(t_cdata **start)
{
	t_cdata	*comment;
	t_cdata	*command;

	if (!((*start) = (t_cdata*)malloc(sizeof(t_cdata) * 1)))
		return ;
	(*start)->str = ft_memalloc(4 + PROG_NAME_LENGTH);
	(*start)->str[1] = 234;
	(*start)->str[2] = 131;
	(*start)->str[3] = 243;
	(*start)->size = 4 + PROG_NAME_LENGTH;
	(*start)->index = 1;
	if (!(comment = (t_cdata*)malloc(sizeof(t_cdata) * 1)))
		return ;
	comment->str = ft_memalloc(12 + COMMENT_LENGTH);
	comment->size = 12 + COMMENT_LENGTH;
	comment->index = 2;
	if (!(command = (t_cdata*)malloc(sizeof(t_cdata) * 1)))
		return ;
	command->str = ft_memalloc(CHAMP_MAX_SIZE);
	command->size = CHAMP_MAX_SIZE;
	command->index = 3;
	(*start)->next = comment;
	comment->next = command;
	command->next = *start;
}

int		line_is_correct(char **line, t_cdata **sta, t_label **lab, int *reader)
{
	static int	step = 0;
	static int 	lol = 0;//debug laul

	lol++;
	if (!(*line))
		return (1);
	if (!(step))
		init_cor(sta);
	ft_printf("step = %d && line_is_correct = %s\n", lol, *line);
	if (step == 0 && is_name(line, sta, reader))
		step = 1;
	else if (step == 1 && is_comment(line, sta, reader))
		step = 2;
	else if (step >= 2 && stock_command(line, sta, lab, 0))
		step += 1;
	else if ((*line)[0] && (*line)[0] != COMMENT_CHAR && (*line)[0] != ';')
	{
		ft_strdel(line);
		ft_printf("ERROR LOL = %d\n", lol);
		return (ft_error("NOT A VALID INPUT"));
	}
	else
		ft_printf("JUMP\n");
	return (1);
}
