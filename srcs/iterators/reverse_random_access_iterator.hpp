/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_random_access_iterator.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:43:22 by frthierr          #+#    #+#             */
/*   Updated: 2021/02/06 13:44:36 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_RANDOM_ACCESS_ITERATOR_HPP

# define REV_RANDOM_ACCESS_ITERATOR_HPP

# include "ft_containers.hpp"

namespace	ft {

	template<typename T, bool B>
	class reverse_random_access_iterator: public reverse_bidirectional_iterator<T, B> {
		public:

			typedef typename ft::reverse_bidirectional_iterator<T, B>::difference_type	difference_type;
			typedef typename ft::reverse_bidirectional_iterator<T, B>::value_type		value_type;
			typedef typename ft::reverse_bidirectional_iterator<T, B>::size_type		size_type;
			typedef typename ft::reverse_bidirectional_iterator<T, B>::reference		reference;
			typedef typename ft::reverse_bidirectional_iterator<T, B>::pointer			pointer;
			typedef typename ft::reverse_bidirectional_iterator<T, B>::nonConstPointer	nonConstPointer;
			typedef typename ft::reverse_bidirectional_iterator<T, B>					reverse_bidirectional_iterator;

		
			reverse_random_access_iterator(nonConstPointer val = 0):
				reverse_bidirectional_iterator(val) {}
				
			reverse_random_access_iterator(const reverse_random_access_iterator<T, false> &src):
				reverse_random_access_iterator(src.getNonConstPointer) {}

			reverse_random_access_iterator(const random_access_iterator<T, false> &src):
				reverse_bidirectional_iterator(src.getNonConstPointer() - 1) {}

			reverse_random_access_iterator	&operator=(const reverse_random_access_iterator &src) {
				if (this != &src)
					reverse_bidirectional_iterator::_val = src._val;
				return *this;
			}

			bool operator<(const reverse_random_access_iterator& it) const {
				return (it._val > this->_val);
			}
			bool operator>(const reverse_random_access_iterator& it) const {
				return (it._val < this->_val);
			}
			bool operator<=(const reverse_random_access_iterator& it) const {
				return (it._val >= this->_val); }

			bool operator>=(const reverse_random_access_iterator& it) const {
				return (it._val <= this->_val);
			}

			reverse_random_access_iterator	&operator+=(int n) {
				this->modifyVal(n, ADD);
				return *this;
			}

			reverse_random_access_iterator	operator+(int n) const {
				reverse_random_access_iterator	it(*this);

				it.modifyVal(n, ADD);
				return it;
			}

			reverse_random_access_iterator	&operator-=(int n) {
				this->modifyVal(n, SUB);
				return *this;
			}

			reverse_random_access_iterator	operator-(int n) const {
				reverse_random_access_iterator	it(*this);

				it.modifyVal(n, SUB);
				return it;
			}

			reference						operator[](int n) const {
				value_type	tmp(*this);

				tmp.modifyVal(n, ADD);
				return *tmp;
			}

			difference_type					operator-(reverse_random_access_iterator it) const {
				return it._val - this->_val;
			}

			friend reverse_random_access_iterator operator+(int n, const reverse_random_access_iterator& it)
			{
				reverse_random_access_iterator it2(it);
				return it2 += n;
			}

			friend reverse_random_access_iterator operator-(int n, const reverse_random_access_iterator& it)
			{
				reverse_random_access_iterator it2(it);
				return it2 -= n;
			}
			
			virtual ~reverse_random_access_iterator(void);
				
		private:
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
