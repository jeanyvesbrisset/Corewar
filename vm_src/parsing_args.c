/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:02:22 by maginist          #+#    #+#             */
/*   Updated: 2019/07/15 18:41:16 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int	is_dot_cor(char *av)
{
	if (ft_strnchr(av, '.') != 1)
		return (0);
	if (*av != '.' && !ft_strcmp(ft_strchr(av, '.'), ".cor"))
		return (1);
	return (0);
}

int	is_order_n(char **av, int i, t_core *core)
{
	int champ_n;

	if (ft_strcmp(av[i], "-n"))
		return (0);
	if (!(ft_isdigit(av[i + 1])))
		return (0);
	champ_n = ft_atoi(av[i + 1]);
	if (is_dot_cor(av[i + 2]))
	{
		if (!(stock_champ(core, av, i, champ_n)))
			return (0);
	}
	else
		return (0);
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
	if (ft_strcmp(av[i], "-d") || ft_strcmp(av[i], "-dump"))
		return (0);
	if (!(ft_isdigit(av[i + 1])))
		return (0);
	return (1);
}

int	parcing_args(int ac, char **av, t_core *core)
{	
	int i;

	i = 1;
	while (i < ac)
	{
		if (!(ft_strcmp(av[i], "-h")) || !(ft_strcmp(av[i], "-help")))
			return (write_help(av[0]));
		else if (core->flag_d == -1 && is_d_dump(av, i))
			core->flag_d = ft_atoi(av[++i]);
		else if (!(core->flag_v) && !(ft_strcmp(av[i], "-v")))
			core->flag_v = 1;
		else if (is_dot_cor(av[i]))
		{
			if (!(stock_champ(core, av, i, 0)))
				return (0);
		}
		else if (is_order_n(av, i, core))
			i += 2;
		else
			return (0);
	
		//si flag n && flag d, alors ignore flag d
		//flag n marche nimporte quel endroit une fois mis apres l'exec
		//flag d est ignore si le nombre de cycles est negatif
		//si le nombre de cycle envoye est un float ? est ce qu'on fait une troncature ou un arrondi comme la vm du sujet ou on renvoie vers ft_usage ?
		// le nombre de cycles doit etre le prochain argumnt qui suit -d, sinon error
		// s;il y a plus d'un -d, ft usage
		// si -d nest pas suivi du nombre de cycle ? est-ce quon fait un ft_usage ou on considere que nb cycle = 0 et on display le programme
		i++;
	}
	return (1);
}