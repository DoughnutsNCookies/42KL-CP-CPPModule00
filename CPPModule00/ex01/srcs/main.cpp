/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:54:18 by schuah            #+#    #+#             */
/*   Updated: 2022/08/18 14:16:59 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/* Start of the main function, the main loop of the program. */
int	main(void)
{
	std::string	command;
	Phonebook	phonebook;

	std::cout << "ADD: Adds a new contact" << std::endl;
	std::cout << "SEARCH: Searchs for a contact" << std::endl;
	std::cout << "EXIT: Exits the program" << std::endl;
	while (1)
	{
		std::cout << "pb>";
		if (std::getline(std::cin, command).eof())
		{
			std::cout << std::endl;
			break ;
		}
		if (command == "ADD")
			phonebook.add_contact();
		if (command == "SEARCH")
			phonebook.search_contact();
		if (command == "EXIT")
			break ;
	}
	return (0);
}
