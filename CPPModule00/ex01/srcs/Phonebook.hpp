/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:55:22 by schuah            #+#    #+#             */
/*   Updated: 2022/08/18 15:10:02 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

# define	MAX_CONTACTS 8

class	Phonebook
{
	public:
		Phonebook();
		virtual	~Phonebook();
		void	add_contact();
		void	search_contact();
	private:
		Contact	_contacts[MAX_CONTACTS];
		int		_index;
		
};

#endif
