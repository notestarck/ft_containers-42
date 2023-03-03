/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:09:26 by estarck           #+#    #+#             */
/*   Updated: 2023/02/27 08:57:06 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ITERATOR_TRAITS_HPP_
#define _ITERATOR_TRAITS_HPP_

#include <iterator>

/*
*	To implement algorithms only in terms of iterators, it is often necessary to determine
*	the value and difference types that correspond to a particular iterator type.
*	Accordingly, it is required that if Iterator is the type of an iterator, the types
*	
*	iterator_traits<Iterator>::difference_type
*	iterator_traits<Iterator>::value_type
*	iterator_traits<Iterator>::iterator_category
*	
*	be defined as the iterator’s difference type, value type and iterator category, respectively.
*	In the case of an output iterator, the types
*	
*	iterator_traits<Iterator>::difference_type
*	iterator_traits<Iterator>::value_type
*	
*	are both defined as void.
*/

namespace ft
{
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category	iterator_category;
   		typedef typename Iterator::value_type			value_type;
   		typedef typename Iterator::difference_type		difference_type;
   		typedef typename Iterator::pointer				pointer;
   		typedef typename Iterator::reference			reference;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef	std::random_access_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef std::ptrdiff_t						difference_type;
		typedef T*									pointer;
		typedef T&									reference;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef	std::random_access_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef std::ptrdiff_t						difference_type;
		typedef const T*							pointer;
		typedef const T&							reference;
	};
	
}// namespace ft

#endif /* _ITERATOR_TRAITS_HPP_ */