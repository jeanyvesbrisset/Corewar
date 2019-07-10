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

int main(int ac, char **av)
{
	if (ac < 3)
		return (ft_usage(av));
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