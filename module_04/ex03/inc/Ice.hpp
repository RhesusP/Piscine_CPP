/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:17:36 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/01 12:35:35 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

/*
	Implémentez les Materias Ice (glace) et Cure (soin) sous forme de classes concrètes.
	Utilisez leur noms en minuscules ("ice" pour Ice, "cure" pour Cure) comme types. Bien
	sûr, leur fonction membre clone() retournera une nouvelle instance de même type (en
	clonant une Materia Ice, on obtient une autre Materia Ice).

	Pour ce qui est de la fonction membre use(ICharacter&), elle affichera :
	• Ice : "* shoots an ice bolt at <name> *"
	• Cure : "* heals <name>’s wounds *"
	<name> est le nom du Character (personnage) passé en paramètre. N’affichez pas les
	chevrons (< et >).
*/

class Ice
{
	private:
		/* data */
	public:
		Ice(/* args */);
		Ice(Ice const & i);
		~Ice();
		Ice& operator=(Ice const & rhs);
};

#endif
