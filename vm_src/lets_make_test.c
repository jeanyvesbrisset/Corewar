/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_make_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:40:13 by floblanc          #+#    #+#             */
/*   Updated: 2019/07/23 13:33:56 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <ncurses.h>

int		main(int ac, char **av)
{
	int				fd;
	int				fd2;
	int				ret;
	unsigned char	*str;
	int				size = (64 * 1024);

	if (ac != 4)
		return (printf("Wrong number of arguments\n proto : ./exec <file> <value> <pos>\n"));
	printf("av[1] = %s\n", av[1]);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (printf("Open failed\n"));
	if (!(str = malloc(sizeof(unsigned char) * size)))
		return (printf("Malloc failed\n"));
	if ((ret = read(fd, str, size)) <= 0)
		return (printf("read failed\n"));
	str[atoi(av[3])] = (unsigned char)atoi(av[2]);
	if ((fd2 = open("test", O_WRONLY | O_CREAT | O_TRUNC)) == -1)
		return (printf(" failed\n"));
	write(fd2, str, ret);
	close(fd);
	close(fd2);
	initscr();
	printw("This is a test :)\n");
	refresh();
	getch();
	endwin();
	return (0);
}