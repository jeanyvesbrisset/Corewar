/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_visual_live.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:03:14 by maginist          #+#    #+#             */
/*   Updated: 2019/08/16 13:50:09 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	refresh_process(t_core *core)
{
	wattron(core->visu->hud, A_BOLD);
	mvwprintw(core->visu->hud, 15, 17, "      ");
	core->visu->str = ft_itoa(core->sum_process);
	mvwprintw(core->visu->hud, 15, 17, core->visu->str);
	wattroff(core->visu->hud, A_BOLD);
	wrefresh(core->visu->hud);
	ft_strdel(&(core->visu->str));
}

void	refresh_live_by_champ(t_core *core, int i, t_champ **current)
{
	while ((*current)->pos != i + 1)
		(*current) = (*current)->next;
	wattron(core->visu->hud, A_BOLD);
	mvwprintw(core->visu->hud, 19 + (i * 4), 47, "by process ");
	core->visu->str = ft_itoa((*current)->last_live);
	mvwprintw(core->visu->hud, 19 + (i * 4), 40, core->visu->str);
	ft_strdel(&(core->visu->str));
	core->visu->str = ft_itoa((*current)->process_live);
	mvwprintw(core->visu->hud, 19 + (i * 4), 59, core->visu->str);
	mvwprintw(core->visu->hud, 19 + (i * 4), 59 + ft_strlen(core->visu->str)
	, "      ");
	ft_strdel(&(core->visu->str));
	core->visu->str = ft_itoa((*current)->live_by_ctd);
	mvwprintw(core->visu->hud, 20 + (i * 4), 40, core->visu->str);
	ft_strdel(&(core->visu->str));
	wattroff(core->visu->hud, A_BOLD);
	wattron(core->visu->hud, COLOR_PAIR(i + 1));
}

void	refresh_live(t_core *core)
{
	int		i;
	int		j;
	t_champ	*current;

	i = 0;
	j = 0;
	core->visu->live_bd[0] = 0;
	while (i < core->champ_nb)
	{
		current = core->champs;
		refresh_live_by_champ(core, i, &current);
		while (j - core->visu->live_bd[i] < (current->live_by_ctd * 100)
			/ (core->live_champ + 1) && j < 100)
			mvwprintw(core->visu->hud, 20 + (core->champ_nb * 4), 6 + j++, "-");
		if ((((current->live_by_ctd * 1000) / (core->live_champ + 1)) % 10) >= 5
			&& j < 100)
			mvwprintw(core->visu->hud, 20 + (core->champ_nb * 4), 6 + j++, "-");
		if (i == core->champ_nb - 1)
			while (j < 100)
				mvwprintw(core->visu->hud, 20 + (core->champ_nb * 4), 6 + j++
				, "-");
		wattroff(core->visu->hud, COLOR_PAIR(i + 1));
		i++;
		core->visu->live_bd[i] = j;
	}
}

void	refresh_champion_ctd(t_core *core, int *j, int i, t_champ **current)
{
	wattron(core->visu->hud, A_BOLD);
	mvwprintw(core->visu->hud, 20 + (i * 4), 7
	, "live in current period :\t\t0       ");
	wattroff(core->visu->hud, A_BOLD);
	wattron(core->visu->hud, COLOR_PAIR(i + 1));
	while ((*j) - core->visu->live_bd[i] < ((*current)->live_by_ctd * 100)
	/ (core->live_champ + 1) && (*j) < 100)
		mvwprintw(core->visu->hud, 23 + (core->champ_nb * 4), 6 + (*j)++, "-");
	if (((((*current)->live_by_ctd * 1000) / (core->live_champ + 1)) % 10) >= 5
	&& (*j) < 100)
		mvwprintw(core->visu->hud, 23 + (core->champ_nb * 4), 6 + (*j)++, "-");
	if (i == core->champ_nb - 1)
		while ((*j) < 100)
			mvwprintw(core->visu->hud, 23 + (core->champ_nb * 4), 6 + (*j)++
			, "-");
	wattroff(core->visu->hud, COLOR_PAIR(i + 1));
}

void	refresh_live_ctd(t_core *core)
{
	t_champ	*current;
	int		i;
	int		j;

	i = 0;
	current = core->champs;
	j = 0;
	core->visu->live_bd[0] = 0;
	while (i < core->champ_nb)
	{
		current = core->champs;
		while (current->pos != i + 1)
			current = current->next;
		refresh_champion_ctd(core, &j, i, &current);
		i++;
		core->visu->live_bd[i] = j;
	}
	mvwprintw(core->visu->hud, 20 + (i * 4), 5
	, "[--------------------------------------------------");
	mvwprintw(core->visu->hud, 20 + (i * 4), 56
	, "--------------------------------------------------]");
	refresh_process(core);
}
