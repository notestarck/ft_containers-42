/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:29:28 by estarck           #+#    #+#             */
/*   Updated: 2023/03/02 12:12:11 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <memory>
#include "../type_traits/enable_if.hpp"
#include "../algorithm/equal.hpp"
#include "../algorithm/lexicographical_compare.hpp"
#include "../other/node.hpp"
#include "../utility/pair.hpp"
#include "../iterator/map_iterator.hpp"
#include "../iterator/reverse_iterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map {

		public:

			/* ****************************************** */
			/*              Member types                  */
			/* ****************************************** */

			typedef Key													key_type;
			typedef T													mapped_type;
			typedef typename ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare												key_compare;
			typedef Allocator											allocator_type;
			typedef typename std::size_t								size_type;
			typedef typename std::ptrdiff_t								difference_type;

			typedef typename ft::Node<value_type>						node;
			typedef node*												node_pointer;

			typedef typename ft::map_iterator<value_type, node>			iterator;
			typedef typename ft::map_iterator<const value_type, node>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;

		private:
		
			/* ****************************************** */
			/*              Member objects                */
			/* ****************************************** */

			node_pointer		_content;
			key_compare			_cmp;
			allocator_type		_alloc;
			size_type			_size;

		protected :

			/* ****************************************** */
			/*              Member classes                */
			/* ****************************************** */

			// @brief  a function object that compares objects of type std::map::value_type (key-value pairs) by comparing of the first components of the pairs.
			class value_compare
			{
				public:
					// @brief the stored comparator
					Compare comp;
					
					// @brief Initializes the internal instance of the comparator to c.
					// @param c comparator to assign
					value_compare(Compare c): comp(c){};

					// @brief Compares lhs.first and rhs.first by calling the stored comparator.
					// @param lhs values to compare
					// @param rhs values to compare
					// @return comp(lhs.first, rhs.first)
					bool	operator()(const value_type &lhs, const value_type &rhs) const
					{
						return (comp(lhs.first, rhs.first));
					}
			};
			
		public :
		
			/* ****************************************** */
			/*              Member functions              */
			/* ****************************************** */

			//Constructors

			// @brief Default constructor creates no elements.
			explicit map(): _content(new node), _size(0)
			{}
			
			// @brief Builds a map from a range.
			// @param first An input iterator first element of range 
			// @param last  An input iterator last element of range
			template <class InputIt>
			map(InputIt first, InputIt last): _content(new node), _size(0)
			{ insert(first, last); }
			
			// @brief Map copy constructor
			// @param other A map of identical element and allocator types.
			map(const map &other): _content(new node), _size(0)
			{ *this = other; }

			// destructor

			~map()
			{
				clear();
				delete _content;
			}

			//assings

			// @brief Map assignment operator.
			// @param other A map of identical element and allocator types.
			// @return *this
			map& operator=(map const &other)
			{
				if (this == &other)
					return (*this);
				clear();
				insert(other.begin(), other.end());
				return (*this);
			}

			// @brief Get a copy of the memory allocation object.
			allocator_type get_allocator(void) const
			{ return (this->alloc); }

			/* ****************************************** */
			/*              Element Access                */
			/* ****************************************** */

			// @brief Access to map data.
			// @param key The key for which data should be retrieved.
			// @return A reference to the data whose key is equivalent to key, if such a data is present in the map.
			mapped_type &at(const Key &key)
			{
				Node<value_type> *result = search_node(_content, key);
    			if (result == NULL)
    			   throw std::out_of_range("map::a::  key not found");
    			return result->_value.second;
			}

			// @brief Access to map data.
			// @param key The key for which data should be retrieved.
			// @return A reference to the data whose key is equivalent to key, if such a data is present in the map.
            const mapped_type &at(const Key &key) const
			{ return (at(key)); }

			// @brief Subscript ( [] ) access to map data.
			// @param key The key for which data should be retrieved.
			// @return A reference to the data of the (key,data) pair.
			mapped_type	&operator[](const key_type &key)
			{ return ((insert(value_type(key, mapped_type()))).first->second); }
			//{ return (insert()); }

			/* ****************************************** */
			/*              Iterators                     */
			/* ****************************************** */

			// @brief Returns a read/write iterator that points to the first pair in the map. Iteration is done in ascending order according to the keys.
			iterator begin() 
			{ return (iterator(fmin(_content))); }

			// @brief Returns a read-only (constant) iterator that points to the first pair in the map. Iteration is done in ascending order according to the keys.
			const_iterator begin() const 
			{ return (const_iterator(fmin(_content))); }

			// @brief Returns a read/write iterator that points one past the last pair in the map. Iteration is done in ascending order according to the keys.
			iterator end()  
			{ return (iterator(fmax(_content))); }

			// @brief Returns a read-only (constant) iterator that points one past the last pair in the map. Iteration is done in ascending order according to the keys.
			const_iterator end() const 
			{ return (const_iterator(fmax(_content))); }

			// @brief Returns a read/write reverse iterator that points to the last pair in the map. Iteration is done in descending order according to the keys.
			reverse_iterator rbegin() 
			{ return (reverse_iterator(end())); }

			// @brief Returns a read-only (constant) reverse iterator that points to the last pair in the map. Iteration is done in descending order according to the keys.
			const_reverse_iterator rbegin() const  
			{ return (const_reverse_iterator(end())); }

			// @brief Returns a read/write reverse iterator that points to one before the first pair in the map. Iteration is done in descending order according to the keys.
			reverse_iterator rend()  
			{ return (reverse_iterator(begin())); }

			// @brief Returns a read-only (constant) reverse iterator that points to one before the first pair in the map. Iteration is done in descending order according to the keys.
			const_reverse_iterator rend() const
			{ return (const_reverse_iterator(begin())); }

			/* ****************************************** */
			/*              Capacity                      */
			/* ****************************************** */

			// @brief Returns the size of the map.
			size_type size() const
			{ return (_size); }

			// @brief Returns the maximum size of the map.
			size_type max_size() const
			{ return (_alloc.max_size()); }

			// @brief Returns true if the map is empty. (
			bool empty() const
			 { return (_size == 0 ? true : false); }

			/* ****************************************** */
			/*              Modifiers                     */
			/* ****************************************** */

			// @brief Attempts to insert a std::pair into the map.
			// @param val Pair to be inserted
			// @return A pair, of which the first element is an iterator that points to the possibly inserted pair, and the second is a bool that is true if the pair was actually inserted.
			ft::pair<iterator, bool> insert(const value_type &val)
			{
				ft::pair<iterator, bool>	ret;

				ret.second = false;
				if(!count(val.first))
				{
					ret.second = true;
					new_node(new node(val));
				}
				ret.first = find(val.first);
				return (ret);
			}

			// @brief Attempts to insert a std::pair into the map.
			// @param position An iterator that serves as a hint as to where the pair should be inserted.
			// @param val Pair to be inserted 
			// @return An iterator that points to the element 
			iterator insert(iterator position, const value_type &val)
			{
				(void)position;
				return (insert(val).first);
			}

			// @brief Template function that attempts to insert a range of elements.
			// @param first Iterator pointing to the start of the range to be inserted.
			// @param last Iterator pointing to the end of the range.
			template <class InputIt>
			void insert(InputIt first, InputIt last)
			{
				while (first != last)
					insert(*first++);
			}

			// @brief Erases an element from a map.
			// @param position An iterator pointing to the element to be erased.
			// @return An iterator pointing to the element immediately following position prior to the element being erased. If no such element exists, end() is returned.
			iterator erase(iterator position)
			{
				iterator ret = position;
				ret++;
				if (ret == NULL)
					ret = end();
				del_node(position._node);
				return (ret);
			}

			// @brief Erases elements according to the provided key.
			// @param key Key of element to be erased.
			// @return The number of elements erased.
			size_type erase(const key_type &key)
			{
				iterator it = find(key);
				if (it == end())
					return 0;
				del_node(it._node);
				return (1);
			}

			// @brief Erases a [first,last) range of elements from a map.
			// @param first Iterator pointing to the start of the range to be erased
			// @param last Iterator pointing to the end of the range to be erased
			// @return The iterator last.
			iterator erase(iterator first, iterator last)
			{
				while (first != last)
					del_node((first++)._node);
				return (last);
			}

			// @brief Swaps data with another map.
			// @param x A map of the same element and allocator types
			void swap(map &x)
			{
				std::swap(_content, x._content);
				std::swap(_cmp, x._cmp);
				std::swap(_size, x._size);
			}

			// @brief Erases all elements in a map.
			void clear()
			{
				if (_size == 0)
					return ;
				node_pointer tmp = end()._node;
				tmp->_parent->_right = NULL;
				tmp->_parent->_left = NULL;
				clear_tree(_content);
				_content = tmp;
				_size = 0;
			}
			
			/* ****************************************** */
			/*              Observers                     */
			/* ****************************************** */

			// @brief Returns the key comparison object out of which the map was constructed.
			key_compare	 key_comp() const
			{ return (_cmp); }

			// @brief Returns a value comparison object, built from the key comparison object out of which the map was constructed.
			value_compare value_comp() const 
			{ return (value_compare(key_compare())); }

			/* ****************************************** */
			/*              Lookup                        */
			/* ****************************************** */

			// @brief Tries to locate an element in a map.
			// @param k Key of pair to be located.
			// @return Iterator pointing to sought-after element, or end() if not found.
			iterator find(const key_type &k)
			{
				for (iterator tmp = begin(); tmp != end(); tmp++)
				{
					if (tmp->first == k)
						return tmp;
				}
				return (end());
			}

			// @brief Tries to locate an element in a map.
			// @param k Key of pair to be located.
			// @return Read-only (constant) iterator pointing to sought-after element, or end() if not found.
			const_iterator find(const key_type &k) const
			{
				for (const_iterator tmp = begin(); tmp != end(); tmp++)
				{
					if (tmp->first == k)
						return tmp;
				}
				return (end());
			}

			// @brief Finds the number of elements with given key.
			// @param k Key of (key, value) pairs to be located.
			// @return for map the result will either be 0 (not present) or 1 (present).
			size_type count(const key_type &k) const
			{
				for (const_iterator tmp = begin(); tmp != end(); tmp++)
				{
					if (tmp->first == k)
						return (1);
				}
				return (0);
			}

			// @brief Finds the beginning of a subsequence matching given key.
			// @param k Key of (key, value) pair to be located.
			// @return This function returns the first element of a subsequence of elements that matches the given key.
			iterator lower_bound(const key_type &k)
			{
				for (iterator tmp = begin(); tmp != end(); ++tmp)
				{
					if (!_cmp(tmp->first, k))
						return (tmp);
				}
				return end();
			}

			// @brief Finds the beginning of a subsequence matching given key.
			// @param k Key of (key, value) pair to be located.
			// @return Read-only (constant) iterator pointing to first element equal to or greater than key, or end().
			const_iterator lower_bound(const key_type &k) const
			{
				for (const_iterator tmp = begin(); tmp != end(); ++tmp)
				{
					if (!_cmp(tmp->first, k))
						return tmp;
				}
				return end();
			}

			// @brief Finds the end of a subsequence matching given key.
			// @param k Key of (key, value) pair to be located
			// @return Iterator pointing to the first element greater than key, or end()
			iterator upper_bound(const key_type &k)
			{
				for (iterator tmp = begin(); tmp != end(); ++tmp)
				{
					if (_cmp(k, tmp->first))
						return tmp;
				}
				return end();
			}

			// @brief Finds the end of a subsequence matching given key.
			// @param k Key of (key, value) pair to be located.
			// @return Read-only (constant) iterator pointing to first iterator greater than key, or end().
			const_iterator upper_bound(const key_type &k) const
			{
				for (const_iterator tmp = begin(); tmp != end(); ++tmp)
				{
					if (_cmp(k, tmp->first))
						return tmp;
				}
				return end();
			}

			// @brief Returns a range containing all elements with the given key in the container.
			// @param k key value to compare the elements
			// @return std::pair containing a pair of iterators 
			pair<iterator,iterator>	 equal_range(const key_type &k)
			{ return (ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k))); }
	
			// @brief Returns a range containing all elements with the given key in the container.
			// @param k key value to compare the elements
			// @return std::pair containing a pair of const_iterators
			pair<const_iterator,const_iterator>	equal_range(const key_type &k) const
			{ return (ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k))); }


			// @brief Checks if the contents of lhs and rhs are equal
			// @param lhs maps whose contents to compare
			// @param rhs maps whose contents to compare
			// @return true if the contents of the maps are equal, false otherwise
			friend bool operator==(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
			{
				if (lhs.size() != rhs.size())
					return 0;
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}

			// @brief Checks if the contents of lhs and rhs are equal
			// @param lhs maps whose contents to compare
			// @param rhs maps whose contents to compare
			// @return true if the contents of the maps are not equal, false otherwise
			friend bool operator!=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
			{ return (!(lhs == rhs)); }

			// @brief Compares the contents of lhs and rhs lexicographically.
			// @param lhs maps whose contents to compare
			// @param rhs maps whose contents to compare
			// @return true if the contents of the lhs are lexicographically less than the contents of rhs, false otherwise
			friend bool operator< (const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
			{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

			// @brief Compares the contents of lhs and rhs lexicographically.
			// @param lhs maps whose contents to compare
			// @param rhs maps whose contents to compare
			// @return true if the contents of the lhs are lexicographically less than or equal to the contents of rhs, false otherwise
			friend bool operator<=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
			{ return (!(rhs < lhs)); }

			// @brief Compares the contents of lhs and rhs lexicographically.
			// @param lhs maps whose contents to compare
			// @param rhs maps whose contents to compare
			// @return true if the contents of the lhs are lexicographically greater than the contents of rhs, false otherwise
			friend bool operator>(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
			{ return ((rhs < lhs)); }

			// @brief Compares the contents of lhs and rhs lexicographically.
			// @param lhs maps whose contents to compare
			// @param rhs maps whose contents to compare
			// @return true if the contents of the lhs are lexicographically greater than or equal to the contents of rhs, false otherwise
			friend bool operator>=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
			{ return (!(lhs < rhs)); }

			// @brief swap 2 map
			// @param a map to swap
			// @param b map to swap
			friend void swap(map<Key, T, Compare, Allocator> &a, map<Key, T, Compare, Allocator> &b)
			{ a.swap(b); }

		private :

			// @brief add a new node to the tree
			// @param node_ptr node to add
			void new_node(node_pointer node_ptr)
			{
				node_pointer	*parent = &_content;
				node_pointer	*node = &_content;
				node_pointer	end = fmax(_content);
				++_size;
				while (*node && *node != end)
				{
					parent = node;
					if (_cmp(node_ptr->_value.first, (*node)->_value.first))
						node = &(*node)->_left;
					else
						node = &(*node)->_right;
				}
				if (*node == NULL)
				{
					node_ptr->_parent = (*parent);
					*node = node_ptr;
				}
				else
				{
					*node = node_ptr;
					node_ptr->_parent = end->_parent;
					end->_parent = fmax(node_ptr);
					fmax(node_ptr)->_right = end;
				}
			}

			// @brief del node to the tree
			// @param node_ptr node to del
			void del_node(node_pointer node_ptr)
			{
				node_pointer	new_node_ptr = NULL;
				node_pointer	*node_adr = &_content;
				if (node_ptr->_parent)
					node_adr = (node_ptr->_parent->_left == node_ptr ? &node_ptr->_parent->_left : &node_ptr->_parent->_right);
				if (node_ptr->_left == NULL && node_ptr->_right == NULL)
					;
				else if (node_ptr->_left == NULL)
					new_node_ptr = node_ptr->_right;
				else
				{
					new_node_ptr = fmax(node_ptr->_left);
					if (new_node_ptr != node_ptr->_left)
						if ((new_node_ptr->_parent->_right = new_node_ptr->_left))
							new_node_ptr->_left->_parent = new_node_ptr->_parent;
				}
				if (new_node_ptr)
				{
					new_node_ptr->_parent = node_ptr->_parent;
					if (node_ptr->_left && node_ptr->_left != new_node_ptr)
					{
						new_node_ptr->_left = node_ptr->_left;
						new_node_ptr->_left->_parent = new_node_ptr;
					}
					if (node_ptr->_right && node_ptr->_right != new_node_ptr)
					{
						new_node_ptr->_right = node_ptr->_right;
						new_node_ptr->_right->_parent = new_node_ptr;
					}
				}
				*node_adr = new_node_ptr;
				--_size;
				delete node_ptr;
			}

	}; /* class Map */

} /* namespace ft */

#endif /* _MAP_HPP_ */