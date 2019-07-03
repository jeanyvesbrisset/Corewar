/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_three_args1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:51:17 by floblanc          #+#    #+#             */
/*   Updated: 2019/07/02 18:15:24 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		gest_add(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;

	i = 0;
	(void)lab;
	if (*index + 5 >= CHAMP_MAX_SIZE)
		return (0);
	(*start)->str[(*index)++] = 4;
	(*start)->str[(*index)] = 84;
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
	(void)lab;
	if (*index + 5 >= CHAMP_MAX_SIZE)
		return (0);
	(*start)->str[(*index)++] = 5;
	(*start)->str[(*index)] = 84;
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
	void	*tab[4];
	int		i;
	int		int_size;

	i = 0;
	int_size = 4;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 6;
	tab[3] = &((*start)->str[(*index)]);
	if (!(fct_separator(str, 2, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (!(ft_three_choices(str, (int**)tab, start, lab)))
		return (0);
	if (!(ft_three_choices(str, (int**)tab, start, lab)))
		return (ft_error("BAD CHOICES 3 AND 2"));
	if ((*((int*)(tab[1]))) >= CHAMP_MAX_SIZE)
			return (0);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	ocp_adder(tab[3], REG_CODE);
	return (end_gestion(str, &i));
}

int		gest_or(char *str, t_cdata **start, t_label **lab, int *index)
{
	void	*tab[4];
	int		i;
	int		int_size;

	i = 0;
	int_size = 4;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 7;
	tab[3] = &((*start)->str[(*index)]);
	if (!(fct_separator(str, 2, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (!(ft_three_choices(str, (int**)tab, start, lab)))
		return (0);
	if (!(ft_three_choices(str, (int**)tab, start, lab)))
		return (0);
	if ((*((int*)(tab[1]))) >= CHAMP_MAX_SIZE)
			return (0);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	ocp_adder(tab[3], REG_CODE);
	return (end_gestion(str, &i));
}

int		gest_xor(char *str, t_cdata **start, t_label **lab, int *index)
{
	void	*tab[4];
	int		i;
	int		int_size;

	i = 0;
	int_size = 4;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 8;
	tab[3] = &((*start)->str[(*index)]);
	if (!(fct_separator(str, 2, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (!(ft_three_choices(str, (int**)tab, start, lab)))
		return (0);
	if (!(ft_three_choices(str, (int**)tab, start, lab)))
		return (0);
	if ((*((int*)(tab[1]))) >= CHAMP_MAX_SIZE)
			return (0);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	ocp_adder(tab[3], REG_CODE);
	return (end_gestion(str, &i));
}
