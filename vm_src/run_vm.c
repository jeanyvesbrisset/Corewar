/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/25 17:24:04 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/vm.h"

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

void	handle_proces(t_core *core, t_proces *pr)
{
	unsigned char	ocp;

	ocp = 0;
	if (g_fvm_tab[pr->op - 1].ocp)
		ocp = core->arena[pr->pc + 1];
	read_ocp(pr, ocp);
	pr->pc_jump = get_pr_length(core, pr);
	g_fvm_tab[pr->op - 1].f(core, pr);//fonctions respectives a chaque instruction a coder
	pr->pc += pr->pc_jump;
}

int		read_op(t_core *core, t_proces *pr)
{
	pr->op = core->arena[pr->pc];
	if (pr->op < 1 || pr->op > 16)
		return (0); // to do, prendre en compte cette erreur
	pr->wait = core->cycle_to_die + g_fvm_tab[pr->op - 1].cycle_delay;
	return (1);
}

int		run_cycles_to_die(t_core *core)
{
	t_proces *pr;

	pr = core->proces;
	while (core->tmp_cycle < core->cycle_to_die)
	{
		if (!pr->wait || pr->wait == core->total_cycle - 1)
			if (!read_op(core, pr))
				pr->pc++;
		else if (pr->wait == core->total_cycle)
			handle_proces(core, pr);
		if (pr->next)
			pr = pr->next;
		else
		{
			if (core->flag_v == 1)
				init_visual(core);
			pr = core->proces;
			core->total_cycle++;
			core->tmp_cycle++;
		}
	}
	return (1);
}

void	run_vm(t_core *core)
{
	while (run_cycles_to_die(core) && core->cycle_to_die > 0)
	{
		if (!check_lives(core))
			break ;
		else if (core->nbr_live > NBR_LIVE || core->max_checks == MAX_CHECKS)
		{
			core->cycle_to_die -= CYCLE_DELTA;
			core->max_checks = 0;
		}
		else
			core->max_checks++;
		reinit_cycle_lives(core);
	}
}
