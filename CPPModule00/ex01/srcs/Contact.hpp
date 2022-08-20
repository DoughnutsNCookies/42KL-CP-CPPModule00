/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:19:29 by schuah            #+#    #+#             */
/*   Updated: 2022/08/18 15:10:12 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class	Contact
{
	public:
		Contact();
		virtual 	~Contact();
		void		set_contact(std::string firstname, std::string lastname,
								std::string nickname, std::string phonenumber,
								std::string darkestsecret);
		void		print_contact();
		std::string	get_firstname();
		std::string	get_lastname();
		std::string	get_nickname();
		int			get_empty();
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phonenumber;
		std::string	_darkestsecret;
};

#endif
