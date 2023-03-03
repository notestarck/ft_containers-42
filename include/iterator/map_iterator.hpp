/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:47:51 by estarck           #+#    #+#             */
/*   Updated: 2023/02/27 09:02:27 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_ITERATOR_HPP_
#define _MAP_ITERATOR_HPP_

#include "../iterator/iterator.hpp"

namespace ft
{

	template <typename T, typename tree_node>
	class map_iterator
	{

		public:
			typedef T								value_type;
			typedef value_type&						reference;
			typedef value_type*						pointer;
			typedef std::ptrdiff_t					difference_type;
			typedef ft::bidirectional_iterator_tag iterator_category;

			map_iterator() : _node(NULL)
			{}

			map_iterator(const map_iterator &other)
			{*this = other;}

			~map_iterator()
			{}

			map_iterator &operator=(map_iterator const &other)
			{
				if (this == &other)
					return (*this);
				_node = other._node;
				return (*this);
			}

			bool operator==(const map_iterator &other) const
			{ return (_node == other._node); }

			bool operator!=(const map_iterator &other) const
			{ return (_node != other._node); }

			map_iterator &operator++()
			{
				tree_node *previous = _node;
				if (_node->_right)
					_node = fmin(_node->_right);
				else
				{
					_node = _node->_parent;
					while (_node && previous == _node->_right)
					{
						previous = _node;
						_node = _node->_parent;
					}
				}
				return (*this);
			}

			map_iterator operator++(int)
			{
				map_iterator tmp(*this);
				++(*this);
				return (tmp);
			}

			map_iterator &operator--()
			{
				tree_node *previous = _node;
				if (_node->_left != NULL)
					_node = fmax(_node->_left);
				else
				{
					_node = _node->_parent;
					while (_node && previous == _node->_left)
					{
						previous = _node;
						_node = _node->_parent;
					}
				}
				return (*this);
			}

			map_iterator operator--(int)
			{
				map_iterator tmp(*this);
				--(*this);
				return (tmp);
			}

			reference operator*() const
			{ return (_node->_value); }

			pointer operator->() const
			{ return &_node->_value; }

			operator map_iterator<const T, tree_node>() const
			{return map_iterator<const T, tree_node>(_node);}

			template <class, class, class, class> friend class map;
			template <class, class> friend class map_iterator;

		private:
			tree_node	*_node;

			map_iterator(tree_node *other)
			{_node = other;}

	};/* class map_iterator */

}// namespace ft

#endif /* _MAP_ITERATOR_HPP_ */