/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:23:45 by maginist          #+#    #+#             */
/*   Updated: 2019/07/23 17:03:41 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void   init_visual(t_core *core)
{
	int	i;

	i = 0;
  initscr();
	mvprintw(5, 159, "COREWAR");
	WINDOW * win = newwin(66, 195, 7, 30);
	WINDOW * win2 = newwin(66, 100, 7, 226);
	refresh();
	box(win, 0, 0);
	box(win2, 0, 0);
	while (i < 12288)
	{
		mvwprintw(win, 1 + (i / 192), 2 + (i % 192), "00");
		mvwprintw(win, 1 + (i / 192), 4 + (i % 192) , " ");
		i += 3;
	}
	wrefresh(win);
	wrefresh(win2);
}