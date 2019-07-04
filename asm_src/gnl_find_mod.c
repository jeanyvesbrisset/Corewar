/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_find_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:37:00 by floblanc          #+#    #+#             */
/*   Updated: 2019/07/04 19:11:04 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		ft_itoo(unsigned char *str, char *str_nb, unsigned long long int size
		, int *index)
{
	unsigned long long int	nb;
	unsigned long long int	i;
	unsigned long long int	div;
	static char				*error = "Champion size too long, Max length : ";

	i = size;
	div = 1;
	if (*index + (int)size >= CHAMP_MAX_SIZE)
		return (ft_error(error, 0, 0, CHAMP_MAX_SIZE));
	nb = (9223372036854775807 + (str_nb[0] == '-'
	? ft_atoll(str_nb) + 1 : ft_atoll(str_nb)));
	if (!(ft_atoll(str_nb) == -1))
		nb %= 9223372036854775807;
	while (--i > 0)
		div *= 256;
	nb %= div * 256;
	while (i < size)
	{
		str[(*index)++] = (unsigned char)(nb / div);
		nb %= div;
		div /= 256;
		i++;
	}
	return (len_digit(str_nb));
}

int		comment_stocker(char **line, int *i, t_cdata **start, int ret)
{
	static int	diff;
	static char	*error = "Champion comment too long, Max length : ";

	if (!(diff))
		diff = 8 - (*i);
	if (diff == -1)
		return (ft_error("Too many .comment\n", 0, 0, 0));
	while ((*line)[*i] && (*line)[*i] != '"')
	{
		if ((diff + *i) >= (COMMENT_LENGTH + 7))
			return (ft_error(error, 0, 0, COMMENT_LENGTH));
		((*start)->next)->str[diff + (*i)] = (*line)[*i];
		(*i)++;
	}
	if (ret == 1 && (!(*line)[*i]))
	{
		((*start)->next)->str[diff + (*i)] = '\n';
		diff += (*i) + 1;
	}
	else
		diff = -1;
	return (1);
}

int		name_stocker(char **line, int *i, t_cdata **start, int ret)
{
	static int	diff;
	static char	*error = "Champion name too long, Max length : ";

	if (!(diff))
		diff = 4 - (*i);
	if (diff == -1)
		return (ft_error("Too many .name\n", 0, 0, 0));
	while ((*line)[*i] && (*line)[*i] != '"')
	{
		if ((diff + *i) >= (PROG_NAME_LENGTH + 4))
			return (ft_error(error, 0, 0, PROG_NAME_LENGTH));
		(*start)->str[diff + (*i)] = (*line)[*i];
		(*i)++;
	}
	if (ret == 1 && (!(*line)[*i]))
	{
		(*start)->str[diff + (*i)] = '\n';
		diff += (*i) + 1;
	}
	else
		diff = -1;
	return (1);
}

int		gnl_find_mod(char **line, t_cdata **start, int *reader, char c_or_n)
{
	int i;

	ft_strdel(line);
	while ((reader[1] = get_next_line_mod(reader[0], line)) > 0)
	{
		i = 0;
		if (c_or_n == 'n')
		{
			if (!(name_stocker(line, &i, start, reader[1])))
				return (-1);
		}
		else if (c_or_n == 'c')
		{
			if (!(comment_stocker(line, &i, start, reader[1])))
				return (-1);
		}
		if ((*line)[i] == '"')
		{
			return (i);
		}
		ft_strdel(line);
	}
	return (ft_error("Name & comment must finish with '\"'\n", -1, 0, 0));
}
