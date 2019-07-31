/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_visual.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:50:14 by maginist          #+#    #+#             */
/*   Updated: 2019/07/31 12:52:32 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	write_visu(t_core *core, WINDOW *win, int attr, int color)
{
	if (color)
		attron(COLOR_PAIR(color));
	if (attr & (1 == 1))
		attron(A_BOLD);
	if (attr & (2 == 2))
		attron(A_STANDOUT);
	if (attr & (4 == 4))
		attron(A_BLINK);
	if (attr & (8 == 8))
		attron(A_REVERSE);
	if (attr & (16 == 16))
		attron(A_NORMAL);
	wprintw(win, core->visu->str);
	ft_strdel(&(core->visu->str));
	attrset(0);
	attrset(A_BOLD);
	wattrset(win, 0);
	wattrset(win, A_BOLD);
}
void	visu_sti_st(t_core *core, t_proces *pr, int pos, int size)
{
	int	i;

	i = 0;
	while (i < size * 3)
	{
		core->visu->str = get_hexa((int)(core->arena[pos + i]));
		wmove(core->visu->arena, 1 + ((pos + i) / 192), 2 + ((pos + i) % 192));
		write_visu(core, core->visu->arena, 2, (pr->champ * 2) - 1);
		i += 3;
	}
	wrefresh(core->visu->arena);
	usleep(100000);
	i = 0;
	while (i < size * 3)
	{
		mvwchgat(core->visu->arena, 1 + ((pos + i) / 192), 2 + ((pos + i) / 192)
				, 2, 0, (pr->champ * 2) - 1, 0);
		i += 3;
	}
}

void	refresh_process(t_core *core)
{
	core->visu->str = ft_itoa(core->sum_process);
	mvwprintw(core->visu->hud, 15, 18, core->visu->str);
	wrefresh(core->visu->hud);
	ft_strdel(&(core->visu->str));
}

void	refresh_live(t_core *core)
{
	int i;
	int j;
	t_champ *current;

	i  = 0;
	j = 0;
	core->visu->live_bd[0] = 0;
	while (i < core->champ_nb)
	{
		current = core->champs;
		while (current->pos != i + 1)
			current = current->next;
		mvwprintw(core->visu->hud, 19 + (i * 4), 25, "/t/tby process ");
		core->visu->str = ft_itoa(current->last_live);
		mvwprintw(core->visu->hud, 19 + (i * 4), 25, core->visu->str);
		ft_strdel(&(core->visu->str));
		core->visu->str = ft_itoa(current->process_live);
		mvwprintw(core->visu->hud, 19 + (i * 4), 47, core->visu->str);
		ft_strdel(&(core->visu->str));
		core->visu->str = ft_itoa(current->live_by_ctd);
		mvwprintw(core->visu->hud, 20 + (i * 4), 41 , core->visu->str);
		ft_strdel(&(core->visu->str));
		wattron(core->visu->hud, COLOR_PAIR(((i + 1) * 2) - 1));
		while (j - core->visu->live_bd[i] < (current->live_by_ctd * 100) 
				/ core->nbr_live)
			mvwprintw(core->visu->hud, 20 + (i * 4), 6 + j++, "-");
		if ((((current->live_by_ctd * 1000) / core->nbr_live) % 10) >= 5
			&& j < 100)
			mvwprintw(core->visu->hud, 20 + (i * 4), 6 + j++, "-");
		if (i == core->champ_nb - 1)
			while (j < 100)
				mvwprintw(core->visu->hud, 20 + (i * 4), 6 + j++, "-");
		wattroff(core->visu->hud, COLOR_PAIR(((i + 1) * 2) - 1));
		i++;
		core->visu->live_bd[i] = j;
	}
}

void	refresh_cycle_to_die(t_core *core)
{
	core->visu->str = ft_itoa(core->cycle_to_die);
	mvwprintw(core->visu->hud, 26 + (core->champ_nb * 4), 20, core->visu->str);
	mvwprintw(core->visu->hud, 26 + (core->champ_nb * 4)
			, 20 + ft_strlen(core->visu->str), "    ");
	ft_strdel(&(core->visu->str));
}

void	refresh_live_ctd(t_core *core)
{
	t_champ *current;
	int i;
	int j;

	i = 0;
	current = core->champs;
	j = 0;
	core->visu->live_bd[0] = 0;
	while (i < core->champ_nb)
	{
		current = core->champs;
		while (current->pos != i + 1)
			current = current->next;
		wattron(core->visu->hud, A_BOLD);
		mvwprintw(core->visu->hud, 20 + (i * 4), 7
		, "live in current period :\t\t0       ");
		wattroff(core->visu->hud, A_BOLD);
		wattron(core->visu->hud, COLOR_PAIR(((i + 1) * 2) - 1));
		while (j - core->visu->live_bd[i] < (current->live_by_ctd * 100) 
				/ core->nbr_live)
			mvwprintw(core->visu->hud, 23 + (i * 4), 6 + j++, "-");
		if ((((current->live_by_ctd * 1000) / core->nbr_live) % 10) >= 5
			&& j < 100)
			mvwprintw(core->visu->hud, 23 + (i * 4), 6 + j++, "-");
		if (i == core->champ_nb - 1)
			while (j < 100)
				mvwprintw(core->visu->hud, 23 + (i * 4), 6 + j++, "-");
		wattroff(core->visu->hud, COLOR_PAIR(((i + 1) * 2) - 1));
		i++;
		core->visu->live_bd[i] = j;
	}
	mvwprintw(core->visu->hud, 20 + (i * 4), 5
	, "[--------------------------------------------------");
	mvwprintw(core->visu->hud, 20 + (i * 4), 56
	, "--------------------------------------------------]");
	refresh_process(core);
}

void	visual_every_cycle(t_core *core)
{
	t_proces	*pr;
	
	pr = core->proces;
	while (pr)
	{
		mvwchgat(core->visu->arena, 1 + ((pr->pc * 3) / 192)
		, 2 + ((pr->pc * 3) / 192), 2, A_REVERSE, 0, 0);
		pr = pr->next;
	}
	wrefresh(core->visu->arena);
	pr = core->proces;
	while (pr)
	{
		mvwchgat(core->visu->arena, 1 + ((pr->pc * 3) / 192)
		, 2 + ((pr->pc * 3) / 192), 2, A_REVERSE, 0, 0);
		pr = pr->next;
	}
	core->visu->str = ft_itoa(core->visu->cps);
	mvwprintw(core->visu->hud, 11, 26, core->visu->str);
	mvwprintw(core->visu->hud, 11, 26 + ft_strlen(core->visu->str), "    ");
	ft_strdel(&(core->visu->str));
	core->visu->str = ft_itoa(core->total_cycle);
	mvwprintw(core->visu->hud, 13, 13, core->visu->str);
	ft_strdel(&(core->visu->str));
	wrefresh(core->visu->hud);
}
