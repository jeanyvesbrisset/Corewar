/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:09:38 by maginist          #+#    #+#             */
/*   Updated: 2019/07/03 14:18:17 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int	ft_error(char *error)
{
	ft_putstr("\033[31m]");
	write(2, error, ft_strlen(error));
	ft_putstr("\033[00m]");
	return (0);
}

int	main(int ac, char **av)
{
	t_stock	*begin;
	t_cdata	*start;
	t_label	*lab;
	char	*name;
	int		i;

	begin = 0;
	start = 0;
	lab = 0;
	if (ac < 2)
	{
		ft_printf("Usage: %s <sourcefile.s>\n", av[0]);
		return (0);
	}
	i = ft_strlen(av[ac - 1]);
	if (i > 1 && !(av[ac - 1][i - 1] == 's' && av[ac - 1][i - 2] == '.'))
		return (ft_error("File has not the good format, must end with .s\n"));
	name = ft_strdup(av[ac - 1]);
	if (read_n_stock(av[ac - 1], &begin, &start, &lab))
		create_cor(&start, &name);
	free_structs(&begin, &start, &lab);
	free(name);
	return (0);
}
