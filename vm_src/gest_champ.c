/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:40:16 by maginist          #+#    #+#             */
/*   Updated: 2019/08/09 11:23:19 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		pos_in_list(t_core *core, t_champ *to_find)
{
	t_champ	*current;
	int		pos;

	pos = core->champ_nb;
	current = core->champs;
	while (current && current != to_find)
	{
		current = current->next;
		pos--;
	}
	return (pos);
}

void	ajust_champ_pos2(t_core *core)
{
	t_champ	*slow;
	t_champ	*current;
	int		tmp;

	slow = core->champs;
	current = slow->next;
	while (slow->next)
	{
		current = slow->next;
		while (current)
		{
			if (!(slow->tmp_n) && !(current->tmp_n)
				&& slow->pos < current->pos)
			{
				tmp = slow->pos;
				slow->pos = current->pos;
				current->pos = tmp;
				slow = core->champs;
				current = slow;
			}
			current = current->next;
		}
		slow = slow->next;
	}
}

void	ajust_champ_pos(t_core *core)
{
	t_champ	*slow;
	t_champ	*current;

	slow = core->champs;
	current = slow->next;
	while (slow->next)
	{
		current = slow->next;
		while (current)
		{
			if (current->pos == slow->pos)
			{
				if (current->tmp_n != 0)
					slow->pos = pos_in_list(core, current);
				else if (slow->tmp_n != 0)
					current->pos = pos_in_list(core, slow);
				slow = core->champs;
				current = slow;
			}
			current = current->next;
		}
		slow = slow->next;
	}
	ajust_champ_pos2(core);
}

void	sort_champ_list(t_champ **champ)
{
	t_champ *current;
	t_champ *before;
	t_champ *after;

	current = *champ;
	after = current->next;
	while (after)
	{
		if (current->pos < after->pos)
		{
			if (before)
				before->next = after;
			current->next = after->next;
			after->next = current;
			current = *champ;
			after = current->next;
			before = 0;
		}
		else
		{
			before = current;
			current = after;
			after = after->next;
		}
	}
}

int		init_process(t_proces **proce, int champ_nb, int pc, int *sum_process)
{
	t_proces	*pro;
	int			i;

	if (!(pro = (t_proces*)malloc(sizeof(t_proces) * 1)))
		return (0);
	(*sum_process)++;
	pro->champ = champ_nb;
	pro->proces_nb = champ_nb;
	pro->carry = 0;
	pro->pc = pc;
	pro->alive = 0;
	pro->wait = 0;
	i = 0;
	while (i < 16)
		pro->r[i++] = 0;
	pro->r[0] = pro->champ;
	pro->next = *proce;
	*proce = pro;
	return (1);
}
