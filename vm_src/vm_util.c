/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/08/09 15:12:37 by floblanc         ###   ########.fr       */
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
		core->arena[((MEM_SIZE + pos + i) % MEM_SIZE)] = nb / div;
		nb %= div;
		div /= 256;
		i++;
	}
}

/* void	del_process_loop(t_proces **tmp, t_proces *pr, t_proces *prev, int i)
{
	int j;

	j = 0;
	while (pr)
	{
		if (j == i)
		{
			*tmp = pr;
			prev->next = pr->next;
			return ;
		}
		prev = pr;
		pr = pr->next;
		j++;
	}
}

void	del_process(t_proces **proces, int i)
{
	t_proces	*tmp;
	t_proces	*pr;
	t_proces	*prev;

	pr = *proces;
	tmp = 0;
	prev = 0;
	if (!i)
	{
		tmp = *proces;
		*proces = (*proces)->next;
	}
	else
		del_process_loop(&tmp, pr, prev, i);
	free(tmp);
}*/

int		check_lives(t_core *core)
{
	t_proces	*prev;
	t_proces	*cur;

	cur = core->proces;
	prev = 0;
	while (cur)
	{
		if (!(cur->alive))
		{
			if (prev)
				prev->next = cur->next;
			else
				core->proces = cur->next;
			free (cur);
			if (prev)
				cur = prev->next;
			else
				cur = core->proces;
			core->sum_process--;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	if (core->proces)
		return (1);

 	return (0);
}

void	reinit_cycle_lives(t_core *core)
{
	t_proces	*pr;
	t_champ		*champ;

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
