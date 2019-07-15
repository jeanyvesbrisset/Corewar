/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:30:51 by maginist          #+#    #+#             */
/*   Updated: 2019/07/10 14:16:21 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void		create_player(char *file)
{
	(void)file;
	//enregistrer la position du joueur dans la structure
}

/*
**	Returns 0 if the parameters is written badly (.cor  player.cor.player player.cor.cor cor. ...)
*/

int	is_dot_cor(char *av)
{
	if (ft_strnchr(av, '.') != 1)
		return (0);
	if (*av != '.' && !ft_strcmp(ft_strchr(av, '.'), ".cor"))
		return (1);
	return (0);
}

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

int	ft_usage(char **av)
{
	/*(faire un ft_Dprintf(gerer la sortie avec le fd?))*/
	write(2, "Not enougth arguments.\nUsage: ", 30);
	write(2, av[0], ft_strlen(av[0]));
	//ecrire les différents flags
	write(2, " <champion1.cor> <...>\n", 23);
	//ajouter usage pour flags choisi
	return (0);
}

void	player_order(char *order_nb)
{
	int	player_nb;

	player_nb = ft_atoi(order_nb);
}

int main(int ac, char **av)
{
	int i;
	
	i = 1;
	if (ac < 3) //faux, tu peux jouer tout seul, cest plutot if ac == 1, ft_usage
		return (ft_usage(av));
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-n"))
		{
			player_order(av[i + 1]);
			ft_printf("flag -n\n");
		}
		if (!ft_strcmp(av[i], "-d") && is_cycle(av[i + 1]))
		{
			ft_printf("flag -d\n");
		}	
		if (is_dot_cor(av[i]))
		{
			create_player(av[i]);
			//incementer dans la structure le flag players
			//si players > 4, renvoyer error
			ft_printf("le joueur %s a ete enregistre\n", av[i]);
		}
			

		//si flag n && flag d, alors ignore flag d
		//flag n marche nimporte quel endroit une fois mis apres l'exec
		//flag d est ignore si le nombre de cycles est negatif
		//si le nombre de cycle envoye est un float ? est ce qu'on fait une troncature ou un arrondi comme la vm du sujet ou on renvoie vers ft_usage ?
		// le nombre de cycles doit etre le prochain argumnt qui suit -d, sinon error
		// s;il y a plus d'un -d, ft usage
		// si -d nest pas suivi du nombre de cycle ? est-ce quon fait un ft_usage ou on considere que nb cycle = 0 et on display le programme
		i++;
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
   return (0);           
}