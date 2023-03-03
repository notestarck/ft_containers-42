/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:21:46 by estarck           #+#    #+#             */
/*   Updated: 2023/02/27 16:50:36 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <iostream>
//#include <deque>
#include "vector.hpp"

namespace ft
{
	template<class T, class Container = ft::vector<T> >
	class stack
	{
		public :
			/* ****************************************** */
			/*              Member types                  */
			/* ****************************************** */
			
			// @brief Type qui fournit le conteneur de base à adapter par un objet stack.
			typedef Container 							container_type;
			
			// @brief Type qui représente le type d'objet stocké en tant qu'élément dans un objet stack.
			typedef T 									value_type;
			
			// @brief Type entier non signé qui peut représenter le nombre d'éléments dans un stack.
			typedef typename Container::size_type 		size_type;
			
			typedef typename Container::reference 		reference;
			typedef typename Container::const_reference	const_reference;

		protected :
			/* ****************************************** */
			/*              Member objects                */
			/* ****************************************** */
			
			// @brief the underlying container
			container_type c;
		
		public :
			/* ****************************************** */
			/*              Member functions              */
			/* ****************************************** */
			
			// @brief constructs the stack
			explicit stack (const Container & ctnr = Container()) : c(ctnr)
			{}
			
			// @brief destructs the stack
			virtual ~stack ()
			{}
			
			// @brief assigns values to the container adaptor
			stack & operator= (const stack<T, Container> & srcs)
			{
				if (this != &srcs)
					this->c = srcs.c;
				return (*this);
			}
			
			/* ****************************************** */
			/*              Element access                */
			/* ****************************************** */

			// @brief accesses the top element
			// @return Returns reference to the top element in the stack. This is the most recently pushed element.
			reference top ()
			{ return (c.back()); }

			// @brief accesses the top element
			// @return Returns const reference to the top element in the stack. This is the most recently pushed element
			const_reference top () const
			{ return (c.back()); }
			
			/* ****************************************** */
			/*              Capacity                      */
			/* ****************************************** */

			// @brief checks whether the underlying container is empty
			// @return true if the underlying container is empty, false otherwise
			bool empty() const
			{ return (c.empty()); }
			
			// @brief returns the number of elements
			// @return The number of elements in the container.
			size_type size() const
			{ return (c.size()); }
			
			/* ****************************************** */
			/*              Modifiers                     */
			/* ****************************************** */

			// @brief inserts element at the top
			// @param value the value of the element to push
			void push( const value_type& value )
			{ c.push_back(value); }

			// @brief removes the top element
			void pop()
			{ c.pop_back(); }
		
			/* ****************************************** */
			/*              Non-member functions          */
			/* ****************************************** */

			// @brief Vérifie si l’objet stack situé à gauche de l’opérateur est égal à l’objet stack situé à droite.
			// @param lhs Objet de type stack
			// @param rhs Objet de type stack
			// @return true si les piles ou les piles sont égales ; false si les piles ou les piles ne sont pas égales.
			friend bool operator==( const stack<T, Container> & lhs, const stack<T, Container> & rhs )
			{ return (lhs.c == rhs.c); }
			
			// @brief Vérifie si l’objet stack situé à gauche de l’opérateur n’est pas égal à l’objet stack situé à droite.
			// @param lhs Objet de type stack.
			// @param rhs Objet de type stack.
			// @return true si les piles ou les piles ne sont pas égales ; false si les piles ou les piles sont égales.
			friend bool operator!=( const stack<T, Container> & lhs, const stack<T, Container> & rhs )
			{ return (lhs.c != rhs.c); }
			
			// @brief Teste si l'objet de pile situé à gauche de l'opérateur est inférieur à l'objet de pile situé à droite.
			// @param lhs Objet de type stack
			// @param rhs Objet de type stack
			// @return true si la pile sur le côté gauche de l’opérateur est inférieure et non égale à la pile sur le côté droit de l’opérateur ; sinon false.
			friend bool operator<( const stack<T, Container> & lhs, const stack<T, Container> & rhs )
			{ return (lhs.c < rhs.c); }
			
			// @brief Teste si l'objet de pile situé à gauche de l'opérateur est inférieur ou égal à l'objet de pile situé à droite.
			// @param lhs Objet de type stack
			// @param rhs Objet de type stack
			// @return true si la pile sur le côté gauche de l’opérateur est inférieure ou égale à la pile sur le côté droit de l’opérateur ; sinon false.
			friend bool operator<=( const stack<T, Container> & lhs, const stack<T, Container> & rhs )
			{ return (lhs.c <= rhs.c); }
			
			// @brief Teste si l'objet de pile situé à gauche de l'opérateur est supérieur à l'objet de pile situé à droite.
			// @param lhs Objet de type stack
			// @param rhs Objet de type stack
			// @return true si la pile sur le côté gauche de l’opérateur est supérieure et non égale à la pile sur le côté droit de l’opérateur ; sinon false.
			friend bool operator>( const stack<T, Container> & lhs, const stack<T, Container> & rhs )
			{ return (lhs.c > rhs.c); }
			
			// @brief Teste si l'objet de pile situé à gauche de l'opérateur est supérieur ou égal à l'objet de pile situé à droite.
			// @param lhs Objet de type stack
			// @param rhs Objet de type stack
			// @return true si la pile sur le côté gauche de l’opérateur est strictement inférieure à la pile sur le côté droit de l’opérateur ; sinon false.
			friend bool operator>=( const stack<T, Container> & lhs, const stack<T, Container> & rhs )
			{ return (lhs.c >= rhs.c); }
			
	};// class stack
	
}// namespace ft

#endif /* _STACK_HPP_ */