/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bidirectional_iterator.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 13:40:24 by frthierr          #+#    #+#             */
/*   Updated: 2021/02/06 13:25:24 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_BIDIRECTIONNAL_ITERATOR_HPP

#define REVERSE_BIDIRECTIONNAL_ITERATOR_HPP

#include "ft_containers.hpp"

namespace ft
{
	template<typename T, bool B>
	class reverse_bidirectional_iterator
	{
		public:

			/* -------- ALIASES -------- */
			
			typedef long int										difference_type;
			typedef T												value_type;
			typedef size_t											size_type;
			
			typedef typename ConstBool<B, T&, const T&>::type		reference;
			typedef typename ConstBool<B, T*, const T*>::type		pointer;
			typedef T*												nonConstPointer;


			/* -------- CONSTRUCTORS / DESTRUCTOR / ASSIGNMENT -------- */

			reverse_bidirectional_iterator(nonConstPointer val = 0) : _val(val) {}
			reverse_bidirectional_iterator(const reverse_bidirectional_iterator<T, false>& src) { _val = src.getNonConstPointer(); }
			reverse_bidirectional_iterator(const ft::bidirectional_iterator<T, false>& src) { _val = src.getNonConstPointer(); }
			~reverse_bidirectional_iterator() {}

			nonConstPointer	getNonConstPointer() const		{ return _val; }

			reverse_bidirectional_iterator& operator=(const reverse_bidirectional_iterator& assign)
			{
				if (this != &assign)
					_val = assign._val;
				return (*this);
			}


			/* -------- OPERATORS -------- */

			// INTPUT / OUTPUT / FORWARD / BIDIRECTIONNAL ITERATOR PART

			reference operator*()			{ return (*_val); }
			pointer operator->() const		{ return (_val); }

			reverse_bidirectional_iterator& operator++()		{ --_val; return (*this); }
			reverse_bidirectional_iterator operator++(int)		{ reverse_bidirectional_iterator res(*this); ++(*this); return (res); };
			reverse_bidirectional_iterator& operator--()		{ ++_val; return (*this); }
			reverse_bidirectional_iterator operator--(int)		{ reverse_bidirectional_iterator res(*this); --(*this); return (res); };
			
			bool operator==(const reverse_bidirectional_iterator& it) const	{ return (it._val == _val); }
			bool operator!=(const reverse_bidirectional_iterator& it) const	{ return (it._val != _val); }

			protected:

				nonConstPointer	_val;
	};
}

#endif