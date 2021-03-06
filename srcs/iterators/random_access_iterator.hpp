/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 13:46:46 by frthierr          #+#    #+#             */
/*   Updated: 2021/03/06 11:04:25 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP

# define RANDOM_ACCESS_ITERATOR_HPP

# include "ft_containers.hpp"
# include "bidirectional_iterator.hpp"

namespace	ft {
	template<typename T, bool B>
	class	rev_random_access_iterator;

	template<typename T, bool B>
	class	random_access_iterator: public bidirectional_iterator<T, B> {
		public:
			typedef typename ft::bidirectional_iterator<T, B>::difference_type		difference_type;
			typedef typename ft::bidirectional_iterator<T, B>::value_type			value_type;
			typedef typename ft::bidirectional_iterator<T, B>::size_type			size_type;
			
			typedef typename ft::bidirectional_iterator<T, B>::reference			reference;
			typedef typename ft::bidirectional_iterator<T, B>::pointer				pointer;
			typedef typename ft::bidirectional_iterator<T, B>::nonConstPointer		nonConstPointer;

			typedef typename ft::bidirectional_iterator<T, B>						bidirectional_iterator;


			random_access_iterator(nonConstPointer val = 0):
				bidirectional_iterator(val) {}
			random_access_iterator(const random_access_iterator<T, false> &src):
				bidirectional_iterator(src.getNonConstPointer()) {}
			~random_access_iterator() {}

			random_access_iterator	&operator=(const random_access_iterator &src) {
				if (this != !src)
					this->_val = src._val;
				return *this;
			}

			bool operator<(const random_access_iterator& src) const		{return (src._val > this->_val);}
			bool operator>(const random_access_iterator& src) const		{return (src._val < this->_val);}
			bool operator<=(const random_access_iterator& src) const	{return (src._val >= this->_val);}
			bool operator>=(const random_access_iterator& src) const	{return (src._val <= this->_val);}

			random_access_iterator	&operator+=(int n) {
				this->modifyVal(n, ADD);
				return *this;
			}
			random_access_iterator	operator+(int n) const {
				random_access_iterator	it(*this);

				it.modifyVal(n, ADD);
				return it;
			}
			random_access_iterator	&operator-=(int n) {
				this->modifyVal(n, SUB);
				return *this;
			}
			random_access_iterator	operator-(int n) const {
				random_access_iterator	it(*this);

				it.modifyVal(n, SUB);
				return it;
			}
			reference				operator[](int n) const {
				return this->_val + n;
			}

			difference_type operator-(random_access_iterator it) const
			{
				return (this->_val - it._val);
			}
			
			friend random_access_iterator operator+(int n, const random_access_iterator& it)
			{
				return it - n;
			}

			friend random_access_iterator operator-(int n, const random_access_iterator& it)
			{
				return it - n;
			}
			
			private:
				// sign == true is an addition, sign == false is a substraction
				void	modifyVal(int n, bool sign) {
					int	mov = 1;
					
					if ((sign == ADD && n < 0) || (sign == SUB && n > 0))
						mov = -1;
					if (n < 0)
						n *= -1;
					for (; n > 0; n--)
						bidirectional_iterator::_val += mov;
				}
	};
}

#endif
