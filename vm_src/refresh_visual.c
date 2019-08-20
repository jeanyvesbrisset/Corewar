/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_visual.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:50:14 by maginist          #+#    #+#             */
/*   Updated: 2019/08/20 16:47:55 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

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

void	visu_sti_st(t_core *core, t_proces *pr, int pos, int size)
{
	int	i;
	int	mem_s;

	i = 0;
	while (i < size)
	{
		mem_s = (pos + i) % MEM_SIZE;
		core->visu->color_arena[mem_s] = (unsigned char)(pr->champ);
		core->visu->str = get_hexa(core->arena[mem_s]);
		mvwprintw(core->visu->arena, 1 + ((3 * (mem_s)) / 192)
		, 2 + ((3 * (mem_s)) % 192), core->visu->str);
		mvwchgat(core->visu->arena, 1 + ((3 * (mem_s)) / 192)
		, 2 + ((3 * (mem_s)) % 192), 2, A_BOLD, pr->champ, 0);
		ft_strdel(&(core->visu->str));
		i++;
	}
	wrefresh(core->visu->arena);
}

void	refresh_cycle_to_die(t_core *core)
{
	wattron(core->visu->hud, A_BOLD);
	core->visu->str = ft_itoa(core->cycle_to_die);
	mvwprintw(core->visu->hud, 26 + (core->champ_nb * 4), 20, core->visu->str);
	mvwprintw(core->visu->hud, 26 + (core->champ_nb * 4)
			, 20 + ft_strlen(core->visu->str), "    ");
	wattroff(core->visu->hud, A_BOLD);
	ft_strdel(&(core->visu->str));
}

void	refresh_pc(t_core *core)
{
	t_proces	*pr;

	pr = core->proces;
	while (pr)
	{
		mvwchgat(core->visu->arena, 1 + ((pr->pc * 3) / 192)
		, 2 + ((pr->pc * 3) % 192), 2, A_REVERSE
		, core->visu->color_arena[pr->pc], 0);
		pr = pr->next;
	}
	wrefresh(core->visu->arena);
	pr = core->proces;
	while (pr)
	{
		if (core->visu->color_arena[pr->pc] != 9)
			mvwchgat(core->visu->arena, 1 + ((pr->pc * 3) / 192)
			, 2 + ((pr->pc * 3) % 192), 2, A_NORMAL
			, core->visu->color_arena[pr->pc], 0);
		else
			mvwchgat(core->visu->arena, 1 + ((pr->pc * 3) / 192)
			, 2 + ((pr->pc * 3) % 192), 2, A_BOLD
			, core->visu->color_arena[pr->pc], 0);
		pr = pr->next;
	}
}

void	visual_every_cycle(t_core *core)
{
	int	i;

	wattron(core->visu->hud, A_BOLD);
	core->visu->str = ft_itoa(core->total_cycle);
	mvwprintw(core->visu->hud, 13, 13, core->visu->str);
	ft_strdel(&(core->visu->str));
	wattroff(core->visu->hud, A_BOLD);
	wrefresh(core->visu->hud);
	if ((core->total_cycle % 100) == 0)
	{
		i = 0;
		while (i < MEM_SIZE)
		{
			if (core->visu->color_arena[i] != 9)
				mvwchgat(core->visu->arena, 1 + ((3 * i) / 192)
				, 2 + ((3 * i) % 192), 2, A_NORMAL, core->visu->color_arena[i]
				, 0);
			i++;
		}
	}
	get_key(core);
}
