/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 09:54:53 by maginist          #+#    #+#             */
/*   Updated: 2019/07/01 11:32:55 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int	ft_good_transi(char *str, int *i)
{
	ft_jump_white_spaces(str, i);
	if (str[(*i)++] != SEPARATOR_CHAR)
		return (0);
	ft_jump_white_spaces(str, i);
	return (1);
}

int	ft_three_choices(char *str, int **tab, t_cdata **start, t_label **lab)
{
	int res;

	if (str[(*(tab[0]))] == DIRECT_CHAR)
	{
		if ((res = is_direct(str + *(tab[0]), tab[0], lab, *(tab[1]))) == 1)
		{
			if ((res = ft_itoo((*start)->str, str + *(tab[0]), *tab[2], tab[1])) == 0)
				return (ft_error("ITOO A CRASH"));
			//ft_printf("res = %d, *i = %d\n", res, *(tab[0]));
			*(tab[0]) += res;
		}
		else if (res == 0)
			return (0);
		else
		{
			ft_printf("used saved to = %d\n", *(tab[1]));
			ft_printf("tab[1] = %d et tab[2] = %d\n", *tab[1], *tab[2]);
			(*start)->str[*(tab[1])] = *(tab[2]);
			(*(tab[1])) += (*tab[2]);
			ft_printf("tab[1] = %d et tab[2] = %d\n", *tab[1], *tab[2]);
		}	
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
	else if (is_index(str + *(tab[0]), tab[0]))
	{
		if (!(ft_itoo((*start)->str, str + *(tab[0]), 2, tab[1])))
			return (0);
		ocp_adder((unsigned char*)(tab[3]), IND_CODE);
	}
	else
		return (0);
	if (!(ft_good_transi(str, tab[0])))
		return (0);
	return (1);
}

int	ft_two_choices(char *str, int **tab, t_cdata **start, t_label **lab)
{
	int	res;

	//ft_printf("2_choices[%d] = %c\n", *(tab[0]), str[*(tab[0])]);
	if (str[(*(tab[0]))] == DIRECT_CHAR)
	{
		if ((res = is_direct(str + *(tab[0]), tab[0], lab, *(tab[1]))) == 1)
		{
		//	ft_printf("res = %d\n", res);
			ft_printf("verif itoo  01 = %d index %d et %d\n", (int)((*start)->str + *(tab[1]))[0], *tab[1],  (int)((*start)->str + *(tab[1]) + 1)[0]);
			if ((res = ft_itoo((*start)->str, str + *(tab[0]), *tab[2], tab[1])) == 0)
				return (ft_error("ITOO A CRASH"));
			ft_printf("verif itoo  01 = %d index %d et %d\n", (int)((*start)->str + *(tab[1]) - 2)[0], *tab[1] - 2, (int)((*start)->str + *(tab[1]) - 1)[0]);
			*(tab[0]) += res;
		}
		else if (res == 0)
		{
			//ft_printf("res1 = %d\n", res);
			return (0);
		}
		else
		{
			ft_printf("used saved to = %d\n", *(tab[1]));
			(*start)->str[*(tab[1])] = *(tab[2]);
			(*(tab[1])) += *(tab[2]);
		}
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
//	ft_printf("OK GOOGLE\n");
	return (1);
}

int	fct_separator(char *str, int nb_sep, int *index, int ocp)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
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
	//ft_printf("end[str] = %s\n", str);
	//ft_printf("end(str[%d])= %c\n", *i, str[*i - 1]);
	if (str[(*i)] != 0)
		return (0);
//	ft_printf("end gestion works\n");
	return (1);
}
