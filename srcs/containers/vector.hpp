/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:25:58 by frthierr          #+#    #+#             */
/*   Updated: 2021/03/07 14:46:15 by frthierr         ###   ########.fr       */
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
			_data(_allocator.allocate(0)) {}
			
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
				 typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) : // checks if InputIterator is not an integral type; if it is, the compiler will use the appropriate constructor defined up above
				 _allocator(alloc),
				 _size(0),
				 _capacity(0) {
					InputIterator	nav(first);

					for (; nav != last; this->_capacity++, nav++);
					this->_data = this->_allocator.allocate(this->_capacity);
					for (; this->_size < this->_capacity; this->_size++, first++)
						this->_allocator.construct(&this->_data[this->_size], *first);					
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
			const_iterator			end() const {
				return const_iterator(this->_data + this->_size);
			}
			reverse_iterator		rbegin() {return reverse_iterator(this->_data + this->_size - 1);}
			const_reverse_iterator	rbegin() const {return const_reverse_iterator(this->_data + this->_size - 1);}
			reverse_iterator		rend() {return reverse_iterator(this->_data - 1);}
			const_reverse_iterator	rend() const {return const_reverse_iterator(this->_data - 1);}
// 4611686018427387904
// 4611686018427387904
		// CAPACITY	
			size_type	size() const {return this->_size;}
			size_type	max_size() const {
				return (static_cast<size_type>(pow(2.0, sizeof(pointer) * 8)/sizeof(value_type)) - 1);
			}
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
					throw std::length_error("ft::vector::at : length-_error");
				if (n > this->_capacity)
					this->_increaseCapacity(n);
			}

		// ELEMENT ACCESS
			reference		operator[] (size_type n) {return this->_data[n];}
			const_reference operator[] (size_type n) const {return this->_data[n];}
			reference		at (size_type n) {
				if (n > this->_size)
					throw std::out_of_range("ft::vector::at : out_of_range");
				return this->_data[n];
			}
			const_reference at (size_type n) const {
				if (n > this->_size)
					throw std::out_of_range("ft::vector::at : out_of_range");
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
				this->_size = static_cast<size_type>(last - first);

				if (this->_size < this->_capacity) {
					this->~vector();
					this->_data = this->_allocator.allocate(this->_size);
				}
				for (; first < last; first++) 
					this->_allocator.construct(&this->_data[last - first], *first);
			}
			void 		assign (size_type n, const value_type& val) {
				this->_size = n;
				if (n < this->_capacity) {
					this->~vector();
					this->_data = this->_allocator.allocate(n);
				}
				for (size_type i = 0; i < n; i++)
					this->_allocator.construct(val, &this->_data[i]);
			}
			void 		push_back (const value_type& val) {
				if (this->_capacity <= this->_size) {
					if (this->_capacity)
						this->_increaseCapacity(this->_capacity * 2);
					else
						this->_increaseCapacity(1);
				}
				this->_allocator.construct(&this->_data[this->_size++], val);
			}
			void 		pop_back() {
				if (this->_size)
					this->_allocator.destroy(&this->_data[--this->_size]);
			}
			iterator 	insert (iterator position, const value_type& val) {
				this->insert(position, 1, val);
			}
			void 		insert (iterator position, size_type n, const value_type& val) {
				if (this->_capacity < this->_size + n)
					this->_increaseCapacity(this->_size + n);
				this->_size += n;
				value_type	tmp = val;
				for (value_type tmp2 = *position ; n; n--, tmp = tmp2, position++, tmp2 = *position) {
					this->_allocator.destroy(position.getNonConstPointer());
					this->_allocator.construct(position.getNonConstPointer(), *tmp);
				}
				
			}
			template <class InputIterator>
			void 		insert (iterator position, InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) {
				for (; first != last, position != this->end(); position++, first++)
					this->_insert(position, *first);		
			}				
			iterator	erase (iterator position) {
				iterator	ret(position++);
				size_type	idx = static_cast<size_type>(position - this->begin());
				for (; position != this->_end(); idx++, position++) {
					this->_allocator.destroy(&this->_data[idx]);
					this->_allocator.construct(&this->_data[idx], *position);
				}
				--this->_size;
				return ret;
		}
			iterator	erase (iterator first, iterator last) {
				iterator	ret;
				for (; first != last; ++first)
					ret = this->_erase(first);
				return ret;
			}
			void		swap (vector& x) {
				vector	tmp;
				tmp._allocator = this->_allocator;
				tmp._size = this->_size;
				tmp._capacity = this->_capacity;
				tmp._data = this->_data;
				
				this->_allocator = x._allocator;
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_data = x._data;

				x._allocator = tmp._allocator;
				x._size = tmp._size;
				x._capacity = tmp._capacity;
				x._data = tmp._data;
			}
			void 		clear() {
				while(this->_size)
					this->pop_back();
			}

		// NON-MEMBER FUNCTION OVERLOADS
			friend bool operator== (const vector &lhs, const vector &rhs) {
				if (lhs._size != rhs._size)
					return false;
				iterator lit = lhs.begin();
				iterator rit = rhs.begin();
				for (;	lit != lhs.end(), rit != rhs.end(); lit++, rit++) {
						if (*lit != *rit)
							return false;
					}
				if (lit == lhs.end() && rit == rhs.end())
					return true;
			}
			friend bool operator!= (const vector &lhs, const vector &rhs) {
				return !(lhs == rhs);
			}
			friend bool operator<  (const vector &lhs, const vector &rhs) {
				iterator lit = lhs.begin();
				iterator rit = rhs.begin();
				for (; lit != lhs.end(), rit != rhs.end(); lit++, rit++) {
						if (*lit < *rit)
							return true;
					}
				return lhs._size < rhs._size;
			}
			friend bool operator<= (const vector &lhs, const vector &rhs) {return (lhs < rhs) || (lhs == rhs);}
			friend bool operator>  (const vector &lhs, const vector &rhs) {return !(lhs < rhs);};
			friend bool operator>= (const vector &lhs, const vector &rhs) {return (lhs > rhs) || (lhs == rhs);};

			friend void swap (vector& x, vector& y) {
				x.swap(y);
			}
		
		
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
