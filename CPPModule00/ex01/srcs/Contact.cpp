/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:37:19 by schuah            #+#    #+#             */
/*   Updated: 2022/08/18 15:17:08 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/* Constructor function of the Contact class */
Contact::Contact(void)
{
	
}

/* Destructor function of the Contact class */
Contact::~Contact(void)
{
	
}

/* Sets the Class variables accordingly based on the userinput */
void	Contact::set_contact(std::string firstname, std::string lastname, 
							std::string nickname, std::string phonenumber,
							std::string darkestsecret)
{
	this->_firstname = firstname;
	this->_lastname = lastname;
	this->_nickname = nickname;
	this->_phonenumber = phonenumber;
	this->_darkestsecret = darkestsecret;
}

/* Prints out the Class variables */
void	Contact::print_contact(void)
{
	std::cout << "First name: " << this->_firstname << std::endl;
	std::cout << "Last name: " << this->_lastname << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phonenumber: " << this->_phonenumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestsecret << std::endl;
}

/* Returns the firstname of the class */
std::string	Contact::get_firstname(void)
{
	return (this->_firstname);
}

/* Returns the lastname of the class */
std::string Contact::get_lastname(void)
{
	return (this->_lastname);
}

/* Returns the nickname of the class */
std::string Contact::get_nickname(void)
{
	return (this->_nickname);
}

/* Returns 1 if the class is empty, else returns 0 */
int	Contact::get_empty(void)
{
	return (this->_firstname.empty());
}
