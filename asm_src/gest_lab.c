/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_lab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:43:46 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/25 16:01:02 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		all_label_good(t_cdata **start, t_label **lab)
{
	t_label		*cur;
	int			i;

	cur = *lab;
	while (cur->next != *lab)
	{
		if (cur->proto < 0)
			return (0);
		i = -1;
		while (cur->used && cur->used[++i] != -1)
			if (!(ft_itoo(&((*start)->str[cur->used[i]]), ft_itoa((MEM_SIZE 
			+ cur->used[i] - cur->proto) % MEM_SIZE)
			, (*start)->str[cur->used[i]] , &(cur->used[i]))))
				return (0);
		cur = cur->next;
	}
	if (cur->proto < 0)
		return (0);
	i = -1;
	while (cur->used && cur->used[++i] != -1)
		if (!(ft_itoo(&((*start)->str[cur->used[i]]), ft_itoa((MEM_SIZE 
		+ cur->used[i] - cur->proto) % MEM_SIZE), (*start)->str[cur->used[i]]
		, cur->used[i])))
			return (0);
	return (1);
}

void	start_to_command(t_cdata **start)
{
	while ((*start)->index != 3)
		*start = (*start)->next;
}

void	add_to_lab(t_label **lab, char **name, int proto)
{
	t_label	*current;
	t_label *new;

	current = *lab;
	if (*lab)
		while (current->next != *lab && ft_strcmp(current->name, *name) != 0)
			current = current->next;
	if (current && current->next != *lab)
	{
		if (current->next != *lab && current->proto < 0)
			current->proto = proto;
		return ;
	}
	if (!(new = (t_label*)malloc(sizeof(t_label) * 1)))
		return ;
	new->name = *name;
	if (proto >= 0)
		new->proto = proto;
	if (!(new->used))
		new->used = 0;
	new->next = *lab;
	current->next = new;
}

int		gest_lab(t_label **lab, int index, char **line, int *jump)
{
	int		i;
	char	*name;

	i = *jump;
	name = 0;
	while ((*line)[i] && (*line)[i] != ':')
		i++;
	if (i > 0 && (*line)[i] && (*line)[i - 1] != '%')
	{
		(*line)[i] = 0;
		if (*line + *jump == 0 || ft_charstr((*line) + *jump, LABEL_CHARS) == 0)
			return (0);
		name = ft_strdup((*line) + *jump);
		(*line)[i] = ':';
		add_to_lab(lab, &name, index);
		*jump = i + 1;
	}
	return (1);
}
