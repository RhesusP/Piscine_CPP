/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:23:00 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/01 12:42:25 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

/*
	• learnMateria(AMateria*)
		Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
		plus tard. Tout comme le Character, la MateriaSource peut contenir 4 Materias
		maximum. Ces dernières ne sont pas forcément uniques.
	• createMateria(std::string const &)
		Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédem-
		ment par la MateriaSource et dont le type est le même que celui passé en para-
		mètre. Retourne 0 si le type est inconnu.
		En bref, votre MateriaSource doit pouvoir apprendre des "modèles" de Materias
		afin de les recréer à volonté. Ainsi, vous serez capable de générer une nouvelle Materia à
		partir de son type sous forme de chaîne de caractères.
*/

class MateriaSource
{
	private:
		/* data */
	public:
		MateriaSource(/* args */);
		MateriaSource(MateriaSource const & m);
		~MateriaSource();
		MateriaSource& operator=(MateriaSource const & rhs);
};

#endif
