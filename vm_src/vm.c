/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/31 12:51:57 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

t_champ	*get_winner(t_core *core)
{
	t_champ *champ;
	t_champ	*winner;

	winner = core->champs;
	champ = NULL;
	if (core->champs->next)
		champ = core->champs->next;
	while (champ)
	{
		ft_printf("champ[%s]->last_live = %d && ->process_live = %d\n", champ->name, champ->last_live, champ->process_live);
		if (champ->last_live > winner->last_live || (champ->last_live == winner->last_live && champ->process_live < winner->process_live))
			winner = champ;
		champ = champ->next;
	}
	ft_printf("winner[%s]->last_live = %d && ->process_live = %d\n", winner->name, winner->last_live, winner->process_live);
	return (winner);
}

void	vm(t_core *core)
{
	t_champ	*winner;

	init_vm(core);
	run_vm(core);
	winner = get_winner(core);
	ft_printf("le joueur %d(%s) à gagné\n", winner->pos, winner->name);
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