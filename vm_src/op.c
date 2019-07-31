/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/31 12:51:56 by maginist         ###   ########.fr       */
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
		champ->last_live = core->total_cycle;
		champ->process_live = pr->proces_nb;
		ft_printf("un processus dit que le joueur %d(%s) est en vie\n",
			champ_nb, champ->name);
		core->nbr_live++;
		champ->live_by_ctd++;
		if (core->flag_v)
			refresh_live(core);
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
		pr->carry = (!pr->carry ? 1 : 0);
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
	if (pr->op + 1 == 132)
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
		sum = value[0] + value[1];
		pr->r[p_index - 1] = sum;
		pr->carry = (!pr->carry ? 1 : 0);
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
	if (pr->op + 1 == 132)
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
		pr->carry = (!pr->carry ? 1 : 0);
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
		ft_printf("ZJMP execution\n");
	}
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
	if (pr->params[0] < 1 || pr->params[0] > 3
		|| pr->params[1] != DIR_CODE || pr->params[1] != REG_CODE
		|| pr->params[2] != REG_CODE)
		return ;
	sum = param_1 + param_2;
	r_index = core->arena[pr->pc + 2 + get_size(pr->op
		, pr->params[0]) + get_size(pr->op, pr->params[0])];
	if (r_index > 0 && r_index >= REG_SIZE)
		pr->r[r_index - 1] = pr->pc + (sum % IDX_MOD);
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
		ft_itoo_vm(core, pr->pc + (param_2 % IDX_MOD), param_1, 4);
		ft_printf("st ecrit ici : %d et il ecrit ca %d\n", pr->pc + (param_2 % IDX_MOD), param_1);
		if (core->flag_v)
			visu_sti_st(core, pr, pr->pc + (param_2 % IDX_MOD), 4);
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
	addr = pr->pc + ((param_2 + param_3) % IDX_MOD);
	if (pr->params[0] == REG_CODE &&
		(pr->params[1] == REG_CODE || pr->params[1] == DIR_CODE
		 || pr->params[1] == IND_CODE)
		&& (pr->params[2] == REG_CODE || pr->params[2] == DIR_CODE))
	{
		ft_itoo_vm(core, addr, param_1, 4);
		if (core->flag_v)
			visu_sti_st(core, pr, addr, 4);
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
	pr->carry = (!pr->carry ? 1 : 0);
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
	ft_printf("%c\n", param);
}

void	vm_sub_fork(t_core *core, t_proces *pr, int l)
{
	int	param_1;
	int	i;
	t_proces *new;

	param_1 = get_param(core, pr, pr->params[0], pr->pc + 2);
	new = (t_proces*)malloc(sizeof(t_proces));
	new->champ = pr->champ;
	new->proces_nb = core->proces->proces_nb + 1;
	core->sum_process++;
	i = -1;
	while (++i < REG_SIZE)
		new->r[i] = pr->r[i];
	new->carry = pr->carry;
	if (!l)
		new->pc = pr->pc + (param_1 % IDX_MOD);
	else
		new->pc = pr->pc + param_1;
	new->next = core->proces;
	core->proces = new;
	if (core->flag_v)
		refresh_process(core);
}

void	vm_fork(t_core *core, t_proces *pr)
{
	vm_sub_fork(core, pr, 0);
}

void	vm_lfork(t_core *core, t_proces *pr)
{
	vm_sub_fork(core, pr, 1);
}

void	vm_and(t_core *core, t_proces *pr)
{
	int	param_1;
	int	param_2;
	int	index_3;

	param_1 = get_param(core, pr, pr->params[0], pr->pc + 2);
	param_2 = get_param(core, pr, pr->params[1], pr->pc + 2 + get_size(pr->op
		, pr->params[0]));
	index_3 = get_param(core, pr, pr->params[2], pr->pc + 2 + get_size(pr->op
		, pr->params[0]) + get_size(pr->op, pr->params[1]));
	if ((pr->params[0] == REG_CODE || pr->params[0] == DIR_CODE || pr->params[0] == IND_CODE) &&
		(pr->params[1] == REG_CODE || pr->params[1] == DIR_CODE || pr->params[1] == IND_CODE) &&
		pr->params[2] == REG_CODE)
	{
		ft_printf("ZORK EST DANS AND\n");
		pr->r[index_3 - 1] = param_1 & param_2;
		pr->carry = (!pr->carry ? 1 : 0);
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
	index_3 = get_param(core, pr, pr->params[2], pr->pc + 2 + get_size(pr->op
		, pr->params[0]) + get_size(pr->op, pr->params[1]));
	if ((pr->params[0] == REG_CODE || pr->params[0] == DIR_CODE || pr->params[0] == IND_CODE) &&
		(pr->params[1] == REG_CODE || pr->params[1] == DIR_CODE || pr->params[1] == IND_CODE) &&
		pr->params[2] == REG_CODE)
	{
		pr->r[index_3 - 1] = param_1 | param_2;
		pr->carry = (!pr->carry ? 1 : 0);
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
	index_3 = get_param(core, pr, pr->params[2], pr->pc + 2 + get_size(pr->op
		, pr->params[0]) + get_size(pr->op, pr->params[1]));
	if ((pr->params[0] == REG_CODE || pr->params[0] == DIR_CODE || pr->params[0] == IND_CODE) &&
		(pr->params[1] == REG_CODE || pr->params[1] == DIR_CODE || pr->params[1] == IND_CODE) &&
		pr->params[2] == REG_CODE)
	{
		pr->r[index_3 - 1] = param_1 ^ param_2;
		pr->carry = (!pr->carry ? 1 : 0);
	}
}
