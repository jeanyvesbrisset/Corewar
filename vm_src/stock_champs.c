/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_champs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:52:24 by maginist          #+#    #+#             */
/*   Updated: 2019/07/16 18:03:37 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		pos_in_list(t_core *core, t_champ *to_find)
{
	t_champ	*current;
	int		pos;

	pos = core->champ_nb;
	current = core->champs;
	while (current && current != to_find)
	{
		current = current->next;
		pos--;
	}
	return (pos);
}

void	ajust_champ_pos2(t_core *core)
{
	t_champ	*slow;
	t_champ	*current;
	int		tmp;

	slow = core->champs;
	current = slow->next;
	while (slow->next)
	{	
		current = slow->next;
		while (current)
		{
			if (!(slow->tmp_n) && !(current->tmp_n)
			&& slow->pos < current->pos)
			{
				tmp = slow->pos;
				slow->pos = current->pos;
				current->pos = tmp;
				slow = core->champs;
				current = slow;
			}
			current = current->next;
		}
		slow = slow->next;
	}
}

void	ajust_champ_pos(t_core *core)
{
	t_champ	*slow;
	t_champ	*current;

	slow = core->champs;
	current = slow->next;
	while (slow->next)
	{	
		current = slow->next;
		while (current)
		{
			if (current->pos == slow->pos)
			{
				if (current->tmp_n != 0)
					slow->pos = pos_in_list(core, current);
				else if (slow->tmp_n != 0)
					current->pos = pos_in_list(core, slow);
				slow = core->champs;
				current = slow;
			}
			current = current->next;
		}
		slow = slow->next;
	}
	ajust_champ_pos2(core);
}

void	sort_champ_list(t_champ **champ, int champ_n)
{
	t_champ *current;
	t_champ *before;
	t_champ *after;

	current = *champ;
	after = current->next;
	while (after)
	{
		if (current->pos < after->pos)
		{
			if (before)
				before->next = after;
			current->next = after->next;
			after->next = current;
			current = *champ;
			after = current->next;
			before = 0;
		}
		else
		{
			before = current;
			current = after;
			after = after->next;
		}
	}
}

int		init_process(t_proces **proce, int champ_nb, int pc, int *sum_process)
{	
	t_proces	*pro;
	int			i;

	if (!(pro = (t_proces*)malloc(sizeof(t_proces) * 1)))
		return (0);
	(*sum_process)++;
	pro->champ = champ_nb;
	pro->proces_nb = champ_nb;
	pro->carry = 0;
	i = 0;
	while (i < 16)
		pro->r[i++] = 0;
	pro->r[0] = pro->champ;
	pro->next = *proce;
	*proce = pro;
	return (1);
}

int		read_champ2(t_champ *champ, int fd)
{
	int ret;
	unsigned char str[4];
	
	if ((ret = read(fd, champ->comment, COMMENT_LENGTH)) != COMMENT_LENGTH)
		return (0);
	if (!(champ->bytecode = (unsigned char*)malloc(champ->size)))
		return (0);
	if ((ret = read(fd, champ->bytecode, champ->size)) != champ->size)
		return (0);
	if (champ->size == CHAMP_MAX_SIZE && (ret = read(fd, str, 4)) != -1)
		return (0);
	return (1);
}

int		read_champ(t_champ *champ)
{
	int	fd;
	int	ret;
	unsigned char str[4];
	
	if ((fd = open(champ->name, O_RDONLY)) == -1)
		return (0);
	if ((ret = read(fd, str, 4)) != 4)
		return (0);
	if (ft_atoi(str) != COREWAR_EXEC_MAGIC)
		return (0);
	if (!(champ->name = (unsigned char*)malloc(PROG_NAME_LENGTH)))
		return (0);
	if ((ret = read(fd, champ->name, PROG_NAME_LENGTH)) != PROG_NAME_LENGTH)
		return (0);
	if ((ret = read(fd, str, 4)) != 4)
		return (0);
	if ((ret = read(fd, str, 4)) != 4)
		return (0);
	if ((champ->size = ft_atoi((char*)str)) > CHAMP_MAX_SIZE)
		return (0);
	if (!(champ->comment = (unsigned char*)malloc(COMMENT_LENGTH)))
		return (0);
	return (read_champ2(champ, fd));
}

int		add_champ_list(t_core *core, t_champ **champ)
{
	t_champ	*current;

	current = core->champs;
	if (!(read_champ(*champ)))
		return (0);
	while (current && current->pos != (*champ)->pos)
		current = current->next;
	if (current)
		if (current->tmp_n != 0 && (*champ)->tmp_n != 0)
			return (0);
	(*champ)->next = core->champs;
	core->champs = *champ;
	return (1);
}

int		init_champ(t_core *core, char *name, int *i, int n)
{
	t_champ 	*n_champ;
	static int	champ_order = 0;

	champ_order++;
	if (!(n_champ = (t_champ*)malloc(sizeof(t_core) * 1)))
		return (0);
	if (n > 0)
	{
		n_champ->pos = n;
		n_champ->tmp_n = n;
		*i += 2;
	}
	else
		n_champ->pos = champ_order;
	if (!(add_champ_list(core, &n_champ)))
		return (0);
	return (1);
}

int		stock_champ(int ac, char **av, t_core *core)
{
	int	i;

	i = 0;
	while(++i < ac)
	{
		if (is_dot_cor(av[i]))
		{
			if (!(init_champ(core, av[i], &i, 0)))
				return (0);
		}
		else if ((ft_strcmp(av[i], "-n")))
		{
			if (!(init_champ(core, av[i], &i, ft_atoi(av[i + 1]))))
				return (0);
		}
	}
	ajust_champ_pos(core);
	sort_champ_list(&(core->champs), core->champ_nb);
	i = 0;
	while (++i <= core->champ_nb)
		if (!(init_process(&(core->proces), i, 0
		, &(core->sum_process))))
			return (0);
	return (1);
}