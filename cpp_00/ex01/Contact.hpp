/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:08:21 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/05 10:40:34 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>
# include <ctime>

class Contact {
	private:

		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phonenumber;
		std::string _darkestsecret;
		std::time_t _last_update;
	public:
		Contact();
		~Contact();
		int		set_firstname(std::string firstname);
		int		set_lastname(std::string lastname);
		int		set_nickname(std::string nickname);
		int		set_phonenumber(std::string phonenumber);
		int		set_darkestsecret(std::string darkestsecret);
		void	set_last_update(std::time_t last_update);
		std::string	get_firstname(void);
		std::string	get_lastname(void);
		std::string	get_nickname(void);
		std::string	get_phonenumber(void);
		std::string	get_darkestsecret(void);
		std::time_t	get_last_update(void);
		void		print(void);
};

#endif
