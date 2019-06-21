/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_three_args1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:51:17 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/21 16:15:59 by maginist         ###   ########.fr       */
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
	int		*tab[3];
	int		i;
	int		int_size;

	i = 0;
	int_size = 4;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
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

int		gest_or(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		*tab[3];
	int		i;
	int		int_size;

	i = 0;
	int_size = 4;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 7;
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

int		gest_xor(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		*tab[3];
	int		i;
	int		int_size;

	i = 0;
	int_size = 4;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 8;
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
