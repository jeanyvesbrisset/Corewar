/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:41:29 by maginist          #+#    #+#             */
/*   Updated: 2019/07/05 11:25:28 by floblanc         ###   ########.fr       */
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

int		is_brut_num(char *str)
{
	int j;

	j = 0;
	if (str[j] == '-')
		j++;
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
	if (str[j] == LABEL_CHAR)
	{
		j++;
		while (str[j] && ft_strsearch(LABEL_CHARS, str[j]))
			j++;
		tmp = str[j];
		if (j == 2)
			return (0);
		str[j] = 0;
		str_cpy = ft_strdup(str + 1);
		if (!(add_used_label(&str_cpy, lab, index)))
			return (0);
		str[j] = tmp;
		(*i) += j;
		free(str_cpy);
	}
	else
		return (is_brut_num(str));
	return (2);
}

int		is_direct(char *str, int *i, t_label **lab, int index)
{
	if (str[0] != DIRECT_CHAR)
		return (0);
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
	while (str[(*i) + j] && ft_isdigit(str[(*i) + j]))
		j++;
	res = (int)(ft_atoll(str + (*i)));
	if (res < 1 || res > REG_NUMBER)
		return (0);
	(*i) += j;
	return (res);
}
