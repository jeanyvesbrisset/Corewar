/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_two_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:35:21 by floblanc          #+#    #+#             */
/*   Updated: 2019/07/02 18:08:13 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		gest_ld2(char *str, t_cdata **start, int **tab, unsigned char *ocp)
{
	if (!(ft_good_transi(str, tab[0])))
		return (0);
	if ((*tab)[1] >= CHAMP_MAX_SIZE)
			return (0);
	if (!((*start)->str[((*tab)[1])++] = is_register(str, tab[0])))
		return (0);
	ocp_adder(ocp, REG_CODE);
	ocp_adder(ocp, 0);
	return (end_gestion(str, tab[0]));	
}

int		gest_ld(char *str, t_cdata **start, t_label **lab, int *index)
{
	unsigned char	*ocp;
	void	*tab[3];
	int		i;
	int		int_size;

	i = 0;
	int_size = 4;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 2;
	ocp = &((*start)->str[(*index)]);
	if (!(fct_separator(str, 1, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (str[i] == DIRECT_CHAR)
	{
		if (verif_direct(str, (int**)tab, start, lab))
			ocp_adder(ocp, DIR_CODE);
	}
	else if (verif_index(str, (int**)tab, start, lab))
		ocp_adder(ocp, IND_CODE);
	else
		return (0);
	return (gest_ld2(str, start, (int**)tab, ocp));
}

int		gest_st2(char *str, int **tab, t_cdata **start, unsigned char *ocp)
{
	if (!(fct_separator(str, 1, tab[1], 1)))
		return (0);
	ft_jump_white_spaces(str, tab[0]);
	if (!((*start)->str[((*tab)[1])++] = is_register(str, tab[0])))
		return (0);
	ocp_adder(ocp, REG_CODE);
	if (!(ft_good_transi(str, tab[0])))
		return (0);
	return (1);
}

int		gest_st(char *str, t_cdata **start, t_label **lab, int *index)
{
	int				i;
	unsigned char	*ocp;
	void			*tab[2];

	i = 0;
	tab[0] = &i;
	tab[1] = index;
	(*start)->str[(*index)++] = 3;
	ocp = &((*start)->str[(*index)]);
	if	(!(gest_st2(str, (int**)tab, start, ocp)))
		return (0);
	if (str[i] == 'r')
	{
		if ((*index) >= CHAMP_MAX_SIZE)
			return (0);
		if (!((*start)->str[(*index)++] = is_register(str, &i)))
			return (0);
		ocp_adder(ocp, REG_CODE);
	}
	else if (verif_index(str, (int**)tab, start, lab))
		ocp_adder(ocp, IND_CODE);
	else
		return (0);
	ocp_adder(ocp, 0);
	return (end_gestion(str, &i));
}

int		gest_lld(char *str, t_cdata **start, t_label **lab, int *index)
{
	unsigned char	*ocp;
	void	*tab[3];
	int		i;
	int		int_size;

	i = 0;
	int_size = 4;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 13;
	ocp = &((*start)->str[(*index)]);
	if (!(fct_separator(str, 1, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (str[i] == DIRECT_CHAR)
	{
		if (verif_direct(str, (int**)tab, start, lab))
			ocp_adder(ocp, DIR_CODE);
	}
	else if (verif_index(str, (int**)tab, start, lab))
		ocp_adder(ocp, IND_CODE);
	else
		return (0);
	return (gest_ld2(str, start, (int**)tab, ocp));
}
