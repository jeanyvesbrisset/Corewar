/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/08/20 16:48:16 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	ft_delete_proc(t_core *core)
{
	t_proces *current;
	t_proces *before;

	current = core->proces;
	before = 0;
	while (current)
	{
		before = current;
		current = current->next;
		free(before);
		before = NULL;
	}
	free(before);
}

void	visual_winner(t_core *core, t_champ *winner)
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
	mvwprintw(core->visu->hud, 45 + (core->champ_nb * 4), 40
		, "Press any key to quit visual");
	wattron(core->visu->hud, A_BOLD);
	wrefresh(core->visu->hud);
	timeout(-1);
	getch();
	endwin();
}

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
		if (champ->last_live > winner->last_live
		|| (champ->last_live == winner->last_live
		&& champ->process_live < winner->process_live))
			winner = champ;
		champ = champ->next;
	}
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
		visual_winner(core, winner);
		free(core->visu);
	}
	ft_delete_proc(core);
	ft_printf("AND THE WINNER IS...\n");
	sleep(1);
	ft_printf("%s (player %d)! (%d)\n!!!!!CONGRATULATIONS!!!!\n"
	, winner->name, winner->pos, core->total_cycle);
}
