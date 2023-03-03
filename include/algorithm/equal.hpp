/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:00:47 by estarck           #+#    #+#             */
/*   Updated: 2023/02/27 08:05:22 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EQUAL_HPP_
#define _EQUAL_HPP_

namespace ft
{
	// @brief Compares the elements in the range [first1,last1) with those in the range beginning at first2, and returns true if all of the elements in both ranges match. The elements are compared using operator==.
	// @param first1 Input iterators to the initial and final positions of the first sequence. The range used is [first1,last1), which contains all the elements between first1 and last1, including the element pointed by first1 but not the element pointed by last1.
	// @param last1 Input iterators to the initial and final positions of the first sequence. The range used is [first1,last1), which contains all the elements between first1 and last1, including the element pointed by first1 but not the element pointed by last1.
	// @param first2 Input iterator to the initial position of the second sequence. The comparison includes up to as many elements of this sequence as those in the range [first1,last1)
	// @return true if all the elements in the range [first1,last1) compare equal to those of the range starting at first2, and false otherwise.
	template <class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}
	
	// @brief Compares the elements in the range [first1,last1) with those in the range beginning at first2, and returns true if all of the elements in both ranges match. The elements are compared using pred.
	// @param first1 Input iterators to the initial and final positions of the first sequence. The range used is [first1,last1), which contains all the elements between first1 and last1, including the element pointed by first1 but not the element pointed by last1.
	// @param last1 Input iterators to the initial and final positions of the first sequence. The range used is [first1,last1), which contains all the elements between first1 and last1, including the element pointed by first1 but not the element pointed by last1.
	// @param first2 Input iterator to the initial position of the second sequence. The comparison includes up to as many elements of this sequence as those in the range [first1,last1).
	// @param p Binary function that accepts two elements as argument (one of each of the two sequences, in the same order), and returns a value convertible to bool. The value returned indicates whether the elements are considered to match in the context of this function. The function shall not modify any of its arguments. This can either be a function pointer or a function object.
	// @return true if all the elements in the range [first1,last1) compare equal to those of the range starting at first2, and false otherwise.
	template <class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
	{
		while (first1 != last1)
		{
			if (!p(*first1, *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}

	
}// namespace ft

#endif /* _EQUAL_HPP_ */