/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:34:01 by francisco         #+#    #+#             */
/*   Updated: 2021/03/28 17:59:38 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     SET_HPP

# define    SET_HPP

# include "ft_containers" 

namespace ft {
    
using ft::pair;

template< class T,
          class Compare = std::less<T>,
          class Alloc = std::allocator<T>
          > class set {
			
			public:
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
			
				typedef typename ft::bst_iterator<T, false>					iterator;
								typedef typename ft::bst_iterator<T, true>					const_iterator;

				typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
				typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			

				explicit set (const key_compare& comp = key_compare(),
            		const allocator_type& alloc = allocator_type());

				template <class InputIterator>
				set (InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type());

				set (const set& x);

				~set();

				set& operator= (const set& x);

				iterator begin();
				const_iterator begin() const;
				
				iterator end();
				const_iterator end() const;

				reverse_iterator rbegin();
				const_reverse_iterator rbegin() const;

				reverse_iterator rend();
				const_reverse_iterator rend() const;

				bool empty() const;

				size_type size() const

				size_type max_size() const;

				pair<iterator,bool> insert (const value_type& val);
				iterator insert (iterator position, const value_type& val);
				template <class InputIterator>
				void insert (InputIterator first, InputIterator last);

			private:
				key_compare		_comp;

}

}

#endif