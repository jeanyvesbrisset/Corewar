/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_lab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:43:46 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/28 11:55:47 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	add_by_used(t_label **lab, char **str, t_label **new, t_label *current)
{
	if (!(*new = (t_label*)malloc(sizeof(t_label) * 1)))
		return ;
	(*new)->proto = -1;
	(*new)->used = 0;
	(*new)->name = ft_strdup(*str);
	if (!(*lab))
		(*lab) = (*new);
	else if (current)
		current->next = (*new);
	(*new)->next = (*lab);
}

int		all_label_good(t_cdata **start, t_label **lab)
{
	t_label		*cur;
	int			i;
	int 		res;

	cur = *lab;
//	ft_printf("coucou label\n");
	while (cur->next != *lab)
	{
		//ft_printf("cur->name = %s && proto = %d\n", cur->name, cur->proto);
		if (cur->proto < 0)
			return (ft_error("proto < 0\n"));
		i = 0;
		ft_printf("all label good name = %s\n\n", cur->name);
		while (cur->used && cur->used[i] != -1)
		{
			res = (MEM_SIZE + cur->used[i] - cur->proto);
			res %= MEM_SIZE;
	//		ft_printf("THE RES = %d\n", res);
			if (!(ft_itoo(&((*start)->str[cur->used[i]]), ft_itoa(res)
			, (*start)->str[cur->used[i]] , &(cur->used[i]))))
				return (ft_error("BUG ITOO\n"));
			i++;
		}
		cur = cur->next;
	}
	ft_printf("cur->name = %s && proto = %d\n", cur->name, cur->proto);
	if (cur->proto < 0)
		return (ft_error("Proto < 0 2\n"));
	i = -1;
	ft_printf("all label good name = %s\n\n", cur->name);
	while (cur->used && cur->used[++i] != -1)
	{
		res = (MEM_SIZE + cur->used[i] - cur->proto);
		res %= MEM_SIZE;
	//	ft_printf("THE RES = %d\n", res);
		if (!(ft_itoo(&((*start)->str[cur->used[i]]), ft_itoa(res)
			, (*start)->str[cur->used[i]] , &(cur->used[i]))))
			return (ft_error("BUG ITOO\n"));
	}
	return (1);
}

void	start_to_command(t_cdata **start)
{
	while ((*start)->index != 3)
		*start = (*start)->next;
}

void	add_to_lab(t_label **lab, char **name, int proto) //modifier le proto en fonction de la distance au premier DIR
{
	t_label	*current;
	t_label *new;

	current = *lab;
	if (*lab)
		while (current->next != *lab && ft_strcmp(current->name, *name) != 0)
			current = current->next;
	//ft_printf("is_at_t %d\n", proto);	
	if (current && ft_strcmp(current->name, *name) == 0)
	{
		//ft_printf("is_at_to_lab = %s, %d\n", current->name, proto);	
		if ((ft_strcmp(current->name, *name) == 0) && current->proto < 0) 
		{
		//	ft_printf("is_at_to_lab = %s, %d\n", current->name, proto);	
			current->proto = proto;
		}
		return ;
	}
	if (!(new = (t_label*)malloc(sizeof(t_label) * 1)))
		return ;
	new->name = *name;
	//ft_printf("is_at_to_lab = %s, %d\n", new->name, proto);	
	new->proto = proto;
	new->used = 0;
	if (!(*lab))
		*lab = new;
	new->next = *lab;
	if (current)
		current->next = new;
}

int		gest_lab(t_label **lab, int index, char **line, int *jump)
{
	int		i;
	char	*name;

	i = *jump;
	name = 0;
	while ((*line)[i] && (*line)[i] != LABEL_CHAR)
		i++;
	if (i > 0 && (*line)[i] && (*line)[i - 1] != DIRECT_CHAR)
	{
		(*line)[i] = 0;
		if ((*line)[(*jump)] == 0 || ft_charstr((*line) + *jump, LABEL_CHARS) == 0)
			return (0);
		name = ft_strdup((*line) + *jump);
		(*line)[i] = LABEL_CHAR;
		add_to_lab(lab, &name, index);
		*jump = i + 1;
	}
	return (1);
}
