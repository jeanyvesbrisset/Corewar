/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:30:51 by maginist          #+#    #+#             */
/*   Updated: 2019/07/24 17:53:39 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int	ft_error(char *error, int ret, void **to_free, int line)
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

int		ft_otoi(unsigned char *nb_str, int size)
{//fonction pour recuperer une valeur stockee sur plusieurs octets
//pour le nb_str soit on lui envoie arena + <index du nombre sur la memoire>
// soit on lui envoie l'index a part dans les parametres mais il faudra faire "nb_str[pos + i++]" ligne  30
	int	i;
	int	res;
	int	div;

	div = 1;
	res = 0;
	i = size - 1;
	while (i-- > 0)
		div *= 256;
	while (++i < size)
	{
		res += ((int)(nb_str[i]) * div);
		div /= 256;
	}
	return (res);
}

void		create_player(char *file)
{
	(void)file;
	//enregistrer la position du joueur dans la structure
}

/*
**	Returns 0 if the parameters is written badly (.cor  player.cor.player player.cor.cor cor. ...)
*/

int		cycle_number(char *cycle)
{
	int cycle_nb;
	int i;

	i = 0;
	if (is_dot_cor(cycle))
	{
		cycle_nb = 0;
		ft_printf("il y a %d cycles\n", cycle_nb);
		return (1);
	}
	while (cycle[i])
	{
		if (!ft_isdigit(cycle[i]))
		{
			ft_printf("number of cycles badly written\n");
			return (0);
		}
		i++;
	}
	cycle_nb = ft_atoi(cycle);
	ft_printf("il y a %d cycles\n", cycle_nb);
	return (1);
	//verifier que le nombre de cycle est un entier, positif ou nul
	//mettre le flag dump a 1 dans la structure
	//mettre cycle_nb dans la structure
}

int		is_cycle(char *cycle)
{
	cycle_number(cycle); //fonction qui recupere le nombre de cycles apres le flag -d
	return (1);
}

int main(int ac, char **av)
{
	t_core *core;

	if (!(core = (t_core*)malloc(sizeof(t_core) *1)))
		return (0);
	core->flag_d = -1;
	core->flag_v = 0;
	core->champ_nb = 0;
	core->champs = 0;
	core->proces = 0;
	core->visu = 0;
	ft_printf("on commence\n");
	if (!(parcing_args(ac, av, core)))
		return (0);
	ft_printf("parcing good\n");
	if (!(stock_champ(ac, av, core)))
		return (0);
	ft_printf("all good\n");
	init_vm(core);
	if (core->flag_v)
		init_visual(core);
	return (1);
}