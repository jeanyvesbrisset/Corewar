/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/24 17:53:37 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/vm.h"

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
	t_champ *champ;
	int	champ_nb;

	champ_nb = ft_otoi(core->arena[pr->pc + 1], 4);
	champ = get_champ(core, champ_nb);
	pr->alive = 1;
	if (champ)
	{
		champ->last_live = core->total_cycle;
		champ->process_live = pr->proces_nb;
		ft_printf("un processus dit que le joueur %d(%s) est en vie", 
		champ_nb, champ->name);
	}
}

/*
** Loads the value of the first param (can be a DIR or a IND) into the second param which is a reg.
** if the value of the first param equals 0, carry is 1, else is 0 
*/

void	vm_ld(t_core *core, t_proces *pr)
{
	int	param_1;
	int	param_2;
	int	p2_index;

	if (pr->params[0] == IND_CODE)	
		param_1 = pr->pc + (ft_otoi(core->arena[pr->pc + 2], 2) % IDX_MOD);
	else if (pr->params[0] == DIR_CODE)
		param_1 = ft_otoi(core->arena[pr->pc + 2], 2);
	p2_index = (int)(core->arena[pr->pc + 4]);
	if (p2_index > 0 && p2_index <= REG_NUMBER)
	{
		pr->r[p2_index - 1] = param_1;
		pr->carry = (!param_1 ? 1 : 0);
	}
}

// Transfert direct Registre > RAM / Registre. 
// Charge le contenu du registre passé en premier parametre dans le second parametre. 
// Si la valeur du premier parametre est egale a zero, alors le carry passe a l'etat un, sinon a l'etat zero.

void	vm_st(t_core *core, t_proces *pr)
{
	int	param_1;
	int	param_2;
	int	p1_index;
	// todo:verifier reg number
	p1_index = (int)(core->arena[pr->pc + 2]);
	param_2 = ft_otoi(core->arena[pr->pc + 3], pr->params[1]);
	if (p1_index > 0 && p1_index <= REG_NUMBER)
	{
		param_1 = pr->r[p1_index - 1];
		pr->carry = (!param_1 ? 1 : 0);
		core->arena[pr->pc + (param_2 % IDX_MOD)] = param_1;
	}
}

/*
** Adds the value of the first and the second param (which are both registers) and loads this sum into the third params (which is also a register)
*/

void	vm_add(t_core *core, t_proces *pr)
{
	int params[2];
	int	p_index;
	int	i;
	int	sum;

	i = 2;
	while (i < 4)
	{
		p_index = (int)(core->arena[pr->pc + i]);
		params[i - 2] = pr->r[p_index - 1];
		i++;
	}
	p_index = (int)(core->arena[pr->pc + 4]);
	sum = params[0] + params[1];
	pr->r[p_index - 1] = sum;
	pr->carry = (!sum ? 1 : 0);
}

/*
** Substracts the value of the first and the second param (which are both registers) and loads this sum into the third params (which is also a register)
*/

void	vm_sub(t_core *core, t_proces *pr)
{
	int params[2];
	int	p_index;
	int	i;
	int	sub;

	i = 2;
	while (i < 4)
	{
		p_index = (int)(core->arena[pr->pc + i]);
		params[i - 2] = pr->r[p_index - 1];
		i++;
	}
	p_index = (int)(core->arena[pr->pc + 4]);
	sub = params[0] - params[1];
	pr->r[p_index - 1] = sub;
	pr->carry = (!sub ? 1 : 0);
}

void	vm_sti(t_core *core, t_proces *pr)
{
	int	param_1;
	int	param_2;
	int	param_3;
	int addr;

	param_1 = pr->r[0];
	param_2 = ft_otoi(core->arena[pr->pc + 3], pr->params[1]);
	param_3 = ft_otoi(core->arena[pr->pc + (3 + pr->params[1])], pr->params[2]);
	addr = param_2 + param_3;
	(pr->pc) + addr = param_1;//ft_itoo

	//TO DO :gerer l'oveflow si addr > ffff
}

/*
** additionne les deux oremiers params et stocke le resultat dans le 3eme param qui est un registre.
*/ 

void	vm_and(t_core *core, t_proces *pr)
{
	int	param_1;
	int	param_2;
	int	param_3;
	int res;

	param_2 = ft_otoi(core->arena[pr->pc + 3], pr->params[1]);
	res = param_1 + param_2;
	param_3 = res;
	if (res == 0)
		pr->carry = 1;
	//TO DO : verifier si quand il est ecrit modifie le carry, il faut le mettre a 1, ou sil faut le mettre a 1 ou 0
}

/*
** saute a l'adresse passee en param 1 si le carry est a 1
*/
void	vm_zjmp(t_core *core, t_proces *pr)
{
	int	jump;
	int	param_1;

	param_1 = ft_otoi(core->arena[pr->pc + 1], pr->params[0]);
	jump = pr->pc + param_1;
	if (pr->carry)
		pr->pc += jump; 

	//TO DO :gerer l'oveflow si jump > ffff
}


int		get_indirect(t_core *core, int pc, int index)
{
	int param;

	param = pc + (ft_otoi(core->arena[pc + index], 2) % IDX_MOD);
	return (param);
}

int		get_reg(t_core *core, t_proces *pr, int cursor)
{
	int p_index;
	int param;

	param = 0;
	p_index = (int)(core->arena[cursor]);
	if (p_index > 0 && p_index <= REG_NUMBER)
		param = pr->r[p_index - 1];
	return (param);
}

/*
** Sums the value of the first and second parameters
*/

void	vm_ldi(t_core *core, t_proces *pr)
{
	int param_1;
	int param_2;
	int p_index;
	int	r_index;
	int sum;

	if (pr->params[0] == IND_CODE)	
		param_1 = pr->pc + (ft_otoi(core->arena[pr->pc + 2], 2) % IDX_MOD);
	else if (pr->params[0] == DIR_CODE)
		param_1 = ft_otoi(core->arena[pr->pc + 2], 2);
	else if (pr->params[0] == REG_CODE)
	{
		if (!(param_1 = get_reg(core, pr, pr->pc + 2)))
			return ; //TODO GESTION D"ERREUR
	}
	if (pr->params[1] == DIR_CODE)	
		param_2 = ft_otoi(core->arena[pr->pc + 2 + pr->params[0]], 2);
	else if (pr->params[1] == REG_CODE)
	{
		if (!(param_2 = get_reg(core, pr, pr->pc + 2 + pr->params[0])))
			return ; //TODO GESTION D"ERREUR
	}
	sum = param_1 + param_2;
	pr->carry = (!sum ? 1 : 0);
	r_index = core->arena[pr->pc + 2 + pr->params[0] + pr->params[1]];
	pr->r[r_index - 1] = pr->pc + (sum % IDX_MOD);
}

/*
** Like ld but without the adressing restriction (aka %IDX_MOD)
*/

void	vm_lld(t_core *core, t_proces *pr)
{
	int	param_1;
	int	param_2;
	int	p2_index;

	if (pr->params[0] == IND_CODE)	
		param_1 = pr->pc + ft_otoi(core->arena[pr->pc + 2], 2);
	else if (pr->params[0] == DIR_CODE)
		param_1 = ft_otoi(core->arena[pr->pc + 2], 2);
	p2_index = (int)(core->arena[pr->pc + 4]);
	if (p2_index > 0 && p2_index <= REG_NUMBER)
	{
		pr->r[p2_index - 1] = param_1;
		pr->carry = (!param_1 ? 1 : 0);
	}
}

/*
** Like ldi but without the adressing restriction (aka %IDX_MOD)
*/

void	vm_lldi(t_core *core, t_proces *pr)
{
	int param_1;
	int param_2;
	int p_index;
	int	r_index;
	int sum;

	if (pr->params[0] == IND_CODE)	
		param_1 = pr->pc + ft_otoi(core->arena[pr->pc + 2], 2);
	else if (pr->params[0] == DIR_CODE)
		param_1 = ft_otoi(core->arena[pr->pc + 2], 2);
	else if (pr->params[0] == REG_CODE)
	{
		if (!(param_1 = get_reg(core, pr, pr->pc + 2)))
			return ; //TODO GESTION D"ERREUR
	}
	if (pr->params[1] == DIR_CODE)	
		param_2 = ft_otoi(core->arena[pr->pc + 2 + pr->params[0]], 2);
	else if (pr->params[1] == REG_CODE)
	{
		if (!(param_2 = get_reg(core, pr, pr->pc + 2 + pr->params[0])))
			return ; //TODO GESTION D"ERREUR
	}
	sum = param_1 + param_2;
	pr->carry = (!sum ? 1 : 0);
	r_index = core->arena[pr->pc + 2 + pr->params[0] + pr->params[1]];
	pr->r[r_index - 1] = pr->pc + sum;
}

/*
** Takes the value of the register and displays it as a char (ascii code % 256) on the standard output 
*/

void	vm_aff(t_core *core, t_proces *pr)
{
	int param;

	if (!(param = get_reg(core, pr, pr->pc + 2)))
		return ;
	param %= 256;
	ft_printf("%c\n", param);
}