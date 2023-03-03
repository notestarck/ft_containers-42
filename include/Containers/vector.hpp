/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:11:04 by estarck           #+#    #+#             */
/*   Updated: 2023/03/02 11:36:26 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <memory>
#include <cstddef>

#include "../type_traits/enable_if.hpp"
#include "../type_traits/is_integral.hpp"
#include "../iterator/iterator_traits.hpp"
#include "../iterator/reverse_iterator.hpp"
#include "../iterator/random_access_iterator.hpp"
#include "../algorithm/equal.hpp"
#include "../algorithm/lexicographical_compare.hpp"
#include "../other/utils.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public :

			/* ****************************************** */
			/*              Member types                  */
			/* ****************************************** */

			typedef T															value_type;
			typedef T const														const_value_type;
			typedef Allocator													allocator_type;
			typedef typename std::size_t										size_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename ft::random_access_iterator<value_type>				iterator;
			typedef typename ft::random_access_iterator<const_value_type>		const_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		
		private:    
        
			/* ****************************************** */
			/*              Member objects                */
			/* ****************************************** */
			
    		allocator_type	_alloc;
    		pointer			_start;
    		size_type		_size;
    		size_type		_capacity;

		public :
			/* ****************************************** */
			/*              Member functions              */
			/* ****************************************** */	
			
			// Constructors
			
			// @brief Creates a vector with no elements.
			// @param alloc An allocator object.
			explicit vector(const allocator_type& alloc = allocator_type()) :
				_alloc(alloc),
				_start(nullptr),
				_size(0),
				_capacity(0)
			{}
			
			// @brief Constructs a container with n elements. Each element is a copy of val.
			// @param n The number of elements
			// @param val Value of element
			// @param alloc Allocator Object
			explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()) :
				_alloc(alloc),
				_start(nullptr),
				_size(0),
				_capacity(0)
			{
				_start = _alloc.allocate(n);
				_capacity = n;
				while (n--)
				{
					_alloc.construct(_start + _size, val);
					_size++;
				}
			}

			// @brief Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
			// @param first An iterator is the first value in x.
			// @param last An iterator is the last value in x.
			template <class InputIt> //Utiliser enable_if
			vector(InputIt first, InputIt last, const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = 0) :
				_alloc(alloc),
				_start(nullptr),
				_size(0),
				_capacity(0)
			{
				difference_type n = ft::distance(first, last);
				_start = _alloc.allocate(n);
				_capacity = n;
				while (n--)
				{
					_alloc.construct(_start + _size, *first);
					first++;
					_size++;
				}
			}

			// @brief Copy constructor
			// @param other another container to use as data source
			vector(const vector& other) :
				_alloc(other._alloc),
				_start(_alloc.allocate(other._capacity)),
				_size(other._size),
				_capacity(other._capacity)
			{
				assign(other.begin(), other.end());
			}
			
			// destructor

			~vector()
			{
				clear();
				_alloc.deallocate(_start, _capacity);
			}

			//assings

			// @brief Copy assignment operator. 
			// @param other another container to use as data source
			// @return *this
			vector& operator=(const vector& other)
			{
				if (this == &other)
					return (*this);
				clear();
				assign(other.begin(), other.end());
				return (*this);
			}
			
			// @brief This function fills a vector with count copies of the given value. Note that the assignment completely changes the vector and that the resulting vector's size is the same as the number of elements assigned. Old data may be lost.
			// @param count Number of elements to be assigned.
			// @param value Value to be assigned.
			void assign(size_type count, const T& value)
			{
				clear();
				if (count > capacity())
					reserve(count);
				for(size_type i = 0; i < count; i++)
				{
					_alloc.construct(_start + i, value);
				}
				_size = count;
			}

			// @brief The new contents are elements constructed from each of the elements in the range between first and last, in the same order.
			// @param first the range to copy the elements from
			// @param last the range to copy the elements from
			template< class InputIt >
			void assign(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0)
			{
				size_type	s = ft::distance(first, last);
				
				clear();
				if (s >= capacity())
					reserve(s);
				for (; &(*first) != &(*last); first++, _size++)
					_alloc.construct((&_start[_size]), *first);
				_size = s;
			}
			
			// @brief Returns a copy of the allocator object associated with the vector.
			// @return The allocator.
			allocator_type get_allocator() const
			{ return (_alloc); }
		
		/* ****************************************** */
		/*              Element Access                */
		/* ****************************************** */
		
			// @brief Provides access to the data contained in the vector.
			// @param n The index of the element for which data should be accessed.
			// @return Read/write reference to data.
			reference at(size_type n)
			{
				if(n >= size())
					throw std::out_of_range("Error - ft::vector::at - Out of range");
				return (_start[n]);
			}

			// @brief Provides access to the data contained in the vector.
			// @param n The index of the element for which data should be accessed.
			// @return Read-only (constant) reference to data.
			const_reference at(size_type n) const
			{
				if(n >= size())
					throw std::out_of_range("Error - ft::vector::at - Out of range");
				return (_start[n]);
			}
			
			// @brief Subscript access to the data contained in the vector.
			// @param n The index of the element for which data should be accessed.
			// @return Read/write reference to data.
			reference operator[](size_type n)
			{ return (_start[n]); }

			// @brief Subscript access to the data contained in the vector.
			// @param n The index of the element for which data should be accessed.
			// @return Read-only (constant) reference to data.
			const_reference operator[](size_type n) const
			{ return (_start[n]); }

			// @brief Returns a read/write reference to the data at the first element of the vector.
			reference front()
			{ return (*(_start)); }

			// @brief Returns a read-only (constant) reference to the data at the first element of the vector.
			const_reference front() const
			{ return (*(_start)); }

			// @brief Returns a read/write reference to the data at the last element of the vector.
			reference back()
			{ return *(_start + _size - 1); }
			
			// @brief Returns a read-only (constant) reference to the data at the last element of the vector.
			const_reference back() const
			{ return *(_start + _size - 1); }

		/* ****************************************** */
		/*              Iterators                     */
		/* ****************************************** */

			// @brief Returns a read/write iterator that points to the first element in the vector. Iteration is done in ordinary element order.
			iterator begin()
			{ return (_start); }

			// @brief Returns a read-only (constant) iterator that points to the first element in the vector. Iteration is done in ordinary element order.
			const_iterator begin() const
			{ return (_start); }

			// @brief Returns a read/write iterator that points one past the last element in the vector. Iteration is done in ordinary element order.
			iterator end()
			{ 
				if (empty())
					return (begin());
				return (_start + _size);
			}

			// @brief Returns a read-only (constant) iterator that points one past the last element in the vector. Iteration is done in ordinary element order.
			const_iterator end() const
			{ 
				if (empty())
					return (begin());
				return (_start + _size);
			}

			// @brief Returns a read/write reverse iterator that points to the last element in the vector. Iteration is done in reverse element order.
			reverse_iterator rbegin()
			{ return(reverse_iterator(end())); }

			// @brief Returns a read-only (constant) reverse iterator that points to the last element in the vector. Iteration is done in reverse element order.
			const_reverse_iterator rbegin() const
			{ return(reverse_iterator(end())); }

			// @brief Returns a read/write reverse iterator that points to one before the first element in the vector. Iteration is done in reverse element order.
			reverse_iterator rend()
			{ return (reverse_iterator(begin())); }

			// @brief Returns a read-only (constant) reverse iterator that points to one before the first element in the vector. Iteration is done in reverse element order. 
			const_reverse_iterator rend() const
			{ return (reverse_iterator(begin())); }
		
		/* ****************************************** */
		/*              Capacity                      */
		/* ****************************************** */

			/// @brief Returns true if the vector is empty. (Thus begin() would equal end().)
			bool empty() const
			{
				if(size() == 0)
					return (true);
				return (false);
			}

			// @brief Returns the number of elements in the vector.
			size_type size() const
			{ return (_size); }
				
			// @brief Returns the total number of elements that the vector can hold before needing to allocate more memory.				returns the number of elements that can be held in currently allocated storage (public member function)
			size_type capacity() const
			{ return (_capacity); }

			// @brief Returns the size of the largest possible vector.
			size_type max_size() const
			{ return _alloc.max_size(); }
			//{ return (std::min<size_type>(_alloc.max_size(), std::numeric_limits<difference_type>::max())); }
			
			// @brief Attempt to preallocate enough memory for specified number of elements.
			// @param n Number of elements required.
			void	reserve(size_type n)
			{
				if (n <= capacity())
					return ;
				if (n > max_size())
					throw (std::length_error("vector::reserve n exceeds max_size()"));
				pointer 	prev_start = _start;
				size_type	prev_capacity = _capacity;

				_start = _alloc.allocate(n);
				_capacity = n;
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(_start + i, prev_start[i]);
					_alloc.destroy(prev_start + i);
				}
				_alloc.deallocate(prev_start, prev_capacity);
			}
		
		/* ****************************************** */
		/*              Modifiers                     */
		/* ****************************************** */
		
			// @brief Erases all the elements. Note that this function only erases the elements, and that if the elements themselves are pointers, the pointed-to memory is not touched in any way. Managing the pointer is the user's responsibility.
			void clear()
			{ erase(begin(), end()); }
			
			// @brief Inserts given value into vector before specified iterator.
			// @param position An iterator into the vector.
			// @param val Data to be inserted.
			// @return An iterator that points to the inserted data.
			iterator insert(iterator position, const value_type& val)
			{
				size_type	s = &(*position) - _start;
				
				if ((_start + _size < _start + _capacity) && position == end())
				{
					_alloc.construct(&(*position), val);
					_size += 1;
				}
				else
				{
					pointer		new_start;
					size_type	new_size;
					size_type	new_capacity;
					
					if (_start + _size >= _start + _capacity)
						new_capacity = (size() * 2 > 0) ? size() * 2 : 1;
					else
						new_capacity = capacity();
					new_start = _alloc.allocate(new_capacity);
					new_size = size() + 1;

					for (size_type i = 0; i < s; i++)
						_alloc.construct(new_start + i, *(_start + i));
					_alloc.construct(new_start + s, val);
					for (size_type i = 0; i < size() - s; i++)
						_alloc.construct(new_start + s + i + 1, *(_start + s + i));
					for (size_type i = 0; i < size(); i++)
						_alloc.destroy(_start + i);
					if (_start)
						_alloc.deallocate(_start, _capacity);
					
					_start = new_start;
					_size = new_size;
					_capacity = new_capacity; 
				}
				return (_start + s);
			}

			// @brief Inserts a number of copies of given data into the vector.
			// @param position A const_iterator into the vector.
			// @param n Number of elements to be inserted.
			// @param val Data to be inserted.
			// @return An iterator that points to the inserted data.
			iterator insert(iterator position, size_type n, const value_type& val)
			{
				if (n == 0)
					return (position);
				if (n > max_size())
					throw (std::length_error("ft::vector::insert max_size()"));

				size_type	s = &(*position) - _start;
				if ((_start + _size != _start + _capacity) && n <= _capacity - _size)
				{
					for(size_type i = _size; i >= s; i--)
						_alloc.construct(_start + n + i, *(_start + i));
					while (n)
					{
						_alloc.construct(&(*position) + (n - 1), val);
						n--;
						_size++;
					}	
				}
				else
				{
					pointer		new_start;
					size_type	new_size;
					size_type	new_capacity;
					
					new_capacity = (size() * 2 > 0) ? size() * 2 : 1;
					new_size = size() + n;

					if (new_capacity < size() + n)
						new_capacity = size() + n;
					
					new_start = _alloc.allocate(new_capacity);

					for (size_type i = 0; i < s; i++)
						_alloc.construct(new_start + i, *(_start + i));
					for (size_type i = 0; i < n; i++)
						_alloc.construct(new_start + s + i, val);
					for (size_type i = 0; i < new_size - n; i++)
						_alloc.construct(new_start + s + n + i, *(_start + s + i));
					for (size_type i = 0; i < size(); i++)
						_alloc.destroy(_start + i);
					if (_start)
						_alloc.deallocate(_start, _capacity);
					
					_start = new_start;
					_size = new_size;
					_capacity = new_capacity; 
				}
				return (_start + s);
			}

			// @brief Inserts a range into the vector.
			// @param position A const_iterator into the vector.
			// @param first An input iterator.
			// @param last	An input iterator.
			// @return An iterator that points to the inserted data.
			template <class InputIterator>
			iterator insert (const_iterator position, InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				size_type	n = ft::distance(first, last);
				size_type	s = position - begin();

				if ((_start + _size != _start + _capacity) && n <= _capacity - _size)
				{
					for(size_type i = _size; i > s; i--)
						_alloc.construct(_start + n + i - 1, *(_start + i - 1));
					for(size_type i = 0; &(*first) != &(*last); first++, i++, _size++)
						_alloc.construct(_start + s + i, *first);
				}
				else
				{
					pointer		new_start;
					size_type	new_size;
					size_type	new_capacity;
					
					new_capacity = (size() * 2 > 0) ? size() * 2 : 1;
					new_size = size() + n;

					if (new_capacity < size() + n)
						new_capacity = size() + n;
					
					new_start = _alloc.allocate(new_capacity);

					for (size_type i = 0; i < s; i++)
						_alloc.construct(new_start + i, *(_start + i));
					for (size_type i = 0; i < n; i++, first++)
						_alloc.construct(new_start + s + i, *first);
					for (size_type i = 0; i < new_size - n; i++)
						_alloc.construct(new_start + s + i + n, *(_start + s + i));
					for (size_type i = 0; i < size(); i++)
						_alloc.destroy(_start + i);
					if (_start)
						_alloc.deallocate(_start, _capacity);
					
					_start = new_start;
					_size = new_size;
					_capacity = new_capacity;
				}
				
				return (_start + s);
			}
			
			// @brief Remove element at given position.
			// @param position Iterator pointing to element to be erased.
			// @return An iterator pointing to the next element (or end()).
			iterator erase(iterator position)
			{
				size_type	s = position - begin();

				_size--;
				_alloc.destroy(&_start[s]);
				for (size_type i = s; i < size(); i++)
				{
					_alloc.construct(&_start[i], _start[i + 1]);
					_alloc.destroy(&_start[i + 1]);
				}
				return (iterator(&_start[s]));
			}

			// @brief Remove a range of elements.
			// @param first Iterator pointing to the first element to be erased.
			// @param last Iterator pointing to one past the last element to be erased.
			// @return An iterator pointing to the element pointed to by __last prior to erasing (or end()).
			iterator erase (iterator first, iterator last)
			{
				size_type	s = last - first;

				while (first != end() - s)
				{
					*first = first[s];
					first++;
				}
				while (first != end())
				{
					_alloc.destroy(&(*first));
					first++;
				}
				_size -= s;
				return (last - s);
			}

			// @brief Add data to the end of the vector.
			// @param x Data to be added.
			void push_back(const value_type & x)
			{
				//std::cout
				if (size() == capacity())
				{
					size_type new_capacity = 1;
					if (size() > 0)
						new_capacity = size() * 2;
					reserve(new_capacity);	
				}
				_alloc.construct(_start + _size, x);
				_size++;
			}

			// @brief Removes last element.
			void pop_back()
			{
				_size--;
				_alloc.destroy(_start + _size);
			}
			
			// @brief Resizes the vector to the specified number of elements.
			// @param new_size Number of elements the vector should contain.
			// @param x Data with which new elements should be populated
			void resize(size_type new_size, const value_type & x = value_type())
			{
				if(new_size > max_size())
					throw (std::length_error("vector::resize"));
				else if(new_size < size())
				{
					while(size() > new_size)
					{
						--_size;
						_alloc.destroy(_start + size());
					}
				}
				else
					insert(end(), new_size - size(), x);
			}
			
			// @brief Swaps data with another vector.
			// @param x A vector of the same element and allocator types.
			void swap(vector & x)
			{
				allocator_type	save_alloc = x._alloc;
    			pointer			save_start = x._start;
    			size_type		save_size = x._size;
    			size_type		save_capacity = x._capacity;

				x._alloc = _alloc;
				x._start = _start;
				x._size = _size;
				x._capacity = _capacity;

				_alloc = save_alloc;
				_start = save_start;
				_size = save_size;
				_capacity = save_capacity;
			}
		
		/* ****************************************** */
		/*              Non-Member Fubctions          */
		/* ****************************************** */

			// @brief Checks if the contents of lhs and rhs are equal, that is, they have the same number of elements and each element in lhs compares equal with the element in rhs at the same position.
			// @return true if the contents of the vectors are equal, false otherwise
			friend bool	operator==(const vector &lhs, const vector &rhs)
			{
				if (lhs.size() != rhs.size())
					return (false);
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}

			// @brief Checks if the contents of lhs and rhs are equal, that is, they have the same number of elements and each element in lhs compares equal with the element in rhs at the same position.
			// @return true if the contents of the vectors are not equal, false otherwise
			friend bool	operator!=(const vector &lhs, const vector &rhs)
			{ return (!(lhs == rhs)); }

			// @brief Compares the contents of lhs and rhs lexicographically. The comparison is performed by a function equivalent to std::lexicographical_compare.
			// @return true if the contents of the lhs are lexicographically less than the contents of rhs, false otherwise
			friend bool	operator<(const vector &lhs, const vector &rhs)
			{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

			// @brief Compares the contents of lhs and rhs lexicographically. The comparison is performed by a function equivalent to std::lexicographical_compare.
			// @return true if the contents of the lhs are lexicographically less than or equal to the contents of rhs, false otherwise
			friend bool	operator>(const vector &lhs, const vector &rhs)
			{ return (rhs < lhs); }

			// @brief Compares the contents of lhs and rhs lexicographically. The comparison is performed by a function equivalent to std::lexicographical_compare.
			// @brief true if the contents of the lhs are lexicographically greater than the contents of rhs, false otherwise
			friend bool	operator<=(const vector &lhs, const vector &rhs)
			{ return (!(lhs > rhs)); }

			// @brief Compares the contents of lhs and rhs lexicographically. The comparison is performed by a function equivalent to std::lexicographical_compare.
			// @brief true if the contents of the lhs are lexicographically greater than or equal to the contents of rhs, false otherwise
			friend bool	operator>=(const vector &lhs, const vector &rhs)
			{ return (!(lhs < rhs)); }

	};// class vector
	
}// namespace ft

#endif /* _VECTOR_HPP_ */