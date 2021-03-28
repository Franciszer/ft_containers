/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:45:25 by francisco         #+#    #+#             */
/*   Updated: 2021/03/28 14:25:18 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_NODE_HPP

# define BST_NODE_HPP

# include "ft_containers.hpp"

namespace ft {

	template<typename T>
	class bst_node {
		public:
			typedef	T													value_type;
			typedef	long int											difference_type;

		protected:
			T           content;
			bst_node    *left;
			bst_node    *right;
			bst_node	*parent;
	};

	template<typename T>
	class	avl_tree_node: public bst_node {
		difference_type	height;
	}
}

#endif