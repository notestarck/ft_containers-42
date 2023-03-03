/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:01:01 by estarck           #+#    #+#             */
/*   Updated: 2023/02/27 09:05:09 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _IS_INTEGRAL_HPP_
#define _IS_INTEGRAL_HPP_

/*
*	Trait class that identifies whether T is an integral type.
*	It inherits from integral_constant as being either true_type or false_type,
*	depending on whether T is an integral type.
*	All fundamental integral types, along with all their aliases (like those in cstdint),
*	are considered integral types by this class, including their const and volatile qualified variants.
*	Enums are not considered integral types in C++.
*/

#include  <type_traits>

namespace ft
{
	template<typename T>
	struct is_integral
	{ static const bool value = false; };

	template<>
	struct is_integral<bool>
	{ static const bool value = true; };

	template<>
	struct is_integral<char>
	{ static const bool value = true; };

	template<>
	struct is_integral<char16_t>
	{ static const bool value = true; };

	template<>
	struct is_integral<char32_t>
	{ static const bool value = true; };

	template<>
	struct is_integral<wchar_t>
	{ static const bool value = true; };

	template<>
	struct is_integral<signed char>
	{ static const bool value = true; };

	template<>
	struct is_integral<short int>
	{ static const bool value = true; };

	template<>
	struct is_integral<int>
	{ static const bool value = true; };

	template<>
	struct is_integral<long int>
	{ static const bool value = true; };

	template<>
	struct is_integral<long long int>
	{ static const bool value = true; };

	template<>
	struct is_integral<unsigned char>
	{ static const bool value = true; };

	template<>
	struct is_integral<unsigned short int>
	{ static const bool value = true; };

	template<>
	struct is_integral<unsigned int>
	{ static const bool value = true; };

	template<>
	struct is_integral<unsigned long int>
	{ static const bool value = true; };

	template<>
	struct is_integral<unsigned long long int>
	{ static const bool value = true; };
	
} // namespace ft

#endif /* _IS_INTEGRAL_HPP_ */