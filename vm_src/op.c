/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/23 17:13:12 by maginist         ###   ########.fr       */
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
** Loads the value of the first param into the second param which is a reg. 
*/

void	vm_ld(t_core *core, t_proces *pr)
{
	int	param_1;
	int	param_2;
	int	p2_index;

	p2_index = (int)(core->arena[pr->pc + 5]);
	if (p2_index > 0 && p2_index <= REG_NUMBER)
	{
		param_1 = ft_otoi(core->arena[pr->pc + 3], pr->params[0]);
		pr->r[p2_index - 1] = param_1;
		pr->carry = 1;
	}
}

void	vm_st(t_core *core, t_proces *pr)
{
 
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
	(pr->pc + addr) = param_1;//ft_itoo

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
