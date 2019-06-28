/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:41:29 by maginist          #+#    #+#             */
/*   Updated: 2019/06/28 11:42:54 by maginist         ###   ########.fr       */
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

int		add_used_label(char **str, t_label **lab, int index) //ajouter la size du direct a l'index ou l'envoyer en 4eme element
{
	t_label *cur;
	int		size;
	t_label *new;

	cur = (*lab);
	new = 0;
	while (cur && cur->next != *lab && ft_strcmp(cur->name, *str) != 0)
		cur = cur->next;
	//ft_printf("add_used_label cur->name = %s && proto = %d\n", cur->name, cur->proto);
	if (!(cur) || ft_strcmp(cur->name, *str) != 0)
	{
		//ft_printf("OKKKKK->name = %s && proto = %d\n", cur->name, cur->proto);
		add_by_used(lab, str, &new, cur);
		//ft_printf("new->name = %s && proto = %d\n", new->name, new->proto);
		cur = new;
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

	(void)*i;
	j = 0;
	if (str[j] == '-')
		j++;
//	ft_printf("is index str[%d] = %c\n", j, str[j]);
	if (!(ft_isdigit(str[j])))
		return (0);
	while (str[j] && ft_isdigit(str[j]))
		j++;
	return (1);
}

int		is_direct(char *str, int *i, t_label **lab, int index)
{
	int		j;
	char	tmp;
	char	*str_cpy;

	j = 0;
	//ft_printf("is_direct[%d] = %c\n", 0, str[0]);
	if (str[j++] != DIRECT_CHAR)
		return (0);
	//ft_printf("is_direct1[%d] = %c\n", j, str[j]);
	if (str[j] == LABEL_CHAR)
	{
		j++;
		while (str[j] && ft_strsearch(LABEL_CHARS, str[j]))
			j++;
		tmp = str[j];
		//ft_printf("is_direct2[%d] = %c\n", j, str[j]);
		if (j == 2)
			return (0);
		str[j] = 0;
		str_cpy = ft_strdup(str + 2);
		//ft_printf("is_direct3[%d] = %s\n", j, str_cpy);
		if (!(add_used_label(&str_cpy, lab, index)))
			return (ft_error("BAD_LABELLLLLLL"));
		str[j] = tmp;
		(*i) += j;
		free(str_cpy);
	}
	else
	{
		(*i)++;
		return (is_index(str + 1, i));
	}
	return (2);
}

int		is_register(char *str, int *i)
{
	int j;
	int res;

	j = 0;
	if (str[(*i)] != 'r')
		return (0);
	(*i)++;
	while (str[(*i) + j] && ft_isdigit(str[(*i) + j]))
		j++;
	res = ft_atoll(str + (*i));
	//ft_printf("res = %d\n", res);
	if (res < 1 || res > REG_NUMBER)
		return (0);
	(*i) += j;
	return (res);
}
