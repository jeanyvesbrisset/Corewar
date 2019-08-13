/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_one_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:19:52 by floblanc          #+#    #+#             */
/*   Updated: 2019/08/13 15:02:35 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		gest_live(char *str, t_cdata **start, t_label **lab, int *index)
{
	int			i;
	void		*tab[3];
	int			int_size;
	static char	*error = "Champion size too long, Max length : ";

	int_size = 4;
	i = 0;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	if (*index + 5 > CHAMP_MAX_SIZE)
		return (ft_error(error, 0, 0, CHAMP_MAX_SIZE));
	(*start)->str[(*index)++] = 1;
	if (!(fct_separator(str, 0, index, 0)))
		return (0);
	ft_jump_white_spaces(str, &i);
	if (!(verif_direct(str, (int**)tab, start, lab)))
		return (0);
	return (end_gestion(str, &i));
}

int		gest_zjmp(char *str, t_cdata **start, t_label **lab, int *index)
{
	int			i;
	void		*tab[3];
	int			int_size;
	static char	*error = "Champion size too long, Max length : ";

	int_size = 2;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	if (*index + 3 > CHAMP_MAX_SIZE)
		return (ft_error(error, 0, 0, CHAMP_MAX_SIZE));
	(*start)->str[(*index)++] = 9;
	if (!(fct_separator(str, 0, index, 0)))
		return (0);
	i = 0;
	ft_jump_white_spaces(str, &i);
	if (!(verif_direct(str, (int**)tab, start, lab)))
		return (0);
	return (end_gestion(str, &i));
}

int		gest_fork(char *str, t_cdata **start, t_label **lab, int *index)
{
	int			i;
	void		*tab[3];
	int			int_size;
	static char	*error = "Champion size too long, Max length : ";

	int_size = 2;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 12;
	if (*index + 3 > CHAMP_MAX_SIZE)
		return (ft_error(error, 0, 0, CHAMP_MAX_SIZE));
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
	int			i;
	void		*tab[3];
	int			int_size;
	static char	*error = "Champion size too long, Max length : ";

	int_size = 2;
	tab[0] = &i;
	tab[1] = index;
	tab[2] = &int_size;
	(*start)->str[(*index)++] = 15;
	if (*index + 3 > CHAMP_MAX_SIZE)
		return (ft_error(error, 0, 0, CHAMP_MAX_SIZE));
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
	int			i;
	static char	*error = "Champion size too long, Max length : ";

	(*start)->str[(*index)++] = 16;
	(*start)->str[(*index)++] = 64;
	(void)lab;
	if (*index + 3 > CHAMP_MAX_SIZE)
		return (ft_error(error, 0, 0, CHAMP_MAX_SIZE));
	if (!(fct_separator(str, 0, index, 0)))
		return (0);
	i = 0;
	ft_jump_white_spaces(str, &i);
	if (!((*start)->str[(*index)++] = is_register(str, &i)))
		return (0);
	return (end_gestion(str, &i));
}
