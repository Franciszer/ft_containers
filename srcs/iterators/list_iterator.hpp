/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:30:05 by francisco         #+#    #+#             */
/*   Updated: 2021/03/19 12:35:09 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATOR_HPP

# define LIST_ITERATOR_HPP

# include "ft_containers.hpp"

namespace ft {

	template<typename T, bool B>
	class list_iterator {
		public:
			typedef long int										difference_type;
			typedef T												value_type;
			typedef size_t											size_type;
			
			typedef typename ConstBool<B, T&, const T&>::type		reference;
			typedef typename ConstBool<B, T*, const T*>::type		pointer;
			typedef	ft::list_node<T>								node;
			typedef	ft::list_node<T>*								nodePtr;
			
			list_iterator(nodePtr ptr = 0): _current(ptr) {}
			list_iterator(const list_iterator<T, false> &src) { _current = src.getNodePtr(); }
			~list_iterator() {}

			nodePtr			getNodePtr() const { return _current; }

			list_iterator	&operator=(const list_iterator &src) {
				if (this != &src)
					this->_current = src._current;
				return *this;
			}

			reference		operator*() const { return _current->content; }
			pointer			operator->() const { return &(_current->content); }
			list_iterator	&operator++() { _current = _current->next; return *this; }
			list_iterator	operator++(int) {
				list_iterator	tmp(*this);
				++(*this);
				return tmp;
			}
			list_iterator	&operator--() { _current = _current->prev; return *this; }
			list_iterator	operator--(int) {
				list_iterator	tmp(*this);
				--(*this);
				return tmp;
			}

			bool			operator==( const list_iterator &it ) const { return this->_current == it._current; }
			bool			operator!=( const list_iterator &it ) const { return this->_current != it._current; }
		private:
			nodePtr	_current;
	};
}

#endif 	