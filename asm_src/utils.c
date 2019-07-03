/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 09:54:53 by maginist          #+#    #+#             */
/*   Updated: 2019/07/03 14:08:59 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		verif_index(char *str, int **tab, t_cdata **start, t_label **lab)
{
	int	res;
	// ft_printf("VERIF INDEX : i = %d\n", (*tab[0]));
	if ((res = is_index(str + *(tab[0]), tab[0], lab, *(tab[1]))) == 1)
	{
		if ((res = ft_itoo((*start)->str, str + *(tab[0]), 2, tab[1]))
		== 0)
			return (ft_error("ITOO A CRASH"));
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
	// ft_printf("VERIF DIRECT : i = %d\n", (*tab[0]));
	if ((res = is_direct(str + *(tab[0]), tab[0], lab, *(tab[1]))) == 1)
	{
		if ((res = ft_itoo((*start)->str, str + *(tab[0]), *tab[2], tab[1]))
		== 0)
			return (ft_error("ITOO A CRASH"));
		*(tab[0]) += res;
	}
	else if (res == 0)
	{//////////
		// ft_printf("verif_direct return 0\n");/////////
		return (0);
	}//////////
	else
	{
		(*start)->str[*(tab[1])] = *(tab[2]);
		(*(tab[1])) += (*tab[2]);
	}
	// ft_printf("VERIF DIRECT:  works\n");
	return (1);
}

int	ft_good_transi(char *str, int *i)
{
	ft_jump_white_spaces(str, i);
	// ft_printf("transi, str[%d] = %c\n", *i, str[(*i)]);
	if (str[(*i)++] != SEPARATOR_CHAR)
		return (0);
	// ft_printf("transi, str[%d] = %c\n", *i, str[(*i)]);
	ft_jump_white_spaces(str, i);
	return (1);
}

int	ft_three_choices(char *str, int **tab, t_cdata **start, t_label **lab)
{
	if (str[(*(tab[0]))] == DIRECT_CHAR)
	{
		if (verif_direct(str, tab, start, lab))
			ocp_adder((unsigned char*)(tab[3]), DIR_CODE);
	}
	else if (str[(*(tab[0]))] == 'r')
	{
		if (*(tab[1]) >= CHAMP_MAX_SIZE)
			return (0);
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

int	ft_two_choices(char *str, int **tab, t_cdata **start, t_label **lab)
{
	if (str[(*(tab[0]))] == DIRECT_CHAR)
	{
		if (verif_direct(str, tab, start, lab))
			ocp_adder((unsigned char*)tab[3], DIR_CODE);
	}
	else if (str[(*(tab[0]))] == 'r')
	{
		if (*(tab[1]) >= CHAMP_MAX_SIZE)
			return (0);
		if (!((*start)->str[(*(tab[1]))++] = is_register(str, tab[0])))
			return (0);
		ocp_adder((unsigned char*)(tab[3]), REG_CODE);
	}
	else
		return (0);
	return (1);
}

int	fct_separator(char *str, int nb_sep, int *index, int ocp)
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

int	end_gestion(char *str, int *i)
{
	ft_jump_white_spaces(str, i);
	if (str[(*i)] != 0 && str[(*i)] != COMMENT_CHAR && str[(*i)] != ';')
		return (0);
	return (1);
}
