/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/08/10 16:33:39 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

t_champ	*get_champ(t_core *core, int pos)
{
	t_champ *champ;

	champ = core->champs;
	while (champ)
	{
		if (champ->pos == pos)
			return (champ);
		champ = champ->next;
	}
	return (NULL);
}

void	vm_live(t_core *core, t_proces *pr)
{
	t_champ	*champ;
	int		champ_nb;

	champ_nb = get_param(core, pr, DIR_CODE, pr->pc + 1);
	champ = get_champ(core, champ_nb);
	pr->alive = 1;
	if (champ && pr->params[0] == DIR_CODE)
	{
		champ->live_by_ctd++;
		core->nbr_live++;
		champ->last_live = core->total_cycle;
		champ->process_live = pr->proces_nb;
		if (core->flag_vb)
			ft_printf("P:%d (at cycle %d)| Player %d(%s) is said to be alive\n"
			, pr->proces_nb, core->total_cycle, champ->pos, champ->name);
		// ft_printf("un processus dit que le joueur %d(%s) est en vie\n", champ_nb, champ->name);
		// ft_printf("LIVE of %d(%s} at cycle %d\n", champ_nb, champ->name, core->total_cycle);
	}			
}

/*
** Loads the value of the first param (can be a DIR or a IND) into the second param which is a reg.
** if the value of the first param equals 0, carry is 1, else is 0 
*/

void	vm_ld(t_core *core, t_proces *pr)
{
	int	param_1;
	int	p2_index;

	param_1 = get_param(core, pr, pr->params[0], pr->pc + 2);
	p2_index = (int)(core->arena[pr->pc + 2 + get_size(pr->op, pr->params[0])]);
	if ((p2_index > 0 && p2_index <= REG_NUMBER) &&
		(pr->params[0] == DIR_CODE || pr->params[0] == IND_CODE) &&
		(pr->params[1] == REG_CODE))
	{
		pr->r[p2_index - 1] = param_1;
		if (!(param_1))
			pr->carry = 1;
		else
			pr->carry = 0;
		//  if (p2_index == 4)
			//  ft_printf("LD champ %d (pr %d) : param1 = %d dans r%d, carry = %d at cycle %d\n", pr->champ, pr->proces_nb, param_1, p2_index, pr->carry, core->total_cycle);
		//if (core->total_cycle < 3000)
			// ft_printf("le carry = %d du process %d apred un ld\n", pr->carry, pr->champ);
	}
}

/*
** Adds the value of the first and the second param (which are both registers) and loads this sum into the third params (which is also a register)
*/

void	vm_add(t_core *core, t_proces *pr)
{
	int value[2];
	int	p_index;
	int	i;
	int	sum;

	i = 2;
//	ft_printf("op = %d\n", pr->op);
	if (pr->params[0] == REG_CODE && pr->params[1] == REG_CODE
	&& pr->params[2] == REG_CODE)
	{
		//ft_printf("ADD\n");
		while (i < 4)
		{
		p_index = (int)(core->arena[pr->pc + i]);
		if (p_index < 1 && p_index > REG_NUMBER)
			return ;
		value[i - 2] = pr->r[p_index - 1];
		i++;
		}
		p_index = (int)(core->arena[pr->pc + 4]);
		if (p_index < 1 && p_index > REG_NUMBER)
			return ;
		sum = value[0] + value[1];
		pr->r[p_index - 1] = sum;
		if (sum == 0)
			pr->carry = 1;
		else
			pr->carry = 0;
		//if (core->total_cycle < 3000)
		//	ft_printf("le carry = %d du process %d apred un add\n", pr->carry, pr->champ);
	}
}

/*
** Substracts the value of the first and the second param (which are both registers) and loads this sum into the third params (which is also a register)
*/

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
			if (p_index < 1 && p_index > REG_NUMBER)
				return ;
			value[i - 2] = pr->r[p_index - 1];
			i++;
		}
		p_index = (int)(core->arena[pr->pc + 4]);
		if (p_index < 1 && p_index > REG_NUMBER)
			return ;
		sub = value[0] - value[1];
		pr->r[p_index - 1] = sub;
		if (sub == 0)
			pr->carry = 1;
		else
			pr->carry = 0;
		//if (core->total_cycle < 3000)
		//	ft_printf("le carry = %d du process %d apred un sub\n", pr->carry, pr->champ);
	}
}

/*
** saute a l'adresse passee en param 1 si le carry est a 1
*/

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

/*
** Sums the value of the first and second parameters
*/

void	vm_ldi(t_core *core, t_proces *pr)
{
	int param_1;
	int param_2;
	int	r_index;
	int sum;

	param_1 = get_param(core, pr, pr->params[0], pr->pc + 2);
	param_2 = get_param(core, pr, pr->params[1], pr-> pc + 2 + get_size(pr->op
		, pr->params[0]));
	
	if ((pr->params[0] < 1 && pr->params[0] > 3)
		|| (pr->params[1] != DIR_CODE && pr->params[1] != REG_CODE)
		|| pr->params[2] != REG_CODE)
		return ;
	sum = (param_1 + param_2) % MEM_SIZE;
	r_index = core->arena[pr->pc + 2 + get_size(pr->op
		, pr->params[0]) + get_size(pr->op, pr->params[1])];
	//ft_printf("r_index = %d : arena[pr->pc : %d + 2 + pr->params[0] %d + pr->param[1] %d\n", r_index, pr->pc, pr->params[0], pr->params[1]);
	if (r_index > 0 && r_index <= REG_SIZE)
	{
		if (sum < MEM_SIZE - IDX_MOD)
			pr->r[r_index - 1] = ft_otoi(&(core->arena[(pr->pc
			+ (sum % IDX_MOD))% MEM_SIZE]), 4);
		else
			pr->r[r_index - 1] = ft_otoi(&(core->arena[(pr->pc + (MEM_SIZE
			+ ((ft_abs(sum - MEM_SIZE) % IDX_MOD) * -1))) % MEM_SIZE]), 4);
		// if (core->total_cycle == 2510)
			// ft_printf("ldi by pr %d for champ %d, sum = %d( p1 %d + p2 %d), r%d = %d at cycle %d\n", pr->proces_nb, pr->champ, sum, param_1, param_2, r_index, pr->r[r_index - 1], core->total_cycle);
	}
}

// Transfert direct Registre > RAM / Registre. 
// Charge le contenu du registre passé en premier parametre dans le second parametre. 

void	vm_st(t_core *core, t_proces *pr)
{
	int	param_1;
	int	param_2;
	int	p2_index;

	param_1 = get_param(core, pr, pr->params[0], pr->pc + 2);
	param_2 = get_param(core, pr, pr->params[1], pr->pc + 3);
	//if (pr->params[1] == IND_CODE)
	//	param_2 %= IDX_MOD;
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
		ft_itoo_vm(core, pr->pc + param_2, param_1, 4);
		//ft_printf("Param_2 dans st = %d\n", param_2);
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
	if ((param_2 + param_3) < MEM_SIZE - IDX_MOD)
			addr = (pr->pc + ((param_2 + param_3) % IDX_MOD)) % MEM_SIZE;
	else
		addr = (pr->pc + (MEM_SIZE + ((ft_abs(param_2 + param_3 - MEM_SIZE)
		% IDX_MOD) * -1))) % MEM_SIZE;
	//addr = pr->pc + ((param_2 + param_3) % IDX_MOD);
	if (pr->params[0] == REG_CODE &&
		(pr->params[1] == REG_CODE || pr->params[1] == DIR_CODE
		 || pr->params[1] == IND_CODE)
		&& (pr->params[2] == REG_CODE || pr->params[2] == DIR_CODE))
	{
		ft_itoo_vm(core, addr, param_1, 4);
		if (core->flag_v)
			visu_sti_st(core, pr, addr, 4);
		// if (core->total_cycle < 3500)
			// ft_printf("pr %d for champ %d sti print %d from r%d at cycle %d\n", pr->proces_nb, pr->champ, param_1, core->arena[pr->pc + 2], core->total_cycle);
	}
}
/*
** Like ld but without the adressing restriction (aka %IDX_MOD)
*/

void	vm_lld(t_core *core, t_proces *pr)
{
	vm_ld(core, pr);
}

/*
** Like ldi but without the adressing restriction (aka %IDX_MOD)
*/

void	vm_lldi(t_core *core, t_proces *pr)
{
	vm_ldi(core, pr);
	pr->carry = !(pr->carry);
//	if (core->total_cycle < 3000)
	//		ft_printf("le carry = %d du process %d apred un lldi\n", pr->carry, pr->champ);
}

/*
** Takes the value of the register and displays it as a char (ascii code % 256) on the standard output 
*/

void	vm_aff(t_core *core, t_proces *pr)
{
	int param;

	param = get_param(core, pr, pr->params[0], pr->pc + 2);
	if (pr->params[0] != REG_CODE)
		return ;
	param %= 256;
	//// ft_printf("%c\n", param);
}

void	vm_fork(t_core *core, t_proces *pr)
{
	int	param_1;
	int	i;
	t_proces *new;
	
	param_1 = get_param(core, pr, pr->params[0], pr->pc + 1);
	if (!(new = (t_proces*)malloc(sizeof(t_proces) * 1)))
		return ;
	new->champ = pr->champ;
	new->wait = 0;
	new->alive = pr->alive;
	new->proces_nb = core->proces->proces_nb + 1;
	core->sum_process++;
	i = -1;
	while (++i < REG_SIZE)
		new->r[i] = pr->r[i];
	new->carry = pr->carry;
	new->pc = (pr->pc + param_1) % MEM_SIZE;
	//ft_printf("new->pc = %d\n", new->pc); 
	new->next = core->proces;
	core->proces = new;
	read_op(core, new);
}

void	vm_lfork(t_core *core, t_proces *pr)
{
	vm_fork(core, pr);
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
	if ((pr->params[0] == REG_CODE || pr->params[0] == DIR_CODE || pr->params[0] == IND_CODE) &&
		(pr->params[1] == REG_CODE || pr->params[1] == DIR_CODE || pr->params[1] == IND_CODE) &&
		pr->params[2] == REG_CODE)
	{
		pr->r[index_3 - 1] = param_1 & param_2;
		if (pr->r[index_3 - 1] == 0)
			pr->carry = 1;
		else
			pr->carry = 0;
	//	if (core->total_cycle < 3000)
		//	ft_printf("le carry = %d du process %d apred un and\n", pr->carry, pr->champ);
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
	if ((pr->params[0] == REG_CODE || pr->params[0] == DIR_CODE || pr->params[0] == IND_CODE) &&
		(pr->params[1] == REG_CODE || pr->params[1] == DIR_CODE || pr->params[1] == IND_CODE) &&
		pr->params[2] == REG_CODE)
	{
		pr->r[index_3 - 1] = param_1 | param_2;
		if (pr->r[index_3 - 1] == 0)
			pr->carry = 1;
		else
			pr->carry = 0;
	//	if (core->total_cycle < 3000)
		//	ft_printf("le carry = %d du process %d apred un or\n", pr->carry, pr->champ);
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
	if ((pr->params[0] == REG_CODE || pr->params[0] == DIR_CODE || pr->params[0] == IND_CODE) &&
		(pr->params[1] == REG_CODE || pr->params[1] == DIR_CODE || pr->params[1] == IND_CODE) &&
		pr->params[2] == REG_CODE)
	{
		pr->r[index_3 - 1] = param_1 ^ param_2;
		if (pr->r[index_3 - 1] == 0)
			pr->carry = 1;
		else
			pr->carry = 0;
	//	if (core->total_cycle < 3000)
			// ft_printf("le carry = %d du process %d apred un xor\n", pr->carry, pr->champ);
	}
}
