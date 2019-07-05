/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 09:54:53 by maginist          #+#    #+#             */
/*   Updated: 2019/07/05 11:35:55 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

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
	static char	*error = "Champion size too long, Max length : ";

	if (str[(*(tab[0]))] == DIRECT_CHAR)
	{
		if (verif_direct(str, tab, start, lab))
			ocp_adder((unsigned char*)(tab[3]), DIR_CODE);
	}
	else if (str[(*(tab[0]))] == 'r')
	{
		if (*(tab[1]) >= CHAMP_MAX_SIZE)
			return (ft_error(error, 0, 0, CHAMP_MAX_SIZE));
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
	static char	*error = "Champion size too long, Max length : ";

	if (str[(*(tab[0]))] == DIRECT_CHAR)
	{
		if (verif_direct(str, tab, start, lab))
			ocp_adder((unsigned char*)tab[3], DIR_CODE);
	}
	else if (str[(*(tab[0]))] == 'r')
	{
		if (*(tab[1]) >= CHAMP_MAX_SIZE)
			return (ft_error(error, 0, 0, CHAMP_MAX_SIZE));
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
