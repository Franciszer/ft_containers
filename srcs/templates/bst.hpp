/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:42:55 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/20 11:08:20 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_H
# define BST_H

# include "ft_containers.hpp"

namespace ft {
	

template<class T>
struct bst {
	T		content;
	bool	color;
	bst		*parent;
	bst		*left;
	bst		*right;
};

template<class T>
bst<T>*	_min_value(bst<T>* node) {
	bst<T>*	current = node;
	while (current->left)
		current = current->left;
	return current;
}

template<class T>
bst<T>*	_max_value(bst<T>* node) {
	bst<T>*	current = node;
	while (current->right)
		current = current->right;
	return current;
}

template<class T>
bst<T>*	_next_node(bst<T>* node) {
	if (node->right)
		return _min_value(node->right);
	bst<T>	*parent = node->parent;
	while (parent && node == parent->right) {
		node = parent;
		parent = parent->parent;
	}
	return parent;
}

template<class T>
bst<T>*	_prev_node(bst<T>* node) {
	if (node->left)
		return _max_value(node->left);
	bst<T>	*parent = node->parent;
	while (parent && node == parent->left) {
		node = parent;
		parent = parent->parent;
	}
	return parent;
}

}

#endif