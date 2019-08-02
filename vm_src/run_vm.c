/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:51:00 by maginist          #+#    #+#             */
/*   Updated: 2019/08/02 16:09:12 by maginist         ###   ########.fr       */
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
	t_proces	*pr;

	pr = core->proces;
	while (core->tmp_cycle < core->cycle_to_die && pr)
	{
		if (!pr->wait || pr->wait < core->total_cycle)
		{
			// ft_printf("____________\n(%d)READ at pc %d: %s(%d), ", core->total_cycle, pr->pc, get_champ(core, pr->champ)->name, pr->proces_nb);
			// ft_printf("cycle to die = %d, \n", core->cycle_to_die);
			if (!read_op(core, pr))
				pr->pc = (pr->pc + 1) % MEM_SIZE;
			if (core->flag_v)
				refresh_pc(core);
		}
		else if (pr->wait == core->total_cycle)
		{
			// ft_printf("____________\n(%d)PROCESS: %s(%d) at pc %d does op %d then ", core->total_cycle, get_champ(core, pr->champ)->name, pr->proces_nb, pr->pc, pr->op);
			handle_proces(core, pr);
			if (!read_op(core, pr))
				pr->pc = (pr->pc + 1) % MEM_SIZE;
			if (core->flag_v)
				refresh_pc(core);
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
		// ft_printf("____ CYCLE TO DIE _____ \n");
		// ft_printf("nbr live = %d, max check = %d \n", core->nbr_live, core->max_checks);
		// ft_printf("____ +*+*+*+*+*+*+ _____ \n");
		if (!check_lives(core))
			break ;
		if (core->nbr_live >= NBR_LIVE || core->max_checks == MAX_CHECKS)
		{
			// ft_printf("cycle to die decrease %d\n", core->cycle_to_die);
			core->cycle_to_die -= CYCLE_DELTA;
			core->max_checks = 1;
			if (core->flag_v)
				refresh_cycle_to_die(core);
		}
		else
			core->max_checks++;
		if (core->flag_v)
			refresh_live_ctd(core);
		// ft_printf("*+*++*+*+**+*+*+*+*+*+*+*+*++*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+\n");
		// ft_printf("(%d)\n", core->total_cycle);
		// ft_printf("bigzork has done %d lives,", get_champ(core, 1)->live_by_ctd);
		// ft_printf("zork has done %d lives \n",  get_champ(core, 2)->live_by_ctd);
		// ft_printf("for a total of: %d \n",  core->nbr_live);
		reinit_cycle_lives(core);
	}
	ft_printf("total cycle = %d\n", core->total_cycle);
	check_lives(core);
}