/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stock_first_half.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:38:17 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/18 17:26:32 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		gest_lab(t_label **lab, char *str, char **line, int jump)
{
	t_label		*current;
	int			i;

	i = 0;
	current = 0;
	while ((*line)[jump])
	{
		str[i] = (*line)[jump];
		if ((*line)[jump] == ':' && (*line)[jump - 1] != '%')
		{	
			str[i] = '\0';
			if (ft_charstr(str, LABEL_CHARS) == 0)
				return (0);
			if (!((current) = ft_strdup(str)))
				return (0);
			return (jump);
		}
		jump++;
		i++;
	}
	return (1);
}

void		stock_command(char **line, t_cdata **start, t_label **lab)
{
	int		i;
	char 	*str;
	int		diff;

	i = 0;
	str = 0;
	while ((*line)[i] == '\t' || (*line)[i] == ' ')
		i++;
	if ((diff = gest_lab(lab, str, line, i)) == 0)
		return ;
	if (diff > 1)
		i = diff;
	while ((*line)[i] == '\t' || (*line)[i] == ' ')
		i++;
	if ((*line)[i] == '\0')
		return ;
	
	
}
	//reperer les LABEL_CHAR ':' -> si '%' avant c'est potentiellement un label parametre qu'on enregistre et on laisse un blanc dans la memoire, sinon si c'est le premier qu'on croise et qu'il est précédé par des LABEL_CHARS alors on enregistre le label et check si la suite est bien un opcode
	// ajouter un int pos a la struc label (ou direct utiliser le l'int proto) qui reperera le label quand i parcourera le str des command
	//compter le nombre de SEPARATOR_CHAR (',') pour connaitre le nombre de parametres - 1

void	is_comment(char **line, t_cdata **start, int *reader, int *step)
{
	int	i;

	i = 0;
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (ft_strncmp(*line + i, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) != 0)
		return ;
	i += 5;
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (!((*line)[i]) || (*line)[i] != '"')
		return ;
	i++;
	comment_stocker(line, &i, start, reader[1]);
	if (!((*line)[i]) && reader[1] == 1)
	{
		if (!(gnl_find_mod(line, start, reader, 'c')))
			return ;
	}
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (!(line[i]))
		*step = 2;
}

void	is_name(char **line, t_cdata **start, int *reader, int *step)
{
	int	i;

	i = 0;
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (ft_strncmp(*line + i, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) != 0)
		return ;
	i += 5;
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (!((*line)[i]) || (*line)[i] != '"')
		return ;
	i++;
	name_stocker(line, &i, start, reader[1]);
	if (!((*line)[i]) && reader[1] == 1)
	{
		if (!(gnl_find_mod(line, start, reader, 'n')))
			return ;
	}
	while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
		i++;
	if (!(line[i]))
		*step = 1;
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
	if (step == 0)
		is_name(line, sta, reader, &step);
	else if (step == 1)
		is_comment(line, sta, reader, &step);
	else if (step == 2)
		stock_command(line, sta, lab);
	else if ((*line)[0] != COMMENT_CHAR && (*line)[0] != ';')
	{
		ft_strdel(line);
		return (ft_error(""));
	}
	return (1);
}
