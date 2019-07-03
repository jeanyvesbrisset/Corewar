/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:41:29 by maginist          #+#    #+#             */
/*   Updated: 2019/07/03 14:06:49 by floblanc         ###   ########.fr       */
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
	t_label *new;

	cur = (*lab);
	new = 0;
	while (cur && cur->next != *lab && ft_strcmp(cur->name, *str) != 0)
		cur = cur->next;
	if (!(cur) || ft_strcmp(cur->name, *str) != 0)
	{
		add_by_used(lab, str, &new, cur);
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
	if (!(cur->used = (int*)realloc(cur->used, sizeof(int) * (size + 2))))
		return (ft_error("ERROR_REALLOC"));
	cur->used[size] = index;
	cur->used[size + 1] = -1;
	return (1);
}

int		is_brut_num(char *str, int *i)
{
	int j;

	(*i)--;//mdr
	(*i)++;
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

int		is_index(char *str, int *i, t_label **lab, int index)
{
	int		j;
	char	tmp;
	char	*str_cpy;

	j = 0;
	//ft_printf("IS_INDEX debut: str[0] = %c (label char?, redirection)\n", str[0]);
	if (str[j] == LABEL_CHAR)
	{
		j++;
		while (str[j] && ft_strsearch(LABEL_CHARS, str[j]))
			j++;
		tmp = str[j];
	//	ft_printf("IS_INDEX : str[%d] = %c\n", j, str[j]);
		if (j == 2)
			return (0);
		//ft_printf("IS_INDEX : str[%d] = %c\n", j, str[j]);
		str[j] = 0;
		str_cpy = ft_strdup(str + 1);
		if (!(add_used_label(&str_cpy, lab, index)))
			return (0);
		//ft_printf("IS_INDEX : after add_used_label\n");
		str[j] = tmp;
		(*i) += j;
		free(str_cpy);
	}
	else
		return (is_brut_num(str, i));
	return (2);
}

int		is_direct(char *str, int *i, t_label **lab, int index)
{

	if (str[0] != DIRECT_CHAR)
		return (0);
	//ft_printf("IS_DIRECT : le DIRECT_CHAR est bon c'est le is_index qui deconne\n");
	*i += 1;
	return (is_index(str + 1, i, lab, index));
}

int		is_register(char *str, int *i)
{
	int j;
	int res;

	j = 0;
	if (str[(*i)++] != 'r')
		return (0);
	//ft_printf("IS_REGISTER : r est passe\n");
	while (str[(*i) + j] && ft_isdigit(str[(*i) + j]))
		j++;
	//ft_printf("IS_REGISTER : le parcours isdigit est passe\n");
	res = (int)(ft_atoll(str + (*i)));
	//ft_printf("IS_REGISTER : atoll est passe\n");
	if (res < 1 || res > REG_NUMBER)
		return (0);
	(*i) += j;
	//ft_printf("IS_REGISTER : on sort avec res = %d\n", res);
	return (res);
}
