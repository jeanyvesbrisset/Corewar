/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_one_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:19:52 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/25 16:06:15 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		gest_live(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;
	int		res;

	if (*index + 5 >= CHAMP_MAX_SIZE)
		return (0);
	(*start)->str[(*index)++] = 1;
	i = 0;
	if (!(fct_separator(str, 0, index, 0)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if ((res = is_direct(str + i, &i, lab, *index)) == 1)
	{
		if (!(ft_itoo((*start)->str + (*index), str + i, 4, index)))
			return (0);
	}
	else if (res == 0)
		return (0);
	else
	{
		(*start)->str[*index] = 4;
		(*index) += 4;
	}	
	return (end_gestion(str, &i));
}

int		gest_zjmp(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;
	int		res;

	(*start)->str[(*index)++] = 9;
	i = 0;
	while (str[i])
		if (str[i++] == SEPARATOR_CHAR)
			return (0);
	i = 0;
	ft_jump_white_spaces(str, &i);
	if ((res = is_direct(str + i, &i, lab, *index)) == 1)
	{
		if (!(ft_itoo((*start)->str + (*index), str + i, 2, index)))
			return (0);
	}
	else if (res == 0)
		return (0);
	else
	{
		(*start)->str[*index] = 2;
		(*index) += 2;
	}
	return (end_gestion(str, &i));
}

int		gest_fork(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;
	int		res;

	(*start)->str[(*index)++] = 12;
	i = 0;
	while (str[i])
		if (str[i++] == SEPARATOR_CHAR)
			return (0);
	i = 0;
	ft_jump_white_spaces(str, &i);
	if ((res = is_direct(str + i, &i, lab, *index)) == 1)
	{
		if (!(ft_itoo((*start)->str + (*index), str + i, 2, index)))
			return (0);
	}
	else if (res == 0)
		return (0);
	else
	{
		(*start)->str[*index] = 2;
		(*index) += 2;
	}	
	return (end_gestion(str, &i));
}

int		gest_lfork(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;
	int		res;

	(*start)->str[(*index)++] = 15;
	i = 0;
	while (str[i])
		if (str[i++] == SEPARATOR_CHAR)
			return (0);
	i = 0;
	ft_jump_white_spaces(str, &i);
	if ((res = is_direct(str + i, &i, lab, *index)) == 1)
	{
		if (!(ft_itoo((*start)->str + (*index), str + i, 2, index)))
			return (0);
	}
	else if (res == 0)
		return (0);
	else
	{
		(*start)->str[*index] = 2;
		(*index) += 2;
	}	
	return (end_gestion(str, &i));
}

int		gest_aff(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;

	(*start)->str[(*index)++] = 16;
	(*start)->str[(*index)++] = 64;
	i = 0;
	while (str[i])
		if (str[i++] == SEPARATOR_CHAR)
			return (0);
	i = 0;
	ft_jump_white_spaces(str, &i);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	return (end_gestion(str, &i));
}
