/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_two_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:35:21 by floblanc          #+#    #+#             */
/*   Updated: 2019/07/01 14:59:11 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		gest_ld(char *str, t_cdata **start, t_label **lab, int *index)
{
	int				i;
	int				res;
	unsigned char	*ocp;

	i = 0;
	(*start)->str[(*index)++] = 2;
	ocp = &((*start)->str[(*index)]);
	if (!(fct_separator(str, 1, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (str[i] == DIRECT_CHAR)
	{
		if ((res = is_direct(str + i, &i, lab, *index)) == 1)
		{
			if ((res = ft_itoo((*start)->str, str + i, 4, index))
			== 0)
				return (ft_error("ITOO A CRASH"));
			i += res;
		}
		else if (res == 0)
			return (0);
		else
		{
			(*start)->str[*index] = 4;
			(*index) += 4;
		}
		ocp_adder(ocp, DIR_CODE);
	}
	else if (is_index(str + i, &i))
	{
		if (!(res = ft_itoo((*start)->str, str + i, 2, index)))
			return (0);
			i += res;
		ocp_adder(ocp, IND_CODE);
	}
	else
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if ((*index) >= CHAMP_MAX_SIZE)
			return (0);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	ocp_adder(ocp, REG_CODE);
	return (end_gestion(str, &i));
}

int		gest_st(char *str, t_cdata **start, t_label **lab, int *index)
{
	int				i;
	unsigned char	*ocp;
	int				res;

	i = 0;
	(void)lab;
	(*start)->str[(*index)++] = 3;
	ocp = &((*start)->str[(*index)]);
	if (!(fct_separator(str, 1, index, 1)))
		return (ft_error("separator bug"));
	ft_jump_white_spaces(str, &i);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	ocp_adder(ocp, REG_CODE);
	if (!(ft_good_transi(str, &i)))
		return (ft_error("good transi bug"));
	if (str[i] == 'r')
	{
		if ((*index) >= CHAMP_MAX_SIZE)
			return (ft_error("INEX TROP BIG"));
		if (!((*start)->str[(*index)++] = is_register(str, &i)))
			return (ft_error("register bug"));
		ocp_adder(ocp, REG_CODE);
	}
	else if (is_index(str + i, &i))
	{
		if (!(res = ft_itoo((*start)->str, str + i, 2, index)))
			return (ft_error("ITOO PLANTE"));
		i += res;
		ocp_adder(ocp, IND_CODE);
	}
	else
		return (ft_error("whatt???"));
	ft_printf("str[%d] = %c\n", i, str[i]);
	return (end_gestion(str, &i));
}

int		gest_lld(char *str, t_cdata **start, t_label **lab, int *index)
{
	int				i;
	int				res;
	unsigned char	*ocp;

	i = 0;
	(*start)->str[(*index)++] = 13;
	ocp = &((*start)->str[(*index)]);
	if (!(fct_separator(str, 1, index, 1)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (str[i] == DIRECT_CHAR)
	{
		if ((res = is_direct(str + i, &i, lab, *index)) == 1)
		{
			if ((res = ft_itoo((*start)->str, str + i, 4, index))
			== 0)
			return (ft_error("ITOO A CRASH"));
			i += res;
		}
		else if (res == 0)
			return (0);
		else
		{
			(*start)->str[*index] = 4;
			(*index) += 4;
		}
		ocp_adder(ocp, DIR_CODE);	
	}
	else if (is_index(str + i, &i))
	{
		if (!(res = ft_itoo((*start)->str, str + i, 2, index)))
			return (0);
		i += res;
		ocp_adder(ocp, IND_CODE);
	}
	else
		return (0);
	if (!(ft_good_transi(str, &i)))
		return (0);
	if ((*index) >= CHAMP_MAX_SIZE)
			return (0);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	ocp_adder(ocp, REG_CODE);
	return (end_gestion(str, &i));
}
