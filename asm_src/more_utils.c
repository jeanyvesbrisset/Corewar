/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:24:46 by floblanc          #+#    #+#             */
/*   Updated: 2019/07/05 11:25:53 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		len_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int		champ_exist(t_cdata **start)
{
	t_cdata *cur;

	cur = *start;
	while (cur && cur->index != 3)
		cur = cur->next;
	if (cur->str[0] == 0)
		return (ft_error("There is no champion\n", 0, 0, 0));
	return (1);
}

int		ocp_trad_size(int com, int ocp)
{
	int		res;
	int		mult;
	int		extract;
	int		div;

	div = 256;
	res = 2;
	if (com == 10 || com == 11 || com == 14)
		mult = 1;
	else
		mult = 2;
	while ((div /= 4) != 1)
	{
		extract = ocp / div;
		ocp -= extract * div;
		if ((extract) == 2)
			extract *= mult;
		else if (extract == 3)
			extract--;
		res += extract;
	}
	return (res);
}

int		put_champ_size(t_cdata **st)
{
	t_cdata	*comment;
	t_cdata	*champ;
	char	*nb;
	int		i;

	i = 0;
	comment = *st;
	while (comment->index != 2)
		comment = comment->next;
	champ = comment->next;
	while (i < CHAMP_MAX_SIZE && champ->str[i] != 0)
	{
		if (champ->str[i] == 9 || champ->str[i] == 12 || champ->str[i] == 15)
			i += 3;
		else if (champ->str[i] == 1)
			i += 5;
		else
			i += ocp_trad_size((int)champ->str[i], (int)champ->str[i + 1]);
	}
	champ->size = i;
	nb = ft_itoa(champ->size);
	i = 4;
	ft_itoo((comment)->str, nb, 4, &i);
	ft_strdel(&nb);
	return (1);
}

void	ocp_adder(unsigned char *ocp, int value)
{
	(*ocp) += (unsigned char)value;
	(*ocp) <<= 2;
}
