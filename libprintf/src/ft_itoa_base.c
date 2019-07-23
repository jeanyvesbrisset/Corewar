/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:35:03 by maginist          #+#    #+#             */
/*   Updated: 2019/07/23 15:36:30 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

int		sizet(int nb, int base)
{
	int	size;

	size = 0;
	if ((base == 10 && nb <= 0) || nb == 0)
		size++;
	while (nb != 0)
	{
		nb /= base;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(int value, int base)
{
	int		neg;
	int		size;
	char	*str;
	char	*hex;

	hex = "0123456789ABCDEF";
	size = sizet(value, base);
	neg = 0;
	if (base == 10 && value < 0)
		neg = 1;
	if (!(str = (char *)malloc(sizeof(char) * size + 1 + neg)))
		return (0);
	if (neg)
		str[0] = '-';
	str[size--] = '\0';
	if (neg)
		neg = -1;
	else
		neg = 1;
	while (size >= 0 && str[size] != '-')
	{
		str[size--] = hex[(value % base) * neg];
		value /= base;
	}
	return (str);
}
