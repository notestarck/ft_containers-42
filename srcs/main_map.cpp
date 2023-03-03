/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:18:21 by estarck           #+#    #+#             */
/*   Updated: 2023/03/02 11:56:12 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <assert.h>
#include <map>
#include "../include/Containers/map.hpp"

#ifdef STD
	using namespace std;
#else
	using namespace ft;
#endif

namespace ft
{
	void	namesp()
	{
		std::cout << "diff :Affichage de ft::map\n\n";
	}	
}

namespace std
{
	void	namesp()
	{
		std::cout << "diff :Affichage de std::map\n\n";
	}	
}

void	printComment(std::string str)
{
	std::cout << "\033[31m" << str << "\033[0m" << std::endl;
}

void	printMap(map<int, std::string> myMap)
{
	std::cout << "    " << std::right << std::setw(5) << "key" << std::setw(15) << "value" << std::endl;
    std::cout << "    " << std::setfill('-') << std::setw(20) << "" << std::setfill(' ') << std::endl;

    for (map<int, std::string>::iterator it = myMap.begin(); it != myMap.end(); ++it)
        std::cout << "diff :" << std::right << std::setw(5) << it->first << std::right << std::setw(15) << it->second << std::endl;
}

int main(void)
{
	std::cout << "\033[1;32m---------- Tester ft::map && std::map ----------\033[0m\n" << std::endl;
	//namesp();
	{
		map<int, std::string> m;
		printComment("Insertion d'elements dans map :");
		m.insert(pair<int, std::string>(1, "One"));
		m.insert(pair<int, std::string>(2, "Two"));
    	m.insert(pair<int, std::string>(3, "Three"));
    	m.insert(pair<int, std::string>(42, "Forty-two"));
		printMap(m);

		printComment("\nTest de la taille :");
		std::cout << "diff :Taille de map - " << m.size() << std::endl;
		
		printComment("\nTest de l'operateur [1]");
		std::cout << "diff :" << "map[1] = " << m[1] <<std::endl;

		printComment("\nTest de at(42) :");
		std::cout << "diff :" << "at(42) = " << m.at(42) << std::endl;

		printComment("\nTest de insert(21, Twenty-one) :");
		m.insert(pair<int, std::string>(21, "Twenty-one"));
		printMap(m);

		printComment("\nTest de erase(3) :");
		m.erase(3);
		printMap(m);

		printComment("\nTest des reverse_iterateur :");
		std::cout << "    " << std::right << std::setw(5) << "key" << std::setw(15) << "value" << std::endl;
    	std::cout << "    " << std::setfill('-') << std::setw(20) << "" << std::setfill(' ') << std::endl;
		for(map<int, std::string>::reverse_iterator rit = m.rbegin(); rit != m.rend(); rit++)
        	std::cout << "diff :" << std::right << std::setw(5) << rit->first << std::right << std::setw(15) << rit->second << std::endl;

		printComment("\nTest pour savoir si la key = 22 existe :");
			std::cout << "diff :" << std::boolalpha << "bool : " << m.count(22) << std::endl;
		printComment("Test pour savoir si la key = 21 existe :");
			std::cout << "diff :" << std::boolalpha << "bool : " << m.count(21) << std::endl;
		
		printComment("\nTest de la fonction lower_bound(2) :");
		std::cout << "    " << std::right << std::setw(5) << "key" << std::setw(15) << "value" << std::endl;
    	std::cout << "    " << std::setfill('-') << std::setw(20) << "" << std::setfill(' ') << std::endl;
    	for (map<int, std::string>::iterator it = m.lower_bound(2); it != m.end(); ++it)
    	    std::cout << "diff :" << std::right << std::setw(5) << it->first << std::right << std::setw(15) << it->second << std::endl;
		printComment("Test de la fonction power_bound(2) :");
		std::cout << "    " << std::right << std::setw(5) << "key" << std::setw(15) << "value" << std::endl;
    	std::cout << "    " << std::setfill('-') << std::setw(20) << "" << std::setfill(' ') << std::endl;
    	for (map<int, std::string>::iterator it = m.upper_bound(2); it != m.end(); ++it)
    	    std::cout << "diff :" << std::right << std::setw(5) << it->first << std::right << std::setw(15) << it->second << std::endl;

		printComment("\nTest des operateur < :");
		map<int, std::string> n;
		std::string	a = "valeur";
		for (int i = 0; i < 5; i++)
			n.insert(pair<int, std::string>(i, a));
		std::cout << "diff :" << std::boolalpha << "bool : " << (n < m )<< std::endl;
		printComment("Test des operateur == :");
		std::cout << "diff :" << std::boolalpha << "bool : " << (n == m) << std::endl;

		printComment("\033[33m\nSuppression des elements de map.");
		m.clear();
		printComment("Affichage de map :");
		printMap(m);
		printComment("Affichage de la taille :");
		std::cout << "diff :Taille de Map : " << m.size() << std::endl;
	}
	return (0);
}