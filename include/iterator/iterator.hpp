/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:26:14 by estarck           #+#    #+#             */
/*   Updated: 2023/02/27 09:06:35 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ITERATOR_HPP_ 
#define _ITERATOR_HPP_

#include <cstddef>
#include <iostream>

namespace ft
{
	//@brief Empty class to identify the category of an iterator as an input iterator
	struct input_iterator_tag
	{};
	
	//@brief Empty class to identify the category of an iterator as an output iterator
	struct output_iterator_tag
	{};
	
	//@brief Empty class to identify the category of an iterator as an forward iterator
	struct forward_iterator_tag : public input_iterator_tag
	{};
	
	//@brief Empty class to identify the category of an iterator as an bidirectional iterator
	struct bidirectional_iterator_tag : public forward_iterator_tag
	{};
	
	//@brief Empty class to identify the category of an iterator as an random-access iterator
	struct random_access_iterator_tag : public bidirectional_iterator_tag
	{};
	
	//@brief std::iterator is the base class provided to simplify definitions of the required types for iterators.
	template < class Category, class T, class Distance = std::ptrdiff_t,
	           class Pointer = T*, class Reference = T& >
	struct iterator
	{
		//the category of the iterator
		typedef Category iterator_category;
		
		//the type of the values that can be obtained by dereferencing the iterator
		typedef T value_type;
		
		//a type that can be used to identify distance between iterators
		typedef Distance difference_type;
		
		//defines a pointer to the type iterated over (value_type)
		typedef Pointer pointer;
		
		//defines a reference to the type iterated over (value_type)
		typedef Reference reference;

	};/* struct iterator */

}// namespace ft

#endif  /* _ITERATOR_HPP_ */