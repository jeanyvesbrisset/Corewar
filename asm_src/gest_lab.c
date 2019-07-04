/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_lab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:43:46 by floblanc          #+#    #+#             */
/*   Updated: 2019/07/04 19:27:12 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	add_by_used(t_label **lab, char **str, t_label **new, t_label **current)
{
	if (!(*new = (t_label*)malloc(sizeof(t_label) * 1)))
		return ;
	(*new)->proto = -1;
	(*new)->used = 0;
	(*new)->name = ft_strdup(*str);
	if (!(*lab))
		(*lab) = (*new);
	else if ((*current))
		(*current)->next = (*new);
	(*new)->next = (*lab);
	*current = *new;
}

int		all_label_good(t_cdata **start, t_label **lab)
{
	t_label		*cur;
	int			i;
	int			res;
	char		*res_str;

	if (!(lab && *lab))
		return (1);
	cur = *lab;
	while (cur->next != *lab)
	{
		if (cur->proto < 0)
		{
			write(2, "This label doesn't exist : ", 27);
			write(2, cur->name, ft_strlen(cur->name));
			return (ft_error("\n", 0, 0, 0));
		}
		i = 0;
		while (cur->used && cur->used[i] != -1)
		{
			res = (MEM_SIZE + cur->proto - used_s_begin(start, cur->used[i]));
			res %= MEM_SIZE;
			res_str = ft_itoa(res);
			if (!(ft_itoo((*start)->str, res_str
			, (*start)->str[cur->used[i]], &(cur->used[i]))))
				return (0);
			ft_strdel(&res_str);
			i++;
		}
		cur = cur->next;
	}
	if (cur->proto < 0)
		return (0);
	i = -1;
	while (cur->used && cur->used[++i] != -1)
	{
		res = (MEM_SIZE + cur->proto - used_s_begin(start, cur->used[i]));
		res %= MEM_SIZE;
		res_str = ft_itoa(res);
		if (!(ft_itoo((*start)->str, res_str
			, (*start)->str[cur->used[i]], &(cur->used[i]))))
			return (0);
		ft_strdel(&res_str);
	}
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
	if (current && ft_strcmp(current->name, *name) == 0)
	{
		if ((ft_strcmp(current->name, *name) == 0) && current->proto < 0)
		{
			current->proto = proto;
		}
		return ;
	}
	if (!(new = (t_label*)malloc(sizeof(t_label) * 1)))
		return ;
	new->name = ft_strdup(*name);
	new->proto = proto;
	new->used = 0;
	if (!(*lab))
		*lab = new;
	new->next = *lab;
	if (current)
		current->next = new;
}

void	gest_lab(t_label **lab, int index, char **line, int *jump)
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
		if ((*line)[(*jump)] == 0
			|| ft_charstr((*line) + *jump, LABEL_CHARS) == 0)
		{
			(*line)[i] = LABEL_CHAR;
			return ;
		}
		name = ft_strdup((*line) + *jump);
		(*line)[i] = LABEL_CHAR;
		add_to_lab(lab, &name, index);
		ft_strdel(&name);
		*jump = i + 1;
	}
	return ;
}
