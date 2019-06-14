/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_find_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:37:00 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/14 10:53:47 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/op.h"

void   comment_stocker(char **line, int *i, t_data **start, int ret)
{
    static int     diff;

    if (!(diff))
        diff = 4 - (*i);
    while ((*line)[*i] && (*line)[*i] != '"')//limiter le nombre de caracteres a COMMENT_LENGTH : 2048
    {
        ((*start)->next)->str[diff + (*i)] = (*line)[*i];
        (*i)++;
    }
    if (ret == 1 && (!(*line)[*i]))
    {
        ((*start)->next)->str[diff + (*i)] = '\n';
        diff += (*i) + 1;
    }
    else
        diff += *i;
}

void    name_stocker(char **line, int *i, t_data **start, int ret)
{
    static int     diff;

    if (!(diff))
        diff = 4 - (*i);
    while ((*line)[*i] && (*line)[*i] != '"')//limiter le nombre de caracteres a PROG_NAME_LENGTH : 128
    {
        (*start)->str[diff + (*i)] = (*line)[*i];
        (*i)++;
    }
    if (ret == 1 && (!(*line)[*i]))
    {
        (*start)->str[diff + (*i)] = '\n';
        diff += (*i) + 1;
    }
    else
        diff += *i;
}

int     gnl_find_mod(char **line, t_data **start, int *reader, char c_or_n)
{
    int i;

    while ((reader[1] = get_next_line_mod(reader[0], line)) > 0)
    {
        i = 0;
        if (c_or_n == 'n')
            name_stocker(line, &i, start, reader[1]);
        else if (c_or_n == 'c')
            comment_stocker(line, &i, start, reader);
        if ((*line)[i] == '"')
            return (1);
        ft_strdel(line);
    }
    return (0);
}