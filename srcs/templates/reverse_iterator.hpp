/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 22:49:52 by francisco         #+#    #+#             */
/*   Updated: 2021/05/25 18:30:47 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP

# define REVERSE_ITERATOR_HPP

# include "ft_containers.hpp"

namespace ft{

    template<class Iter>
    class reverse_iterator {
        
        public:
            typedef Iter                             iterator_type;
            typedef typename Iter::value_type        iter;
            typedef typename Iter::difference_type   difference_type;
            typedef typename Iter::pointer           pointer;
            typedef typename Iter::reference         reference;

            // CONSTRUCTORS
            reverse_iterator(): _current() {}
            reverse_iterator(iterator_type it): _current(it) {}
			template<class T>
            reverse_iterator(const reverse_iterator<T>   &rev_it):_current(rev_it.base()) {}


            iterator_type       base() const { return iterator_type(_current); }
            reference           operator*() const {
                iterator_type   tmp(_current);

                return *(--tmp);
            }

            reverse_iterator    operator+(difference_type n) const { return (_current - n); }

            reverse_iterator    &operator++() { --_current; return *this; }
            reverse_iterator    operator++(int) {
                reverse_iterator tmp = *this;
                ++(*this);
                return tmp;
              }

            reverse_iterator& operator+= (difference_type n) {
                _current -= n;
                return *this;
            }

            reverse_iterator operator- (difference_type n) const { 
                reverse_iterator    it(_current - n);

                return it;
            }        

            reverse_iterator& operator--() { ++_current; return *this; }
            reverse_iterator  operator--(int) {
                reverse_iterator    tmp(*this);

                --(*this);
                return tmp;
            }

            reverse_iterator& operator-= (difference_type n) {
                _current += n;
                return *this;
            }

            pointer operator->() const {
                return &(operator*());
            }

            reference operator[] (difference_type n) const { return base()[-n-1]; }

            template<class Iterator>
			friend bool operator== (const reverse_iterator& lhs,
                const reverse_iterator<Iterator>& rhs) { return lhs._current == rhs.base(); }
            template<class Iterator>
			friend bool operator!= (const reverse_iterator& lhs,
                const reverse_iterator<Iterator>& rhs) { return lhs._current != rhs.base(); }
            template<class Iterator>
			friend bool operator< (const reverse_iterator& lhs,
                const reverse_iterator<Iterator>& rhs) { return lhs._current < rhs.base(); }
            template<class Iterator>
			friend bool operator<= (const reverse_iterator& lhs,
                const reverse_iterator<Iterator>& rhs) { return lhs._current <= rhs.base(); }
            template<class Iterator>
			friend bool operator> (const reverse_iterator& lhs,
                const reverse_iterator<Iterator>& rhs) { return lhs._current > rhs.base(); }
            template<class Iterator>
			friend bool operator>= (const reverse_iterator& lhs,
                const reverse_iterator<Iterator>& rhs) { return lhs._current >= rhs.base(); }

			template <class Iterator>
            friend reverse_iterator operator+ (
             typename reverse_iterator::difference_type n,
             const reverse_iterator<Iterator>& rev_it) { return (rev_it + n); }
            template <class Iterator>
            friend reverse_iterator operator- (
             typename reverse_iterator::difference_type n,
             const reverse_iterator<Iterator>& rev_it) { return (rev_it - n); }

            private:
                iterator_type                   _current;
    };
}

#endif