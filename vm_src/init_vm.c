/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/18 16:46:30 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/vm.h"

static void	cpy_champs(t_core *core)
{
	t_champ	*champ;
	int		i;
	int		j;

	champ = core->champs;
	while (champ)
	{
		i = champ->byte_start;
		j = 0;
		while (j < champ->size)
			core->arena[i++] = champ->bytecode[j++];
		champ = champ->next;
	}
}

static void	init_pc( t_core *core, t_champ *champ)
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

void	init_vm(t_core *core)
{
	t_champ	*champ;
	int		gap;

	champ = core->champs;
	gap = MEM_SIZE / core->champ_nb;
	champ->byte_start = MEM_SIZE - gap;
	while (champ)
	{
		if (champ->next)
			champ->next->byte_start = champ->byte_start - gap;
		init_pc(core, champ);
		champ = champ->next;
	}
	ft_bzero(core->arena, MEM_SIZE);
	cpy_champs(core);
	core->cycle_to_die = CYCLE_TO_DIE;
}