/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/08/07 16:31:58 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

/*
** cursor : index of the PC + the lenght you need to travel to reach
the memory case you want
*/

int			get_indirect(t_core *core, t_proces *pr, int cursor)
{
	int param;

	if (pr->op != 13 || pr->op != 14 || pr->op != 15)
		param = ft_otoi(&(core->arena[cursor]), 2);
	else
		param = ft_otoi(&(core->arena[cursor]), 2);
	//if (core->total_cycle > 1700 && core->total_cycle < 2100)
	//	ft_printf("res = %d\n", param);
	return (param);
}

static int	get_reg(t_core *core, t_proces *pr, int cursor)
{
	int p_index;
	int param;

	p_index = (int)(core->arena[cursor]);
	if (p_index > 0 && p_index <= REG_NUMBER)
		param = pr->r[p_index - 1];
	else
	{
		pr->params[0] = -1;
		param = -1;
	}
	return (param);
}

int			get_param(t_core *core, t_proces *pr, int type, int cursor)
{
	if (type == REG_CODE)
		return (get_reg(core, pr, cursor));
	else if (type == IND_CODE)
		return (get_indirect(core, pr, cursor));
	else if (type == DIR_CODE)
		return (get_direct(core, pr, cursor));
	else
		return (0);
}
