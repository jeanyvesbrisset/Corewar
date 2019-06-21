/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_three_args2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:11:01 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/21 14:55:20 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		gest_ldi(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		*tab[3];
	int		i;
	int		int_size;

	int_size = 2;
	i = 0;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 10;
	if (!(fct_separator(str, 2, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (!(ft_three_choices(str, tab, start, lab)))
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (!(ft_two_choices(str, tab, start, lab)))
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	return (end_gestion(str, &i));
}

int		gest_sti(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		*tab[3];
	int		i;
	int		int_size;

	i = 0;
	int_size = 2;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 11;
	if (!(fct_separator(str, 2, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (!(ft_three_choices(str, tab, start, lab)))
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (!(ft_two_choices(str, tab, start, lab)))
		return (0);
	return (end_gestion(str, &i));
}

int		gest_lldi(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		*tab[3];
	int		i;
	int		int_size;

	i = 0;
	int_size = 2;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 14;
	if (!(fct_separator(str, 2, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (!(ft_three_choices(str, tab, start, lab)))
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (!(ft_two_choices(str, tab, start, lab)))
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	return (end_gestion(str, &i));
}
