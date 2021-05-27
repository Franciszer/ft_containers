/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:56:52 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/27 16:59:27 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

#ifndef	QUEUE_HPP

#define QUEUE_HPP

namespace ft {
	
	template <class T, class Container = list<T> >
	class queue {
		public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;


		explicit queue (const container_type& ctnr = container_type()): _c(ctnr) {}

		queue(const queue &src): _c(src._c) {}
		
		queue &operator=(const queue &rhs) {
			if (this != &rhs)
				_c = rhs._c;
			return *this;
		}

		virtual ~queue() {}

		bool	empty() const {
			return _c.empty();
		}
		
		size_type size() const {
			return _c.size();
		}

		value_type& front() {
			return _c.front();
		}
		
		const value_type& front() const {
			return _c.front();
		}

		value_type& back() {
			return _c.back();
		}
		
		const value_type& back() const {
			return _c.back();
		}
		
		void push (const value_type& val) {
			_c.push_back(val);
		}

		void pop() {
			_c.pop_front();
		}
		private:
		
		container_type	_c;
	
		friend bool operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
				return lhs._c == rhs._c;
		}

		friend bool operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
			return lhs._c != rhs._c;
		}

		friend bool operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
			return lhs._c < rhs._c;
		}

		friend bool operator>(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
			return lhs._c > rhs._c;
		}

		friend bool operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
			return lhs._c <= rhs._c;
		}

		friend bool operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
			return lhs._c >= rhs._c;
		}

		void swap (queue<T,Container>& x, queue<T,Container>& y) {
				x._c.swap(y._c);
		}
	};

}

#endif