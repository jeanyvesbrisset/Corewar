/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:51:33 by maginist          #+#    #+#             */
/*   Updated: 2019/08/06 16:22:13 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	write_infos_hud(t_core *core, int i)
{
	core->visu->str = ft_itoa(CYCLE_TO_DIE);
	mvwprintw(core->visu->hud, 26 + (i * 4), 5, "CYCLE TO DIE :");
	mvwprintw(core->visu->hud, 26 + (i * 4), 20, core->visu->str);
	ft_strdel(&(core->visu->str));
	core->visu->str = ft_itoa(CYCLE_DELTA);
	mvwprintw(core->visu->hud, 28 + (i * 4), 5, "CYCLE_DELTA :");
	mvwprintw(core->visu->hud, 28 + (i * 4), 20, core->visu->str);
	ft_strdel(&(core->visu->str));
	core->visu->str = ft_itoa(NBR_LIVE);
	mvwprintw(core->visu->hud, 30 + (i * 4), 5, "NBR_LIVE :");
	mvwprintw(core->visu->hud, 30 + (i * 4), 20, core->visu->str);
	ft_strdel(&(core->visu->str));
	core->visu->str = ft_itoa(MAX_CHECKS);
	mvwprintw(core->visu->hud, 32 + (i * 4), 5, "NBR_CHECKS :");
	mvwprintw(core->visu->hud, 32 + (i * 4), 20, core->visu->str);
	ft_strdel(&(core->visu->str));
	wrefresh(core->visu->hud);
}

void	create_player_hud(t_core *core, int *i)
{
	t_champ *current;

	while ((*i) < core->champ_nb)
	{
		core->visu->str = ft_itoa((*i) + 1);
		current = core->champs;
		while (current->pos != (*i) + 1)
			current = current->next;
		mvwprintw(core->visu->hud, 18 + ((*i) * 4), 5, "Player   :");
		mvwprintw(core->visu->hud, 18 + ((*i) * 4), 12, core->visu->str);
		wattron(core->visu->hud, COLOR_PAIR((*i) + 1));
		mvwprintw(core->visu->hud, 18 + ((*i) * 4), 18, (char*)current->name);
		wattroff(core->visu->hud, COLOR_PAIR(((*i) + 1)));
		mvwprintw(core->visu->hud, 19 + ((*i) * 4), 7, "Last live :\t\t\t0");
		mvwprintw(core->visu->hud, 20 + ((*i) * 4), 7
		, "live in current period :\t\t0");
		ft_strdel(&(core->visu->str));
		(*i)++;
	}
	mvwprintw(core->visu->hud, 19 + ((*i) * 4), 35
			, "Live breakdown for current period :");
	mvwprintw(core->visu->hud, 22 + ((*i) * 4), 37
			, "Live breakdown for last period :");
	wattroff(core->visu->hud, A_BOLD);
}

void	init_visual_hud(t_core *core)
{
	int		i;

	i = 0;
	wattron(core->visu->hud, A_BOLD);
	mvwprintw(core->visu->hud, 5, 45, "**   PAUSE   **");
	mvwprintw(core->visu->hud, 11, 5, "Cycle/second limit : 50");
	mvwprintw(core->visu->hud, 13, 5, "Cycle : 0");
	mvwprintw(core->visu->hud, 15, 5, "Processes :");
	core->visu->str = ft_itoa(core->champ_nb);
	mvwprintw(core->visu->hud, 15, 17, core->visu->str);
	ft_strdel(&(core->visu->str));
	create_player_hud(core, &i);
	mvwprintw(core->visu->hud, 20 + (i * 4), 5
	, "[--------------------------------------------------");
	mvwprintw(core->visu->hud, 20 + (i * 4), 56
	, "--------------------------------------------------]");
	mvwprintw(core->visu->hud, 23 + (i * 4), 5
	, "[--------------------------------------------------");
	mvwprintw(core->visu->hud, 23 + (i * 4), 56
	, "--------------------------------------------------]");
	wattron(core->visu->hud, A_BOLD);
	write_infos_hud(core, i);
}
