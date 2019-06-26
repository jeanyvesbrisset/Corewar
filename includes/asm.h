/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:38:38 by maginist          #+#    #+#             */
/*   Updated: 2019/06/26 13:44:12 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "op.h"

t_f		g_f_tab[] =
{
	{"live", &gest_live},
	{"ld", &gest_ld},
	{"st", &gest_st},
	{"add", &gest_add},
	{"sub", &gest_sub},
	{"and", &gest_and},
	{"or", &gest_or},
	{"xor", &gest_xor},
	{"zjmp", &gest_zjmp},
	{"ldi", &gest_ldi},
	{"sti", &gest_sti},
	{"fork", &gest_fork},
	{"lld", &gest_lld},
	{"lldi", &gest_lldi},
	{"lfork", &gest_lfork},
	{"aff", &gest_aff}
};

#endif