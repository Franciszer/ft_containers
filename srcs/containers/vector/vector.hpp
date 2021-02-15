/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:25:58 by frthierr          #+#    #+#             */
/*   Updated: 2021/02/15 14:30:28 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP

# define VECTOR_HPP

# include "ft_containers.hpp"

namespace	ft {
	
	template<typename T, class Alloc = std::allocator<T> >
	class vector {
		public:

			typedef	T													value_type;
			typedef	Alloc												allocator_type;
			typedef	long int											difference_type;
			typedef	size_t												size_type;

			typedef	T&													reference;
			typedef	const T&											const_reference;
			typedef	T*													pointer;
			typedef	const T*											const_pointer;
			
			typedef typename ft::random_access_iterator<T, false>		iterator;
			typedef typename ft::random_access_iterator<T, true>		const_iterator;

			typedef typename ft::reverse_random_access_iterator<T, false>		reverse_iterator;
			typedef typename ft::reverse_random_access_iterator<T, true>		const_reverse_iterator;

			explicit vector(const allocator_type &alloc = allocator_type()):
			_allocator(alloc),
			_size(0),
			_capacity(0),
			_data(_allocator.allocate(_capacity)) {}
			
			explicit vector(size_type n, const value_type &val = value_type(),
							const allocator_type &alloc = allocator_type()):
			_allocator(alloc),
			_size(n),
			_capacity(n),
			_data(_allocator.allocate(_capacity)) {
				for(size_t i = 0 ; i < n ; i++)
					_allocator.construct(&_data[i], val);
			}

			// DON'T UNDERSTAND THIS ONE YET
			template <class InputIterator>
         	vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type(),
				 typename ft::enable_if<!ft::is_integral<InputIterator>>::value::type = 0) : // checks if InputIterator is not an integral type; if it is, the compiler will use the appropriate constructor defined up above
				 _allocator(alloc),
				 _size(0) {
					this->_size = static_cast<size_type>(last - first);
					this->_data = this->_allocator(this->_size);
					this->_capacity = _size;
					for (size_t i = 0; first != last ; first++)
						this->_allocator.construct(&this->_data[i], *first)
				 }
				 
			vector(const vector &src):
			_allocator(src._allocator),
			_size(src._size),
			_capacity(src._capacity) {
				this->_data = this->_allocator.allocate(this->_capacity);
				for (size_type i = 0; i != src.size(); i++)
					this->_allocator.construct(&this->_data[i], src[i]);					
			}
			virtual ~vector(void) {
				for (iterator it = this->begin(); it != this->end(); it++)
					this->_allocator.destroy(&(*it));
				this->_allocator.deallocate(this->_data, this->_capacity);
			}

		// ITERATORS
			iterator				begin() {return iterator(this->_data);}
			const_iterator			begin() const {return const_iterator(this->_data);}
			iterator				end() {return iterator(this->_data + this->_size);}
			const_iterator			end() const {return const_iterator(this->_data + this->_size);}
			reverse_iterator		rbegin() {return reverse_iterator(this->_data + this->_size - 1);}
			const_reverse_iterator	rbegin() const {return const_reverse_iterator(this->_data + this->_size - 1);}
			reverse_iterator		rend() {return reverse_iterator(this->_data - 1);}
			const_reverse_iterator	rend() const {return const_reverse_iterator(this->_data - 1);}

		// CAPACITY	
			size_type	size() const {return this->_size;}
			size_type	max_size() const {return std::numeric_limits<difference_type>::max();}
			void		resize (size_type n, value_type val = value_type()) {
				if (n > this->_capacity)
					this->_increaseCapacity(n);
				while (this->_size < n)
					this->push_back(val);
				while (this->_size > n)
					this->pop_back();
			}
			size_type	capacity() const {return this->_capacity;}
			bool		empty() const {return this->_size==0;}
			void		reserve(size_type n) {
				if (n > this->max_size())
					throw std::length_error();
				if (n > this->_capacity)
					this->_increaseCapacity(n);
			}

		// ELEMENT ACCESS
			reference		operator[] (size_type n) {return this->_data[n];}
			const_reference operator[] (size_type n) const {return this->_data[n];}
			reference		at (size_type n) {
				if (n > this->_size)
					throw std::out_of_range();
				return this->_data[n];
			}
			const_reference at (size_type n) const {
				if (n > this->_size)
					throw std::out_of_range();
				return this->_data[n];
			}
			reference		front() {return this->_data[0];}
			const_reference	front() const {return this->_data[0];}
			reference		back() {return this->_data[this->_size - 1];}
			const_reference	back() const {return this->_data[this->_size - 1];}

		// MODIFIERS
			template <class InputIterator>
			void 		assign (InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) {
				size_type	static_cast<size_type>(last - first);

				if (size < this->_size) {
					this->~vector();
					this->_data = this->_allocator(size);
				}
				for (size_type i = 0; i < size; i++) 
					this->_allocator.construct(&this->_data[i], *(first + i));
			}
			void 		assign (size_type n, const value_type& val) {
				
			}
			void 		push_back (const value_type& val);
			void 		pop_back();
			iterator 	insert (iterator position, const value_type& val);
			void 		insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>
			void 		insert (iterator position, InputIterator first, InputIterator last);
			iterator	erase (iterator position);
			iterator	erase (iterator first, iterator last);
			void		swap (vector& x);
			void 		clear();

		// NON-MEMBER FUNCTION OVERLOADS
			friend bool operator== (const vector &lhs, const vector &rhs);
			friend bool operator!= (const vector &lhs, const vector &rhs);
			friend bool operator<  (const vector &lhs, const vector &rhs);
			friend bool operator<= (const vector &lhs, const vector &rhs);
			friend bool operator>  (const vector &lhs, const vector &rhs);
			friend bool operator>= (const vector &lhs, const vector &rhs);

			friend void swap (vector& x, vector& y);
		
		
		private:
			allocator_type	_allocator;
			size_type		_size;
			size_type		_capacity;
			pointer			_data;

			void	_increaseCapacity(size_type capacity) {
				
				if (capacity <= this->_capacity)
					return ;
				pointer	newData = this->_allocator.allocate(capacity);
				size_type i;

				for (i = 0; i < this->_size; i++)
					this->_allocator.construct(&newData[i], this->_data[i]);
				this->~vector();
				this->_size = i;
				this->_capacity = capacity;
				this->_data = newData;
			}
			
	};
}


#endif
