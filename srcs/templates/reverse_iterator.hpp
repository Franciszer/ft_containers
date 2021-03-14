/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 22:49:52 by francisco         #+#    #+#             */
/*   Updated: 2021/03/13 21:46:33 by francisco        ###   ########.fr       */
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
            typedef typename Iter::nonConstPointer   nonConstPointer;

            // CONSTRUCTORS
            reverse_iterator(): _current() {}
            reverse_iterator(iterator_type it): _current(it) {}
            reverse_iterator(const reverse_iterator<Iter>   &rev_it): _current(rev_it._current) {}


            iterator_type       base() const { return (_current - 1); }
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

            friend bool operator== (const reverse_iterator<Iter>& lhs,
                const reverse_iterator<Iter>& rhs) { return lhs._current == rhs._current; }
            friend bool operator!= (const reverse_iterator<Iter>& lhs,
                const reverse_iterator<Iter>& rhs) { return lhs._current != rhs._current; }
            friend bool operator< (const reverse_iterator<Iter>& lhs,
                const reverse_iterator<Iter>& rhs) { return lhs._current < rhs._current; }
            friend bool operator<= (const reverse_iterator<Iter>& lhs,
                const reverse_iterator<Iter>& rhs) { return lhs._current <= rhs._current; }
            friend bool operator> (const reverse_iterator<Iter>& lhs,
                const reverse_iterator<Iter>& rhs) { return lhs._current > rhs._current; }
            friend bool operator>= (const reverse_iterator<Iter>& lhs,
                const reverse_iterator<Iter>& rhs) { return lhs._current >= rhs._current; }

            friend reverse_iterator<Iter> operator+ (
             typename reverse_iterator<Iter>::difference_type n,
             const reverse_iterator<Iter>& rev_it) { return (rev_it + n); }
            
            friend reverse_iterator<Iter> operator- (
             typename reverse_iterator<Iter>::difference_type n,
             const reverse_iterator<Iter>& rev_it) { return (rev_it - n); }

            private:
                iterator_type                   _current;
    };
}

#endif