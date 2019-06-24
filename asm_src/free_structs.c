/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:44:08 by maginist          #+#    #+#             */
/*   Updated: 2019/06/24 15:26:45 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	free_label(t_label **lab)
{
	return ;
}

void	free_cdata(t_cdata **start)
{
	return ;
}

void	free_stock(t_stock **begin)
{
	t_stock	*current;
	t_stock	*before;
	
	before = *begin;
	current = before->next;
	*begin = 0;
	before->next = 0;
	ft_strdel(&(before->str));
	free(before);
	while (current)
	{
		before = current;
		current = current->next;
		before->next = 0;
		ft_strdel(&(before->str));
		free(before);
		before = 0;
	}
}

void	free_structs(t_stock **begin, t_cdata **start, t_label **lab)
{
	if (begin && *begin)
		free_stock(begin);
	if (start && (*start))
		free_cdata(start);
	if (lab && (*lab))
		free_label(lab);
	return ;
}
