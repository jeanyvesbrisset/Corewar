/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 09:54:53 by maginist          #+#    #+#             */
/*   Updated: 2019/06/21 15:56:07 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int	ft_three_choices(char *str, int **tab, t_cdata **start, t_label **lab)
{
	int res;

	if (str[(*(tab[0]))] == DIRECT_CHAR)
	{
		if ((res = is_direct(str + *(tab[0]) + 1, tab[0], lab, *(tab[1]))) == 2)
			ft_itoo((*start)->str + *(tab[1]), str + *(tab[0]), *(tab[2])
			, tab[1]);
		else if (res == 0)
			return (0);
	}
	else if (str[(*(tab[0]))] == 'r')
	{
		if (!((*start)->str[(*(tab[1]))++] = is_register(str, tab[0])))
			return (0);
	}
	else if (is_index(str + *(tab[0]), tab[0]))
		ft_itoo((*start)->str + *(tab[1]), str + *(tab[0]), 2, tab[1]);
	else
		return (0);
	return (1);
}

int	ft_two_choices(char *str, int **tab, t_cdata **start, t_label **lab)
{
	int	res;

	if (str[(*(tab[0]))] == DIRECT_CHAR)
	{
		if ((res = is_direct(str + *(tab[0]) + 1, tab[0], lab, *(tab[1]))) == 2)
			ft_itoo((*start)->str + *(tab[1]), str + *(tab[0]), 2, tab[1]);
		else if (res == 0)
			return (0);
	}
	else if (str[(*(tab[0]))] == 'r')
	{
		if (!((*start)->str[(*(tab[1]))++] = is_register(str, tab[0])))
			return (0);
	}
	else
		return (0);
	return (1);
}

int	fct_separator(char *str, int nb_sep, int *index, int ocp)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == SEPARATOR_CHAR)
			count++;
		i++;		
	}
	if (count != nb_sep)
		return (0);
	if (ocp)
		(*index)++;
	return (1);
;
}

int	ft_good_transi(char *str, int *i)
{
	ft_jump_white_spaces(str, i);
	if (str[(*i)++] != SEPARATOR_CHAR)
		return (0);
	ft_jump_white_spaces(str, i);
	return (1);
}

int	end_gestion(char *str, int *i)
{
	ft_jump_white_spaces(str, i);
	if (str[(*i)] != 0)
		return (0);
	return (1);
}
