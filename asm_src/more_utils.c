/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:24:46 by floblanc          #+#    #+#             */
/*   Updated: 2019/07/01 13:51:19 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		len_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int	ocp_trad_size(int com, int ocp)
{
	int		res;
	int		mult;
	int		extract;
	int		div;

	ft_printf("OCP = %d\n", ocp);
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
		ft_printf("res(%d) += extract(%d) -> %d\n", res - extract, extract, res);
	}
	ft_printf("res de l'ocp calc = %d\n", res);
	return (res);
}

void	put_champ_size(t_cdata **st)
{
	t_cdata			*comment;
	t_cdata 		*champ;
	char			*nb;
	int				i;

	i = 0;
	comment = *st;
	while (comment->index != 2)
		comment = comment->next;
	champ = comment->next;
	while (i < CHAMP_MAX_SIZE && champ->str[i] != 0)
	{
		if (champ->str[i] == 9 || champ->str[i] == 12  || champ->str[i] == 15)
			i += 3;
		else if (champ->str[i] == 1)
			i += 5;
		else
			i += ocp_trad_size((int)champ->str[i] , (int)champ->str[i + 1]);
		ft_printf("dans le calcul de la size i = %d et next commande = %d\n", i, champ->str[i]);
	}
	champ->size = i;
	ft_printf("champ size = %d\n", champ->size);
	nb = ft_itoa(champ->size);
	//ft_printf("nb = %s\n", nb);
	i = 4;
	ft_itoo((comment)->str, nb, 4, &i);
}

void	ocp_adder(unsigned char *ocp, int value)
{
//	ft_printf("LE OCP %d et value = %d\n", (int)(*ocp), value);
	(*ocp) += (unsigned char)value;
	(*ocp) <<= 2;
	ft_printf("LE OCP %d\n", (int)(*ocp));
}
