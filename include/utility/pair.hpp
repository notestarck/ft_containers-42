/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:52:34 by estarck           #+#    #+#             */
/*   Updated: 2023/02/27 09:31:42 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PAIR_HPP_
#define _PAIR_HPP_

#include <iostream>

namespace ft
{
	// @brief pair is a class template that provides a way to store two heterogeneous objects as a single unit.
	// @tparam T1 first type
	// @tparam T2 second type
	template <class T1, class T2>
	struct pair
	{
		/* ****************************************** */
		/*              Member types                  */
		/* ****************************************** */
		
		typedef T1	first_type; //first_type is the first bound type
		typedef T2	second_type; //second_type is the second bound type

		/* ****************************************** */
		/*              Member variables              */
		/* ****************************************** */
		
		T1	first; //first is a copy of the first object
		T2	second; //second is a copy of the second object

		/* ****************************************** */
		/*              Member functions              */
		/* ****************************************** */

		/* ************ Constructor ***************** */
		
		// @brief The default constructor creates first and second using their respective default constructors.
		pair() : first(), second()
		{}

		// @brief Two objects may be passed to a pair constructor to be copied.
		// @param a An object of the type of first, or some other type implicitly convertible to it.
		// @param b An object of the type of second, or some other type implicitly convertible to it.
		pair (const first_type& a, const second_type& b) : first(a), second(b)
		{}
		
		// @brief Copy constructor for the pair class itself
		// @param pr Another pair object. This may be an object of the same type as the object being constructed or of a pair type whose elements' types are implicitly convertible to those in the pair being constructed.
		template <class U1, class U2>
		pair (const pair <U1, U2>& pr) : first(pr.first), second(pr.second)
		{}

		/* ************ Assign contents ********** */

		// @brief Assigns pr as the new content for the pair object.
		// @param pr Another pair object. 
		// @return *this pair
		pair& operator=(const pair& pr)
		{
			first = pr.first;
			second = pr.second;
			return (*this);
		}
	};// struct pair

	/* ****************************************** */
	/*              Non-Member functions          */
	/* ****************************************** */

	// @brief Creates a std::pair object, deducing the target type from the types of arguments.
	// @param t1 the first object to construct the pair
	// @param t2 the second object to construct the pair
	// @return A ft::pair object containing the given values.
	template<typename T1, typename T2>
	ft::pair<T1, T2> make_pair(T1 t1, T2 t2)
	{ return (pair<T1, T2>(t1, t2)); }

	// @brief Tests if both elements of lhs and rhs are equal, that is, compares lhs.first with rhs.first and lhs.second with rhs.second.
	// @param lhs first pair object to compare
	// @param rhs second pair object to compare
	// @return true if lhs == rhs, else false.
	template<typename T1, typename T2>
	bool operator==(const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs)
	{ return (lhs.first == rhs.first && lhs.second == rhs.second); }

	// @brief ests if both elements of lhs and rhs are equal, that is, compares lhs.first with rhs.first and lhs.second with rhs.second.
	// @param lhs first pair object to compare
	// @param rhs second pair object to compare
	// @return false if lhs == rhs, else true.
	template< class T1, class T2 >
	bool operator!=(const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs)
	{ return (!(lhs == rhs)); }

	// @brief Compares lhs and rhs lexicographically by operator<, that is, compares the first elements and only if they are equivalent, compares the second elements.
	// @param lhs first pair object to compare
	// @param rhs second pair object to compare
	// @return if lhs.first < rhs.first, returns true. Otherwise, if rhs.first < lhs.first, returns false. Otherwise, if lhs.second < rhs.second, returns true. Otherwise, returns false.
	template< class T1, class T2 >
	bool operator<(const ft::pair<T1, T2> & lhs, const ft::pair<T1, T2> & rhs)
	{ return ((lhs.first < rhs.first) || (!(rhs.first < lhs.first) && lhs.second < rhs.second)); }

	// @brief Compares lhs and rhs lexicographically by operator<, that is, compares the first elements and only if they are equivalent, compares the second elements.
	// @param lhs first pair object to compare
	// @param rhs second pair object to compare
	// @return !(rhs < lhs)
	template< class T1, class T2 >
	bool operator<=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs )
	{ return (!(rhs < lhs)); }

	// @brief Compares lhs and rhs lexicographically by operator<, that is, compares the first elements and only if they are equivalent, compares the second elements.
	// @param lhs first pair object to compare
	// @param rhs second pair object to compare
	// @return rhs < lhs
	template< class T1, class T2 >
	bool operator>( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs )
	{ return (rhs < lhs); }

	// @brief Compares lhs and rhs lexicographically by operator<, that is, compares the first elements and only if they are equivalent, compares the second elements.
	// @param lhs first pair object to compare
	// @param rhs second pair object to compare
	// @return !(lhs < rhs)
	template< class T1, class T2 >
	bool operator>=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs )
	{ return (!(lhs < rhs)); }

	// @brief overloaded operator << for pair<>
	// @param stream out stream
	// @param lhs pair<>
	// @return "first(second)"
	template <typename T1, typename T2>
	std::ostream	&operator<<(std::ostream &stream, pair<T1, T2> const &lhs)
	{
		stream << lhs.first << "(" << lhs.second << ")";
 		return (stream);
	}
	
}// namespace ft

#endif /* _PAIR_HPP_ */