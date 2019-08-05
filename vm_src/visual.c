/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:51:33 by maginist          #+#    #+#             */
/*   Updated: 2019/08/05 13:30:43 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h" 

/* CTD = cycle to die
** to refresh : 
**		ARENA	- ecriture des process				--> chaque : sti et st
**		ARENA	- Pc pour chaque champ				--> chaque : cycle -|
**		HUD		- Cycles/second limit				--> chaque : cycle -|--->1f✅
**		HUD		- Cycle								--> chaque : cycle -|
**		HUD		- Processes							--> chaque : fork	/	CTD
**		HUD		- Last live	n by process n			--> chaque : live
**		HUD		- Live in current period			--> chaque : live	/	CTD
**		HUD		- Live breakdown for current period	--> chaque : live	/	CTD
**		HUD		- Live breakdown for last period	--> chaque : CTD
**		HUD		- CYCLE_TO_DIE						--> chaque : CTD
**	recap :1 ft processes ✅ / 1 ft CTD qui appel la ft processes ✅ / 1 ft LIVE ✅
** / 1 ft cycle ✅/ 1 ft sti_st ✅
*/

void 	modif_cps(t_core *core, int to_add)
{
		core->visu->cps += to_add;
		if (core->visu->cps > 1000)
			core->visu->cps = 1000;
		else if (core->visu->cps < 1)
			core->visu->cps = 1;
		wattron(core->visu->hud, A_BOLD);
		core->visu->str = ft_itoa(core->visu->cps);
		mvwprintw(core->visu->hud, 11, 26, core->visu->str);
		mvwprintw(core->visu->hud, 11, 26 + ft_strlen(core->visu->str), "    ");
		ft_strdel(&(core->visu->str));
		wrefresh(core->visu->hud);
}

void	get_key(t_core *core)
{
	int	i;
	static int pause = 1;
	
	while (1)
	{
		timeout(0);
		if ((i = getch()) == ' ')
		{
			wattron(core->visu->hud, A_BOLD);
			mvwprintw(core->visu->hud, 5, 45, "**   PAUSE   **");
			wrefresh(core->visu->hud);
			pause *= -1;
			wattroff(core->visu->hud, A_BOLD);
		}
		else if (i == 'r' && core->visu->cps < 1000)
			modif_cps(core, 10);
		else if (i == 'e' && core->visu->cps < 1000)
			modif_cps(core, 1);
		else if (i == 'w' && core->visu->cps > 1)
			modif_cps(core, -1);
		else if (i == 'q' && core->visu->cps > 1)
			modif_cps(core, -10);
		if (pause == -1)
		{
			wattron(core->visu->hud, A_BOLD);
			mvwprintw(core->visu->hud, 5, 45, "**  RUNNING  **");
			wrefresh(core->visu->hud);	
			wattroff(core->visu->hud, A_BOLD);
			break;
		}
	}
	timeout(500);
	usleep(1000000 / core->visu->cps);
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

void	init_champ_in_visu(t_core *core, int k)
{
	t_champ	*current;
	int		i;

	while (k < 4096 * 3)
	{
		core->visu->color_arena[k / 3] = 9;
		core->visu->str = get_hexa(core->arena[k / 3]);
		mvwprintw(core->visu->arena, 1 + (k / 192), 2 + (k % 192)
		, core->visu->str);
		mvwchgat(core->visu->arena, 1 + (k / 192), 2 + (k % 192), 2
		, A_BOLD, 9, 0);
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
			core->visu->color_arena[i / 3] = current->pos;
			mvwchgat(core->visu->arena, 1 + (i / 192), 2 + (i % 192)
				, 2, 0, current->pos, 0);
			i += 3;
		}
		current = current->next;
	}
}

void	init_color_vm(void)
{
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_CYAN);
	init_pair(6, COLOR_WHITE, COLOR_RED);
	init_pair(7, COLOR_WHITE, COLOR_YELLOW);
	init_pair(8, COLOR_WHITE, COLOR_BLUE);
	init_pair(9, COLOR_BLACK, COLOR_BLACK);
}

void	init_visual(t_core *core)
{
	int	i;

	i = 0;
	if (!(core->visu = (t_visu*)malloc(sizeof(t_visu) * 1)))
		return ;
	initscr();
	noecho();
	timeout(500);
	curs_set(0);
	init_color_vm();
	core->visu->arena = newwin(66, 195, 0, 0);
	core->visu->hud = newwin(66, 111, 0, 195);
	refresh();
	box(core->visu->arena, 0, 0);
	box(core->visu->hud, 0, 0);
	core->visu->cps = 50;
	init_champ_in_visu(core, i);
	wrefresh(core->visu->arena);
	init_visual_hud(core);
	get_key(core);// a mettre en commentaire si tu veux que le visu soit rapide
}