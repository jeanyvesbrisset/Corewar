/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_three_args1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:51:17 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/21 13:35:14 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		gest_add(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;

	i = 0;
	(*start)->str[(*index)++] = 4;
	if (!(fct_separator(str, 2, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	return (end_gestion(str, &i));
}

int		gest_sub(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;

	i = 0;	
	(*start)->str[(*index)++] = 5;
	if (!(fct_separator(str, 2, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	return (end_gestion(str, &i));
}

int		gest_and(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		*tab[2];
	int		i;

	i = 0;
	tab[0] = &i;
	tab[1] = index;
	(*start)->str[(*index)++] = 6;
	if (!(fct_separator(str, 2, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (!(ft_three_choices(str, tab, start, lab)))
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (!(ft_three_choices(str, tab, start, lab)))
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	return (end_gestion(str, &i));
}