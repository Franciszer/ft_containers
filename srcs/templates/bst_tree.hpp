/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:17:30 by francisco         #+#    #+#             */
/*   Updated: 2021/04/03 12:02:07 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

#ifndef		BST_TREE_HPP

# define	BST_TREE_HPP

namespace ft {

template <
	class Key,\
	bool B,\
	class KCompare = std::less<Key>,\
	class V = Key,\
	class VCompare = std::less<V>,\
	class Alloc = std::allocator<bst_node<Key, B, V> >\
	>
class bst_tree
{
public:
	typedef bst_node<_BST_NODE_TP_INTIT>						node_type;
	typedef	node_type::value_type								value_type;
	typedef	node_type::key_type									key_type;
	typedef	node_type::key_compare								key_compare;
	typedef	node_type::value_compare							value_compare;
	typedef	Alloc												allocator_type;
	typedef	long int											difference_type;
	typedef	size_t												size_type;

	typedef	node_type&											reference;
	typedef	const node_type&									const_reference;
	typedef	node_type*											pointer;
	typedef	const node_type*									const_pointer;
	
	bst_tree(/* args */);
	~bst_tree();
private:
	node_type	_current;
	node_type	_leftmost;
	node_type	_rightmost;
	size_type	_size;
};


}

#endif