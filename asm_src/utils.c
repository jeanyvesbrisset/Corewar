/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 09:54:53 by maginist          #+#    #+#             */
/*   Updated: 2019/07/04 17:30:05 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		stock_len(t_stock **beg, t_cdata **start)
{
	t_stock	*cur;
	t_cdata	*back_slash;
	int		len;
	int		i;

	if (!(beg && *beg) || !(start && *start))
		return (0);
	len = 1;
	cur = *beg;
	back_slash = *start;
	while (cur->next != *beg && len++ > 0)
		cur = cur->next;
	while (back_slash->index != 1)
		back_slash = back_slash->next;
	i = 0;
	while (i < PROG_NAME_LENGTH)
		if (back_slash->str[i++] == '\n')
			len++;
	i = 0;
	back_slash = back_slash->next;
	while (i < COMMENT_LENGTH)
		if (back_slash->str[i++] == '\n')
			len++;
	return (len);
}

int		verif_index(char *str, int **tab, t_cdata **start, t_label **lab)
{
	int	res;

	if ((res = is_index(str + *(tab[0]), tab[0], lab, *(tab[1]))) == 1)
	{
		if ((res = ft_itoo((*start)->str, str + *(tab[0]), 2, tab[1]))
		== 0)
			return (0);
		(*tab[0]) += res;
	}
	else if (res == 0)
		return (0);
	else
	{
		(*start)->str[*(tab[1])] = 2;
		(*(tab[1])) += 2;
	}
	return (1);
}

int		verif_direct(char *str, int **tab, t_cdata **start, t_label **lab)
{
	int	res;

	if ((res = is_direct(str + *(tab[0]), tab[0], lab, *(tab[1]))) == 1)
	{
		if ((res = ft_itoo((*start)->str, str + *(tab[0]), *tab[2], tab[1]))
		== 0)
			return (0);
		*(tab[0]) += res;
	}
	else if (res == 0)
		return (0);
	else
	{
		(*start)->str[*(tab[1])] = *(tab[2]);
		(*(tab[1])) += (*tab[2]);
	}
	return (1);
}

int		ft_good_transi(char *str, int *i)
{
	ft_jump_white_spaces(str, i);
	if (str[(*i)++] != SEPARATOR_CHAR)
		return (0);
	ft_jump_white_spaces(str, i);
	return (1);
}

int		ft_three_choices(char *str, int **tab, t_cdata **start, t_label **lab)
{
	if (str[(*(tab[0]))] == DIRECT_CHAR)
	{
		if (verif_direct(str, tab, start, lab))
			ocp_adder((unsigned char*)(tab[3]), DIR_CODE);
	}
	else if (str[(*(tab[0]))] == 'r')
	{
		if (*(tab[1]) >= CHAMP_MAX_SIZE)
			return (ft_error("Champion size too long, Max length : ", 0, 0
				, CHAMP_MAX_SIZE));
		if (!((*start)->str[(*(tab[1]))++] = is_register(str, tab[0])))
			return (0);
		ocp_adder((unsigned char*)(tab[3]), REG_CODE);
	}
	else if (verif_index(str, tab, start, lab))
		ocp_adder((unsigned char*)(tab[3]), IND_CODE);
	else
		return (0);
	if (!(ft_good_transi(str, tab[0])))
		return (0);
	return (1);
}

int		ft_two_choices(char *str, int **tab, t_cdata **start, t_label **lab)
{
	if (str[(*(tab[0]))] == DIRECT_CHAR)
	{
		if (verif_direct(str, tab, start, lab))
			ocp_adder((unsigned char*)tab[3], DIR_CODE);
	}
	else if (str[(*(tab[0]))] == 'r')
	{
		if (*(tab[1]) >= CHAMP_MAX_SIZE)
			return (ft_error("Champion size too long, Max length : ", 0, 0
				, CHAMP_MAX_SIZE));
		if (!((*start)->str[(*(tab[1]))++] = is_register(str, tab[0])))
			return (0);
		ocp_adder((unsigned char*)(tab[3]), REG_CODE);
	}
	else
		return (0);
	return (1);
}

int		fct_separator(char *str, int nb_sep, int *index, int ocp)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i] && str[i] != COMMENT_CHAR && str[i] != ';')
	{
		if (str[i] == SEPARATOR_CHAR)
			count++;
		i++;
	}
	if (count != nb_sep)
		return (0);
	if (ocp)
		(*index)++;
	return (1);
}

int		end_gestion(char *str, int *i)
{
	ft_jump_white_spaces(str, i);
	if (str[(*i)] != 0 && str[(*i)] != COMMENT_CHAR && str[(*i)] != ';')
		return (0);
	return (1);
}
