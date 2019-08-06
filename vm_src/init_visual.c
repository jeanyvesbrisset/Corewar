/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:08:17 by maginist          #+#    #+#             */
/*   Updated: 2019/08/06 16:16:50 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	print_arena(t_core *core, int k)
{
	core->visu->color_arena[k / 3] = 9;
	core->visu->str = get_hexa(core->arena[k / 3]);
	mvwprintw(core->visu->arena, 1 + (k / 192), 2 + (k % 192)
	, core->visu->str);
	mvwchgat(core->visu->arena, 1 + (k / 192), 2 + (k % 192), 2
	, A_BOLD, 9, 0);
	mvwprintw(core->visu->arena, 1 + (k / 192), 4 + (k % 192), " ");
	ft_strdel(&(core->visu->str));
}

void	init_champ_in_visu(t_core *core, int k)
{
	t_champ	*current;
	int		i;

	while (k < 4096 * 3)
	{
		print_arena(core, k);
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
	get_key(core);
}
