/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fvm_tab_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:45:12 by maginist          #+#    #+#             */
/*   Updated: 2019/07/30 11:49:18 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/vm.h"

int		get_direct(t_core *core, t_proces *pr, int cursor)
{
	int	size;

	size = g_fvm_tab[pr->op - 1].direct_size;
	return (ft_otoi(&(core->arena[cursor]), size));
}

int	    get_size(int op, int type)
{
	if (type == REG_CODE)
		return (1);
	else if (type == IND_CODE)
		return (2);
	else if (type == DIR_CODE)
		return (g_fvm_tab[op - 1].direct_size);
	return (0);
}

void	handle_proces(t_core *core, t_proces *pr)
{
	unsigned char	ocp;

	ocp = 0;
	if (g_fvm_tab[pr->op - 1].ocp)
		ocp = core->arena[pr->pc + 1];
	read_ocp(pr, ocp);
	pr->pc_jump = get_pr_length(pr, pr->op);
	g_fvm_tab[pr->op - 1].f(core, pr);
	if (pr->op != 9)
		pr->pc = (pr->pc + pr->pc_jump) % MEM_SIZE;
}

int		read_op(t_core *core, t_proces *pr)
{
	pr->op = core->arena[pr->pc];
	if (pr->op < 1 || pr->op > 16)
		return (0);
	pr->wait = core->total_cycle + g_fvm_tab[pr->op - 1].cycle_delay;
    return (1);
}

int		get_pr_length(t_proces *pr, int op)
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
		else if (pr->params[i] == IND_CODE
			|| (pr->params[i] == DIR_CODE
				&& g_fvm_tab[op - 1].direct_size == 2))
			len += 2;
		else if (pr->params[i] == DIR_CODE &&
			g_fvm_tab[op - 1].direct_size == 4)
			len += 4;
		i++;
	}
	return (len);
}