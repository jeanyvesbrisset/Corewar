/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_for_used_lab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:23:50 by floblanc          #+#    #+#             */
/*   Updated: 2019/07/15 16:59:29 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		write_the_magic(t_cdata **start, int nb)
{
	int		unused;
	char	*str;

	unused = 0;
	str = ft_itoa(nb);
	if (!(ft_itoo((*start)->str, str, 4, &unused)))
		return (0);
	ft_strdel(&str);
	return (1);
}

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

int		add_used_label(char **str, t_label **lab, int index)
{
	t_label *cur;
	int		size;
	t_label *new;

	cur = (*lab);
	new = 0;
	while (cur && cur->next != *lab && ft_strcmp(cur->name, *str) != 0)
		cur = cur->next;
	if (!(cur) || ft_strcmp(cur->name, *str) != 0)
		add_by_used(lab, str, &new, &cur);
	if (!(cur->used))
	{
		if (!(cur->used = (int*)malloc(sizeof(int) * 2)))
			return (ft_error("ERROR_MALLOC\n", 0, 0, 0));
		cur->used[0] = index;
		cur->used[1] = -1;
		return (1);
	}
	size = size_used_tab(cur->used);
	if (!(cur->used = (int*)realloc(cur->used, sizeof(int) * (size + 2))))
		return (ft_error("ERROR_REALLOC\n", 0, 0, 0));
	cur->used[size] = index;
	cur->used[size + 1] = -1;
	return (1);
}

int		used_s_begin(t_cdata **st, int used)
{
	int	i;
	int	run;

	i = 0;
	run = 0;
	while (i + run <= used)
	{
		i += run;
		run = 0;
		if ((*st)->str[i] == 9 || (*st)->str[i] == 12 || (*st)->str[i] == 15)
			run = 3;
		else if ((*st)->str[i] == 1)
			run = 5;
		else
			run = ocp_trad_size((int)(*st)->str[i], (int)(*st)->str[i + 1]);
	}
	return (i);
}
