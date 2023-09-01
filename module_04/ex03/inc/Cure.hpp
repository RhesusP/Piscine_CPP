/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:20:25 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/01 12:54:30 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

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

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const & c);
		~Cure(void);
		Cure& operator=(Cure const & rhs);
		std::string const & getType() const;
		void use(ICharacter& target);
};

#endif
