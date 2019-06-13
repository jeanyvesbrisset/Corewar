/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stock_first_half.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:38:17 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/13 09:35:12 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int     is_name(char *line, int ret)
{
    int i;

    i = 0;
    while ((line[i] && line[i] <= ' ') || line[i] == 127)
        i++;
    if (ft_strncmp(line + i, ".name", 5) != 0)
        return (0);
    i += 5;
    while ((line[i] && line[i] <= ' ') || line[i] == 127)
        i++;
    if (!(line[i]) || line[i] != '"')
        return (0);
    while (line[i] && line[i] != '"')
        i++;
    if (!(line[i]) && ret == 1)
    {
        if (!(gnl_find_mod(line))
            return (0);
    }
    while ((line[i] && line[i] <= ' ') || line[i] == 127)
        i++;
    if (!(line[i])
        return (1);
    return (0);
}

int     line_is_correct(char **line, t_data **start, t_label **lab, int ret)
{
    static int step;

    if (!(*line))
        return (1);
    if (!(step)
        step = 0;
    if (is_name(*line, ret) && step == 0)
        stock_name(start, *line, &step);
    else if (is_comment(*line) && step == 1)
        stock_comment(start, *line, &step);
    else if (is_command(*line) && step == 2)
        stock_command(start, *line, lab);
    else if (line[0] != '#' && line[0] != ';')
    {
        ft_strdel(line);
        return (ft_error(""));
    }
    return (1);
}