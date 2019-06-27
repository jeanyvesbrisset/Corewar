/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:24:46 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/27 15:31:05 by maginist         ###   ########.fr       */
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

	res = 0;
	if (com == 10 || com == 11 || com == 14)
		mult = 1;
	else
		mult = 2;
	extract = ocp / 64;
	if (extract == 2)
		extract *= mult;
	res += extract;
	ocp -= extract * 64;
	extract = ocp / 16;
	if (extract == 2)
		extract *= mult;
	res += extract;
	ocp -= extract * 32;
	extract = ocp / 4;
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
	while (champ->str[i])
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
	nb = ft_itoa(i - 1);
	tmp = ft_memndup(champ->str, i);
	ft_itoo((comment)->str, nb, 4, &i);
	ft_memdel((void**)(&(champ->str)));
	champ->str = tmp;
}

void	ocp_adder(unsigned char *ocp, int value)
{
	*ocp += value;
	*ocp <<= 2;
}
