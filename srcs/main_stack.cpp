/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:18:21 by estarck           #+#    #+#             */
/*   Updated: 2023/03/02 11:56:17 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifdef STD
	#include <stack>
	using namespace std;
#else
	#include "../include/Containers/stack.hpp"
	using namespace ft;
#endif

namespace ft
{
	void	namesp()

	{
		std::cout << "diff :Affichage de ft::stack\n\n";
	}	
}

namespace std
{
	void	namesp()

	{
		std::cout << "diff :Affichage de std::stack\n\n";
	}	
}

void	printComment(std::string str)
{
	std::cout << "\033[31m" << str << "\033[0m" << std::endl;
}

int main(void)
{
	std::cout << "\033[1;32m---------- Tester ft::stack && std::stack ----------\033[0m\n" << std::endl;
	//namesp();
	{
		stack<int>	intStack;
		printComment("\033[1;32mCreation d'une stack de type int.\n");
		printComment("Taille de la pile :");
		std::cout << "diff :" << intStack.size() << std::endl;
		
		intStack.push(42);
		printComment("Ajout de la valeur 42. Taille de la pile :");
		std::cout << "diff :" << intStack.size() << std::endl;
		
		intStack.push(21); intStack.push(10); intStack.push(5);
		printComment("Ajout des valeurs 21, 10, 5. Taille de la pile :");
		std::cout << "diff :" << intStack.size() << std::endl;
		printComment("Valeur du dessus de la pile :");
		std::cout << "diff :" << intStack.top() << std::endl;
		
		intStack.pop();
		printComment("Suppression de la valeur au dessus de la pile et affichage de la nouvelle valeur :");
		std::cout << "diff :" << intStack.top() << std::endl;
		printComment("Taille de la pile :");
		std::cout << "diff :" << intStack.size() << std::endl;
		printComment("Verification si la pile est vide :");
		std::cout << "diff :" << intStack.empty() << std::endl;
	}
	std::cout << "\n---\n\n";
	{
		stack<std::string>	strStack;
		printComment("\033[1;32mCreation d'une stack de type string.\n");
		printComment("Taille de la pile :");
		std::cout << "diff :" << strStack.size() << std::endl;
		
		strStack.push("Bonjour");
		printComment("Ajout de la valeur 'Bonjour'. Taille de la pile :");
		std::cout << "diff :" << strStack.size() << std::endl;
		
		strStack.push("Ici"); strStack.push("42"); strStack.push("Mulhouse");
		printComment("Ajout des valeurs 'Ici, '42', 'Mulhouse'. Taille de la pile :");
		std::cout << "diff :" << strStack.size() << std::endl;
		printComment("Valeur du dessus de la pile :");
		std::cout << "diff :" << strStack.top() << std::endl;
		
		strStack.pop();
		printComment("Suppression de la valeur au dessus de la pile et affichage de la nouvelle valeur :");
		std::cout << "diff :" << strStack.top() << std::endl;
		printComment("Taille de la pile :");
		std::cout << "diff :" << strStack.size() << std::endl;
		printComment("Verification si la pile est vide :");
		std::cout << "diff :" << strStack.empty() << std::endl;
	}
	std::cout << "\n---\n\n";
	{
		stack<char>	charStack;
		printComment("\033[1;32mCreation d'une stack de type char.\n");
		printComment("Taille de la pile :");
		std::cout << "diff :" << charStack.size() << std::endl;
		
		charStack.push('a');
		printComment("Ajout de la valeur 'a'. Taille de la pile :");
		std::cout << "diff :" << charStack.size() << std::endl;
		
		charStack.push('M'); charStack.push('z'); charStack.push('8');
		printComment("Ajout des valeurs 'M, 'z', '8'. Taille de la pile :");
		std::cout << "diff :" << charStack.size() << std::endl;
		printComment("Valeur du dessus de la pile :");
		std::cout << "diff :" << charStack.top() << std::endl;
		
		charStack.pop();
		printComment("Suppression de la valeur au dessus de la pile et affichage de la nouvelle valeur :");
		std::cout << "diff :" << charStack.top() << std::endl;
		printComment("Taille de la pile :");
		std::cout << "diff :" << charStack.size() << std::endl;
		printComment("Verification si la pile est vide :");
		std::cout << "diff :" << charStack.empty() << std::endl;
	}
	
	
	return (0);
}