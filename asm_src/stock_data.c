/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:55:14 by floblanc          #+#    #+#             */
/*   Updated: 2019/07/04 18:01:54 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		last_line_good(t_stock **begin, int line_empty)
{
	t_stock	*cur;
	int		i;

	if (line_empty)
		return (1);
	i = 0;
	cur = (*begin)->next;
	while (cur && cur->next != (*begin))
		cur = cur->next;
	ft_jump_white_spaces(cur->str, &i);
	if (cur->str[i] && cur->str[i] != COMMENT_CHAR && cur->str[i] != ';')
		return (ft_error("Missing empty line at the end of the file\n"
		, 0, 0, 0));
	return (1);
}

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
	unsigned int	i;

	i = ft_strlen((*name));
	*name = realloc(*name, i + 3);
	(*name)[i + 2] = 0;
	(*name)[i + 1] = 'r';
	(*name)[i] = 'o';
	(*name)[i - 1] = 'c';
}

int		create_cor(t_cdata **start, char **name)
{
	t_cdata	*current;
	int		fd;

	while ((*start)->index != 1)
		*start = (*start)->next;
	name_cor(name);
	current = (*start);
	if ((fd = open((*name), O_WRONLY | O_TRUNC | O_APPEND | O_CREAT, 00755))
		== -1)
		return (0);
	while (current->next != *start)
	{
		write(fd, current->str, current->size);
		current = current->next;
	}
	if (current && current->next == *start)
		write(fd, current->str, current->size);
	ft_printf("Writing output program to %s\n", *name);
	return (0);
}

int		read_n_stock(char *file, t_stock **beg, t_cdata **start, t_label **lab)
{
	int			*reader;
	char		*line;
	static	int	line_empty = 0;

	if (!(reader = (int*)malloc(sizeof(int) * 2)))
		return (0);
	if ((reader[0] = open(file, O_RDONLY)) == -1)
		return (0);
	line = 0;
	while ((reader[1] = get_next_line_mod(reader[0], &line)) > 0)
	{
		line_empty = (reader[1] == 2 ? 0 : 1);
		stock_in_stock(beg, line, reader[1]);
		if (!(line_is_correct(&line, start, lab, reader)))
			return (ft_error("Error at line ", 0, (void**)&reader
			, stock_len(beg, start)));
		ft_strdel(&line);
	}
	free(reader);
	if (champ_exist(start) && last_line_good(beg, line_empty)
	&& all_label_good(start, lab))
		return (put_champ_size(start));
	return (0);
}
