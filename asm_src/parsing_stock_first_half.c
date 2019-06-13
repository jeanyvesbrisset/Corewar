/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stock_first_half.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:38:17 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/13 15:00:07 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void     is_comment(char **line, t_data **start, int *reader, int *step)
{
    int i;

    i = 0;
    while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
        i++;
    if (ft_strncmp(line + i, COMMENT_CMD_STRING, 8) != 0)
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
        if (!(gnl_find_mod(line, start, reader, "c")))
            return ;
    }
    while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
        i++;
    if (!(line[i]))
        *step = 1;
}

void     is_name(char **line, t_data **start, int *reader, int *step)
{
    int i;

    i = 0;
    while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
        i++;
    if (ft_strncmp(line + i, NAME_CMD_STRING, 5) != 0)
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
        if (!(gnl_find_mod(line, start, reader, "n")))
            return ;
    }
    while (((*line)[i] && (*line)[i] <= ' ') || (*line)[i] == 127)
        i++;
    if (!(line[i]))
        *step = 1;
}

void    init_cor(t_data **start)
{
    t_data  *comment;
    t_data  *command;

    if (!((*start) = (t_data*)malloc(sizeof(t_data) * 1)))
            return ;
    ft_bzero((*start)->str, 4 + PROG_NAME_LENGTH);
    (*start)->str[1] = 234;
    (*start)->str[2] = 131;
    (*start)->str[3] = 243;
    (*start)->size = 4 + PROG_NAME_LENGTH;
    (*start)->index = 1;
    if (!(comment = (t_data*)malloc(sizeof(t_data) * 1)))
        return ;
    ft_bzero(comment->str, 12 + COMMENT_LENGTH);
    comment->size = 12 + COMMENT_LENGTH;
    comment->index = 2;
    if (!(command = (t_data*)malloc(sizeof(t_data) * 1)))
            return ;
    ft_bzero(command->str, CHAMP_MAX_SIZE);
    command->size = CHAMP_MAX_SIZE;
    command->index = 3;
    (*start)->next = comment;
    comment->next = command;
    command->next = *start;
}

int     line_is_correct(char **line, t_data **start, t_label **lab, int *reader)
{
    static int step;

    if (!(*line))
        return (1);
    if (!(step))
    {
        step = 0;
        init_cor(start);
    }
    if (step == 0)
        is_name(line, start, reader, &step);
    else if (step == 1)
        is_comment(*line, start, reader, &step);
    else if (is_command(*line) && step == 2)
        stock_command(start, *line, lab);
    else if (line[0] != COMMENT_CHAR && line[0] != ';')
    {
        ft_strdel(line);
        return (ft_error(""));
    }
    return (1);
}