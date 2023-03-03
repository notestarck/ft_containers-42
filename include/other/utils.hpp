/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:56:59 by estarck           #+#    #+#             */
/*   Updated: 2023/02/24 09:03:04 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include "../iterator/iterator_traits.hpp"

namespace ft
{
	// @brief Range of one iterator
	// @param first The first value of the iterator
	// @param last The last value of the iterator
	// @return size of range
	template<class InputIterator>
    typename ft::iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last)
    {
        typename ft::iterator_traits<InputIterator>::difference_type rtn = 0;
        while (first != last)
        {
            first++;
            rtn++;
        }
        return (rtn);
    }

}// namespace ft

#endif /* _UTILS_HPP_*/