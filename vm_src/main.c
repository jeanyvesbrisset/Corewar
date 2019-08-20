/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:30:51 by maginist          #+#    #+#             */
/*   Updated: 2019/08/20 16:48:11 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		ft_otoi(unsigned char *nb_str, int addr, int size)
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
		res += ((int)(nb_str[(i + addr) % MEM_SIZE] * div));
		div /= 256;
	}
	return (res);
}

void	init_core(t_core *core)
{
	core->flag_d = -1;
	core->flag_v = 0;
	core->flag_vb = 0;
	core->champ_nb = 0;
	core->champs = 0;
	core->proces = 0;
	core->visu = 0;
	core->live_champ = 0;
	core->sum_process = 0;
	core->total_cycle = 0;
	core->cycle_to_die = 0;
	core->max_checks = 0;
	core->nbr_live = 0;
}

void	default_aff(t_core *core)
{
	int		i;
	t_champ	*cur;

	cur = core->champs;
	ft_printf("WELCOME!\nIntroducing contestants...\n");
	i = 1;
	while (i <= core->champ_nb)
	{
		if (cur->pos == i)
		{
			ft_printf("Player %d, weigthing %d bytes, \"%s\", (\"%s\") !\n"
			, cur->pos, cur->size, cur->name, cur->comment);
			cur = core->champs;
			i++;
		}
		else
			cur = cur->next;
	}
}

int		main(int ac, char **av)
{
	t_core *core;

	if (!(core = (t_core*)malloc(sizeof(t_core) * 1)))
		return (0);
	init_core(core);
	if (!(parcing_args(ac, av, core)))
		return (free_core(core));
	if (!(stock_champ(ac, av, core)))
		return (free_core(core));
	if (!(core->flag_v))
		default_aff(core);
	vm(core);
	free_core(core);
	return (1);
}
