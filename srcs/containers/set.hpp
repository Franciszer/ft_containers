/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:34:01 by francisco         #+#    #+#             */
/*   Updated: 2021/03/26 23:41:34 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     SET_HPP

# define    SET_HPP

# include "ft_containers" 

namespace ft {
    

template< class T,
          class Compare = std::less<T>,
          class Alloc = std::allocator<T>
          > class set {

			typedef	T													value_type;
			typedef	T													key_type;
			typedef	Compare												key_compare;
			typedef	Compare												value_compare;
			typedef	Alloc												allocator_type;
			typedef	long int											difference_type;
			typedef	size_t												size_type;

			typedef	T&													reference;
			typedef	const T&											const_reference;
			typedef	T*													pointer;
			typedef	const T*											const_pointer;
			
			// typedef typename ft::set_iterator<T, false>				iterator;
			// typedef typename ft::set_iterator<T, true>				const_iterator;

			// typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
			// typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;

}

}

#endif