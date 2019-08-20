/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/08/20 16:04:03 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int			get_index(t_core *core, t_proces *pr, int cursor)
{
	int param;

	if (pr->op != 10 || pr->op != 11 || pr->op != 13 || pr->op != 14
	|| pr->op != 15)
	{
		param = ft_otoi(&(core->arena[0]), cursor, 2) % MEM_SIZE;
		if (param < MEM_SIZE - IDX_MOD)
			param = param % IDX_MOD;
	}
	else
		param = ft_otoi(&(core->arena[0]), cursor, 2);
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
	cursor %= MEM_SIZE;
	if (type == REG_CODE)
		return (get_reg(core, pr, cursor));
	else if (type == IND_CODE)
		return (get_index(core, pr, cursor));
	else if (type == DIR_CODE)
		return (get_direct(core, pr, cursor));
	else
		return (0);
}
