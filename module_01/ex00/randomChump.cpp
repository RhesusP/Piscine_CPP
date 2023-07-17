/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:13:32 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/05 12:22:04 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

void	randomChump(std::string name) {
	Zombie	z(name);
	std::cout << "Hi! I'm zombie" << name << std::endl;
}
