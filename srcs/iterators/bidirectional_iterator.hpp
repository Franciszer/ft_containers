/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:45:20 by frthierr          #+#    #+#             */
/*   Updated: 2021/02/04 14:41:47 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSNAME_HPP

# define CLASSNAME_HPP

# include "ft_containers.hpp"

namespace ft {
	template<typename T, bool B>
	class	rev_bidirectional_iterator;

	template<typename T, bool B>
	class	bidirectional_iterator
	{
		public:
			typedef long int										difference_type;
			typedef T												value_type;
			typedef size_t											size_type;
			
			typedef typename ConstBool<B, T&, const T&>::type		reference;
			typedef typename ConstBool<B, T*, const T*>::type		pointer;
			typedef T*												nonConstPointer;
	
			bidirectional_iterator(nonConstPointer val = 0) : _val(val) {}
			bidirectional_iterator(const bidirectional_iterator<T, false>& src) { _val = src.getNonConstPointer(); }
			bidirectional_iterator(const rev_bidirectional_iterator<T, false>& src) { _val = src.getNonConstPointer(); }
			virtual ~bidirectional_iterator() {}

			nonConstPointer			getNonConstPointer() const {return _val;}
			
			bidirectional_iterator	&operator=(const bidirectional_iterator &src) {
				if (this != &src)
					_val = src._val;
				return *this;
			}

			reference operator*()			{ return (*_val); }
			pointer operator->() const		{ return (_val); }

			bidirectional_iterator& operator++()		{ ++_val; return (*this); }
			bidirectional_iterator operator++(int)		{ bidirectional_iterator res(*this); ++(*this); return (res); };
			bidirectional_iterator& operator--()		{ --_val; return (*this); }
			bidirectional_iterator operator--(int)		{ bidirectional_iterator res(*this); --(*this); return (res); };
			
			bool operator==(const bidirectional_iterator& it) const	{ return (it._val == _val); }
			bool operator!=(const bidirectional_iterator& it) const	{ return (it._val != _val); }
		protected:
			nonConstPointer												_val;
	};
}

#endif
