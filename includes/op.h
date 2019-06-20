/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:39:17 by maginist          #+#    #+#             */
/*   Updated: 2019/06/20 14:42:43 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H
/*
 * ** Toutes les tailles sont en octets.
 * ** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
 * */

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


#define MAX_ARGS_NUMBER		4
#define MAX_PLAYERS			4
#define MEM_SIZE			(4*1024)
#define IDX_MOD				(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE		(MEM_SIZE / 6)

#define COMMENT_CHAR		'#'
#define LABEL_CHAR			':'
#define DIRECT_CHAR			'%'
#define SEPARATOR_CHAR		','

#define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING		".name"
#define COMMENT_CMD_STRING	".comment"

#define REG_NUMBER			16

#define CYCLE_TO_DIE		1536
#define CYCLE_DELTA			50
#define NBR_LIVE			21
#define MAX_CHECKS			10

/*
 * **
 * */


typedef char				t_arg_type;

#define T_REG				1
#define T_DIR				2
#define T_IND				4
#define T_LAB				8

/*
 * **
 * */

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3

typedef struct				s_header
{
	unsigned int			magic;
	char					prog_name[PROG_NAME_LENGTH + 1];
	unsigned int			prog_size;
	char					comment[COMMENT_LENGTH + 1];
}							t_header;

typedef struct				s_stock
{
	char 					*str;
	struct s_stock			*next;
}							t_stock;

typedef struct				s_cdata
{
	int						index;
	unsigned char			*str;
	unsigned int			size;
	struct s_cdata			*next;
}							t_cdata;

typedef struct				s_label
{
	char 					*name;
	unsigned int			proto;
	unsigned int			*used;
	struct s_label			*next;
}							t_label;

typedef struct				s_f
{
	int						(*f)(char *str, t_cdata **start, t_label **lab
	, int *index);
}							t_f;


typedef struct				s_op
{
	char					*name;
	int						nb_arg;
	int						args[3];
	int						index;
	int						cycles;
	char					*full_name;
	int						ocp;
	int						direct_sizer;
}							t_op;

int	read_n_stock(char *file, t_stock **begin, t_cdata **start, t_label **lab);
int	free_reader(int *reader);
int	line_is_correct(char **line, t_cdata **start ,t_label **lab, int *reader);
int	gnl_find_mod(char **line, t_cdata **start, int *reader, char c_or_n);
void	name_stocker(char **line, int *i, t_cdata **start, int ret);
void	comment_stocker(char **line, int *i, t_cdata **start, int ret);
int		ft_error(char *error);
void	free_structs(t_stock **begin, t_cdata **start, t_label **lab);
int		create_cor(t_cdata *start, char *name);
int		is_register(char *str, int *i);
int		is_index(char *str, int *i);
int		is_direct(char *str, int *i, t_label **lab, int index);
int		gest_live(char *str, t_cdata **start, t_label **lab, int *index);
int		gest_ld(char *str, t_cdata **start, t_label **lab, int *index);
int		gest_st(char *str, t_cdata **start, t_label **lab, int *index);
int		gest_add(char *str, t_cdata **start, t_label **lab, int *index);
int		gest_sub(char *str, t_cdata **start, t_label **lab, int *index);
int		gest_and(char *str, t_cdata **start, t_label **lab, int *index);
int		gest_or(char *str, t_cdata **start, t_label **lab, int *index);
int		gest_xor(char *str, t_cdata **start, t_label **lab, int *index);
int		gest_zjmp(char *str, t_cdata **start, t_label **lab, int *index);
int		gest_ldi(char *str, t_cdata **start, t_label **lab, int *index);
int		gest_sti(char *str, t_cdata **start, t_label **lab, int *index);
int		gest_fork(char *str, t_cdata **start, t_label **lab, int *index);
int		gest_lld(char *str, t_cdata **start, t_label **lab, int *index);
int		gest_lldi(char *str, t_cdata **start, t_label **lab, int *index);
int		gest_lfork(char *str, t_cdata **start, t_label **lab, int *index);
int		gest_aff(char *str, t_cdata **start, t_label **lab, int *index);

#endif