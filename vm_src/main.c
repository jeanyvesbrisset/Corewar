/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:30:51 by maginist          #+#    #+#             */
/*   Updated: 2019/07/30 17:38:09 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	free_core(t_core *core)
{
	t_champ *current;
	t_champ	*before;

	if (!(core->champs))
		return ;
	before = core->champs;
	current = before->next;
	core->champs = 0;
	before->next = 0;
	ft_strdel((char**)(&((before->name))));
	ft_strdel((char**)(&(before->bytecode)));
	ft_strdel((char**)(&(before->comment)));
	free(before);
	while (current)
	{
		before = current;
		current = current->next;
		before->next = 0;
		ft_strdel((char**)(&((before->name))));
		ft_strdel((char**)(&(before->bytecode)));
		ft_strdel((char**)(&(before->comment)));
		free(before);
		before = 0;
	}
	free(core);
}

int		ft_error(char *error, int ret, void **to_free, int line)
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

int		ft_otoi(unsigned char *nb_str, int size)
{
	int	i;
	int	res;
	int	div;

	div = 1;
	res = 0;
	i = size - 1;
	while (i-- > 0)
		div *= 256;
	while (++i < size)
	{
		res += ((int)(nb_str[i]) * div);
		div /= 256;
	}
	return (res);
}

int main(int ac, char **av)
{
	t_core *core;

	if (!(core = (t_core*)malloc(sizeof(t_core) * 1)))
		return (0);
	core->flag_d = -1;
	core->flag_v = 0;
	core->champ_nb = 0;
	core->champs = 0;
	core->proces = 0;
	core->visu = 0;
	ft_printf("on commence\n");
	if (!(parcing_args(ac, av, core)))
		return (0);
	ft_printf("parcing good\n");
	if (!(stock_champ(ac, av, core)))
		return (0);
	ft_printf("stockage good\n");
	//if (core->flag_v)
		//init_visual(core);
	vm(core);
//	ft_printf("core->total cycle : %d\n", core->total_cycle);
	free_core(core);
	return (1);
}
