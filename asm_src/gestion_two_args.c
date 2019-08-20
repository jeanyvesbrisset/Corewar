/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_two_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:35:21 by floblanc          #+#    #+#             */
/*   Updated: 2019/08/20 16:06:23 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		gest_ld2(char *str, t_cdata **start, int **tab)
{
	static char	*error = "Champion size too long, Max length : ";

	if (!(ft_good_transi(str, tab[0])))
		return (0);
	if ((*tab[1]) + 1 >= CHAMP_MAX_SIZE)
		return (ft_error(error, 0, 0, CHAMP_MAX_SIZE));
	if (!((*start)->str[(*tab[1])++] = is_register(str, tab[0])))
		return (0);
	ocp_adder((void*)(tab[3]), REG_CODE);
	ocp_adder((void*)(tab[3]), 0);
	return (end_gestion(str, tab[0]));
}

int		gest_ld(char *str, t_cdata **start, t_label **lab, int *index)
{
	void	*tab[4];
	int		i;
	int		int_size;

	i = 0;
	int_size = 4;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 2;
	tab[3] = &((*start)->str[(*index)]);
	if (!(fct_separator(str, 1, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (str[i] == DIRECT_CHAR)
	{
		if (verif_direct(str, (int**)tab, start, lab))
			ocp_adder(tab[3], DIR_CODE);
	}
	else if (verif_index(str, (int**)tab, start, lab))
		ocp_adder(tab[3], IND_CODE);
	else
		return (0);
	return (gest_ld2(str, start, (int**)tab));
}

int		gest_st2(char *str, int **tab, t_cdata **start)
{
	static char	*error = "Champion size too long, Max length : ";

	if (!(fct_separator(str, 1, tab[1], 1)))
		return (0);
	ft_jump_white_spaces(str, tab[0]);
	if ((*tab[1]) + 1 >= CHAMP_MAX_SIZE)
		return (ft_error(error, 0, 0, CHAMP_MAX_SIZE));
	if (!((*start)->str[(*tab[1])++] = is_register(str, tab[0])))
		return (0);
	ocp_adder((void*)(tab[2]), REG_CODE);
	if (!(ft_good_transi(str, tab[0])))
		return (0);
	return (1);
}

int		gest_st(char *str, t_cdata **start, t_label **lab, int *index)
{
	int			i;
	void		*tab[3];
	static char	*error = "Champion size too long, Max length : ";

	i = 0;
	tab[0] = &i;
	tab[1] = index;
	(*start)->str[(*index)++] = 3;
	tab[2] = &((*start)->str[(*index)]);
	if (!(gest_st2(str, (int**)tab, start)))
		return (0);
	if (str[i] == 'r')
	{
		if ((*index) > CHAMP_MAX_SIZE)
			return (ft_error(error, 0, 0, CHAMP_MAX_SIZE));
		if (!((*start)->str[(*index)++] = is_register(str, &i)))
			return (0);
		ocp_adder(tab[2], REG_CODE);
	}
	else if (verif_index(str, (int**)tab, start, lab))
		ocp_adder(tab[2], IND_CODE);
	else
		return (0);
	ocp_adder(tab[2], 0);
	return (end_gestion(str, &i));
}

int		gest_lld(char *str, t_cdata **start, t_label **lab, int *index)
{
	void	*tab[4];
	int		i;
	int		int_size;

	i = 0;
	int_size = 4;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 13;
	tab[3] = &((*start)->str[(*index)]);
	if (!(fct_separator(str, 1, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (str[i] == DIRECT_CHAR)
	{
		if (verif_direct(str, (int**)tab, start, lab))
			ocp_adder(tab[3], DIR_CODE);
	}
	else if (verif_index(str, (int**)tab, start, lab))
		ocp_adder(tab[3], IND_CODE);
	else
		return (0);
	return (gest_ld2(str, start, (int**)tab));
}
