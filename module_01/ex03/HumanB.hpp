/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:00:59 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/05 18:03:40 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
# define HUMAN_B_H

# include <iostream>
# include <string.h>
# include "./Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon*		_weapon;
public:
	HumanB(std::string name);
	~HumanB();
	void	setWeapon(Weapon& weapon);
	void	attack(void);
};

#endif
