/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:24:29 by maginist          #+#    #+#             */
/*   Updated: 2019/08/20 16:01:43 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	free_champ(t_champ *champ)
{
	if (!champ)
		return ;
	ft_memdel((void**)&(champ->name));
	ft_memdel((void**)&(champ->comment));
	ft_memdel((void**)&(champ->bytecode));
}

void	free_before(t_champ *before)
{
	before->next = 0;
	ft_strdel((char**)(&((before->name))));
	ft_strdel((char**)(&(before->bytecode)));
	ft_strdel((char**)(&(before->comment)));
	free(before);
	before = 0;
}

int		free_core(t_core *core)
{
	t_champ *current;
	t_champ	*before;

	if (!(core->champs) && !(core->proces))
	{
		free(core);
		return (0);
	}
	before = core->champs;
	current = before->next;
	core->champs = 0;
	before->next = 0;
	ft_strdel((char**)(&((before->name))));
	ft_strdel((char**)(&(before->bytecode)));
	ft_strdel((char**)(&(before->comment)));
	free(before);
	while (current)
	{
		before = current;
		current = current->next;
		free_before(before);
	}
	free(core);
	return (0);
}

int		ft_error(char *error, int ret, void **to_free, int line)
{
	char *nb;

	if (to_free && *to_free)
		free(*to_free);
	ft_putstr("\033[31m");
	write(2, error, ft_strlen(error));
	if (line > 0)
	{
		nb = ft_itoa(line);
		write(2, nb, ft_strlen(nb));
		write(2, "\n", 1);
		free(nb);
	}
	ft_putstr("\033[00m");
	return (ret);
}
