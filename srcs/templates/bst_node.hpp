/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:45:25 by francisco         #+#    #+#             */
/*   Updated: 2021/04/03 12:02:01 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_NODE_HPP

# define BST_NODE_HPP

# include "ft_containers.hpp"

# define _BST_NODE_TP template<\
		typename	Key,\
		bool 		B,\
		class		KCompare = std::less<Key>,\
		typename 	V = Key,\
		class		VCompare = std::less<V>\
		>

# define _BST_NODE_TP_INTIT Key, B, KCompare, V, VCompare
namespace ft {

	_BST_NODE_TP
	class bst_node {
		public:
			typedef	V													value_type;
			typedef	Key													key_type;
			typedef	long int											difference_type;
			typedef	size_t												size_type;
			typedef	KCompare											key_compare;
			typedef	VCompare											value_compare;

			typedef	value_type&											reference;
			typedef	const value_type&									const_reference;
			typedef	value_type*											pointer;
			typedef	const value_type*									const_pointer;

			key_type	key;
			value_type	value;
			bst_node    *left;
			bst_node    *right;
			bst_node	*parent;

			bst_node::bst_node(key_type k = key_type(), value_type v = value_type):
			key(k),
			value(v),
			left(NULL),
			right(NULL),
			parent(NULL) {}

			bst_node::bst_node(const bst_node<Key, false, V> &src):
			key(src.key)
			value(src.value),
			left(src.left),
			right(src.right),
			parent(src.parent) {}

			bst_node::~bst_node() {}

			bst_node	&operator=(const bst_node src) {
				bst_node	cpy(src);

				this->swap(cpy);
				return *this;
			}


			private:
				void	swap(bst_node x) {
					bst_node tmp(*this);

					this->value(x.value);
					this->left(x.left);
					this->right(x.right);
					this->parent(x.parent);

					x.value(tmp.value);
					x.left(tmp.left);
					x.right(tmp.right);
					x.parent(tmp.parent);
				}
	};

	_BST_NODE_TP
	bool		operator==(const bst_node<_BST_NODE_TP_INTIT> &lhs,\
							const bst_node<_BST_NODE_TP_INTIT> &rhs)
	{
		return !lhs::key_compare(lhs.key, rhs.key) &&\
				!lhs::key_compare(rhs.key, lhs.key);
	}

	_BST_NODE_TP
	bool		operator!=(const bst_node<_BST_NODE_TP_INTIT> &lhs,\
							const bst_node<_BST_NODE_TP_INTIT> &rhs)
	{
		return !(lhs == rhs);
	}

	_BST_NODE_TP
	bool		operator<(const bst_node<_BST_NODE_TP_INTIT> &lhs,\
							const bst_node<_BST_NODE_TP_INTIT> &rhs)
	{
		return lhs::key_compare(lhs.key, rhs.key);
	}

	_BST_NODE_TP
	bool		operator<=(const bst_node<_BST_NODE_TP_INTIT> &lhs,\
							const bst_node<_BST_NODE_TP_INTIT> &rhs)
	{
		return lhs < rhs || lhs == rhs;
	}

	_BST_NODE_TP
	bool		operator>(const bst_node<_BST_NODE_TP_INTIT> &lhs,\
							const bst_node<_BST_NODE_TP_INTIT> &rhs)
	{
		return lhs.key > rhs.key;
	}

	_BST_NODE_TP
	bool		operator<(const bst_node<_BST_NODE_TP_INTIT> &lhs,\
							const bst_node<_BST_NODE_TP_INTIT> &rhs)
	{
		return lhs < rhs || lhs == rhs;
	}
}

#endif