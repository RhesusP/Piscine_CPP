/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:51:54 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/25 12:10:42 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"
#define MAX_VAL 20

int main()
{
	std::cout << "============ SUBJECT TESTS ============" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "============ CUSTOM TESTS ============" << std::endl;
	{
		{
			MutantStack<int> mstack;
			for (int i = 0; i < MAX_VAL; i++)
			{
				mstack.push(i);
			}
			std::cout << "========== reverse_iterator ==========" << std::endl;
			MutantStack<int>::reverse_iterator it_rbegin = mstack.rbegin();
			MutantStack<int>::reverse_iterator it_rend = mstack.rend();
			while (it_rbegin != it_rend)
			{
				std::cout << *it_rbegin << std::endl;
				++it_rbegin;
			}
		}
		{
			MutantStack<int> mstack;
			for (int i = 0; i < MAX_VAL; i++)
			{
				const int j = i;
				mstack.push(j);
			}
			std::cout << "========== const_iterator ==========" << std::endl;
			MutantStack<int>::const_iterator it_begin = mstack.begin();
			MutantStack<int>::const_iterator it_end = mstack.end();
			while (it_begin != it_end)
			{
				std::cout << *it_begin << std::endl;
				++it_begin;
			}
		}
		{
			MutantStack<int> mstack;
			for (int i = 0; i < MAX_VAL; i++)
			{
				const int j = i;
				mstack.push(j);
			}
			std::cout << "========== const_reverse_iterator ==========" << std::endl;
			MutantStack<int>::const_reverse_iterator it_rbegin = mstack.rbegin();
			MutantStack<int>::const_reverse_iterator it_rend = mstack.rend();
			while (it_rbegin != it_rend)
			{
				std::cout << *it_rbegin << std::endl;
				++it_rbegin;
			}
		}
	}
	return 0;
}