/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:21:15 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/01 14:23:16 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include <string>

/*
Le Character a un inventaire de 4 items, soit 4 Materias maximum. À la construction,
l’inventaire est vide. Les Materias sont équipées au premier emplacement vide trouvé, soit
dans l’ordre suivant : de l’emplacement 0 au 3. Dans le cas où on essaie d’ajouter une
Materia à un inventaire plein, ou d’utiliser/retirer une Materia qui n’existe pas, ne faites
rien (cela n’autorise pas les bugs pour autant). La fonction membre unequip() ne doit
PAS delete la Materia !

La fonction membre use(int, ICharacter&) utilisera la Materia de l’emplacement[idx],
et passera la cible en paramètre à la fonction AMateria::use.

Votre Character doit comporter un constructeur prenant son nom en paramètre.
Toute copie (avec le constructeur par recopie ou l’opérateur d’affectation) d’un Charac-
ter doit être profonde. Ainsi, lors d’une copie, les Materias du Character doivent être
delete avant que les nouvelles ne les remplacent dans l’inventaire. Bien évidemment, les
Materias doivent aussi être supprimées à la destruction d’un Character.
*/

class Character
{
	private:
		AMateria	*_inventory[4];
		std::string	_name;
	public:
		Character();
		Character(std::string name);
		Character(Character const & c);
		~Character();
		Character&	operator=(Character const & rhs);
};

#endif
