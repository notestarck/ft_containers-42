/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:00:14 by estarck           #+#    #+#             */
/*   Updated: 2023/02/01 11:02:01 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ENABLE_IF_HPP_
#define _ENABLE_IF_HPP_

namespace ft
{
	// @brief The type T is enabled as member type enable_if::type if Cond is true. Otherwise, enable_if::type is not defined.
	template <bool Cond, class T = void>
	struct enable_if
	{};
	
	// @brief The type T is enabled as member type enable_if::type if Cond is true. Otherwise, enable_if::type is not defined.
	template <class T>
	struct enable_if <true, T>
	{ typedef T type; };
} // namespace ft

#endif /*  _ENABLE_IF_HPP_ */