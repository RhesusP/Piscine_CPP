/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:44:21 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/02 16:15:22 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Data.hpp"

Data::Data(void) {
	_msg = "default message";
	_author = "who ???";
}

Data::Data(std::string const & msg, std::string const & author) {
	_msg = msg;
	_author = author;
}

Data::Data(Data const & d) {
	*this = d;
}

Data::~Data(void) {}

Data&	Data::operator=(Data const & rhs) {
	this->_msg = rhs.getMsg();
	this->_author = rhs.getAuthor();
	return *this;
}

std::string const &	Data::getMsg(void) const {
	return _msg;
}

std::string const & Data::getAuthor(void) const {
	return _author;
}

std::ostream&	operator<<(std::ostream& o, Data& rhs) {
	o << "📨 msg: " << rhs.getMsg() << std::endl;
	o << "🖋️  author: " << rhs.getAuthor() << std::endl;
	o << "📍 address: " << &rhs << std::endl;
	return o;
}
