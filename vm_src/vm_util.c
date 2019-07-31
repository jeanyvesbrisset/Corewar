/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/31 17:46:09 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

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
		if (pr && !pr->alive)
		{
			del_process(&prev, &pr);
			core->sum_process--;
		}
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
	t_champ *champ;

	champ = core->champs;
	core->tmp_cycle = 0;
	core->nbr_live = 0;
	pr = core->proces;
	while (champ)
	{
		champ->live_by_ctd = 0;
		champ = champ->next;
	}
	while (pr)
	{
		pr->alive = 0;
		pr = pr->next;
	}
}
