/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_three_args2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:11:01 by floblanc          #+#    #+#             */
/*   Updated: 2019/07/01 11:35:04 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		gest_ldi(char *str, t_cdata **start, t_label **lab, int *index)
{
	void	*tab[4];
	int		i;
	int		int_size;

	int_size = 2;
	i = 0;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 10;
	tab[3] = &((*start)->str[(*index)]);
	if (!(fct_separator(str, 2, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (!(ft_three_choices(str, (int**)tab, start, lab)))
		return (0);
	if (!(ft_two_choices(str, (int**)tab, start, lab)))
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (*((int*)(tab[1])) >= CHAMP_MAX_SIZE)
			return (0);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	ocp_adder(tab[3], REG_CODE);
	return (end_gestion(str, &i));
}

int		gest_sti(char *str, t_cdata **start, t_label **lab, int *index)
{
	void	*tab[4];
	int		i;
	int		int_size;

	i = 0;
	int_size = 2;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 11;
	tab[3] = &((*start)->str[(*index)]);
	if (!(fct_separator(str, 2, index, 1)))
		return (ft_error("BAD NBR SEPARATOR"));
	ft_jump_white_spaces(str, &i);
	ft_printf("line[%d] = %c\n", i, str[i]);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (ft_error("BAD_REGISTER"));
	ocp_adder(tab[3], REG_CODE);
	if (!(ft_good_transi(str, &i)))
		return (ft_error("BAD TRANSI"));
	ft_printf("line[%d] = %c\n", i, str[i]);
	if (!(ft_three_choices(str, (int**)tab, start, lab)))
		return (ft_error("BAD CHOICES 3"));
	if (!(ft_two_choices(str, (int**)tab, start, lab)))
		return (ft_error("BAD CHOICES 2"));
	ft_printf("verif du %%1 de sti str[%d] = %d str[%d] = %d\n", *index - 2, (*start)->str[*index - 2], *index - 1, (*start)->str[*index - 1]);
	return (end_gestion(str, &i));
}

int		gest_lldi(char *str, t_cdata **start, t_label **lab, int *index)
{
	void	*tab[4];
	int		i;
	int		int_size;

	i = 0;
	int_size = 2;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 14;
	tab[3] = &((*start)->str[(*index)]);
	if (!(fct_separator(str, 2, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (!(ft_three_choices(str, (int**)tab, start, lab)))
		return (0);
	if (!(ft_two_choices(str, (int**)tab, start, lab)))
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if (*((int*)(tab[1])) >= CHAMP_MAX_SIZE)
			return (0);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	ocp_adder(tab[3], REG_CODE);
	return (end_gestion(str, &i));
}
