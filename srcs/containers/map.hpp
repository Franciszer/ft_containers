/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 08:24:17 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/20 12:55:03 by frthierr         ###   ########.fr       */
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
              const allocator_type& alloc = allocator_type()) {
				  _construct(comp, alloc);
			  }	
	
		// template <class InputIterator>
		// map (InputIterator first, InputIterator last,
		// 	const key_compare& comp = key_compare(),
		// 	const allocator_type& alloc = allocator_type(),
		// 	typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) {
				
		// 	}
		
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

		void		_construct(const Compare& comp, const Allocator &alloc) {
			_comp_key = comp;
			_alloc = alloc;
			_root = _new_node(ft::make_pair(key_type(), mapped_type()));
			_last_created = NULL;
			_already_present = NULL;
			_end = _root;
			_size = 0;
		}
		
		bst*		_new_node(const value_type& content) {
			bst*	new_node = _alloc_node.allocate(sizeof(bst));
			_alloc.construct(&new_node->content, content);
			new_node->left = NULL;
			new_node->right = NULL;
			new_node->parent = NULL;
			return new_node;
		}

		void		_free_node(bst* node) {
			_alloc.destroy(&node->content);
			_alloc_node.deallocate(node, sizeof(bst));
		}

		bst*		_insert_element(const value_type& content, bst* node) {
			if (!node || node == _end) {
				++_size;
				_last_created = _new_node(content);
				if (node == _end) {
					_last_created->right = _end;
					_end->parent = _last_created;
				}
				return _last_created;
			}
			else if (_comp_key(content.first, node->content.first)) { // content smaller than current node's
				bst*	left_child = _insert_element(content, node->left);
				node->left = left_child;
				left_child->parent = node;
			}
			else if (content.first != node->content.first) { // content greater than current node's
				bst*	right_child = _insert_element(content, node->right);
				node->right = right_child;
				right_child->parent = node;
			}
			return node;
		}

		// bst*		_delete_element()

		typename Allocator::template rebind<bst>::other		_alloc_node;
		Compare		_comp_key;
		Allocator	_alloc;
		bst*		_root;	
		bst*		_last_created;	
		bst*		_already_present;	
		bst*		_end;
		size_type	_size;
			
};

}

#endif
