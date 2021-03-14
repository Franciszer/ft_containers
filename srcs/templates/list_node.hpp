/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_node.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:43:25 by francisco         #+#    #+#             */
/*   Updated: 2021/03/14 13:08:12 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_NODE_HPP

# define LIST_NODE_HPP

# include "ft_containers.hpp"

namespace ft {

    template<typename T>
    struct list_node {
        T           content;
        list_node   *prev;
        list_node   *next;
    };
}

#endif