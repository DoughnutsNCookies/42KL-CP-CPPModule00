/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:19:51 by schuah            #+#    #+#             */
/*   Updated: 2022/08/18 13:29:32 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

/* Converts small characters to big characters and prints them out */
int	main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; j < (int)strlen(av[i]); j++)
				toupper(av[i][j]);
			std::cout << av[i];
		}
		std::cout << std::endl;
	}
	return (0);
}
