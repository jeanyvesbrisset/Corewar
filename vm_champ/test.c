/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:22:05 by maginist          #+#    #+#             */
/*   Updated: 2019/07/23 14:43:05 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <unistd.h>

int main(void)
{
	WINDOW *infos;
	WINDOW *centre;
	int i = 100;
	int ch = getch();

	initscr();
	noecho();
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_WHITE);
	init_pair(4, COLOR_GREEN, COLOR_WHITE);
	curs_set(FALSE);
	centre = subwin(stdscr, 65, 64 * 3 + 3, 0, 0);
	infos = subwin(stdscr, 65, 50, 0, 64 * 3 + 3);
	box(centre, ACS_VLINE , ACS_HLINE);
	box(infos, ACS_VLINE , ACS_HLINE);
	wrefresh(infos);
	for (int y = 1; y < 64; y++)
	{
		wmove(centre, y, 2);
		for (int x = 2; x < 64 * 3; x += 3)
		{

			y > 32 ? wattron(centre, COLOR_PAIR(2)) : wattron(centre, COLOR_PAIR(1));
			wprintw(centre, "00 ");
		}
	}
	wrefresh(centre);
	for (int y = 1; y < 32; y++)
	{
		wmove(centre, y, 0);
		for (int x = 2; x < 64 * 3; x += 3)
		{
			mvwchgat(centre, y, x, 2, A_STANDOUT, 3, NULL);
			mvwchgat(centre, y + 32, x, 2, A_STANDOUT, 4, NULL);
			usleep(100000);
			wrefresh(centre);
			mvwchgat(centre, y, x, 2, A_NORMAL, 1, NULL);
			mvwchgat(centre, y + 32, x, 2, A_NORMAL, 2, NULL);
		}
		if (y == 31)
			y = 1;
	}
	getch();
	endwin();
	return 0;
}
