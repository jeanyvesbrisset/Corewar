/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:06:37 by maginist          #+#    #+#             */
/*   Updated: 2019/08/10 11:41:02 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	modif_cps(t_core *core, int to_add)
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

void	handle_pause(t_core *core, int *pause, int p_or_r)
{
	wattron(core->visu->hud, A_BOLD);
	if (p_or_r == 1)
	{
		mvwprintw(core->visu->hud, 5, 45, "**   PAUSE   **");
		(*pause) *= -1;
	}
	else
		mvwprintw(core->visu->hud, 5, 45, "**  RUNNING  **");
	wrefresh(core->visu->hud);
	wattroff(core->visu->hud, A_BOLD);
}

void	get_key(t_core *core)
{
	int			i;
	static int	pause = 1;

	while (1)
	{
		timeout(0);
		if ((i = getch()) == ' ')
			handle_pause(core, &pause, 1);
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
			handle_pause(core, &pause, 0);
			break ;
		}
	}
	timeout(500);
	usleep(1000000 / core->visu->cps);
}
