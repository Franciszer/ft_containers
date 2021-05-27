/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:56:52 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/27 15:58:02 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

#ifndef	STACK_HPP

#define STACK_HPP

namespace ft {
	
	template <class T, class Container = list<T> >
	class stack {
		public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;


		explicit stack (const container_type& ctnr = container_type()): _c(ctnr) {}

		bool	empty() const {
			return _c.empty();
		}
		
		size_type size() const {
			return _c.size();
		}

		value_type& top() {
			return _c.back();
		}
		
		const value_type& top() const {
			return _c.back();
		}

		void push (const value_type& val) {
			_c.push_back(val);
		}

		void pop() {
			_c.pop_back();
		}
		private:
		
		container_type	_c;
	
		friend bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
				return lhs._c == rhs._c;
		}

		friend bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs._c != rhs._c;
		}

		friend bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs._c < rhs._c;
		}

		friend bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs._c > rhs._c;
		}

		friend bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs._c <= rhs._c;
		}

		friend bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs._c >= rhs._c;
		}

		void swap (stack<T,Container>& x, stack<T,Container>& y) {
				x._c.swap(y._c);
		}
	};

}

#endif