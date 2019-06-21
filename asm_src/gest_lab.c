/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_lab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:43:46 by floblanc          #+#    #+#             */
/*   Updated: 2019/06/21 16:10:17 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	start_to_command(t_cdata **start)
{
	while ((*start)->index != 3)
		*start = (*start)->next;
}

void	add_to_lab(t_label **lab, char **name, int proto)
{
	t_label	*current;
	t_label *new;

	current = *lab;
	if (*lab)
		while (current->next != *lab && ft_strcmp(current->name, *name) != 0)
			current = current->next;
	if (current && current->next != *lab)
	{
		if (current->next != *lab && current->proto < 0)
			current->proto = proto;
		return ;
	}
	if (!(new = (t_label*)malloc(sizeof(t_label) * 1)))
		return ;
	new->name = *name;
	new->proto = proto;
	if (!(new->used))
		new->used = 0;
	new->next = *lab;
	current->next = new;
}

int		gest_lab(t_label **lab, int index, char **line, int *jump)
{
	int		i;
	char	*name;

	i = *jump;
	name = 0;
	while ((*line)[i] && (*line)[i] != ':')
		i++;
	if (i > 0 && (*line)[i] && (*line)[i - 1] != '%')
	{
		(*line)[i] = 0;
		if (*line + *jump == 0 || ft_charstr((*line) + *jump, LABEL_CHARS) == 0)
			return (0);
		name = ft_strdup((*line) + *jump);
		(*line)[i] = ':';
		add_to_lab(lab, &name, index);
		*jump = i + 1;
	}
	return (1);
}
