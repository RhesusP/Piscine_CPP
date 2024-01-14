/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:13:58 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/14 17:26:38 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
#define RNP_HPP

#include <iostream>
#include <stack>

class RNP
{
private:
	std::stack<float> _stack;

public:
	RNP(void);
	RNP(RNP const &r);
	RNP &operator=(RNP const &rhs);
	~RNP(void);
};

#endif