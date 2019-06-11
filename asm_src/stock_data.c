/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:55:14 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/11 21:54:30 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/op.h"

void    name_cor(char **name)
{
    int     i;
    char    *tmp;

    i = 0;
    while ((*name)[i] && (*name)[i] != '.')
        i++;
    if ((*name)[i])
    {
        while ((*name)[i])
            (*name)[i++] = 0;
    }
    tmp = ft_strjoin(*name, ".cor");
    ft_strdel(name);
    name = &tmp;
}

int    create_cor(t_data *start, char *name)
{
    t_data  *current;
    int     fd;

    current = start;
    name_cor(&name);
    if (fd = open(name, O_WRONLY | O_TRUNC | O_APPEND | O_CREAT, 00755)) == -1))
        return (ft_error(OPEN_ERROR));
    while (current->next != start)
    {
        write(fd, current->str, current->size);
        current = current->next
    }
    if (current && current->next == start)
        write(fd, current->str, current->size);
    return (0);
}

int     read_n_stock(char *file, t_stock **begin, t_data **start, t_label **lab)
{
    int     fd;
    int     ret;
    char    *line;
    

    if (fd = open(file, R_ONLY) == -1)
        return (ft_error(OPEN_ERROR)); // a faire (rapide en theorie)
    line = 0;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        stock_in_stock(begin, line); // a faire
        if (!(line_is_correct(line, start)) // a faire
            return (0);
        ft_strdel(&line);
    }
    if (allabel_good(start, lab)) // a faire
        return (1);
    return (0);
}