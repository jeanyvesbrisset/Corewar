/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:30:51 by maginist          #+#    #+#             */
/*   Updated: 2019/07/09 16:10:43 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int main(int ac, char **av)
{
	/*
			1) verifier les arguments (-dump nbr_cycles) (-n 1champ.cor 2champ.cor)
				* -d nbr_cycles copie la mémoire ecrite pendant le cycle demandé en arretant le programme et en l'affichant sur la sortie standart
				* -n est le flag d'affichage
				* mettre numéro d'entré de chaque champion affilié (ex pour <corewar zork.cor helltrain.cor bigzork.cor gagnant.cor> : zork = 1, helltrain = 2, bigzork = 3, gagnant = 4)
			2) lecture des 2 champions et stockage de leur nom, commentaire et code en hexa
				* utiliser gnl mode avec open(ONLY_READ)
				* verifier parcing du champion (taille nom, commentaire et champ)
				* stockage du/des champion(s) sur une liste chainée par champion(?)
			3) tableau
				* allocation du tableau a MEM_SIZE
				* copie du programme des champions sur leur place memoire reservée par leur numéro d'entrée
			4) mise en place des différents cycles (delta, to_die, current cycle)
				* demarrer les processus des champions a CYCLE 0
			5) affichage (?)
			6) utilisation des process des champions
			7) detecter les "LIVE" et arret si fini
			8) gestion de sortie.
	*/
   return (0);           
}