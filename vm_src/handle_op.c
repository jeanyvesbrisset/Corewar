/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:20:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/29 11:40:30 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO : IL FAUT DELETE CA
#include "../includes/op.h"

void	vm_live(char *op, t_core *core)
{
	if (!ft_strcmp(0x01, op) && ft_strlen())
	ft_printf("un processus dit que le joueur %d(%s) est en vie\n"
		, core->champs->pos, core->champs->name);
}