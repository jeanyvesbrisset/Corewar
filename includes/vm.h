/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:38:38 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/07/16 17:03:22 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"

t_fvm		g_fvm_tab[] =
{
	{"0x01", &vm_live},
	{"0x02", &vm_ld},
	{"0x03", &vm_st},
	{"0x04", &vm_add},
	{"0x05", &vm_sub},
	{"0x06", &vm_and},
	{"0x07", &vm_or},
	{"0x08", &vm_xor},
	{"0x09", &vm_zjmp},
	{"0x0a", &vm_ldi},
	{"0x0b", &vm_sti},
	{"0x0c", &vm_fork},
	{"0x0d", &vm_lld},
	{"0x0e", &vm_lldi},
	{"0x0f", &vm_lfork},
	{"0x10", &vm_aff}
};

#endif