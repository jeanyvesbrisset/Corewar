/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_annexe_fct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:34:11 by floblanc          #+#    #+#             */
/*   Updated: 2019/07/05 11:36:08 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		is_commentary(char *line)
{
	int	i;

	i = 0;
	if (!(line))
		return (0);
	ft_jump_white_spaces(line, &i);
	if ((!line[i]) || (line[i] == COMMENT_CHAR || line[i] == ';'))
		return (1);
	else
		return (0);
}

void	check_s_name_len(char **line, int *s_name, int i)
{
	while ((*line)[(*s_name) + i] && (*line)[(*s_name) + i] != ' '
		&& (*line)[(*s_name) + i] != '\t' && (*line)[(*s_name) + i]
		!= DIRECT_CHAR && (*line)[(*s_name) + i] != LABEL_CHAR
		&& (*line)[(*s_name) + i] != '-' && (*line)[(*s_name) + i]
		!= ft_isdigit((*line)[(*s_name) + i]) && ((*line)[(*s_name) + i]
		!= 'r' || (*line)[(*s_name) + i - 1] == 'o'))
		(*s_name)++;
}

int		stock_len(t_stock **beg, t_cdata **start)
{
	t_stock	*cur;
	t_cdata	*back_slash;
	int		len;
	int		i;

	if (!(beg && *beg) || !(start && *start))
		return (0);
	len = 1;
	cur = *beg;
	back_slash = *start;
	while (cur->next != *beg && len++ > 0)
		cur = cur->next;
	while (back_slash->index != 1)
		back_slash = back_slash->next;
	i = 0;
	while (i < PROG_NAME_LENGTH)
		if (back_slash->str[i++] == '\n')
			len++;
	i = 0;
	back_slash = back_slash->next;
	while (i < COMMENT_LENGTH)
		if (back_slash->str[i++] == '\n')
			len++;
	return (len);
}

int		verif_index(char *str, int **tab, t_cdata **start, t_label **lab)
{
	int	res;

	if ((res = is_index(str + *(tab[0]), tab[0], lab, *(tab[1]))) == 1)
	{
		if ((res = ft_itoo((*start)->str, str + *(tab[0]), 2, tab[1]))
		== 0)
			return (0);
		(*tab[0]) += res;
	}
	else if (res == 0)
		return (0);
	else
	{
		(*start)->str[*(tab[1])] = 2;
		(*(tab[1])) += 2;
	}
	return (1);
}

int		verif_direct(char *str, int **tab, t_cdata **start, t_label **lab)
{
	int	res;

	if ((res = is_direct(str + *(tab[0]), tab[0], lab, *(tab[1]))) == 1)
	{
		if ((res = ft_itoo((*start)->str, str + *(tab[0]), *tab[2], tab[1]))
		== 0)
			return (0);
		*(tab[0]) += res;
	}
	else if (res == 0)
		return (0);
	else
	{
		(*start)->str[*(tab[1])] = *(tab[2]);
		(*(tab[1])) += (*tab[2]);
	}
	return (1);
}
