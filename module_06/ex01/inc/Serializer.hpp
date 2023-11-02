/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:28:53 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/02 16:02:10 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string.h>
# include <stdint.h>
# include "Data.hpp"

class Serializer {
	private:
		Serializer(Serializer const & s);
		Serializer&	operator=(Serializer const & s);
	public:
		Serializer(void);
		~Serializer(void);

		uintptr_t	serialize(Data*	ptr);
		Data*		deserialize(uintptr_t raw);
};

#endif
