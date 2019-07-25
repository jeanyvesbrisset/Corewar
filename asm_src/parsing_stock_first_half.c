/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stock_first_half.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:38:17 by floblanc          #+#    #+#             */
/*   Updated: 2019/07/25 16:47:47 by maginist         ###   ########.fr       */
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
	ft_jump_white_spaces(*line, &i);
	gest_lab(lab, index, line, &i);
	ft_jump_white_spaces(*line, &i);
	if (!((*line)[i]) || (*line)[i] == COMMENT_CHAR || (*line)[i] == ';')
		return (1);
	s_name = 0;
	check_s_name_len(line, &s_name, i);
	tabi = 0;
	tmp = (*line)[s_name + i];
	(*line)[s_name + i] = 0;
	while (tabi < 16 && (ft_strcmp(g_f_tab[tabi].name, *line + i) != 0))
		tabi++;
	(*line)[s_name + i] = tmp;
	start_to_command(start);
	if (index + 3 < CHAMP_MAX_SIZE && tabi != 16
		&& g_f_tab[tabi].f(*line + i + s_name, start, lab, &index))
		return (1);
	return (ft_error("Problem with instuction \n", 0, 0, 0));
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
		return (0);
	i++;
	if (comment_stocker(line, &i, start, reader[1]) == 0)
		return (0);
	if (!((*line)[i]) && reader[1] == 1)
		if ((i = gnl_find_mod(line, start, reader, 'c')) == -1)
			return (0);
	i++;
	ft_jump_white_spaces((*line), &i);
	if (!((*line)[i]) || ((*line)[i]) == COMMENT_CHAR || ((*line)[i]) == ';')
		return (1);
	return (0);
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
		return (0);
	i++;
	if (name_stocker(line, &i, start, reader[1]) == 0)
		return (0);
	if (!((*line)[i]) && reader[1] == 1)
	{
		if ((i = gnl_find_mod(line, start, reader, 'n')) == -1)
			return (0);
	}
	i++;
	ft_jump_white_spaces((*line), &i);
	if (!((*line)[i]) || ((*line)[i]) == COMMENT_CHAR || ((*line)[i]) == ';')
		return (1);
	return (-1);
}

int		init_cor(t_cdata **start, int *step)
{
	t_cdata	*comment;
	t_cdata	*command;

	if (!((*start) = (t_cdata*)malloc(sizeof(t_cdata) * 1)))
		return (0);
	(*start)->str = ft_memalloc(4 + PROG_NAME_LENGTH);
	if (!(write_the_magic(start, COREWAR_EXEC_MAGIC)))
		return (ft_error("Wrong magic number format", 0, 0, 0));
	(*start)->size = 4 + PROG_NAME_LENGTH;
	(*start)->index = 1;
	if (!(comment = (t_cdata*)malloc(sizeof(t_cdata) * 1)))
		return (0);
	comment->str = ft_memalloc(12 + COMMENT_LENGTH);
	comment->size = 12 + COMMENT_LENGTH;
	comment->index = 2;
	if (!(command = (t_cdata*)malloc(sizeof(t_cdata) * 1)))
		return (0);
	command->str = ft_memalloc(CHAMP_MAX_SIZE);
	command->size = CHAMP_MAX_SIZE;
	command->index = 3;
	(*start)->next = comment;
	comment->next = command;
	command->next = *start;
	(*step)++;
	return (1);
}

int		line_is_correct(char **line, t_cdata **sta, t_label **lab, int *reader)
{
	static int	step = -1;
	int			ret;

	if (!(*line))
		return (1);
	if (step == -1)
		init_cor(sta, &step);
	if (step < 2 && (ret = is_name(line, sta, reader)))
	{
		if (ret == -1)
			return (ft_error("Error in .name\n", 0, 0, 0));
		step += 1;
	}
	else if (step < 2 && is_comment(line, sta, reader))
		step += 1;
	else if (step >= 2 && stock_command(line, sta, lab, 0))
		step += 1;
	else if (!(is_commentary(*line)))
	{
		ft_strdel(line);
		return (0);
	}
	return (1);
}
