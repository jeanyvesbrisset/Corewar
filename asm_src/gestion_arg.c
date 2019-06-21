/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:41:29 by maginist          #+#    #+#             */
/*   Updated: 2019/06/21 16:12:27 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		size_used_tab(int *tab)
{
	int i;

	i = 0;
	while (tab[i] != -1)
		i++;
	return (i);
}

int		add_used_label(char **str, t_label **lab, int index)
{
	t_label *cur;
	int		size;

	cur = (*lab);
	while (cur && cur->next != *lab && ft_strcmp(cur->name, *str) != 0)
		cur = cur->next;
	if (ft_strcmp(cur->name, *str) != 0)
	{
		add_to_lab(lab, str, -1);
		cur = cur->next;
	}
	if (!(cur->used))
	{
		if (!(cur->used = (int*)malloc(sizeof(int) * 2)))
			return (ft_error("ERROR_MALLOC"));
		cur->used[0] = index;
		cur->used[1] = -1;
		return (1);
	}
	size = size_used_tab(cur->used);
	if (!(cur->used = (int*)realloc(cur->used, sizeof(int) * (size + 1))))
		return (ft_error("ERROR_REALLOC"));
	cur->used[size - 1] = index;
	cur->used[size] = -1;
	return (1);
}

int		is_index(char *str, int *i)
{
	int j;

	j = 0;
	if (str[(*i) + j] == '-')
		j++;
	if (!(ft_isdigit(str[(*i) + j])))
		return (0);
	while (str[(*i) + j] && ft_isdigit(str[(*i) + j]))
		j++;
	return (1);
}

int		is_direct(char *str, int *i, t_label **lab, int index)
{
	int		j;
	char	tmp;
	char	*str_cpy;

	j = 0;
	if (str[(*i)++] != DIRECT_CHAR)
		return (0);
	if (str[(*i) + (j)] == LABEL_CHAR)
	{
		(*i)++;
		while (str[(*i) + j] && ft_strsearch(LABEL_CHARS, str[(*i) + j]))
			j++;
		tmp = str[(*i) + j];
		if (j == 0 || tmp == SEPARATOR_CHAR || tmp == ' ' || tmp == '\0'
			|| tmp == '\t')
			return (0);
		str[(*i) + j] = 0;
		str_cpy = ft_strdup(str + (*i));
		if (!(add_used_label(&str_cpy, lab, index)))
			return (0);
		str[(*i) + j] = tmp;
	}
	else
		return (is_index(str, i));
	return (2);
}

int		is_register(char *str, int *i)
{
	int j;
	int res;

	j = 0;
	if (str[(*i)] != 'r')
		return (0);
	while (str[(*i) + j] && ft_isdigit(str[(*i) + j]))
		j++;
	res = ft_atoll(str + (*i));
	if (res < 1 || res > 16)
		return (0);
	(*i) += j;
	return (res);
}
