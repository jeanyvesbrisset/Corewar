/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/08/05 13:47:05 by maginist         ###   ########.fr       */
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
		// ft_printf("champ[%s]->last_live = %d && ->process_live = %d\n", champ->name, champ->last_live, champ->process_live);
		if (champ->last_live > winner->last_live || (champ->last_live == winner->last_live && champ->process_live < winner->process_live))
			winner = champ;
		champ = champ->next;
	}
	// ft_printf("winner[%s]->last_live = %d && ->process_live = %d\n", winner->name, winner->last_live, winner->process_live);
	return (winner);
}

void	vm(t_core *core)
{
	t_champ	*winner;

	init_vm(core);
	run_vm(core);
	winner = get_winner(core);
	if (core->flag_v)
	{
		wattron(core->visu->hud, COLOR_PAIR(winner->pos));
		mvwprintw(core->visu->hud, 40 + (core->champ_nb * 4), 40
				, (const char*)winner->name);
		wattroff(core->visu->hud, COLOR_PAIR(winner->pos));
		wattron(core->visu->hud, A_BOLD);
		core->visu->str = ft_itoa(core->total_cycle);
		mvwprintw(core->visu->hud, 13, 13, core->visu->str);
		ft_strdel(&(core->visu->str));
		mvwprintw(core->visu->hud, 40 + (core->champ_nb * 4), 40
				+ ft_strlen((const char*)winner->name) + 1, "IS THE WINNER!!");
		mvwprintw(core->visu->hud, 26 + (core->champ_nb * 4), 20, "0       ");
		wattron(core->visu->hud, A_BOLD);
		wrefresh(core->visu->hud);
		timeout(-1);
		getch();
		endwin();
	}
	// ft_printf("le joueur %d(%s) à gagné\n", winner->pos, winner->name);
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
