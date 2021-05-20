/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:30:05 by francisco         #+#    #+#             */
/*   Updated: 2021/05/20 18:10:49 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef map_iterator_HPP

# define map_iterator_HPP

# include "ft_containers.hpp"

namespace ft {

	template<typename T, bool B>
	class map_iterator {
		public:
			typedef std::ptrdiff_t									difference_type;
			typedef T												value_type;
			typedef size_t											size_type;
			
			typedef typename ConstBool<B, T&, const T&>::type		reference;
			typedef typename ConstBool<B, T*, const T*>::type		pointer;
			typedef	ft::bst<T>										node;
			typedef	ft::bst<T>*										nodePtr;
			typedef ft::bst<T>										bst;
			
			map_iterator(const nodePtr ptr = 0): _current(ptr) {}
			map_iterator(const map_iterator<T, false> &src) { _current = src.getNodePtr(); }
			~map_iterator() {}

			nodePtr			getNodePtr() const { return _current; }

			map_iterator	&operator=(const map_iterator &src) {
				if (this != &src)
					this->_current = src._current;
				return *this;
			}

			reference		operator*() const { return _current->content; }
			pointer			operator->() const { return &(_current->content); }
			map_iterator	&operator++() {
				_current = _next_node(_current);
				return *this;
			}
			map_iterator	operator++(int) {
				map_iterator	tmp(*this);
				++(*this);
				return tmp;
			}
			map_iterator	&operator--() {
				_current = _prev_node(_current);	
				return *this;
			}
			map_iterator	operator--(int) {
				map_iterator	tmp(*this);
				--(*this);
				return tmp;
			}

			bool			operator==( const map_iterator &it ) const { return this->_current == it._current; }
			bool			operator!=( const map_iterator &it ) const { return this->_current != it._current; }
		private:
			bst*			_current;
	};
}

#endif 	