/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_one_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:19:52 by floblanc          #+#    #+#             */
/*   Updated: 2019/07/03 17:04:15 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		gest_live(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;
	void	*tab[3];
	int		int_size;

	int_size = 4;
	i = 0;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	if (*index + 5 >= CHAMP_MAX_SIZE)
		return (0);
	(*start)->str[(*index)++] = 1;
	if (!(fct_separator(str, 0, index, 0)))
		return (0);
	ft_jump_white_spaces(str, &i);
	//ft_printf("LIVE : avant verif direct\n");
	if (!(verif_direct(str, (int**)tab, start, lab)))
		return (0);
	//ft_printf("LIVE : apres verif direct avant end_gestion\n");
	return (end_gestion(str, &i));
}

int		gest_zjmp(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;
	void	*tab[3];
	int		int_size;

	//ft_printf("ZJUMP : str = %s\n", str);
	int_size = 2;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 9;
	if (!(fct_separator(str, 0, index, 0)))
		return (0);;
	i = 0;
	ft_jump_white_spaces(str, &i);
//	ft_printf("ZJUMP : before verif\n");
	if (!(verif_direct(str, (int**)tab, start, lab)))
		return (0);
//	ft_printf("ZJUMP : after verif\n");
	return (end_gestion(str, &i));
}

int		gest_fork(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;
	void	*tab[3];
	int		int_size;

	int_size = 2;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 12;
	if (!(fct_separator(str, 0, index, 0)))
		return (0);
	i = 0;
	ft_jump_white_spaces(str, &i);
	if (!(verif_direct(str, (int**)tab, start, lab)))
		return (0);
	return (end_gestion(str, &i));
}

int		gest_lfork(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;
	void	*tab[3];
	int		int_size;

	int_size = 2;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 15;
	if (!(fct_separator(str, 0, index, 0)))
		return (0);
	i = 0;
	ft_jump_white_spaces(str, &i);
	if (!(verif_direct(str, (int**)tab, start, lab)))
		return (0);
	return (end_gestion(str, &i));
}

int		gest_aff(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;

	(*start)->str[(*index)++] = 16;
	(*start)->str[(*index)++] = 64;
	(void)lab;
	if (!(fct_separator(str, 0, index, 0)))
		return (0);
	i = 0;
	ft_jump_white_spaces(str, &i);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	return (end_gestion(str, &i));
}
