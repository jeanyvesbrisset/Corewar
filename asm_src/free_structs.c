/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:44:08 by maginist          #+#    #+#             */
/*   Updated: 2019/06/25 16:04:56 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	free_label(t_label **lab)
{
	t_label *current;
	t_label	*before;
	
	before = *lab;
	current = before->next;
	*lab = 0;
	before->next = 0;
	ft_strdel(&(before->name));
	free(current->used);
	free(before);
	while (current)
	{
		before = current;
		current = current->next;
		before->next = 0;
		ft_strdel(&(before->name));
		free(current->used);	
		free(before);
		before = 0;
	}		
}

void	free_cdata(t_cdata **start)
{
	t_cdata *current;
	t_cdata	*before;
	
	before = *start;
	current = before->next;
	*start = 0;
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
