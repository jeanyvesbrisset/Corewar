/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/25 17:15:40 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/vm.h"

/*
** cursor : index of the PC + the lenght you need to travel to reach
the memory case you want
*/

static int	get_direct(t_core *core, t_proces *pr, int cursor)
{
	int	size;

	size = g_fvm_tab[pr->op - 1].direct_size;
	return (ft_otoi(core->arena[cursor], size));
}

int			get_size(int op, int type)
{
	if (type == REG_CODE)
		return (1);
	else if (type == IND_CODE)
		return (2);
	else if (type == DIR_CODE)
		return (g_fvm_tab[op - 1].direct_size);
}

static int	get_indirect(t_core *core, t_proces *pr, int cursor)
{
	int param;

	if (pr->op != 13 || pr->op != 14 || pr->op != 15)
		param = pr->pc + (ft_otoi(core->arena[cursor], 2) % IDX_MOD);
	else
		param = pr->pc + (ft_otoi(core->arena[cursor], 2));
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
		pr->params[0] = -1;
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
