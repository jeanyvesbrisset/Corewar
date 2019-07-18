/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:38:38 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/18 10:42:58 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"

t_fvm		g_fvm_tab[] =
{
	{1, &vm_live},
	{2, &vm_ld},
	{3, &vm_st},
	{4, &vm_add},
	{5, &vm_sub},
	{6, &vm_and},
	{7, &vm_or},
	{8, &vm_xor},
	{9, &vm_zjmp},
	{10, &vm_ldi},
	{11, &vm_sti},
	{12, &vm_fork},
	{13, &vm_lld},
	{14, &vm_lldi},
	{15, &vm_lfork},
	{16, &gest_aff}
};

#endif