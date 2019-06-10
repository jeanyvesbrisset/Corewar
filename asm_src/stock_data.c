/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:55:14 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/10 15:59:37 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/op.h"

int     read_n_stock(char *file, t_stock **begin, t_data **start)
{
    int     fd;
    int     ret;
    char    *line;
    

    fd = open(file, R_ONLY);
    line = 0;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        stock_in_stock(begin, line);
        if (!(line_is_correct(line, start))
            return (0);
        ft_strdel(&line);
    }
    return (1);
}