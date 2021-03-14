/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 13:46:46 by frthierr          #+#    #+#             */
/*   Updated: 2021/03/09 20:06:21 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR

# define VECTOR_ITERATOR

# include "ft_containers.hpp"
# include "reverse_iterator.hpp"
namespace	ft {

	template<typename T, bool B>
	class	vector_iterator {
		public:
			typedef long int										difference_type;
			typedef T												value_type;
			typedef size_t											size_type;
			
			typedef typename ConstBool<B, T&, const T&>::type		reference;
			typedef typename ConstBool<B, T*, const T*>::type		pointer;
			typedef T*												nonConstPointer;


			vector_iterator(nonConstPointer val = 0) : _val(val) {}
			vector_iterator(const vector_iterator<T, false>& src) { _val = src.getNonConstPointer(); }
			virtual ~vector_iterator() {}

			nonConstPointer	getNonConstPointer() const {return _val;}

			vector_iterator	&operator=(const vector_iterator &src) {
				if (this != &src)
					_val = src._val;
				return *this;
			}

			reference 		operator*()			{ return (*_val); }
			pointer 		operator->() const		{ return (_val); }

			vector_iterator& operator++()		{ ++_val; return (*this); }
			vector_iterator operator++(int)		{ vector_iterator res(*this); ++(*this); return (res); };
			vector_iterator& operator--()		{ --_val; return (*this); }
			vector_iterator operator--(int)		{ vector_iterator res(*this); --(*this); return (res); };

			bool operator<(const vector_iterator& src) const		{return (src._val > this->_val);}
			bool operator>(const vector_iterator& src) const		{return (src._val < this->_val);}
			bool operator<=(const vector_iterator& src) const	{return (src._val >= this->_val);}
			bool operator>=(const vector_iterator& src) const	{return (src._val <= this->_val);}

			bool operator==(const vector_iterator& it) const	{ return (it._val == _val); }
			bool operator!=(const vector_iterator& it) const	{ return (it._val != _val); }

			vector_iterator	&operator+=(int n) {
				this->modifyVal(n, ADD);
				return *this;
			}
			vector_iterator	operator+(int n) const {
				vector_iterator	it(*this);

				it.modifyVal(n, ADD);
				return it;
			}
			vector_iterator	&operator-=(int n) {
				this->modifyVal(n, SUB);
				return *this;
			}
			vector_iterator	operator-(int n) const {
				vector_iterator	it(*this);

				it.modifyVal(n, SUB);
				return it;
			}
			reference				operator[](int n) const {
				return this->_val + n;
			}

			difference_type operator-(vector_iterator it) const
			{
				return (this->_val - it._val);
			}
			
			friend vector_iterator operator+(int n, const vector_iterator& it)
			{
				return it - n;
			}

			friend vector_iterator operator-(int n, const vector_iterator& it)
			{
				return it - n;
			}
			
			private:

				nonConstPointer	_val;

				// sign == ADD is an addition, sign == SUB is a substraction
				void	modifyVal(int n, bool sign) {
					int	mov = 1;
					
					if ((sign == ADD && n < 0) || (sign == SUB && n > 0))
						mov = -1;
					if (n < 0)
						n *= -1;
					for (; n > 0; n--)
						vector_iterator::_val += mov;
				}
	};
}

#endif
