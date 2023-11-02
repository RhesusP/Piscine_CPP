/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:32:13 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/02 16:04:19 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string.h>

class Data
{
	private:
		std::string	_msg;
		std::string	_author;
	public:
		Data(void);
		Data(std::string const & msg, std::string const & author);
		Data(Data const & d);
		Data&	operator=(Data const & rhs);
		~Data(void);

		std::string const &	getMsg(void) const;
		std::string const &	getAuthor(void) const;
};

std::ostream&	operator<<(std::ostream& o, Data& rhs);

#endif