/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_champs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:52:24 by maginist          #+#    #+#             */
/*   Updated: 2019/08/20 16:47:46 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		read_champ2(t_champ *champ, int fd)
{
	int				ret;
	unsigned char	str[4];

	if ((ret = read(fd, champ->comment, COMMENT_LENGTH)) != COMMENT_LENGTH)
		return (0);
	if (!(champ->bytecode = (unsigned char*)malloc(champ->size)))
		return (0);
	if ((ret = read(fd, str, 4) != 4))
		return (0);
	if ((ret = read(fd, champ->bytecode, champ->size)) != champ->size)
		return (ft_error("Champion is too big (682 bytes max)\n", 0, 0, 0));
	if (champ->size == CHAMP_MAX_SIZE && (ret = read(fd, str, 4)) > 0)
		return (ft_error("Champion is too big (682 bytes max)\n", 0, 0, 0));
	return (1);
}

int		read_champ(t_champ *champ, char *file)
{
	int				fd;
	int				ret;
	unsigned char	str[4];

	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	if ((ret = read(fd, str, 4)) != 4)
		return (0);
	if (ft_otoi(str, 0, 4) != COREWAR_EXEC_MAGIC)
		return (ft_error("Not the right magic number\n", 0, 0, 0));
	if (!(champ->name = (unsigned char*)malloc(PROG_NAME_LENGTH)))
		return (0);
	if ((ret = read(fd, champ->name, PROG_NAME_LENGTH)) != PROG_NAME_LENGTH)
		return (ft_error("Name lenght is too big, max 128\n", 0, 0, 0));
	if ((ret = read(fd, str, 4)) != 4)
		return (0);
	if ((ret = read(fd, str, 4)) != 4)
		return (0);
	if ((champ->size = ft_otoi(str, 0, 4)) > CHAMP_MAX_SIZE)
		return (ft_error("Champion is too big (682 bytes max)\n", 0, 0, 0));
	if (!(champ->comment = (unsigned char*)malloc(COMMENT_LENGTH)))
		return (0);
	return (read_champ2(champ, fd));
}

int		add_champ_list(t_core *core, t_champ **champ, char *file)
{
	t_champ	*current;

	current = core->champs;
	(*champ)->name = 0;
	(*champ)->comment = 0;
	(*champ)->bytecode = 0;
	if (!(read_champ(*champ, file)))
		return (0);
	if ((*champ)->tmp_n != 0 && (*champ)->tmp_n > core->champ_nb)
		return (0);
	while (current && current->pos != (*champ)->pos)
		current = current->next;
	if (current)
		if (current->tmp_n != 0 && (*champ)->tmp_n != 0)
			return (0);
	(*champ)->last_live = 0;
	(*champ)->process_live = 0;
	(*champ)->live_by_ctd = 0;
	(*champ)->next = core->champs;
	core->champs = *champ;
	return (1);
}

int		init_champ(t_core *core, char **av, int *i, int n)
{
	t_champ		*n_champ;
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
	{
		n_champ->pos = champ_order;
		n_champ->tmp_n = 0;
	}
	if (!(add_champ_list(core, &n_champ, av[*i])))
	{
		free_champ(n_champ);
		return (ft_error("invalid input for champion\n", 0
		, (void**)&n_champ, 0));
	}
	return (1);
}

int		stock_champ(int ac, char **av, t_core *core)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (is_dot_cor(av[i]))
		{
			if (!(init_champ(core, av, &i, 0)))
				return (0);
		}
		else if (!(ft_strcmp(av[i], "-n")))
		{
			if (!(init_champ(core, av, &i, ft_atoi(av[i + 1]))))
				return (0);
		}
	}
	ajust_champ_pos(core);
	sort_champ_list(&(core->champs), core);
	i = 0;
	while (++i <= core->champ_nb)
		if (!(init_process(&(core->proces), i, 0
			, &(core->sum_process))))
			return (0);
	return (1);
}
