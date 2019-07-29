/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/29 15:12:57 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

static void	cpy_champs(t_core *core)
{
	t_champ	*champ;
	int		i;
	int		j;

	champ = core->champs;
	while (champ)
	{
		champ->last_live = 0;
		champ->process_live = 0;
		i = champ->byte_start;
		j = 0;
		while (j < champ->size)
			core->arena[i++] = champ->bytecode[j++];
		champ = champ->next;
	}
}

static void	init_pc(t_core *core, t_champ *champ)
{
	t_proces	*proces;

	proces = core->proces;
	while (proces)
	{
		if (proces->champ == champ->pos)
		{
			proces->pc = champ->byte_start;
			proces->wait = 0;
			return ;
		}
		proces = proces->next;
	}
}

void		init_vm(t_core *core)
{
	t_champ	*champ;
	int		gap;

	champ = core->champs;
	gap = MEM_SIZE / core->champ_nb;
	champ->byte_start = MEM_SIZE - gap;
	while (champ)
	{
		if (champ->next)
		{
			if (core->champ_nb == 3 && champ == core->champs)
				champ->next->byte_start = champ->byte_start - gap - 1;
			else
				champ->next->byte_start = champ->byte_start - gap;
		}
		init_pc(core, champ);
		champ = champ->next;
	}
	ft_bzero(core->arena, MEM_SIZE);
	cpy_champs(core);
	core->tmp_cycle = 0;
	core->nbr_live = 0;
	core->total_cycle = 0;
	core->cycle_to_die = CYCLE_TO_DIE;
	core->max_checks = 0;
}
