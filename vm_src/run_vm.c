/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/31 12:55:17 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	read_ocp(t_proces *pr, int ocp)
{
	int	exp;
	int	extract;
	int	i;

	exp = 256;
	i = 0;
	if (!ocp)
		pr->params[i++] = DIR_CODE;
	while ((exp /= 4) != 1 && ocp)
	{
		extract = ocp / exp;
		ocp -= extract * exp;
		if (extract == 0 || extract == REG_CODE ||
			extract == DIR_CODE || extract == IND_CODE)
			pr->params[i] = extract;
		i++;
	}
	while (i < 4)
		pr->params[i++] = 0;
}

int		run_cycles_to_die(t_core *core)
{
	t_proces *pr;

	pr = core->proces;
	while (core->tmp_cycle < core->cycle_to_die)
	{
		if (!pr->wait || pr->wait < core->total_cycle)
		{
			// if (pr->champ == 1)
				ft_printf("____________\n(%d)READ at pc %d: %s(%d), ", core->total_cycle, pr->pc, get_champ(core, pr->champ)->name, pr->proces_nb);
			if (!read_op(core, pr))
				pr->pc = (pr->pc + 1) % MEM_SIZE;
		}
		else if (pr->wait == core->total_cycle)
		{
			// if (pr->champ == 1)
			ft_printf("____________\n(%d)PROCESS: %s(%d) at pc %d does op %d then ", core->total_cycle, get_champ(core, pr->champ)->name, pr->proces_nb, pr->pc, pr->op);
			handle_proces(core, pr);
		}
		if (pr->next)
			pr = pr->next;
		else
		{
			if (core->flag_v)
				visual_every_cycle(core);
			pr = core->proces;
			core->total_cycle++;
			core->tmp_cycle++;
		}
	}
	return (1);
}

void	run_vm(t_core *core)
{
	if (core->flag_v == 1)
		init_visual(core);
	while (run_cycles_to_die(core) && core->cycle_to_die > 0)
	{
		if (!check_lives(core))
		{
			ft_printf("tout le monde est mort\n");
			break ;
		}
		else if (core->nbr_live >= NBR_LIVE || core->max_checks >= MAX_CHECKS)
		{
			core->cycle_to_die -= CYCLE_DELTA;
			core->max_checks = 0;
			if (core->flag_v)
				refresh_cycle_to_die(core);
		}
		else
			core->max_checks++;
		if (core->flag_v)
			refresh_live_ctd(core);
		reinit_cycle_lives(core);
	}
	//check_lives(core);
}
