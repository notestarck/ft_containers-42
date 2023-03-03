/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:27:24 by estarck           #+#    #+#             */
/*   Updated: 2023/02/27 08:05:48 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEXICOGRAPHICAL_COMPARE_
#define _LEXICOGRAPHICAL_COMPARE_

namespace ft
{
	// @brief A lexicographical comparison is the kind of comparison generally used to sort words alphabetically in dictionaries; It involves comparing sequentially the elements that have the same position in both ranges against each other until one element is not equivalent to the other. The result of comparing these first non-matching elements is the result of the lexicographical comparison. The elements are compared using operator<.
	// @param first1 Input iterators to the initial and final positions of the first sequence. The range used is [first1,last1), which contains all the elements between first1 and last1, including the element pointed by first1 but not the element pointed by last1.
	// @param last1 Input iterators to the initial and final positions of the first sequence. The range used is [first1,last1), which contains all the elements between first1 and last1, including the element pointed by first1 but not the element pointed by last1.
	// @param first2 Input iterators to the initial and final positions of the second sequence. The range used is [first2,last2).
	// @param last2 Input iterators to the initial and final positions of the second sequence. The range used is [first2,last2).
	// @return true if the first range compares lexicographically less than the second. false otherwise (including when all the elements of both ranges are equivalent).
	template <class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || (*first2 < *first1))
				return (false);
			else if (*first1 < *first2)
				return (true);
			first1++;
			first2++;
		}
		return (first2 != last2);
	}
	
	// @brief A lexicographical comparison is the kind of comparison generally used to sort words alphabetically in dictionaries; It involves comparing sequentially the elements that have the same position in both ranges against each other until one element is not equivalent to the other. The result of comparing these first non-matching elements is the result of the lexicographical comparison. The elements are compared with comp.
	// @param first1 Input iterators to the initial and final positions of the first sequence. The range used is [first1,last1), which contains all the elements between first1 and last1, including the element pointed by first1 but not the element pointed by last1.
	// @param last1 Input iterators to the initial and final positions of the first sequence. The range used is [first1,last1), which contains all the elements between first1 and last1, including the element pointed by first1 but not the element pointed by last1.
	// @param first2 Input iterators to the initial and final positions of the second sequence. The range used is [first2,last2).
	// @param last2 Input iterators to the initial and final positions of the second sequence. The range used is [first2,last2).
	// @param comp Binary function that accepts two arguments of the types pointed by the iterators, and returns a value convertible to bool. The value returned indicates whether the first argument is considered to go before the second in the specific strict weak ordering it defines. The function shall not modify any of its arguments. This can either be a function pointer or a function object.
	// @return true if the first range compares lexicographically less than the second. false otherwise (including when all the elements of both ranges are equivalent).
	template <class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, first1))
				return (false);
			else if (comp(*first1, first2))
				return (true);
			first1++;
			first2++;
		}
		return (first2 != last2);
	}
	
}// namespace ft

#endif /* _LEXICOGRAPHICAL_COMPARE_ */