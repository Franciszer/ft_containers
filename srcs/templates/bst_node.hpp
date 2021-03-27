/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:45:25 by francisco         #+#    #+#             */
/*   Updated: 2021/03/26 23:48:27 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_NODE_HPP

# define BST_NODE_HPP

# include "ft_containers.hpp"

namespace ft {

    template<typename T>
    struct bst_node {
        T           content;
        bst_node    *left;
        bst_node    *right;
        bst_node    *parent;
    };
}

#endif