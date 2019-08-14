/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:51:00 by maginist          #+#    #+#             */
/*   Updated: 2019/08/14 12:56:46 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	ft_delete_proc(t_core *core)
{
	t_proces *current;
	t_proces *before;

	current = core->proces;
	before = 0;
	while (current)
	{
		before = current;
		current = current->next;
		free(before);
		before = NULL;
	}
	free(before);
}

int		print_arena_dump(t_core *core)
{
	int		i;
	char	*str;

	i = 0;
	while (i < 4096)
	{
		if (i == 0)
			ft_printf("0x000%x : ", i);
		str = get_hexa((int)(core->arena[i]));
		ft_printf("%s ", str);
		ft_strdel(&str);
		if (i != 0 && (i % 64) == 63 && i != 4095)
		{
			if (i != 63 && i != 127 && i != 191)
				ft_printf("\n0x0%x : ", i + 1);
			else
				ft_printf("\n0x00%x : ", i + 1);
		}
		i++;
	}
	ft_printf("\n");
	core->flag_d = -2;
	return (0);
}

void	read_ocp(t_proces *pr, int ocp)
{
	int	exp;
	int	extract;
	int	i;

	exp = 256;
	i = 0;
	if (!ocp)
		pr->params[i++] = DIR_CODE;
	while (exp != 0 && (exp /= 4) != 1 && ocp)
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

void	handle_or_not(t_core *core, t_proces *pr, int h_or_n)
{
	if (h_or_n == 1)
		handle_proces(core, pr);
	if (!read_op(core, pr))
		pr->pc = (pr->pc + 1) % MEM_SIZE;
	if (core->flag_v && h_or_n)
	{
		refresh_pc(core);
		refresh_live(core);
		refresh_process(core);
	}
}

int		run_cycles_to_die(t_core *core)
{
	t_proces	*pr;

	pr = core->proces;
	while (core->tmp_cycle < core->cycle_to_die)
	{
		if (pr && (!pr->wait || pr->wait < core->total_cycle))
			handle_or_not(core, pr, 0);
		else if (pr && pr->wait == core->total_cycle)
			handle_or_not(core, pr, 1);
		if (pr->next)
			pr = pr->next;
		else
		{
			if (core->flag_v)
				visual_every_cycle(core);
			else if (core->flag_d >= 0 && core->flag_d == core->total_cycle)
				return (print_arena_dump(core));
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
		//ft_printf("max_check = %d\n", core->max_checks);
		if (!check_lives(core))
			break ;
		if (core->nbr_live >= NBR_LIVE || core->max_checks >= MAX_CHECKS)
		{
			core->cycle_to_die -= CYCLE_DELTA;
			core->max_checks = 1;
			if (core->flag_v)
				refresh_cycle_to_die(core);
		}
		else
			core->max_checks++;
		if (core->flag_v)
			refresh_live_ctd(core);
		/*ft_printf("*+*++*+*+**+*+*+*+*+*+*+*+*++*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+\n");
		ft_printf("(%d)\n", core->total_cycle);
		ft_printf("JUMPER has done %d lives,", get_champ(core, 1)->live_by_ctd);
		ft_printf("ULTIMA has done %d lives \n",  get_champ(core, 2)->live_by_ctd);
		ft_printf("for a total of: %d \n",  core->nbr_live);*/
		reinit_cycle_lives(core);
	}
	ft_printf("total cycle = %d\n", core->total_cycle);
}
