/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_two_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:35:21 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/22 17:55:02 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
// comment pour lire le commit important
int		gest_ld(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;
	int		res;

	i = 0;
	(*start)->str[(*index)++] = 2;
	if (!(fct_separator(str, 1, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (str[i] == DIRECT_CHAR)
	{
		if ((res = is_direct(str + i + 1, &i, lab, *index)) == 2)
			ft_itoo((*start)->str + (*index), str + i, 4, index);
		else if (res == 0)
			return (0);
	}
	else if (is_index(str + i, &i))
		ft_itoo((*start)->str + (*index), str + i, 2, index);
	else
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	return (end_gestion(str, &i));
}

int		gest_st(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;

	i = 0;
	(*start)->str[(*index)++] = 3;
	if (!(fct_separator(str, 1, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (str[i] == 'r')
	{
		if (!((*start)->str[(*index)++] = is_register(str, &i)))
			return (0);
	}
	else if (is_index(str + i, &i))
		ft_itoo((*start)->str + (*index), str + i, 2, index);
	else
		return (0);
	return (end_gestion(str, &i));
}

int		gest_lld(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;
	int		res;

	i = 0;
	(*start)->str[(*index)++] = 13;
	if (!(fct_separator(str, 1, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (str[i] == DIRECT_CHAR)
	{
		if ((res = is_direct(str + i + 1, &i, lab, *index)) == 2)
			ft_itoo((*start)->str + (*index), str + i, 4, index);
		else if (res == 0)
			return (0);
	}
	else if (is_index(str + i, &i))
		ft_itoo((*start)->str + (*index), str + i, 2, index);
	else
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	return (end_gestion(str, &i));
}
