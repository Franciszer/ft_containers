/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 08:24:17 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/20 11:33:59 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP

# define MAP_HPP

# include "ft_containers.hpp"

namespace ft {

template< class Key, class T,
        class Compare = ft::less<Key>,
        class Allocator = std::allocator<ft::pair<const Key, T> >
> class map {
	public:
		typedef Key 									key_type;
        typedef T 										mapped_type;
        typedef ft::pair<const Key, T>					value_type;
        typedef std::size_t 							size_type;
        typedef std::ptrdiff_t 							difference_type;
        typedef Compare 								key_compare;
        typedef Allocator 								allocator_type;
        typedef typename Allocator::reference	 		reference;
        typedef typename Allocator::const_reference		const_reference;
        typedef typename Allocator::pointer				pointer;
        typedef typename Allocator::const_pointer		const_pointer;
		typedef bst<value_type> 						bst;
		typedef	ft::map_iterator<T, false>				iterator;
		typedef	ft::map_iterator<T, true>				const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;


		class value_compare {
		public:
			explicit value_compare( Compare c ) : comp(c) {}

			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

			bool operator()( const value_type& lhs, const value_type& rhs ) const {
				return comp(lhs.first, rhs.first);
			}

		protected:
			Compare comp;
		};
		
		explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type());		
	
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type());
		
		map (const map& x);

		map& operator=(const map& x);

		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		mapped_type& operator[] (const key_type& k);

		pair<iterator,bool> insert (const value_type& val);
		iterator insert (iterator position, const value_type& val);
		
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last);

		void erase (iterator position);
		size_type erase (const key_type& k);
		void erase (iterator first, iterator last);
		void swap (map& x);
		void clear();

		key_compare key_comp() const;
		value_compare value_comp() const;

		iterator find (const key_type& k);
		const_iterator find (const key_type& k) const;
		size_type count (const key_type& k) const;
		iterator lower_bound (const key_type& k);
		const_iterator lower_bound (const key_type& k) const;
		iterator upper_bound (const key_type& k);
		const_iterator upper_bound (const key_type& k) const;
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
		pair<iterator,iterator>             equal_range (const key_type& k);
	private:
		typename Allocator::template rebind<bst>::other		_alloc;
		bst*		_root;	
		bst*		_last_created;	
		bst*		_already_present;	
		bst*		_end;
		size_type	_size;
			
};

}

#endif
