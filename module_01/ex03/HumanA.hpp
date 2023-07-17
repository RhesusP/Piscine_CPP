/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:00:12 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/05 17:57:32 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
# define HUMAN_A_H

# include <iostream>
# include <string.h>
# include "./Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon&		_weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);
	void	attack(void);
};

#endif