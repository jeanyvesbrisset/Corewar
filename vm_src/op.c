/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/08/20 16:55:56 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	vm_live(t_core *core, t_proces *pr)
{
	t_champ	*champ;
	int		champ_nb;

	champ_nb = get_param(core, pr, DIR_CODE, pr->pc + 1);
	champ = get_champ(core, champ_nb);
	pr->alive = 1;
	core->nbr_live++;
	if (champ && pr->params[0] == DIR_CODE)
	{
		champ->live_by_ctd++;
		core->live_champ++;
		champ->last_live = core->total_cycle;
		champ->process_live = pr->proces_nb;
		if (core->flag_vb)
			ft_printf("P:%d (at cycle %d)| Player %d(%s) is said to be alive\n"
			, pr->proces_nb, core->total_cycle, champ->pos, champ->name);
	}
}

void	vm_zjmp(t_core *core, t_proces *pr)
{
	int	param_1;

	param_1 = get_param(core, pr, pr->params[0], pr->pc + 1);
	if (pr->carry && pr->params[0] == DIR_CODE)
	{
		pr->pc = (pr->pc + param_1) % MEM_SIZE;
	}
	else
		pr->pc = (pr->pc + pr->pc_jump) % MEM_SIZE;
}

void	vm_st(t_core *core, t_proces *pr)
{
	int	param_1;
	int	param_2;
	int	p2_index;

	param_1 = get_param(core, pr, pr->params[0], pr->pc + 2);
	param_2 = get_param(core, pr, pr->params[1], pr->pc + 3);
	if (pr->params[0] != REG_CODE
		&& (pr->params[1] != REG_CODE || pr->params[1] != IND_CODE))
		return ;
	if (pr->params[1] == REG_CODE)
	{
		p2_index = (int)(core->arena[pr->pc + 3]);
		if (p2_index > 0 && p2_index <= REG_NUMBER)
			pr->r[p2_index - 1] = param_1;
	}
	else if (pr->params[1] == IND_CODE)
	{
		if (param_1 < 0)
			param_1--;
		ft_itoo_vm(core, pr->pc + param_2, param_1, 4);
		if (core->flag_v)
			visu_sti_st(core, pr, pr->pc + param_2, 4);
	}
}

void	vm_sti(t_core *core, t_proces *pr)
{
	int	param_1;
	int	param_2;
	int	param_3;
	int addr;

	param_1 = get_param(core, pr, pr->params[0], pr->pc + 2);
	param_2 = get_param(core, pr, pr->params[1], pr->pc + 3);
	param_3 = get_param(core, pr, pr->params[2], pr->pc + 3 + get_size(pr->op
		, pr->params[1]));
	addr = ((unsigned int)(param_2 + param_3)) % MEM_SIZE;
	if (addr < MEM_SIZE - IDX_MOD)
		addr = (pr->pc + (addr % IDX_MOD)) % MEM_SIZE;
	else
		addr = (pr->pc + addr) % MEM_SIZE;
	if (pr->params[0] == REG_CODE &&
		(pr->params[1] == REG_CODE || pr->params[1] == DIR_CODE
		|| pr->params[1] == IND_CODE)
		&& (pr->params[2] == REG_CODE || pr->params[2] == DIR_CODE))
	{
		if (param_1 < 0)
			param_1--;
		ft_itoo_vm(core, addr, param_1, 4);
		if (core->flag_v)
			visu_sti_st(core, pr, addr, 4);
	}
}

void	vm_aff(t_core *core, t_proces *pr)
{
	int param;

	param = get_param(core, pr, pr->params[0], pr->pc + 2);
	if (pr->params[0] != REG_CODE)
		return ;
	param %= 256;
	if (!(core->flag_v))
		ft_printf("Aff : %c\n", param);
}
