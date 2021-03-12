/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_vector_iterator.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:43:22 by frthierr          #+#    #+#             */
/*   Updated: 2021/03/06 12:44:23 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_VECTOR_ITERATOR

# define REV_VECTOR_ITERATOR

# include "ft_containers.hpp"

namespace	ft {

	template<typename T, bool B>
	class rev_vector_iterator {
		public:

			typedef long int										difference_type;
			typedef T												value_type;
			typedef size_t											size_type;
			
			typedef typename ConstBool<B, T&, const T&>::type		reference;
			typedef typename ConstBool<B, T*, const T*>::type		pointer;
			typedef T*												nonConstPointer;

		
			rev_vector_iterator(nonConstPointer val = 0) : _val(val) {}
			rev_vector_iterator(const rev_vector_iterator<T, false>& src) { _val = src.getNonConstPointer(); }
			rev_vector_iterator(const ft::vector_iterator<T, false>& src) { _val = src.getNonConstPointer(); }
			~rev_vector_iterator() {}

			nonConstPointer	getNonConstPointer() const		{ return _val; }

			rev_vector_iterator& operator=(const rev_vector_iterator& assign)
			{
				if (this != &assign)
					_val = assign._val;
				return (*this);
			}

			reference operator*()			{ return (*_val); }
			pointer operator->() const		{ return (_val); }

			rev_vector_iterator& operator++()		{ --_val; return (*this); }
			rev_vector_iterator operator++(int)		{ rev_vector_iterator res(*this); ++(*this); return (res); };
			rev_vector_iterator& operator--()		{ ++_val; return (*this); }
			rev_vector_iterator operator--(int)		{ rev_vector_iterator res(*this); --(*this); return (res); };
			
			bool operator==(const rev_vector_iterator& it) const	{ return (it._val == _val); }
			bool operator!=(const rev_vector_iterator& it) const	{ return (it._val != _val); }
			
			bool operator<(const rev_vector_iterator& it) const {
				return (it._val > this->_val);
			}
			bool operator>(const rev_vector_iterator& it) const {
				return (it._val < this->_val);
			}
			bool operator<=(const rev_vector_iterator& it) const {
				return (it._val >= this->_val); }

			bool operator>=(const rev_vector_iterator& it) const {
				return (it._val <= this->_val);
			}

			rev_vector_iterator	&operator+=(int n) {
				this->modifyVal(n, ADD);
				return *this;
			}

			rev_vector_iterator	operator+(int n) const {
				rev_vector_iterator	it(*this);

				it.modifyVal(n, ADD);
				return it;
			}

			rev_vector_iterator	&operator-=(int n) {
				this->modifyVal(n, SUB);
				return *this;
			}

			rev_vector_iterator	operator-(int n) const {
				rev_vector_iterator	it(*this);

				it.modifyVal(n, SUB);
				return it;
			}

			reference						operator[](int n) const {
				value_type	tmp(*this);

				tmp.modifyVal(n, ADD);
				return *tmp;
			}

			difference_type					operator-(rev_vector_iterator it) const {
				return it._val - this->_val;
			}

			friend rev_vector_iterator operator+(int n, const rev_vector_iterator& it)
			{
				rev_vector_iterator it2(it);
				return it2 += n;
			}

			friend rev_vector_iterator operator-(int n, const rev_vector_iterator& it)
			{
				rev_vector_iterator it2(it);
				return it2 -= n;
			}
							
		private:
			nonConstPointer	_val;

			void	modifyVal(int n, bool sign) {
					int	mov = 1;
					
					if ((sign == ADD && n < 0) || (sign == SUB && n > 0))
						mov = -1;
					if (n < 0)
						n *= -1;
					for (; n > 0; n--)
						this->_val += mov;
				}
	};
}

#endif
