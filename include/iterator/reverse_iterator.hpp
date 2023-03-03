/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:31:24 by estarck           #+#    #+#             */
/*   Updated: 2023/02/27 09:04:06 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REVERSE_ITERATOR_HPP_
#define _REVERSE_ITERATOR_HPP_

#include <iterator>
#include "iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator : public std::iterator <	typename iterator_traits<Iterator>::iterator_category,
												typename iterator_traits<Iterator>::value_type,
												typename iterator_traits<Iterator>::difference_type,
												typename iterator_traits<Iterator>::pointer,
												typename iterator_traits<Iterator>::reference >
	{
		protected :
			/* ****************************************** */
			/*              Member objects                */
			/* ****************************************** */
			
			Iterator current;
		
		public :
			/* ****************************************** */
			/*              Member types                  */
			/* ****************************************** */

			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

			
			/* ****************************************** */
			/*              Member functions              */
			/* ****************************************** */

			// @brief Constructs a reverse iterator that points to no object.
			reverse_iterator() : current()
			{}
			
			// @brief Constructs a reverse iterator from some original iterator it. The behavior of the constructed object replicates the original, except that it iterates through its pointed elements in the reverse order.
			explicit reverse_iterator(iterator_type it) : current(it)
			{}
			
			// @brief Constructs a reverse iterator from some other reverse iterator. The constructed object keeps the same sense of iteration as rev_it.
			// @param rev_it An iterator of a reverse_iterator type, whose sense of iteration is preserved.
			template <class U>
			reverse_iterator(const reverse_iterator<U>& rev_it) : current(rev_it.base())
			{}

			// @brief for coplien form - 42 school subject.
			virtual ~reverse_iterator()
			{}

			// @brief Returns the underlying base iterator. That is std::reverse_iterator(it).base() == it.
			// @return The underlying iterator.
			iterator_type base() const
			{ return (current); }

			// @brief Returns a reference to the element pointed to by the iterator.
			// @return A reference to the element pointed by the iterator.
			reference operator*() const
			{
				Iterator tmp = current;
				return (*(--tmp));
			}

			// @brief Returns a pointer to the element pointed to by the iterator (in order to access one of its members).
			// @return A pointer to the element pointed by the iterator.
			pointer operator->()const
			{ return &(operator*()); }

			// @brief Pre-Decrements the underlying iterator.
			// @return *this
			reverse_iterator& operator++()
			{
				--current;
				return (*this);
			}
			
			// @brief Post-Decrements the underlying iterator.
			// @return The original value of *this
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				--current;
				return (tmp);
			}
			
			// @brief Pre-Increments the underlying iterator.
			// @return *this
			reverse_iterator& operator--()
			{
				++current;
				return (*this);
			}
			
			// @brief Post-Increments the underlying iterator.
			// @return The original value of *this
			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				++current;
				return (tmp);
			}
			
			// @brief The underlying iterator must be a Random Access Iterator.
			// @return A reverse_iterator that refers to current - n
			reverse_iterator operator+ (difference_type n) const
			{ return (reverse_iterator(current - n)); }

			// @brief Moves the underlying iterator backwards n steps. The underlying iterator must be a Random Access Iterator.
			// @return *this
			reverse_iterator& operator+=(difference_type n)
			{
				current -= n;
				return (*this);
			}
			
			// @brief The underlying iterator must be a Random Access Iterator.
			// @return A reverse_iterator that refers to current - n
			reverse_iterator operator- (difference_type n) const
			{ return (reverse_iterator(current + n)); }
			
			// @brief Moves the underlying iterator forwards n steps. The underlying iterator must be a Random Access Iterator.
			// @return *this
			reverse_iterator& operator-=(difference_type n)
			{
				current += n;
				return (*this);
			}
			
			// @brief The underlying iterator must be a Random Access Iterator.
			// @return The value at current - n - 1
			reference operator[](difference_type n) const
			{ return *(*this + n); }

	}; //class reverse_iterator
	
	// @brief Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
	// @return true if the condition holds, and false otherwise.
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (lhs.base() == rhs.base()); }
	
	// @brief Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
	// @return true if the condition holds, and false otherwise.
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return !(lhs == rhs); }
	
	// @brief Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
	// @return true if the condition holds, and false otherwise.
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (rhs.base() < lhs.base()); }
	
	// @brief Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
	// @return true if the condition holds, and false otherwise.
	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (rhs < lhs); }
	
	// @brief Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
	// @return true if the condition holds, and false otherwise.
	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return !(rhs < lhs); }
	
	// @brief Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
	// @return true if the condition holds, and false otherwise.
	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return !(lhs < rhs); }

	// @brief Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
	// @return true if the condition holds, and false otherwise.
	template<typename IteratorL, typename IteratorR>
    inline bool operator==(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
    { return (lhs.base() == rhs.base()); }

	// @brief Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
	// @return true if the condition holds, and false otherwise.
	template<typename IteratorL, typename IteratorR>
    inline bool operator<(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
    { return (rhs.base() < lhs.base()); }
 
	// @brief Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
	// @return true if the condition holds, and false otherwise.
	template<typename IteratorL, typename IteratorR>
    inline bool operator!=(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
    { return (!(lhs == rhs)); }

	// @brief Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
	// @return true if the condition holds, and false otherwise.
	template<typename IteratorL, typename IteratorR>
    inline bool operator>(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
    { return (rhs < lhs); }

	// @brief Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
	// @return true if the condition holds, and false otherwise.
	template<typename IteratorL, typename IteratorR>
    inline bool operator<=(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
    { return (!(rhs < lhs)); }

	// @brief Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
	// @return true if the condition holds, and false otherwise.
	template<typename IteratorL, typename IteratorR>
    inline bool operator>=(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
    { return (!(lhs < rhs)); }

	// @brief Returns the distance between lhs and rhs.
	// @return The number of elements between lhs and rhs.
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (rhs.base() - lhs.base()); }

	// @brief For reverser_iterator - const_reverse_iterator
	template <class IteratorL, class IteratorR>
	typename reverse_iterator<IteratorL>::difference_type operator-(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
	{ return (rhs.base() - lhs.base()); }
	
	// @brief Returns a reverse iterator pointing to the element located n positions away from the element pointed to by rev_it.
	// @param n Number of elements to offset.
	// @param rev_it Reverse iterator.
	// @return An iterator pointing to the element n positions away from rev_it.
	template <class Iterator>
	reverse_iterator<Iterator>  operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{ return (rev_it + n); }

}// namespace ft

#endif /* _REVERSE_ITERATOR_HPP_ */