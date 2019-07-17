/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/17 15:27:07 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	cpy_champs(t_core *core)
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

void	init_pc( t_core *core, t_champ *champ)
{
	t_proces	*proces;

	proces = core->proces;
	while (proces)
	{
		if (proces->champ == champ->pos)
		{
			proces->pc = champ->byte_start;
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



void	run_vm(t_core *core)
{
	while (run_cycles_to_die(core))
	{
		if (check_alives(core) > 1)
			break ;
		else if (core->nbr_live > NBR_LIVE)
			core->cycle_to_die -= CYCLE_DELTA;
		core->tmp_cycle = 0;
	}
}

int		vm(t_core *core)
{
	init_vm(core);
	run_vm(core);
}


/*
		etape 1 : creer un espace memoire dedie au comabt des joueurs
		etape 2 : charger les champions et leurs processus associes
				dans cet espace memoire
		etape 3 : executer les champions sequentiellement, donc l'un apres l'autre
					jusqu'a ce que mort s'ensuive
		etape 4 : tous ls 1536 cycles (cycle_to_die), on doit verifier que
					chaque processus a execute au moins une fois l'instruction live depuis la derniere verif
					sinon le processus meurt.
		etape 5 : si au cours d'une verif il y a eu au moins 21 (nbr_live) executions de live
					depuis la derniere verif on decremente cycle to die de 50 (cycle delta)
		etape 6 : quand tous les processus sont dead, on arrete la partie
		etape 7 : le gagnant est le dernier joueurrapporte en vie
		etape 8 : il faut afficher "le joueur n a gagne"

*/