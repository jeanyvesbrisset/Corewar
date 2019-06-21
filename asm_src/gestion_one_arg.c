/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_one_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:19:52 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/21 10:33:02 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		gest_live(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;
	int		res;

	(*start)->str[(*index)++] = 1;
	i = 0;
	while (str[i])
		if (str[i++] == SEPARATOR_CHAR)
			return (0);
	i = 0;
	ft_jump_white_spaces(str, &i);
	if ((res = is_direct(str + i, &i, lab, index)) == 2)
		ft_itoo((*start)->str + (*index), str + i, 4);
	else if (res == 0)
		return (0);
	ft_jump_white_spaces(str, &i);
	if (str[i] != 0)
		return (0);
	return (1);
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
	if ((res = is_direct(str + i, &i, lab, index)) == 2)
		ft_itoo((*start)->str + (*index), str + i, 2);
	else if (res == 0)
		return (0);
	ft_jump_white_spaces(str, &i);
	if (str[i] != 0)
		return (0);
	return (1);
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
	if ((res = is_direct(str + i, &i, lab, index)) == 2)
		ft_itoo((*start)->str + (*index), str + i, 2);
	else if (res == 0)
		return (0);
	ft_jump_white_spaces(str, &i);
	if (str[i] != 0)
		return (0);
	return (1);
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
	if ((res = is_direct(str + i, &i, lab, index)) == 2)
		ft_itoo((*start)->str + (*index), str + i, 2);
	else if (res == 0)
		return (0);
	ft_jump_white_spaces(str, &i);
	if (str[i] != 0)
		return (0);
	return (1);
}

int		gest_aff(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;

	(*start)->str[(*index)++] = 16;
	i = 0;
	while (str[i])
		if (str[i++] == SEPARATOR_CHAR)
			return (0);
	i = 0;
	ft_jump_white_spaces(str, &i);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	ft_jump_white_spaces(str, &i);	
	if (str[i] != 0)
		return (0);
	return (1);
}