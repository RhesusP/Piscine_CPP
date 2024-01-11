/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:39:09 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/29 13:51:14 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
	public :
	typedef typename std::stack<T>::container_type::iterator	iterator;
	
	iterator	begin(void) const {
		return std::stack<T>::c.begin();
	}

	iterator	end(void) const {
		return std::stack<T>::c.end();
	}

	// private:

	// public:
	// 	MutantStack(void);
	// 	MutantStack(MutantStack const & m);
	// 	MutantStack&	operator=(MutantStack const & rhs);
	// 	~MutantStack(void);
};

// TODO MutantStack::iterator<TEMPLATE>
// begin
// end
// comparaison
// incrementation / decrementation

// STD member functions 
// (constructor)	Construct stack (public member function)
// empty			Test whether container is empty (public member function)
// size				Return size (public member function)
// top				Access next element (public member function)
// push				Insert element (public member function)
// emplace			Construct and insert element (public member function)
// pop				Remove top element (public member function)
// swap				Swap contents (public member function)

#endif