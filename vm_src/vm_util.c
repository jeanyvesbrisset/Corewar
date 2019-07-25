/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/25 17:18:50 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"
#include "../includes/vm.h"

void	ft_itoo_vm(t_core *core, int pos, unsigned long long int nb
	, unsigned long long int size)
{
	unsigned long long int	i;
	unsigned long long int	div;

	i = size;
	div = 1;
	nb %= 9223372036854775807;
	while (--i > 0)
		div *= 256;
	nb %= div * 256;
	while (i < size)
	{
		core->arena[(pos + i) % MEM_SIZE] = nb / div;
		nb %= div;
		div /= 256;
		i++;
	}
}

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

void	del_process(t_proces **prev, t_proces **pr)
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

void	reinit_cycle_lives(t_core *core)
{
	t_proces *pr;

	core->tmp_cycle = 0;
	core->nbr_live = 0;
	pr = core->proces;
	while (pr)
	{
		pr->alive = 0;
		pr = pr->next;
	}
}
