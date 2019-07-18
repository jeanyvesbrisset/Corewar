/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/18 16:47:48 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/vm.h"


void	handle_proces(t_core *core, t_proces *pr)
{
	unsigned char op;
	unsigned char ocp;

	op = core->arena[pr->pc];
	ocp = 0;
	if (op != 1 && op != 9 && op != 12 && op != 15)
		ocp = core->arena[pr->pc + 1];
	read_ocp(core, ocp);
}

void	read_op(t_core *core, t_proces *pr)
{
	unsigned char op;

	op = core->arena[pr->pc];
	if (op < 1 || op > 16)
		return ; // to do, prendre en compte cette erreur
	pr->wait = core->cycle_to_die + g_fvm_tab[op - 1].cycle_delay;
}

int		run_cycles_to_die(t_core *core)
{
	t_proces *pr;

	pr = core->proces;
	while (core->tmp_cycle++ < core->cycle_to_die)
	{
		if (!pr->wait || pr->wait == core->total_cycle - 1)
			read_op(core, pr);
		if (pr->wait == core->total_cycle)
			handle_proces(core, pr);
		if (pr->next)
			pr = pr->next;
		else
		{
			pr = core->proces;
			core->total_cycle++;
		}
	}
}

void	run_vm(t_core *core)
{
	while (run_cycles_to_die(core))
	{
		if (!check_lives(core))
			break ;
		else if (core->nbr_live > NBR_LIVE)
			core->cycle_to_die -= CYCLE_DELTA;
		core->tmp_cycle = 0;
		core->nbr_live = 0;
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