/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:24:46 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/28 10:15:35 by floblanc         ###   ########.fr       */
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

	ft_printf("OCP = %d\n", ocp);
	res = 0;
	if (com == 10 || com == 11 || com == 14)
		mult = 1;
	else
		mult = 2;
	extract = ocp / 64;
	ft_printf("extract = %d\n", extract);
	if (extract == 2)
		extract *= mult;
	res += extract;
	ocp -= extract * 64;
	extract = ocp / 16;
	ft_printf("extract = %d\n", extract);
	if (extract == 2)
		extract *= mult;
	res += extract;
	ocp -= extract * 16;
	extract = ocp / 4;
	ft_printf("extract = %d\n", extract);
	if (extract == 2)
		extract *= mult;
	res += extract;
	return (res);
}

void	put_champ_size(t_cdata **st)
{
	t_cdata			*comment;
	t_cdata 		*champ;
	char			*nb;
	int				i;
	unsigned char	*tmp;

	i = 0;
	comment = *st;
	while (comment->index != 2)
		comment = comment->next;
	champ = comment->next;
	while (i < CHAMP_MAX_SIZE && champ->str[i] != 0)
	{
		if ((*st)->str[i] == 9 || (*st)->str[i] == 12  || (*st)->str[i] == 15)
			i += 3;
		else if ((*st)->str[i] == 1)
			i += 5;
		else
			i += ocp_trad_size((int)(*st)->str[i] , (int)(*st)->str[i + 1]);
	}
	champ->size = i;
	ft_printf("champ size = %d\n", champ->size);
	nb = ft_itoa(champ->size);
	ft_printf("nb = %s\n", nb);
	tmp = ft_memndup(champ->str, i);
	ft_itoo((comment)->str + 4, nb, 4, &i);
	ft_memdel((void**)(&(champ->str)));
	champ->str = tmp;
}

void	ocp_adder(unsigned char *ocp, int value)
{
	ft_printf("LE OCP %d et value = %d\n", (int)(*ocp), value);
	(*ocp) += (unsigned char)value;
	(*ocp) <<= 2;
	ft_printf("LE OCP %d\n", (int)(*ocp));
}
