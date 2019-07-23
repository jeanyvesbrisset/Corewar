/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:30:51 by maginist          #+#    #+#             */
/*   Updated: 2019/07/23 17:34:37 by maginist         ###   ########.fr       */
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
		ft_printf("res (%d) += nb_str[%d] (%d) * div (%d)((%d))\n", res, i, (int)(nb_str[i]), div, div * (int)nb_str[i]);
		res += ((int)(nb_str[i]) * div);
		div /= 256;
		ft_printf("pouet\n");
	}
	ft_printf("res = %d, COREWAR = %d\n", res, COREWAR_EXEC_MAGIC);
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
	int	i = 0;

	if (ac > 2)
	{
		initscr();
		mvprintw(5, 159, "COREWAR");
		WINDOW * win = newwin(66, 195, 7, 30);
		WINDOW * win2 = newwin(66, 100, 7, 226);
		refresh();
		box(win, 0, 0);
		mvvline(7, 225, 0, 66);
		box(win2, 0, 0);
		curs_set(0);
		while (i < 12288)
		{
			mvwprintw(win, 1 + (i / 192), 2 + (i % 192), "00");
			mvwprintw(win, 1 + (i / 192), 4 + (i % 192) , " ");
			i += 3;
		}
		wrefresh(win);
		wrefresh(win2);
		getch();
		endwin();
	}	
	if (!(core = (t_core*)malloc(sizeof(t_core) *1)))
		return (0);
	core->flag_d = -1;
	core->flag_v = 0;
	core->champ_nb = 0;
	core->champs = 0;
	core->proces = 0;
	ft_printf("on commence\n");
	if (!(parcing_args(ac, av, core)))
		return (0);
	ft_printf("parcing good\n");
	if (!(stock_champ(ac, av, core)))
		return (0);
	ft_printf("all good\n");
	return (1);
}
	/*
			1) verifier les arguments (-dump nbr_cycles) (-n) champ.cor champ.cor
				* -d nbr_cycles copie la mémoire ecrite pendant le cycle demandé en arretant le programme et en l'affichant sur la sortie standart
				* -n est le flag d'affichage
				* mettre numéro d'entré de chaque champion affilié (ex pour <corewar zork.cor helltrain.cor bigzork.cor gagnant.cor> : zork = 1, helltrain = 2, bigzork = 3, gagnant = 4)
			2) lecture des 2 champions et stockage de leur nom, commentaire et code en hexa
				* utiliser gnl mode avec open(O_RDONLY)
				* verifier parcing du champion (taille nom, commentaire et champ)
				* stockage du/des champion(s) sur une liste chainée par champion(?)
				stocker taille bytecode pour faciliter la transition/copie
			3) tableau de char
				* allocation du tableau a MEM_SIZE
				* copie du bytecode des champions sur leur place memoire reservée par leur numéro d'entrée (identification)(diviser MEM_SIZE par 4, 3 ou 2 en fonction du nombre de champ)
			PC = debut de chaque instruction(equivalent au process?)
			4) mise en place des différents cycles (delta, to_die, current cycle)
				* cycle delta decremente le cycle to die
				* structure contenant des variables pour le nbr de live par champion (de 2 a 4), les cycle to die, nombre de cycle depuis le debut, cycle a verifier
				* demarrer les processus des champions a CYCLE 0
				* utilisation d'un process sur le premier bytecode de chaque champion
				* initialisation du carry et des registres par champs, surement dans struct "champs"
				* process dans une liste chainée pour chaque champions, index qui lance les instructions(a verifier), demarre sur la tete du bytecode
			(si !affichage : introduire les champions, avec leur numero assignee, leur poids, leur nom, et leur commentaire)
			5) affichage avec ncurse(?)
			6) 
			7) detecter les "LIVE" et arret si gagnant
			8) gestion de sortie(free et gestion erreur).
	*/
