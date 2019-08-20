/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:09:38 by maginist          #+#    #+#             */
/*   Updated: 2019/08/20 14:57:06 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int	ft_error(char *error, int ret, void **to_free, int line)
{
	char *nb;

	if (to_free && *to_free)
		free(*to_free);
	ft_putstr("\033[31m");
	write(2, error, ft_strlen(error));
	if (line > 0)
	{
		nb = ft_itoa(line);
		write(2, nb, ft_strlen(nb));
		write(2, "\n", 1);
		free(nb);
	}
	ft_putstr("\033[00m");
	return (ret);
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
		write(2, "Not enougth arguments.\nUsage: ", 30);
		write(2, av[0], ft_strlen(av[0]));
		return (ft_error(" <sourcefile.s>\n", 0, 0, 0));
	}
	i = ft_strlen(av[ac - 1]);
	if (i < 3  || (!(av[ac - 1][i - 1] == 's' && av[ac - 1][i - 2] == '.')))
		return (ft_error("Can't read source file\n", 0, 0, 0));
	name = ft_strdup(av[ac - 1]);
	if (read_n_stock(av[ac - 1], &begin, &start, &lab))
		create_cor(&start, &name);
	free_structs(&begin, &start, &lab);
	free(name);
	return (0);
}
