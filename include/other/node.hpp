/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:01:27 by estarck           #+#    #+#             */
/*   Updated: 2023/03/01 11:14:25 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _NODE_HPP_
#define _NODE_HPP_

namespace ft
{
	// @brief Node for map
	// @tparam T pair<const key_type, mapped_type>
	template <class T>
	struct Node
	{
		public:
		T			_value;
		Node		*_parent;
		Node		*_left;
		Node		*_right;

		Node(const T &src = T()) : _value(src), _parent(NULL), _left(NULL), _right(NULL) {};
	}; /* class Node */

	// @brief find max value in Node
	// @param Node to find
	// @return max value in Node
	template <class T>
	Node<T>	*fmax(Node<T> *Node) {
		while (Node->_right)
			Node = Node->_right;
		return Node;
	}
	
	// @brief find min value in Node
	// @param Node to find
	// @return min value in node
	template <class T>
	Node<T>	*fmin(Node<T> *Node) {
		while (Node->_left)
			Node = Node->_left;
		return Node;
	}

	// @brief search_node corresponding to key
	// @param node start node
	// @param key find key
	// @return good node with good key
	template <class T, class key_type>
	Node<T> *search_node(Node<T> *node, key_type &key)
	{
	    if (node == NULL || node->_value.first == key)
	        return node;
	    if (node->_value.first < key)
	        return search_node(node->_right, key);
	
	    return (search_node(node->_left, key));
	}

	template <class T>
	void clear_tree(ft::Node<T> *node)
	{
		if (!node)
			return ;
		clear_tree(node->_left);
		clear_tree(node->_right);
		delete node;
	}

}/* namespace ft */

#endif /* _NODE_HPP_ */