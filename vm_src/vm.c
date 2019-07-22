/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/18 16:47:48 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/vm.h"

int		get_pr_length(t_core *core, t_proces *pr, int op)
{
	int	param_nb;
	int	i;
	int	len;
	
	i = 0;
	len = 1;
	if (g_fvm_tab[op - 1].ocp == 1)
		len++;
	param_nb = g_fvm_tab[op - 1].param_nb;
	while (i < param_nb)
	{
		if (pr->params[i] == REG_CODE)
			len++;
		else if (pr->params[i] == IND_CODE || 
			(pr->params[i] == DIR_CODE && g_fvm_tab[op - 1].direct_size == 2))
			len += 2;
		else if (pr->params[i] == DIR_CODE &&
			g_fvm_tab[op - 1].direct_size == 4)
			len += 4;
		i++;
	}
	return (len);
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
	unsigned char	op;
	unsigned char	ocp;

	op = core->arena[pr->pc];
	ocp = 0;
	if (g_fvm_tab[op - 1].ocp)
		ocp = core->arena[pr->pc + 1];
	read_ocp(pr, ocp);
	g_fvm_tab[op - 1].f(core, pr);//fonctions respectives a chaque instruction a coder
	pr->pc += get_pr_length(core, pr, op);
}

void	read_op(t_core *core, t_proces *pr)
{
	unsigned char op;

	op = core->arena[pr->pc];
	if (op < 1 || op > 16)
		return ; // to do, prendre en compte cette erreur
	pr->wait = core->cycle_to_die + g_fvm_tab[op - 1].cycle_delay;
}

int		run_cycles_to_die(t_core *core)
{
	t_proces *pr;

	pr = core->proces;
	while (core->tmp_cycle++ < core->cycle_to_die)
	{
		if (!pr->wait || pr->wait == core->total_cycle - 1)
			read_op(core, pr);
		else if (pr->wait == core->total_cycle)
			handle_proces(core, pr);
		else
		{
			if (pr->next)
				pr = pr->next;
			else
			{
				pr = core->proces;
				core->total_cycle++;
			}
		}
	}
	return (1);
}

void	del_process(t_proces **prev ,t_proces **pr)
{
	t_proces *tmp;

	tmp = *pr;
	if (*prev)
		(*prev)->next = (*pr)->next;
	*pr = (*pr)->next;
	free(tmp);
}

int		check_lives(t_core *core)
{
	t_proces	*pr;
	t_proces	*prev;
	int			res;

	pr = core->proces;
	prev = NULL;
	res = 0;
	while (pr)
	{
		if (!pr->alive)
			del_process(&prev, &pr);
		else
		{
			res++;
			prev = pr;
			pr = pr->next;
		}
	}
	return (res);
}

void	run_vm(t_core *core)
{
	while (run_cycles_to_die(core))
	{
		if (!check_lives(core))
			break ;
		else if (core->nbr_live > NBR_LIVE)
			core->cycle_to_die -= CYCLE_DELTA;
		core->tmp_cycle = 0;
		core->nbr_live = 0;
	}
}

int		vm(t_core *core)
{
	init_vm(core);
	run_vm(core);
}


/*
		etape 1 : creer un espace memoire dedie au comabt des joueurs
		etape 2 : charger les champions et leurs processus associes
				dans cet espace memoire
		etape 3 : executer les champions sequentiellement, donc l'un apres l'autre
					jusqu'a ce que mort s'ensuive
		etape 4 : tous ls 1536 cycles (cycle_to_die), on doit verifier que
					chaque processus a execute au moins une fois l'instruction live depuis la derniere verif
					sinon le processus meurt.
		etape 5 : si au cours d'une verif il y a eu au moins 21 (nbr_live) executions de live
					depuis la derniere verif on decremente cycle to die de 50 (cycle delta)
		etape 6 : quand tous les processus sont dead, on arrete la partie
		etape 7 : le gagnant est le dernier joueurrapporte en vie
		etape 8 : il faut afficher "le joueur n a gagne"

*/