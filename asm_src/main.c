/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:09:38 by maginist          #+#    #+#             */
/*   Updated: 2019/06/27 15:19:22 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int	ft_error(char *error)
{
	ft_printf("%s\n", error);
	return (0);
}

int	main(int ac, char **av)
{
	t_stock	*begin;
	t_cdata	*start;
	t_label	*lab;
	char	*name;

	begin = 0;
	start = 0;
	lab = 0;
	if (ac < 2)
	{
		ft_printf("Usage: %s <sourcefile.s>\n", av[0]);
		return (0);
	}
	name = ft_strdup(av[ac - 1]);
	if (read_n_stock(av[ac - 1], &begin, &start, &lab))
		create_cor(&start, name);
	//free_structs(&begin, &start, &lab);
	free(name);
	return (0);
}
