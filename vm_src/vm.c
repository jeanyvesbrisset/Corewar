/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/23 16:02:33 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/vm.h"

t_champ	*get_winner(t_core *core)
{
	t_champ *champ;
	int	winner[3];
	int	tmp[3];

	winner[0] = 0;
	winner[1] = 0;
	winner[2] = 0;
	champ = core->champs;
	while (champ)
	{
		if (champ->last_live > winner[1] ||
			(champ->last_live == winner[1] && champ->process_live < winner[2]))
		{
			winner[0] = champ->pos;
			winner[1] = champ->last_live;
			winner[2] = champ->process_live; 
		}
		champ = champ->next;
	}
	return (get_champ(core, winner[0]));
}

int		vm(t_core *core)
{
	t_champ	*winner;

	init_vm(core);
	run_vm(core);
	winner = get_winner(core);
	ft_printf("le joueur %d(%s) a gagne", winner->pos, winner->name);
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