/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_two_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:35:21 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/20 11:40:06 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/op.h"

int		gest_ld(char *str, t_cdata **start, t_label **lab, int *index)
{
	int		i;
	int		j;

	(*start)->str[(*index)++] = 1;
	i = 0;
	j = 0;
	while (str[i])
		if (str[i++] == ',')
			return (0);
	i = 0;
	ft_jump_white_spaces(str, &i);
	if (str[i] != '%')
		return (0);
	while (str[i + j] && ft_isdigit(str[i + j]))
		j++;
	if (str[i + j] != 0)
		return (0);
	ft_itoo((*start)->str + (*index), str + i, 4);
	(*index) += 4;
	return (1);
}