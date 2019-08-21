/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork_and_other.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:53:52 by maginist          #+#    #+#             */
/*   Updated: 2019/08/21 15:54:16 by maginist         ###   ########.fr       */
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

void	chwap(t_champ **before, t_champ **current, t_champ **after
, t_core *core)
{
	if (*before)
		(*before)->next = *after;
	else
		core->champs = *after;
	(*current)->next = (*after)->next;
	(*after)->next = *current;
	(*current) = core->champs;
	*after = (*current)->next;
	*before = 0;
}

void	vm_fork(t_core *core, t_proces *pr)
{
	int			param_1;
	int			i;
	t_proces	*new;

	param_1 = get_param(core, pr, pr->params[0], pr->pc + 1);
	if (!(new = (t_proces*)malloc(sizeof(t_proces) * 1)))
		return ;
	new->champ = pr->champ;
	new->wait = 0;
	new->alive = pr->alive;
	new->proces_nb = core->proces->proces_nb + 1;
	core->sum_process++;
	i = -1;
	while (++i < REG_NUMBER)
		new->r[i] = pr->r[i];
	new->carry = pr->carry;
	new->pc = (pr->pc + param_1) % MEM_SIZE;
	new->next = core->proces;
	core->proces = new;
	read_op(core, new);
}

void	vm_lfork(t_core *core, t_proces *pr)
{
	vm_fork(core, pr);
}
