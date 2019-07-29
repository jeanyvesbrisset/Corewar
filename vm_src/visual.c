/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:23:45 by maginist          #+#    #+#             */
/*   Updated: 2019/07/29 17:20:02 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	cpy_cur_periode_to_last(t_core *core, int *i, int *j, t_champ *current)
{
	while ((*i) < core->champ_nb)
	{
		wattron(core->visu->hud, A_BOLD);
		mvwprintw(core->visu->hud, 20 + ((*i) * 4), 7
		, "live in current period :\t\t0       ");
		ft_strdel(&(core->visu->str));
		wattroff(core->visu->hud, A_BOLD);
		wattron(core->visu->hud, COLOR_PAIR((((*i) + 1) * 2) - 1));
		(*j) = core->visu->live_bd[(*i)];
		while ((*j) < (current->live_by_ctd * 100) / core->nbr_live)
			mvwprintw(core->visu->hud, 23 + ((*i) * 4), 6 + (*j)++, "-");
		if ((((current->live_by_ctd * 1000) / core->nbr_live) % 10) >= 5
		&& (*j) < 100)
			mvwprintw(core->visu->hud, 23 + ((*i) * 4), 6 + (*j)++, "-");
		if ((*i) == core->champ_nb - 1)
			while ((*j) < 100)
				mvwprintw(core->visu->hud, 23 + ((*i) * 4), 6 + (*j)++, "-");
		wattroff(core->visu->hud, COLOR_PAIR((((*i) + 1) * 2) - 1));
		(*i)++;
	}
}

void	visu_refresh_ctd(t_core *core)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	cpy_cur_periode_to_last(core, &i, &j, 0);
	mvwprintw(core->visu->hud, 20 + (i * 4), 5
	, "[--------------------------------------------------");
	mvwprintw(core->visu->hud, 20 + (i * 4), 56
	, "--------------------------------------------------]");
	wattron(core->visu->hud, A_BOLD);
	core->visu->str = ft_itoa(core->cycle_to_die);
	mvwprintw(core->visu->hud, 26 + (core->champ_nb * 4), 5, "CYCLE TO DIE :");
	mvwprintw(core->visu->hud, 26 + (core->champ_nb * 4), 20, core->visu->str);
	ft_strdel(&(core->visu->str));
	core->visu->str = ft_itoa(core->sum_process);
	mvwprintw(core->visu->hud, 15, 17, core->visu->str);
	ft_strdel(&(core->visu->str));
	wattroff(core->visu->hud, A_BOLD);
	wrefresh(core->visu->hud);
}

void	recolorize_live_bar(t_core *core, int *i, int *j, t_champ *current)
{
	while ((*j) < (current->live_by_ctd * 100) / core->nbr_live)
		mvwprintw(core->visu->hud, 20 + ((*i) * 4), 6 + (*j)++, "-");
	if ((((current->live_by_ctd * 1000) / core->nbr_live) % 10) >= 5
		&& (*j) < 100)
		mvwprintw(core->visu->hud, 20 + ((*i) * 4), 6 + (*j)++, "-");
	if ((*i) == core->champ_nb - 1)
		while ((*j) < 100)
			mvwprintw(core->visu->hud, 20 + ((*i) * 4), 6 + (*j)++, "-");
}

void	colorize_and_refresh_hud(t_core *core, int i, int j, t_champ *current)
{
	char	*str;

	while ((i) < core->champ_nb)
	{
		current = core->champs;
		while (current->pos != (i) + 1)
			current = current->next;
		core->visu->str = ft_itoa(current->last_live);
		mvwprintw(core->visu->hud, 19 + ((i) * 4), 27, core->visu->str);
		mvwprintw(core->visu->hud, 19 + ((i) * 4)
		, 28 + ft_strlen(core->visu->str), "by processus");
		str = ft_itoa(current->process_live);
		mvwprintw(core->visu->hud, 19 + ((i) * 4)
		, 42 + ft_strlen(core->visu->str), str);
		ft_strdel(&(core->visu->str));
		ft_strdel(&str);
		core->visu->str = ft_itoa(current->live_by_ctd);
		mvwprintw(core->visu->hud, 20 + ((i) * 4), 27, core->visu->str);
		ft_strdel(&(core->visu->str));
		wattron(core->visu->hud, COLOR_PAIR((((i) + 1) * 2) - 1));
		(j) = core->visu->live_bd[(i)];
		recolorize_live_bar(core, &i, &j, current);
		wattroff(core->visu->hud, COLOR_PAIR((((i) + 1) * 2) - 1));
		(i)++;
	}
	wrefresh(core->visu->hud);
}

void	refresh_vm_hud(t_core *core)
{
	wattron(core->visu->hud, A_BOLD);
	core->visu->str = ft_itoa(core->visu->cps);
	mvwprintw(core->visu->hud, 11, 26, core->visu->str);
	ft_strdel(&(core->visu->str));
	core->visu->str = ft_itoa(core->total_cycle);
	mvwprintw(core->visu->hud, 13, 13, core->visu->str);
	ft_strdel(&(core->visu->str));
	wattroff(core->visu->hud, A_BOLD);
}

char	*get_hexa(int nb)
{
	char	*str;
	char	*base;

	if (nb < 0 || nb > 255)
		return (0);
	if (!(str = (char*)malloc(sizeof(char) * 3)))
		return (0);
	base = "0123456789abcdef";
	str[0] = base[nb / 16];
	str[1] = base[nb % 16];
	str[2] = 0;
	base = 0;
	return (str);
}

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
		wattron(core->visu->hud, COLOR_PAIR(((*i) + 1) * 2) - 1);
		mvwprintw(core->visu->hud, 18 + ((*i) * 4), 18, (char*)current->name);
		wattroff(core->visu->hud, COLOR_PAIR(((*i) + 1) * 2) - 1);
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
	mvwprintw(core->visu->hud, 5, 45, "**  BETA_TEST  **");
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

void	init_champ_in_visu(t_core *core, int k)
{
	t_champ	*current;
	int		i;

	while (k < 4096 * 3)
	{
		core->visu->str = get_hexa(core->arena[k / 3]);
		mvwprintw(core->visu->arena, 1 + (k / 192), 2 + (k % 192)
		, core->visu->str);
		mvwprintw(core->visu->arena, 1 + (k / 192), 4 + (k % 192), " ");
		ft_strdel(&(core->visu->str));
		k += 3;
	}
	current = core->champs;
	while (current)
	{
		i = current->byte_start * 3;
		k = -1;
		while (++k < current->size)
		{
			mvwchgat(core->visu->arena, 1 + (i / 192), 2 + (i % 192)
				, 2, 0, (current->pos * 2) - 1, 0);
			i += 3;
		}
		current = current->next;
	}
}

void	init_color_vm(void)
{
	start_color();
	init_color(COLOR_WHITE, 300, 300, 300);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_CYAN);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_RED);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_YELLOW);
	init_pair(7, COLOR_BLUE, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_BLUE);
	init_pair(9, COLOR_WHITE, COLOR_BLACK);
}

void	init_visual(t_core *core)
{
	int	i;

	i = 0;
	if (!(core->visu = (t_visu*)malloc(sizeof(t_visu) * 1)))
		return ;
	initscr();
	noecho();
	curs_set(0);
	init_color_vm();
	core->visu->arena = newwin(66, 195, 0, 0);
	core->visu->hud = newwin(66, 111, 0, 195);
	refresh();
	box(core->visu->arena, 0, 0);
	box(core->visu->hud, 0, 0);
	wattron(core->visu->arena, COLOR_PAIR(9));
	init_champ_in_visu(core, i);
	wattroff(core->visu->arena, COLOR_PAIR(9));
	wrefresh(core->visu->arena);
	init_visual_hud(core);
	getch();
	endwin();
	init_color(COLOR_WHITE, 1000, 1000, 1000);
}

void	refresh_vm_arena(t_core *core)
{
	t_proces	*pr;

	pr = core->proces;
	while (pr)
	{
		core->visu->str = get_hexa((int)((core->arena)[pr->pc]));
		if (pr->alive)
			mvwchgat(core->visu->arena, 1 + ((pr->pc * 3) / 192)
			, 2 + ((pr->pc * 3) % 192), 2, A_NORMAL, (pr->champ * 2), 0);
		ft_strdel(&(core->visu->str));
		pr = pr->next;
	}
	wrefresh(core->visu->arena);
	pr = core->proces;
	while (pr)
	{
		core->visu->str = get_hexa((int)((core->arena)[pr->pc]));
		mvwchgat(core->visu->arena, 1 + ((pr->pc * 3) / 192)
			, 2 + ((pr->pc * 3) % 192), 2, A_NORMAL, (pr->champ * 2) - 1, 0);
		ft_strdel(&(core->visu->str));
		pr = pr->next;
	}
	refresh_vm_hud(core);
	getch();
	usleep(100000);
}
