/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:55:14 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/27 15:31:38 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	stock_in_stock(t_stock **begin, char *line, int ret)
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

void	name_cor(char **name)
{
	int		i;
	char	*tmp;

	i = ft_strlen((*name)) - 1;
	while ((*name)[i] && (*name)[i] != '.')
		i--;
	if (i >= 0 && (*name)[i + 1]  && (*name)[i + 1] != '/')
		(*name)[i] = 0;	
	tmp = ft_strjoin(*name, ".cor");
	//ft_strdel(name);
	*name = tmp;
	ft_printf("name = %s\n", *name);
}

int		create_cor(t_cdata **start, char *name)
{
	ft_printf("coucou\n");
	t_cdata	*current;
	int		fd;

	while ((*start)->index != 1)
		*start = (*start)->next;
	name_cor(&name);
	current = (*start);
	if ((fd = open(name, O_WRONLY | O_TRUNC | O_APPEND | O_CREAT, 00755)) == -1)
		return (ft_error("OPEN_ERROR2"));
	while (current->next != *start)
	{
		write(fd, current->str, current->size);
		current = current->next;
	}
	if (current && current->next == *start)
		write(fd, current->str, current->size);
//	ft_strdel(&name);
	ft_printf("Writing output program to %s\n", name);
	return (0);
}

int		read_n_stock(char *file, t_stock **beg, t_cdata **start, t_label **lab)
{
	int		*reader;
	char	*line;

	if (!(reader = (int*)malloc(sizeof(int) * 2)))
		return (0);
	if ((reader[0] = open(file, O_RDONLY)) == -1)
		return (ft_error("OPEN_ERROR1"));
	line = 0;
	while ((reader[1] = get_next_line_mod(reader[0], &line)) > 0)
	{
		stock_in_stock(beg, line, reader[1]);
		if (!(line_is_correct(&line, start, lab, reader)))
		{
			free(reader);
			return (ft_error("PROBLEM ON LINE"));
		}
		ft_strdel(&line);
	}
	free(reader);
	if (all_label_good(start, lab))
	{
		ft_printf("YEEEEEES!\n");
		put_champ_size(start);
		return (1);
	}
	return (ft_error("bite\n"));
}
