/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stock_first_half.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:38:17 by floblanc          #+#    #+#             */
/*   Updated: 2019/07/03 18:00:35 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/asm.h"

int		is_commentary(char *line)
{
	int	i;

	i = 0;
	ft_jump_white_spaces(line, &i);
	if ((!line[i]) || (line[i] == COMMENT_CHAR || line[i] == ';'))
		return (1);
	else
		return (0);
}

int		stock_command(char **line, t_cdata **start, t_label **lab, char tmp)
{
	int				i;
	int				tabi;
	int				s_name;
	static int		index = 0;

	i = 0;
	//ft_printf("\nINDEX_WAY : line : %s && index = %d\n\n", *line, index);
	ft_jump_white_spaces(*line, &i);
	gest_lab(lab, index, line, &i);
	ft_jump_white_spaces(*line, &i);
	if (!((*line)[i]) || (*line)[i] == COMMENT_CHAR || (*line)[i] == ';')
		return (1);
	s_name = 0;
	while ((*line)[s_name + i] && (*line)[s_name + i] != ' '
		&& (*line)[s_name + i] != '\t' && (*line)[s_name + i] != DIRECT_CHAR
		&& (*line)[s_name + i] != LABEL_CHAR && (*line)[s_name + i] != '-' 
		&& (*line)[s_name + i] != ft_isdigit((*line)[s_name + i])
		&& ((*line)[s_name + i] != 'r' || (*line)[s_name + i - 1] == 'o'))
		s_name++;
	tabi = 0;
	tmp = (*line)[s_name + i];
	(*line)[s_name + i] = 0;
	//ft_printf("line[sname] = %s\n", (*line));
	while (tabi < 16 && (ft_strcmp(g_f_tab[tabi].name, *line + i) != 0))
		tabi++;
	(*line)[s_name + i] = tmp;
	//ft_printf("line[sname] = %s\n", (*line));
	start_to_command(start);
	//ft_printf("le TABI pour lancer la fonction = %d\n", tabi);
	 if (index + 3 < CHAMP_MAX_SIZE && tabi != 16
	 	&& g_f_tab[tabi].f(*line + i + s_name, start, lab, &index))
		return (1);
	return (0);
}

int		is_comment(char **line, t_cdata **start, int *reader)
{
	int	i;

	i = 0;
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (ft_strncmp(*line + i, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)
	!= 0))
		return (0);
	i += 8;
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (!((*line)[i]) || (*line)[i] != '"')
		return (ft_error("not a comment1"));
	i++;
	if (comment_stocker(line, &i, start, reader[1]) == 0)
		return (0);
	//ft_printf("%s && line[%d] = %c\n", (*line), i, (*line[i]));
	if (!((*line)[i]) && reader[1] == 1)
		if ((i = gnl_find_mod(line, start, reader, 'c')) == -1)
			return (ft_error("BUG SUR GNLFIND MOD COMMENT"));
	//ft_printf("IS_COMMENT : after stock comment line[i] = %c\n", ((*line)[i]));
	i++;
	ft_jump_white_spaces((*line), &i);
	//ft_printf("%s && line[%d] = %c\n", (*line), i, ((*line)[i]));
	if (!((*line)[i]) || ((*line)[i]) == COMMENT_CHAR || ((*line)[i]) == ';')
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
		return (0);
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
		if ((i = gnl_find_mod(line, start, reader, 'n')) == -1)
			return (ft_error("BUG SUR GNL_FIND_MOD NAME"));
	}
	i++;
	ft_jump_white_spaces((*line), &i);
	if (!((*line)[i]) || ((*line)[i]) == COMMENT_CHAR || ((*line)[i]) == ';')
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
	static int	step = -1;
	static int 	lol = 1;

	if (!(*line))
		return (1);
	if (step == -1)
	{
		init_cor(sta);
		step++;
	}
	//ft_printf("LINE_nb[%d] = %s\n", lol, *line);
	if (step < 2 && is_name(line, sta, reader))
		step += 1;
	else if (step < 2 && is_comment(line, sta, reader))
		step += 1;
	else if (step >= 2 && stock_command(line, sta, lab, 0))
		step += 1;
	else if (!(is_commentary(*line)))
	{
		ft_strdel(line);
		return (ft_error("NOT A VALID INPUT\n"));
	}
	lol++;
	return (1);
}
