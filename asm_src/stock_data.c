/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:55:14 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/13 16:54:16 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void    stock_in_stock(t_stock **begin, char *line, int ret)
{
    t_stock *new;
    t_stock *current;

    new = (t_stock*)malloc(sizeof(t_stock) * 1);
    if (ret == 1)
        new->str = ft_strjoin(line, "\n");
    else if (ret == 2)
        new->str = ft_strdup(line);
    if (!(*begin))
        *begin = new;
    else
    {
        current = *begin;
        while (current->next != *begin)
            current = current->next;
        current->next = new;
    }
    new->next = *begin;
}

void    name_cor(char **name)
{
    int     i;
    char    *tmp;

    i = 0;
    while ((*name)[i] && (*name)[i] != '.')
        i++;
    if (!(name[i]))
        i = 0;
    while ((*name)[i])
        (*name)[i++] = 0;
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
    if ((fd = open(name, O_WRONLY | O_TRUNC | O_APPEND | O_CREAT, 00755)) == -1)
        return (ft_error(OPEN_ERROR));
    while (current->next != start)
    {
        write(fd, current->str, current->size);
        current = current->next;
    }
    if (current && current->next == start)
        write(fd, current->str, current->size);
    ft_strdel(&name);
    return (0);
}

int     read_n_stock(char *file, t_stock **begin, t_data **start, t_label **lab)
{
    int     fd;
    int     *reader;
    char    *line;
    
    if (reader = (int*)malloc(sizeof(int) * 2))
        return (0);
    if (reader[0] = open(file, R_ONLY) == -1)
        return (ft_error("OPEN_ERROR"));
    line = 0;
    while ((reader[1] = get_next_line_mod(reader[0], &line)) > 0)
    {
        stock_in_stock(begin, line, reader[1]);
        if (!(line_is_correct(line, start, lab, reader))) // a faire
            return (free_reader(&reader));
        ft_strdel(&line);
    }
    free_reader(&reader);
    if (allabel_good(start, lab)) // a faire
        return (1);
    return (0);
}