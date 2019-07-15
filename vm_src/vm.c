/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/15 16:37:09 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	init_vm(t_core *core)
{
	
	while (core->champ)
	{
		ft_bzero(core->champ->r, 16);
		core->champ->r[0] = 
		core->champ = core->champ->next;
	}
	ft_bzero(core->arena, MEM_SIZE);

}