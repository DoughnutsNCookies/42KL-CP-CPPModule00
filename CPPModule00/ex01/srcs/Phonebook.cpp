/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:20:08 by schuah            #+#    #+#             */
/*   Updated: 2023/03/21 21:10:26 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/* Constructor function of the Phonebook Class */
Phonebook::Phonebook(void)
{
	this->_index = 0;
}

/* Destructor function of the Phonebook Class */
Phonebook::~Phonebook(void)
{
	
}

/* Sets the data from user input */
static void	get_data(std::string *data)
{
	if (std::getline(std::cin, *data).eof())
	{
		std::cout << std::endl;
		std::exit(0);
	}
	while (data->find('\t') != std::string::npos)
		data->replace(data->find('\t'), 1, "    ");
}

/* Gets data from the user input and sets them into the Contact Class */
void	Phonebook::add_contact(void)
{
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phonenumber;
	std::string	darkestsecret;

	std::cout << "Enter first name: ";
	get_data(&firstname);
	std::cout << "Enter last name: ";
	get_data(&lastname);
	std::cout << "Enter nickname: ";
	get_data(&nickname);
	std::cout << "Enter phonenumber: ";
	get_data(&phonenumber);
	std::cout << "Enter darkest secret: ";
	get_data(&darkestsecret);
	_contacts[_index].set_contact(firstname, lastname, nickname, phonenumber, darkestsecret);
	_index = (_index + 1) % MAX_CONTACTS;
}

/* Prints the contact in right-alignment form using width */
static void	print_contact(Contact contacts[MAX_CONTACTS])
{
	std::cout << "     Index|First name| Last name|  Nickname|" <<std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		if (contacts[i].get_firstname().length() <= 10)
			std::cout << std::setw(10) << std::right << contacts[i].get_firstname();
		else
			std::cout << contacts[i].get_firstname().substr(0, 9) << ".";
		std::cout << "|";
		if (contacts[i].get_lastname().length() <= 10)
			std::cout << std::setw(10) << std::right << contacts[i].get_lastname();
		else
			std::cout << contacts[i].get_lastname().substr(0, 9) << ".";
		std::cout << "|";
		if (contacts[i].get_nickname().length() <= 10)
			std::cout << std::setw(10) << std::right << contacts[i].get_nickname();
		else
			std::cout << contacts[i].get_nickname().substr(0, 9) << ".";
		std::cout << "|" << std::endl;
	}
}

/* Finds the respective Contact class based on the index input from the user */ 
void	Phonebook::search_contact(void)
{
	std::string index;

	if (_contacts[0].get_empty())
	{
		std::cout << "No contacts to display" << std::endl;
		return ;
	}
	print_contact(_contacts);
	while (1)
	{
		std::cout << "Enter an index: ";
		if (std::getline(std::cin, index).eof())
		{
			std::cout << std::endl;
			std::exit(0);
		}
		if (index.length() == 1 && index[0] >= '0'
			&& index[0] <= '0' + MAX_CONTACTS - 1
			&& _contacts[index[0] - '0'].get_empty() == 0)
		{
			_contacts[index[0] - '0'].print_contact();
			break ;
		}
		else
			std::cout << "Invalid or empty index" << std::endl;
	}
}
