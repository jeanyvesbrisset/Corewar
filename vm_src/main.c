/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:30:51 by maginist          #+#    #+#             */
/*   Updated: 2019/07/10 12:47:12 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int	ft_usage(char *str)
{

}

int main(int ac, char **av)
{
	if (ac < 2)
		return (ft_usage(av[0]));
	/*
			1) verifier les arguments (-dump nbr_cycles) (-n 1champ.cor 2champ.cor)
				* -d nbr_cycles copie la mémoire ecrite pendant le cycle demandé en arretant le programme et en l'affichant sur la sortie standart
				* -n est le flag d'affichage
				* mettre numéro d'entré de chaque champion affilié (ex pour <corewar zork.cor helltrain.cor bigzork.cor gagnant.cor> : zork = 1, helltrain = 2, bigzork = 3, gagnant = 4)
			2) lecture des 2 champions et stockage de leur nom, commentaire et code en hexa
				* utiliser gnl mode avec open(O_RDONLY)
				* verifier parcing du champion (taille nom, commentaire et champ)
				* stockage du/des champion(s) sur une liste chainée par champion(?)
				stocker taille bytecode pour faciliter la transition/copie
			3) tableau
				* allocation du tableau a MEM_SIZE
				* copie du programme des champions sur leur place memoire reservée par leur numéro d'entrée (identification)(pour 4, 16/champ || pour 2, 32/champ || pour 3, 21,5/champ )
			PC = debut de chaque instruction
			4) mise en place des différents cycles (delta, to_die, current cycle)
				* cycle delta decremente le cycle to die
				* structure contenant des variables pour le nbr de live par champion (de 2 a 4), les cycle to die, nombre de cycle depuis le debut, cycle a verifier
				* demarrer les processus des champions a CYCLE 0
				* initialisation du carry et des registres par champs, surement dans struct "champs"
				* 
			(si !affichage : introduire les champions, avec leur numero assignee, leur poids, leur nom, et leur commentaire)
			"And the winner is..."
			5) affichage avec ncurse(?)
			6) utilisation d'un process sur le premier bytecode de chaque champion
			7) detecter les "LIVE" et arret si gagnant
			8) gestion de sortie.
	*/
   return (0);           
}