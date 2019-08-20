/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:38:38 by maginist          #+#    #+#             */
/*   Updated: 2019/08/20 14:57:14 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "op.h"

t_f		g_f_tab[] =
{
	{"live", &gest_live, 5},
	{"ld", &gest_ld, 5},
	{"st", &gest_st, 5},
	{"add", &gest_add, 5},
	{"sub", &gest_sub, 5},
	{"and", &gest_and, 5},
	{"or", &gest_or, 5},
	{"xor", &gest_xor, 5},
	{"zjmp", &gest_zjmp, 4},
	{"ldi", &gest_ldi, 5},
	{"sti", &gest_sti, 5},
	{"fork", &gest_fork, 3},
	{"lld", &gest_lld, 5},
	{"lldi", &gest_lldi, 5},
	{"lfork", &gest_lfork, 3},
	{"aff", &gest_aff, 3}
};

#endif