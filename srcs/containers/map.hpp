/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 08:24:17 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/23 13:15:53 by frthierr         ###   ########.fr       */
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
		typedef	ft::map_iterator<value_type, false>		iterator;
		typedef	ft::map_iterator<value_type, true>		const_iterator;
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
	
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) {
				_construct(comp, alloc);
				for (; first != last ; first++)
					insert(*first);
			}
		
		map (const map& x) {
			_construct(Compare(), Allocator());
			for (const_iterator it = x.begin() ; it != x.end(); it++)
				insert(*it);
		}

		map& operator=(const map& x) {
			if (this != &x) {
				for (auto it = x.begin(); it != x.end(); it++)
					this->insert(*it);
			}
		}

		iterator begin() {
			return iterator(ft::_min_value(_root));
		}
		const_iterator begin() const {
			return const_iterator(ft::_min_value(_root));
		}
		iterator end() {
			return iterator(_end);
		}
		const_iterator end() const {
			return const_iterator(_end);
		}
		reverse_iterator rbegin() {
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(end());
		}
		reverse_iterator rend() {
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend() const {
			return const_reverse_iterator(begin());
		}

		bool empty() const {
			return _size == 0;
		}
		size_type size() const {
			return _size;
		}
		
		size_type max_size() const;

		mapped_type& operator[] (const key_type& k);

		pair<iterator,bool> insert (const value_type& val) {
			bst*	node;
			size_type prevsize = _size;
			_insert_element(val, _root);
			node = _size > prevsize ? _last_created : _already_present;
			if (_root == _end) {
				_root = node;
				_root->right = _end;
				_end->parent = _root;
			}
			return ft::make_pair(iterator(node), _size > prevsize);
		}
		iterator insert (iterator position, const value_type& val) {
			bst*	hint = position.getNodePtr();
			size_type	tmp = _size;
			_insert_element(val, hint);
			if (_size == tmp)
				_insert_element(val, _root);
			bst* node = _size == tmp ? _already_present : _last_created;
			return iterator(node);
		}
		
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last,\
			typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) {
			for (; first != last ; first++)
				this->insert(*first);
		}

		void erase (iterator position) {
			erase(position.getNodePtr()->content.first);
		}

		size_type erase (const key_type& k) {
			size_type	tmp = _size;
			_delete_element(k, _root);
			return static_cast<size_type>(tmp == _size);
		}
		void erase (iterator first, iterator last) {
			for (; first != last; first++)
				erase(first);
		}
		void swap (map& x) {
			bst* root_tmp = _root;
			_root = x._root;
			x._root = root_tmp;	

			bst* last_created_tmp = _last_created;
			_last_created = x._last_created;
			x._last_created = last_created_tmp;

			bst* already_present_tmp = _already_present;
			_already_present = x._already_present;
			x._already_present = already_present_tmp;

			bst* end_tmp = _end;
			_end = x._end;
			x._end = end_tmp;

			size_type size_tmp = _size;
			_size = x._size;
			x._size = size_tmp;
		}
		void clear();

		key_compare key_comp() const {
			return key_comp;
		}
		
		value_compare value_comp() const {
			return value_compare(key_comp);
		}

		iterator find(const key_type& k) {
			bst*	node = _find(k, _root);
			if (!node)
				return iterator(_end);
			return iterator(node);		}

		const_iterator find(const key_type& k) const {
			bst*	node = _find(k, _root);
			
			if (!node)
				return iterator(_end);
			return iterator(node);
		}

		size_type count (const key_type& k) const {
			find(k);
			return find(k) != end();
		}
		
		iterator lower_bound (const key_type& k) {
			iterator it = begin();
			while (it != end()) {
				if (!_comp_key(it->first, k))
					return it;
				it++;
			}
			return end();
		}
		const_iterator lower_bound (const key_type& k) const {
			iterator it = begin();
			while (it != end()) {
				if (!_comp_key(it->first, k))
					return it;
				it++;
			}
			return end();
		}
		iterator upper_bound (const key_type& k) {
			iterator it = begin();
			while (it != end()) {
				if (_comp_key(k, it->first))
					return it;
				it++;
			}
			return end();
		}
		const_iterator upper_bound (const key_type& k) const {
			iterator it = begin();
			while (it != end()) {
				if (_comp_key(k, it->first))
					return it;
				it++;
			}
			return end();
		}
		
		pair<iterator,iterator> equal_range( const Key& key ) {
            return make_pair(lower_bound(key), upper_bound(key));
        }
    	pair<const_iterator,const_iterator> equal_range( const Key& key ) const {
			return make_pair(lower_bound(key), upper_bound(key));
        }
		
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
					_end->parent = _last_created;
					_last_created->right = _end;
				}
				return _last_created;
			}
			else if (_comp_key(content.first, node->content.first)) { // content smaller than current node's
				bst*	left_child = _insert_element(content, node->left);
				node->left = left_child;
				left_child->parent = node;
			}
			else if (_comp_key(node->content.first, content.first)) { // content greater than current node's
				bst*	right_child = _insert_element(content, node->right);
				node->right = right_child;
				right_child->parent = node;
			}
			else
				_already_present = node;
			return node;
		}

		bst*		_delete_element(const key_type& key, bst* node) {
			if (!node || node == _end) { // not found
				return node;
			}
			if (_comp_key(key, node->content.first)) {
				node->left = _delete_element(key, node->left);
				return node;
			}
			else if (_comp_key(node->content.first, key)) {
				node->right = _delete_element(key, node->right);
				return node;
			}
			_size -= 1;
			if (!node->left && !node->right) { // case no children
				if (node == _root)
					_root = _end;
				_free_node(node);
				return NULL;
			}
			else if (node->left != node->right) { // case one child
				bst* tmp = node->left ? node->left : node->right;
				tmp->parent = node->parent;
				if (node == _root)
					_root = tmp;
				_free_node(node);
				return tmp;
			}
			else { // case both children
				bst*	successor_parent = node;
				bst*	successor = node->right;
				while (successor->left) { // find smallest node of right subtree
					successor_parent = successor;
					successor = successor->left;
				}
				if (successor_parent != node)
					successor_parent->left = successor->right;
				else
					successor_parent->right = successor_parent->right;
				if (successor->right)
					successor->right->parent = successor_parent;
				successor->right = node->right;
				if (successor->right)
					successor->right->parent = successor;
				successor->left = node->left;
				if (successor->left)
					successor->left->parent = successor;
				successor->parent = node->parent;
				if (node == _root)
					_root = successor;
				_free_node(node);
				return successor;
			}
		}

		bst*	_find(const Key& key, bst* node) const {
			if (!node || node == _end || key == node->content.first) // end of search
				return node;
			else if (_comp_key(key, node->content.first))	// case left
				return _find(key, node->left);
			else 											// case right
				return _find(key, node->right);
		}

		void	_clear(bst* node) {
			if (node->left)
				_clear(node->left);
			if (node->right)
				_clear(node->right);
			_free_node(node);
		}

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
