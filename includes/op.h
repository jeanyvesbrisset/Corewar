/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:39:17 by maginist          #+#    #+#             */
/*   Updated: 2019/07/18 10:42:58 by floblanc         ###   ########.fr       */
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
# define MEM_SIZE			(64*1024)
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
	char			*name;
	int				(*f)(char *str, t_cdata **start, t_label **lab
		, int *index);
}					t_f;

typedef struct s_fvm
{
	unsigned char	op;
	//ajouter pointeur sur fonction
	
}				t_fvm;


typedef struct 		s_proces
{
	int				champ;//1, 2,3 ou 4
	int				proces_nb;//le combientieme process dont il est question
	int				r[16]; //16 registres par process, a mettre dans ce tableau
	int				carry;
	int				alive;//0 ou 1
	int				pc;
	struct s_proces	*next;
}					t_proces;

typedef	struct		s_champ
{
	int				pos;//1, 2, 3 ou 4
	int				tmp_n;
	int				size;
	unsigned char	*name;
	unsigned char	*comment;
	unsigned char	*bytecode;
	int				byte_start;
	struct s_champ	*next;
}					t_champ;

typedef	struct 		s_core
{
	int				flag_v; //0 ou 1
	int				flag_d; //-1 s'il n'y en a pas, sinon nombre de cycle
	int				champ_nb;
	int				sum_process;
	int				total_cycle;
	int				tmp_cycle;;
	int				cycle_to_die;
	int				nbr_live;
	t_champ			*champs; // trié par ordre inverse
	t_proces		*proces;  // trié au depart, par ordre inverse
	unsigned char	arena[MEM_SIZE];
}					t_core;


void				start_to_command(t_cdata **start);
void				gest_lab(t_label **lab, int index, char **line, int *jump);
int					read_n_stock(char *file, t_stock **begin, t_cdata **start
	, t_label **lab);
int					line_is_correct(char **line, t_cdata **start
	, t_label **lab, int *reader);
int					gnl_find_mod(char **line, t_cdata **start, int *reader
	, char c_or_n);
int					name_stocker(char **line, int *i, t_cdata **start, int ret);
int					comment_stocker(char **line, int *i, t_cdata **start
	, int ret);
int					ft_error(char *error, int ret, void **to_free, int line);
int					stock_len(t_stock **beg, t_cdata **start);
void				free_structs(t_stock **begin, t_cdata **start
	, t_label **lab);
int					create_cor(t_cdata **start, char **name);
int					is_register(char *str, int *i);
int					is_index(char *str, int *i, t_label **lab, int index);
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
int					put_champ_size(t_cdata **st);
int					champ_exist(t_cdata **start);
int					len_digit(char *str);
void				add_by_used(t_label **lab, char **str, t_label **new
	, t_label **current);

int					used_s_begin(t_cdata **st, int used);
int					verif_index(char *str, int **tab, t_cdata **start
	, t_label **lab);
int					verif_direct(char *str, int **tab, t_cdata **start
	, t_label **lab);
int					stock_len(t_stock **beg, t_cdata **start);
int					ocp_trad_size(int com, int ocp);
int					size_used_tab(int *tab);
int					add_used_label(char **str, t_label **lab, int index);
int					is_commentary(char *line);
void				check_s_name_len(char **line, int *s_name, int i);
int					write_the_magic(t_cdata **start, int nb);
int					parcing_args(int ac, char **av, t_core *core);
int					stock_champ(int ac, char **av, t_core *core);
int					is_dot_cor(char *av);

#endif
