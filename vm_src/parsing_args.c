/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:02:22 by maginist          #+#    #+#             */
/*   Updated: 2019/07/17 12:15:29 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int	is_dot_cor(char *av)
{
	int i;
	int	len;

	len = ft_strlen(av);
	i = len - 1;
	while (i > 0 && av[i - 1] != '/')
		i--;
	if (ft_isdigit(av[i]))
		return (0);
	while (ft_isalnum(av[i]) || av[i] == '-' || av[i] == '_')
		i++;
	if (ft_strcmp(av + i, ".cor") != 0)
		return (0);
	ft_printf("av[%d] = %c\n", i, av[i]);
	return (1);
}

int	is_order_n(char **av, int i, t_core *core)
{
	int champ_n;
	int	j;

	j = 0;
	if (ft_strcmp(av[i], "-n"))
		return (0);
	while (av[i + 1][j])
		if (!(ft_isdigit(av[i + 1][j++])))
			return (0);
	champ_n = ft_atoi(av[i + 1]);
	if (!(champ_n <= 4 && champ_n > 0))
		return (0);
	if (is_dot_cor(av[i + 2]))
		(core->champ_nb)++;
	else
		return (0);
	return (1);
}

int	write_help(char *str)
{
	ft_printf("Usage: %s -v -d/-dump N [[-n N] <champion1.cor>] ", str);
	ft_printf("<...>\n\t-v\t: visualisation\n");
	ft_printf("\t-d/-dump N\t: Dumps memory after N(int >= 0) cycles then");
	ft_printf("exit the program\n");
	ft_printf("\t-n N\t: Give to champion(s) N(int > 0) player number\n");
	return (0);
}

int	is_d_dump(char **av, int i)
{
	int	j;
	int	d_or_dump;

	d_or_dump = 0;
	j = 0;
	ft_printf("av[%d] = %s\n", i, av[i]);
	if (ft_strcmp(av[i], "-d") == 0)
		d_or_dump = 1;
	if (d_or_dump == 0 && ft_strcmp(av[i], "-dump"))
		return (0);
	ft_printf("av[%d][%d] = %c\n", i, j, av[i][j]);
	while (av[i + 1][j])
		if (!(ft_isdigit(av[i + 1][j++])))
			return (0);
	return (1);
}

int	parcing_args(int ac, char **av, t_core *core)
{	
	int i;

	i = 1;
	ft_printf("ac = %d et i = %d\n", ac, i);
	while (i < ac)
	{
		ft_printf("Sur l'argument numero %d : %s\n", i, av[i]);
		if (!(ft_strcmp(av[i], "-h")) || !(ft_strcmp(av[i], "-help")))
			return (write_help(av[0]));
		else if (core->flag_d == -1 && is_d_dump(av, i))
		{
			ft_printf("flag d :av[%d] = %s\n", i, av[i]);
			core->flag_d = ft_atoi(av[++i]);
		}
		else if (!(core->flag_v) && !(ft_strcmp(av[i], "-v")))
		{
			ft_printf("flag v : av[%d] = %s\n", i, av[i]);
			core->flag_v = 1;
		}
		else if (is_dot_cor(av[i]))
		{
			ft_printf("flag .cor : av[%d] = %s\n", i, av[i]);
			(core->champ_nb)++;
		}
		else if (is_order_n(av, i, core))
		{
			ft_printf("order : av[%d] = %s\n", i, av[i]);
			i += 2;
		}
		else
		{
			ft_printf("bug sur lecture\n");
			return (0);
		}
		i++;
	}
	if (core->champ_nb < 2)
		return (0);
	return (1);
}