/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_find_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:37:00 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/13 12:29:14 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/op.h"

int     gnl_find_mod(char **line, t_data **start)
{
    int i;
    t_data  *current;
    t_data  *new;

    i = 3;
    while (line[++i - 4])
        (*start)->str[i] = line[i - 4];
    (*start)->str[i++] = '\n';
    ft_strdel(line);
    while ((ret = get_next_line_mod(fd, line)) > 0)
    {
        i = 0;
        while ((*line)[i])
        {
            if (line[i] == '"')
                return (1);
            i++;
        }
        ft_strdel(line);
    }
    return (0);
}