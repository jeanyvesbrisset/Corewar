/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:38:38 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/29 14:21:56 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"

//op , cycle_delay, param_nb, direct_size, function;

t_fvm		g_fvm_tab[] =
{
	{1, 0, 10, 1, 4, &vm_live},
	{2, 1, 5, 2, 4, &vm_ld},
	{3, 1, 5, 2, 4, &vm_st},
	{4, 1, 10, 3, 4,&vm_add},
	{5, 1, 10, 3, 4, &vm_sub},
	{6, 1, 6, 3, 4, &vm_and},
	{7, 1, 6, 3, 4, &vm_or},
	{8, 1, 6, 3, 4, &vm_xor},
	{9, 0, 20, 1, 2, &vm_zjmp},
	{10, 1, 25, 3, 2, &vm_ldi},
	{11, 1, 25, 3, 2, &vm_sti},
	{12, 0, 800, 1, 2, &vm_fork},
	{13, 1, 10, 2, 4, &vm_lld},
	{14, 1, 50, 3, 2, &vm_lldi},
	{15, 0, 1000, 1,  2, &vm_lfork},
	{16, 1, 2, 1, 4, &vm_aff}
};

#endif