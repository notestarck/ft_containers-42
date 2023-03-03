/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:18:21 by estarck           #+#    #+#             */
/*   Updated: 2023/03/02 11:56:21 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>

#ifdef STD
	#include <vector>
	using namespace std;
#else
	#include "../include/Containers/vector.hpp"
	using namespace ft;
#endif

namespace ft
{
	void	namesp()
	{
		std::cout << "diff :Affichage de ft::vector\n\n";
	}	
}

namespace std
{
	void	namesp()
	{
		std::cout << "diff :Affichage de std::vector\n\n";
	}	
}

void	printComment(std::string str)
{
	std::cout << "\033[31m" << str << "\033[0m" << std::endl;
}

void	printVector(vector<int> v)
{
	std::cout << "diff :";
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "\033[1;32m---------- Tester ft::vector && std::vector ----------\033[0m\n" << std::endl;
	//namesp();
	{
		vector<int>	v;
		v.push_back(5);
		v.push_back(10);
		v.push_back(42);
		v.push_back(84);
		v.push_back(168);

		printComment("Contenu de vector :");
		printVector(v);
		
		printComment("Taille du vector :");
		std::cout << "diff :" << v.size() << std::endl;
		printComment("Capacite du vector :");
		std::cout << "diff :" << v.capacity() << std::endl << std::endl;

		printComment("Modification d'un element de vector v[1] = 21 :");
		v[1] = 21;
		printVector(v);

		printComment("Inserer un element a une position specifique de vector (insert 0 a la position 2) :");
		v.insert(v.begin() + 2, 0);
		printVector(v);
		printComment("Supprimer un element specifique de vecteur (84) :");
		v.erase(v.begin() + 4);
		printVector(v);
		printComment("Supprimer une plage d'elements de vecteur :");
		v.erase(v.begin(), v.begin() + 3);
		printVector(v);
		
		printComment("Taille du vector :");
		std::cout << "diff :" << v.size() << std::endl;
		printComment("Capacite du vector :");
		std::cout << "diff :" << v.capacity() << std::endl << std::endl;
	
		printComment("\033[33mReserver de l'espace pour des elements dans vecteur (20)");
		v.reserve(20);
		printComment("Taille du vector :");
		std::cout << "diff :" << v.size() << std::endl;
		printComment("Capacite du vector :");
		std::cout << "diff :" << v.capacity() << std::endl;
		printComment("\033[33mRedimensionner le vecteur a une taille plus grande (41)");
		v.resize(41);
		printComment("Taille du vector :");
		std::cout << "diff :" << v.size() << std::endl;
		printComment("Capacite du vector :");
		std::cout << "diff :" << v.capacity() << std::endl;
		printVector(v);
		printComment("\033[33m\nRedimensionner le vecteur a une taille plus petite (1)");
		v.resize(1);
		printComment("Taille du vector :");
		std::cout << "diff :" << v.size() << std::endl;
		printComment("Capacite du vector :");
		std::cout << "diff :" << v.capacity() << std::endl;
		printComment("Contenu de vecteur :");
		printVector(v);

		printComment("\nAjouter des element a vecteur (21-10-5):");
		v.push_back(21);
		v.push_back(10);
		v.push_back(5);
		printVector(v);
		printComment("Ajouter d'un autre vecteur (60-70-80):");
		vector<int>	w;
		w.push_back(60);
		w.push_back(70);
		w.push_back(80);
		v.insert(v.begin(), w.begin(), w.end());
		printVector(v);
		printComment("\n\033[33mSwap de vecteur v et vecteur w");
		printComment("Avant swap v et w :");
		printVector(v);
		printVector(w);
		v.swap(w);
		printComment("Avant swap v et w :");
		printVector(v);
		printVector(w);
		
		printComment("\nComparaison de vecteur v < w :");
		std::cout << "diff :" << std::boolalpha << (v < w) << std::endl;
		printComment("Comparaison de vecteur v > w :");
		std::cout << "diff :" << std::boolalpha << (v > w) << std::endl;
		printComment("Comparaison de vecteur v == w :");
		std::cout << "diff :" << std::boolalpha << (v == w) << std::endl;
		printComment("Comparaison de vecteur v != w :");
		std::cout << "diff :" << std::boolalpha << (v != w) << std::endl;
		
		printComment("Test des reverse iterator :");
		std::cout << "diff :";
		for (vector<int>::reverse_iterator rit = w.rbegin(); rit < w.rend(); rit++)
			std::cout << *rit << " ";
		std::cout << "\n\n";

		printComment("Retirer un element a la position 3 :");
		w.erase(w.begin() + 3);
		printVector(w);
		printComment("Effacer l'ensemble du vecteur :");
		w.clear();
		printVector(w);
	}
	return (0);
}