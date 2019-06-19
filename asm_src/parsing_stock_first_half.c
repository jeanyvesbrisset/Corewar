/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stock_first_half.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:38:17 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/19 14:01:30 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	add_to_lab(t_label **lab, char **name, int proto)
{
	t_label	*current;
	t_label *new;

	current = *lab;
	if (*lab)
		while (current->next != *lab && ft_strcmp(current->name, *name) != 0)
			current = current->next;
	if (current && current->next != *lab)
		{
			if (current->next != *lab && current->proto < 0)
				current->proto = proto;
			return ;
		}
	if (!(new = (t_label*)malloc(sizeof(t_label) * 1)))
		return ;
	new->name = *name;
	new->proto = proto;
	new->used = 0;
	new->next = *lab;
	current->next = new;
}

int		gest_lab(t_label **lab, int	index, char **line, int *jump)
{
	int		i;
	char	*name;

	i = *jump;
	name = 0;
	while ((*line)[i] && (*line)[i] != ':')
		i++;
	if (i > 0 && (*line)[i] && (*line)[i - 1] != '%')
	{
		(*line)[i] = 0;
		if (*line + *jump == 0 || ft_charstr((*line) + *jump, LABEL_CHARS) == 0)
			return (0);
		name = ft_strdup((*line) + *jump);
		(*line)[i] = ':';
		add_to_lab(lab, &name, index);
		*jump = i + 1;
	}
	return (1);
}

int		stock_command(char **line, t_cdata **start, t_label **lab)
{
	int				i;
	int				size_name;
	static int		index;
	static t_op		tab[17];

	i = 0;
	tab = 0;
	init_op_tab(&tab);
	if (!(index))
		index = 0;
	while ((*line)[i] == '\t' || (*line)[i] == ' ')
		i++;
	if (!(gest_lab(lab, index, line, &i)))
		return (0);
	while ((*line)[i] == '\t' || (*line)[i] == ' ')
		i++;
	size_name = 0;
	while ((*line)[size_name + i] && (*line)[size_name + i] != ' ')
		size_name++;
	while (*op_tab && ft_strncmp((*op_tab)->name), *line + i, size_name)
}
	//reperer les LABEL_CHAR ':' -> si '%' avant c'est potentiellement un label parametre qu'on enregistre et on laisse un blanc dans la memoire, sinon si c'est le premier qu'on croise et qu'il est précédé par des LABEL_CHARS alors on enregistre le label et check si la suite est bien un opcode
	// ajouter un int pos a la struc label (ou direct utiliser le l'int proto) qui reperera le label quand i parcourera le str des command
	//compter le nombre de SEPARATOR_CHAR (',') pour connaitre le nombre de parametres - 1

int		is_comment(char **line, t_cdata **start, int *reader)
{
	int	i;

	i = 0;
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (ft_strncmp(*line + i, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) != 0)
		return (0);
	i += 5;
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (!((*line)[i]) || (*line)[i] != '"')
		return (0);
	i++;
	comment_stocker(line, &i, start, reader[1]);
	if (!((*line)[i]) && reader[1] == 1)
	{
		if (!(gnl_find_mod(line, start, reader, 'c')))
			return (0);
	}
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (!(line[i]))
		return (1);
	return (0);
}

int		is_name(char **line, t_cdata **start, int *reader)
{
	int	i;

	i = 0;
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (ft_strncmp(*line + i, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) != 0)
		return (0);
	i += 5;
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (!((*line)[i]) || (*line)[i] != '"')
		return (0);
	i++;
	name_stocker(line, &i, start, reader[1]);
	if (!((*line)[i]) && reader[1] == 1)
	{
		if (!(gnl_find_mod(line, start, reader, 'n')))
			return (0);
	}
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (!(line[i]))
		return (1);
	return (0);
}

void	init_cor(t_cdata **start)
{
	t_cdata	*comment;
	t_cdata	*command;

	if (!((*start) = (t_cdata*)malloc(sizeof(t_cdata) * 1)))
			return ;
	ft_bzero((*start)->str, 4 + PROG_NAME_LENGTH);
	(*start)->str[1] = 234;
	(*start)->str[2] = 131;
	(*start)->str[3] = 243;
	(*start)->size = 4 + PROG_NAME_LENGTH;
	(*start)->index = 1;
	if (!(comment = (t_cdata*)malloc(sizeof(t_cdata) * 1)))
		return ;
	ft_bzero(comment->str, 12 + COMMENT_LENGTH);
	comment->size = 12 + COMMENT_LENGTH;
	comment->index = 2;
	if (!(command = (t_cdata*)malloc(sizeof(t_cdata) * 1)))
			return ;
	ft_bzero(command->str, CHAMP_MAX_SIZE);
	command->size = CHAMP_MAX_SIZE;
	command->index = 3;
	(*start)->next = comment;
	comment->next = command;
	command->next = *start;
}

int		line_is_correct(char **line, t_cdata **sta, t_label **lab, int *reader)
{
	static int	step;

	if (!(*line))
		return (1);
	if (!(step))
	{
		step = 0;
		init_cor(sta);
	}
	if (step == 0 && is_name(line, sta, reader))
		step = 1;
	else if (step == 1 && is_comment(line, sta, reader, &step))
		step = 2;
	else if (step == 2 && stock_command(line, sta, lab))
		step = 2;
	else if ((*line)[0] != COMMENT_CHAR && (*line)[0] != ';')
	{
		ft_strdel(line);
		return (ft_error(""));
	}
	return (1);
}
