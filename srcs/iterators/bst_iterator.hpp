/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:47:22 by francisco         #+#    #+#             */
/*   Updated: 2021/03/26 23:59:00 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_ITERATOR_HPP

# define BST_ITERATOR_HPP

# include "ft_containers.hpp"

namespace ft {

	template<typename T, bool B, class Compare>
	class bst_iterator {
		public:
			typedef	T													value_type;
			typedef	T													key_type;
			typedef	Compare												key_compare;
			typedef	Compare												value_compare;

			typedef long int										    difference_type;
			typedef size_t											    size_type;
			
			typedef typename ConstBool<B, T&, const T&>::type		    reference;
			typedef typename ConstBool<B, T*, const T*>::type		    pointer;
			typedef	ft::bst_node<T>								        node;
			typedef	ft::bst_node<T>*								    nodePtr;
			
			bst_iterator(nodePtr ptr = 0): _current(ptr) {}
			bst_iterator(const bst_iterator<T, false> &src) { _current = src.getNodePtr(); }
			~bst_iterator() {}

			nodePtr			getNodePtr() const { return _current; }

			bst_iterator	&operator=(const bst_iterator &src) {
				if (this != &src)
					this->_current = src._current;
				return *this;
			}

			reference		operator*() const { return _current->content; }
			pointer			operator->() const { return &(_current->content); }
			bst_iterator	&operator++() {
				if (_current->left)
					_current = _current->left;
				else if (_current->right)
					_current = _current->right;
				else if (_current->parent)
					_current = _current->parent;
				return *this;
			}
			bst_iterator	operator++(int) {
				bst_iterator	tmp(*this);
				++(*this);
				return tmp;
			}
			bst_iterator	&operator--() { _current = _current->prev; return *this; }
			bst_iterator	operator--(int) {
				bst_iterator	tmp(*this);
				--(*this);
				return tmp;
			}

			bool			operator==( const bst_iterator &it ) const { return this->_current == it._current; }
			bool			operator!=( const bst_iterator &it ) const { return this->_current != it._current; }
		private:
			nodePtr			_current;
	};
}

#endif 	