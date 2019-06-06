/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <maginist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:09:38 by maginist          #+#    #+#             */
/*   Updated: 2019/05/31 16:43:44 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int	main()
{
	read_champ()
	parcing :
		lire le champion
			utiliser un read sur le bon fd:
			regarder si le nom du champion est bien "blablablabla.s"

		verifier que le champion est pas ecrit comme de la merde:
			si y'a des espaces et des tabs entre le .name et le debut, dans le .name
			, entre le .name et le .comment, etc
			si les commandes existent
		garder les commandes quelque par pour pouvoir les traduire en hexa
		utiliser les valeurs du .h
}
