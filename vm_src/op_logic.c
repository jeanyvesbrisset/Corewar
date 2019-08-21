/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:51:20 by maginist          #+#    #+#             */
/*   Updated: 2019/08/21 12:05:20 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	vm_add(t_core *core, t_proces *pr)
{
	int value[2];
	int	p_index;
	int	i;
	int	sum;

	i = 2;
	if (pr->params[0] == REG_CODE && pr->params[1] == REG_CODE
	&& pr->params[2] == REG_CODE)
	{
		while (i < 4)
		{
			p_index = (int)(core->arena[pr->pc + i]);
			if (p_index < 1 || p_index > REG_NUMBER)
				return ;
			value[i - 2] = pr->r[p_index - 1];
			i++;
		}
		p_index = (int)(core->arena[pr->pc + 4]);
		if (p_index < 1 || p_index > REG_NUMBER)
			return ;
		sum = value[0] + value[1];
		pr->r[p_index - 1] = sum;
		pr->carry = (sum == 0) ? 1 : 0;
	}
}

void	vm_sub(t_core *core, t_proces *pr)
{
	int value[2];
	int	p_index;
	int	i;
	int	sub;

	i = 2;
	if (pr->params[0] == REG_CODE && pr->params[1] == REG_CODE
	&& pr->params[2] == REG_CODE)
	{
		while (i < 4)
		{
			p_index = (int)(core->arena[pr->pc + i]);
			if (p_index < 1 || p_index > REG_NUMBER)
				return ;
			value[i - 2] = pr->r[p_index - 1];
			i++;
		}
		p_index = (int)(core->arena[pr->pc + 4]);
		if (p_index < 1 || p_index > REG_NUMBER)
			return ;
		sub = value[0] - value[1];
		pr->r[p_index - 1] = sub;
		pr->carry = (sub == 0) ? 1 : 0;
	}
}

void	vm_and(t_core *core, t_proces *pr)
{
	int	param_1;
	int	param_2;
	int	index_3;

	param_1 = get_param(core, pr, pr->params[0], pr->pc + 2);
	param_2 = get_param(core, pr, pr->params[1], pr->pc + 2 + get_size(pr->op
		, pr->params[0]));
	index_3 = core->arena[pr->pc + 2 + get_size(pr->op
		, pr->params[0]) + get_size(pr->op, pr->params[1])];
	if ((pr->params[0] == REG_CODE || pr->params[0] == DIR_CODE
		|| pr->params[0] == IND_CODE)
		&& (pr->params[1] == REG_CODE || pr->params[1] == DIR_CODE
		|| pr->params[1] == IND_CODE)
		&& pr->params[2] == REG_CODE && index_3 > 0 && index_3 <= REG_NUMBER)
	{
		pr->r[index_3 - 1] = param_1 & param_2;
		if (pr->r[index_3 - 1] == 0)
			pr->carry = 1;
		else
			pr->carry = 0;
	}
}

void	vm_or(t_core *core, t_proces *pr)
{
	int	param_1;
	int	param_2;
	int	index_3;

	param_1 = get_param(core, pr, pr->params[0], pr->pc + 2);
	param_2 = get_param(core, pr, pr->params[1], pr->pc + 2 + get_size(pr->op
		, pr->params[0]));
	index_3 = core->arena[pr->pc + 2 + get_size(pr->op
		, pr->params[0]) + get_size(pr->op, pr->params[1])];
	if ((pr->params[0] == REG_CODE || pr->params[0] == DIR_CODE
		|| pr->params[0] == IND_CODE)
		&& (pr->params[1] == REG_CODE || pr->params[1] == DIR_CODE
		|| pr->params[1] == IND_CODE)
		&& pr->params[2] == REG_CODE && index_3 > 0 && index_3 <= REG_NUMBER)
	{
		pr->r[index_3 - 1] = param_1 | param_2;
		if (pr->r[index_3 - 1] == 0)
			pr->carry = 1;
		else
			pr->carry = 0;
	}
}

void	vm_xor(t_core *core, t_proces *pr)
{
	int	param_1;
	int	param_2;
	int	index_3;

	param_1 = get_param(core, pr, pr->params[0], pr->pc + 2);
	param_2 = get_param(core, pr, pr->params[1], pr->pc + 2 + get_size(pr->op
		, pr->params[0]));
	index_3 = core->arena[pr->pc + 2 + get_size(pr->op
		, pr->params[0]) + get_size(pr->op, pr->params[1])];
	if ((pr->params[0] == REG_CODE || pr->params[0] == DIR_CODE
		|| pr->params[0] == IND_CODE)
		&& (pr->params[1] == REG_CODE || pr->params[1] == DIR_CODE
		|| pr->params[1] == IND_CODE)
		&& pr->params[2] == REG_CODE && index_3 > 0 && index_3 <= REG_NUMBER)
	{
		pr->r[index_3 - 1] = param_1 ^ param_2;
		if (pr->r[index_3 - 1] == 0)
			pr->carry = 1;
		else
			pr->carry = 0;
	}
}
