/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:23:45 by maginist          #+#    #+#             */
/*   Updated: 2019/07/24 17:53:41 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

char 	*get_hexa(int nb)
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

void	init_visual_hud(t_core *core)
{
	(void)core;
	return ;
}

void	init_champ_in_visu(t_core *core, int k)
{
	t_champ *current;
	int		i;

	while (k < 4096 * 3)
	{
		core->visu->str = get_hexa(core->arena[k /3]);
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
			mvwchgat(core->visu->arena, 1 + (i / 192), 2 + (i % 192), 
			2, 0, (current->pos * 2) - 1, 0);
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

void   init_visual(t_core *core)
{
	int	i;

	i = 0;
	//core->visu->ch = getch();
	if (!(core->visu = (t_visu*)malloc(sizeof(t_visu) * 1)))
		return ;
	initscr();
	noecho();
	curs_set(0);
	init_color_vm();
	mvprintw(5, 159, "COREWAR");
	core->visu->arena = newwin(66, 195, 7, 30);
	core->visu->hud = newwin(66, 100, 7, 226);
	refresh();
	mvprintw(5, 159, "COREWAR");
	box(core->visu->arena, 0, 0);
	box(core->visu->hud, 0, 0);
	wattron(core->visu->arena, COLOR_PAIR(9));
	init_champ_in_visu(core, i);
	wattroff(core->visu->arena, COLOR_PAIR(9));
	wrefresh(core->visu->arena);
	wrefresh(core->visu->hud);
	init_visual_hud(core);
	getch();
	endwin();
	init_color(COLOR_WHITE, 1000, 1000, 1000);
}

/*void	refresh_vm_arena(t_core *core)
{
	t_proces	*pr;

	pr = core->proces;
	while (pr)
	{
		core->visu->str = get_hexa((int)((core->arena)[pr->pc]));
		mvwchgat(core->visu->arena, 1 + ((pr->pc * 3) / 192), 2 + ((pr->pc * 3) % 192), 2, A_NORMAL, (pr->champ * 2), 0);
		ft_strdel(&(core->visu->str));
		pr = pr->next;
	}
	wrefresh(core->visu->arena);
	pr = core->proces;
	while (pr)
	{
		core->visu->str = get_hexa((int)((core->arena)[pr->pc]));
		mvwchgat(core->visu->arena, 1 + ((pr->pc * 3) / 192), 2 + ((pr->pc * 3) % 192), 2, A_NORMAL, (pr->champ * 2) - 1, 0);
		ft_strdel(&(core->visu->str));
		pr = pr->next;
	}
	refresh_vm_hud(core);
	getch();
	//modifier le sleep en fonction des touches tapees
	usleep(100000);
}*/