/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_find_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:37:00 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/18 17:27:53 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/op.h"

void    ft_itoo(unsigned char **str, char *str_nb, unsigned long long int size)
{
	unsigned long long int nb;
	unsigned long long int i;
	unsigned long long int div;

	i = size;
	div = 1;
	nb = (9223372036854775807 + ft_atoll(str_nb)) % 9223372036854775807;
	while (--i > 0)
		div *= 256;
	nb %= div * 256;
	while (i < size)
	{
		(*str)[i] = (unsigned char)(nb / div);
		nb %= div;
		div /= 256;
		i++;
	}
}

void   comment_stocker(char **line, int *i, t_cdata **start, int ret)
{
	static int     diff;

	if (!(diff))
		diff = 4 - (*i);
	while ((*line)[*i] && (*line)[*i] != '"')//limiter le nombre de caracteres a COMMENT_LENGTH : 2048
	{
		((*start)->next)->str[diff + (*i)] = (*line)[*i];
		(*i)++;
	}
	if (ret == 1 && (!(*line)[*i]))
	{
		((*start)->next)->str[diff + (*i)] = '\n';
		diff += (*i) + 1;
	}
	else
		diff += *i;
}

void    name_stocker(char **line, int *i, t_cdata **start, int ret)
{
	static int     diff;

	if (!(diff))
		diff = 4 - (*i);
	while ((*line)[*i] && (*line)[*i] != '"')//limiter le nombre de caracteres a PROG_NAME_LENGTH : 128
	{
		(*start)->str[diff + (*i)] = (*line)[*i];
		(*i)++;
	}
	if (ret == 1 && (!(*line)[*i]))
	{
		(*start)->str[diff + (*i)] = '\n';
		diff += (*i) + 1;
	}
	else
		diff += *i;
}

int     gnl_find_mod(char **line, t_cdata **start, int *reader, char c_or_n)
{
	int i;

	while ((reader[1] = get_next_line_mod(reader[0], line)) > 0)
	{
		i = 0;
		if (c_or_n == 'n')
			name_stocker(line, &i, start, reader[1]);
		else if (c_or_n == 'c')
			comment_stocker(line, &i, start, reader[1]);
		if ((*line)[i] == '"')
			return (1);
		ft_strdel(line);
	}
	return (0);
}
