/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:49:47 by maginist          #+#    #+#             */
/*   Updated: 2019/08/20 16:56:56 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	vm_ld(t_core *core, t_proces *pr)
{
	int	param_1;
	int	p2_index;

	param_1 = get_param(core, pr, pr->params[0], pr->pc + 2);
	p2_index = (int)(core->arena[(pr->pc + 2
	+ get_size(pr->op, pr->params[0])) % MEM_SIZE]);
	if ((p2_index > 0 && p2_index <= REG_NUMBER) &&
		(pr->params[0] == DIR_CODE || pr->params[0] == IND_CODE) &&
		(pr->params[1] == REG_CODE))
	{
		if (pr->params[0] == DIR_CODE)
			pr->r[p2_index - 1] = param_1;
		else
			pr->r[p2_index - 1] = ft_otoi(&(core->arena[0]),
			(pr->pc + param_1) % MEM_SIZE, 4);
		if (!(pr->r[p2_index - 1]))
			pr->carry = 1;
		else
			pr->carry = 0;
	}
}

void	vm_ldi2(t_core *core, t_proces *pr, int sum, int r_index)
{
	if (sum < MEM_SIZE - IDX_MOD && pr->op != 14)
		pr->r[r_index - 1] = ft_otoi(&(core->arena[0])
		, (pr->pc + (sum % IDX_MOD)) % MEM_SIZE, 4);
	else
	{
		pr->r[r_index - 1] = ft_otoi(&(core->arena[0])
		, (pr->pc + sum) % MEM_SIZE, 4);
	}
}

void	vm_ldi(t_core *core, t_proces *pr)
{
	int	param_1;
	int	param_2;
	int	r_index;
	int	sum;

	param_1 = get_param(core, pr, pr->params[0], pr->pc + 2);
	param_2 = get_param(core, pr, pr->params[1], pr->pc + 2 + get_size(pr->op
		, pr->params[0]));
	if ((pr->params[0] != REG_CODE && pr->params[0] != DIR_CODE
		&& pr->params[0] != IND_CODE)
		|| (pr->params[1] != DIR_CODE && pr->params[1] != REG_CODE)
		|| pr->params[2] != REG_CODE)
		return ;
	sum = ((unsigned int)(param_1 + param_2)) % MEM_SIZE;
	if (pr->op == 14)
		pr->carry = (sum ? 1 : 0);
	r_index = core->arena[pr->pc + 2 + get_size(pr->op
		, pr->params[0]) + get_size(pr->op, pr->params[1])];
	if (r_index > 0 && r_index <= REG_NUMBER)
		vm_ldi2(core, pr, sum, r_index);
}

void	vm_lld(t_core *core, t_proces *pr)
{
	vm_ld(core, pr);
}

void	vm_lldi(t_core *core, t_proces *pr)
{
	vm_ldi(core, pr);
}
