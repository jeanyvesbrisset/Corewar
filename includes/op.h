/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:39:17 by maginist          #+#    #+#             */
/*   Updated: 2019/06/25 16:22:28 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libprintf/include/libprintf.h"
# define IND_SIZE			2
# define REG_SIZE			4
# define DIR_SIZE			REG_SIZE
# define REG_CODE			1
# define DIR_CODE			2
# define IND_CODE			3
# define MAX_ARGS_NUMBER	4
# define MAX_PLAYERS		4
# define MEM_SIZE			(4*1024)
# define IDX_MOD			(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)
# define COMMENT_CHAR		'#'
# define LABEL_CHAR			':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','
# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"
# define REG_NUMBER			16
# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		50
# define NBR_LIVE			21
# define MAX_CHECKS			10
# define T_REG				1
# define T_DIR				2
# define T_IND				4
# define T_LAB				8
# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3

typedef char		t_arg_type;

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_stock
{
	char			*str;
	struct s_stock	*next;
}					t_stock;

typedef struct		s_cdata
{
	int				index;
	unsigned char	*str;
	unsigned int	size;
	struct s_cdata	*next;
}					t_cdata;

typedef struct		s_label
{
	char			*name;
	int				proto;
	int				*used;
	struct s_label	*next;
}					t_label;

typedef struct		s_f
{
	int				(*f)(char *str, t_cdata **start, t_label **lab
		, int *index);
}					t_f;

typedef struct		s_op
{
	char			*name;
	int				nb_arg;
	int				args[3];
	int				index;
	int				cycles;
	char			*full_name;
	int				ocp;
	int				direct_sizer;
}					t_op;

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6
		, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25
	, "load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50
	, "long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

void				start_to_command(t_cdata **start);
int					gest_lab(t_label **lab, int index, char **line, int *jump);
int					read_n_stock(char *file, t_stock **begin, t_cdata **start
	, t_label **lab);
int					line_is_correct(char **line, t_cdata **start
	, t_label **lab, int *reader);
int					gnl_find_mod(char **line, t_cdata **start, int *reader
	, char c_or_n);
int					name_stocker(char **line, int *i, t_cdata **start, int ret);
int					comment_stocker(char **line, int *i, t_cdata **start
	, int ret);
int					ft_error(char *error);
void				free_structs(t_stock **begin, t_cdata **start
	, t_label **lab);
int					create_cor(t_cdata *start, char *name);
int					is_register(char *str, int *i);
int					is_index(char *str, int *i);
int					is_direct(char *str, int *i, t_label **lab, int index);
int					gest_live(char *str, t_cdata **start, t_label **lab
	, int *index);
int					gest_ld(char *str, t_cdata **start, t_label **lab
	, int *index);
int					gest_st(char *str, t_cdata **start, t_label **lab
	, int *index);
int					gest_add(char *str, t_cdata **start, t_label **lab
	, int *index);
int					gest_sub(char *str, t_cdata **start, t_label **lab
	, int *index);
int					gest_and(char *str, t_cdata **start, t_label **lab
	, int *index);
int					gest_or(char *str, t_cdata **start, t_label **lab
	, int *index);
int					gest_xor(char *str, t_cdata **start, t_label **lab
	, int *index);
int					gest_zjmp(char *str, t_cdata **start, t_label **lab
	, int *index);
int					gest_ldi(char *str, t_cdata **start, t_label **lab
	, int *index);
int					gest_sti(char *str, t_cdata **start, t_label **lab
	, int *index);
int					gest_fork(char *str, t_cdata **start, t_label **lab
	, int *index);
int					gest_lld(char *str, t_cdata **start, t_label **lab
	, int *index);
int					gest_lldi(char *str, t_cdata **start, t_label **lab
	, int *index);
int					gest_lfork(char *str, t_cdata **start, t_label **lab
	, int *index);
int					gest_aff(char *str, t_cdata **start, t_label **lab
	, int *index);
int					fct_separator(char *str, int nb_sep, int *index, int ocp);
int					end_gestion(char *str, int *i);
int					ft_good_transi(char *str, int *i);
int					ft_three_choices(char *str, int **tab, t_cdata **start
	, t_label **lab);
int					ft_itoo(unsigned char *str, char *str_nb
	, unsigned long long int size, int *index);
void				add_to_lab(t_label **lab, char **name, int proto);
int					ft_two_choices(char *str, int **tab, t_cdata **start
	, t_label **lab);
int					all_label_good(t_cdata **start, t_label **lab);
void				ocp_adder(unsigned char *ocp, int value);


t_f		g_f_tab[] =
{
	{gest_live},
	{gest_ld},
	{gest_st},
	{gest_add},
	{gest_sub},
	{gest_and},
	{gest_or},
	{gest_xor},
	{gest_zjmp},
	{gest_ldi},
	{gest_sti},
	{gest_fork},
	{gest_lld},
	{gest_lldi},
	{gest_lfork},
	{gest_aff},
	{0}
};

#endif
