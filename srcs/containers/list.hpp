/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:27:55 by francisco         #+#    #+#             */
/*   Updated: 2021/03/23 18:17:56 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP

# define LIST_HPP

# include "ft_containers.hpp"
# include "list_node.hpp"

namespace ft {
    template<typename T, class Alloc=std::allocator<list_node<T> > >
    class list {
        
		public:
			typedef	T													value_type;
			typedef	Alloc												allocator_type;
			typedef	long int											difference_type;
			typedef	size_t												size_type;

			typedef	T&													reference;
			typedef	const T&											const_reference;
			typedef	T*													pointer;
			typedef	const T*											const_pointer;
				
			typedef typename ft::list_iterator<T, false>				iterator;
			typedef typename ft::list_iterator<T, true>				    const_iterator;

			typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			typedef ft::list_node<T>									node;
			typedef node*												nodePtr;

			explicit list (const allocator_type& alloc = allocator_type()):\
				_alloc(alloc), _size(0) {
					_setUp();
			}

			explicit list (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()):
					_alloc(alloc),
					_size(0) {
						_setUp();
						for (; _size < n ;)
							this->push_back(val);
					}

			template <class InputIterator>
			list (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0):\
				_alloc(alloc),
				_size(0) {
					_setUp();
					for (; first != last; first++)
						this->push_back(*first);
			}

			list (const list &src):\
			_alloc(src._alloc),
			_size(0) {
				_setUp();
				const_iterator it = src.begin();
				for (; it != src.end(); it++)
					push_back(*it);
			}

			~list() {
				while (_size) {
					this->pop_front();
				}
				delete _end;
			}
			
			list	&operator=(const list &src) {
				list	copy(src);
				
				this->swap(copy);
				return *this;
			}

			iterator					begin() { return iterator(_end->next);}
			const_iterator				begin() const { return const_iterator(_end->next);}
			iterator					end() { return iterator(_end); }
			const_iterator				end() const { return const_iterator(_end); }

			reverse_iterator			rbegin() { return reverse_iterator(_end); }
			const_reverse_iterator		rbegin() const { return const_reverse_iterator(_end); }
			reverse_iterator			rend() { return reverse_iterator(_end->next); }
			const_reverse_iterator		rend() const { return const_reverse_iterator(_end->next); }

			bool						empty() const { return _size == 0; }
			size_type					size() const { return _size; }
			size_type					max_size() const {
				return (static_cast<size_type>(pow(2.0, sizeof(pointer) * 8)/sizeof(value_type)) - 1);
			}
			reference					front() { return _end->next->content; }
			const_reference				front() const { return _end->next->content; }
			reference					back() { return _end->prev->content; }
			const_reference				back() const { return _end->prev->content; }

			template <class InputIterator>
            void		assign (InputIterator first, InputIterator last) {
				while (_size)
					this->pop_back();
					
				for (; first != last; first++) {
					this->push_back(*first);
				}
			}
			void		assign(size_type n, const value_type &val) {
				while (_size)
					this->pop_back();
				for (size_type i = 0; i < n; i++)
					this->push_back(val);
			}
			void		push_front(const value_type &val) {
				_newNode(val, _end);
			}

			void		pop_front() {
				_delNode(_end->next);
			}

			void		push_back(const value_type &val) {
				_newNode(val, _end->prev);
			}

			void		pop_back() {
				_delNode(_end->prev);
			}

			iterator	insert(iterator position, const value_type& val) {
				return iterator(_newNode(val, position.getNodePtr()->prev));
			}
			
			void		insert(iterator position, size_type n, const value_type& val) {
				while (n--) {
					position = this->insert(position, val);	
				}
			}

			template <class InputIterator>
			void 		insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) {
					for (; first != last; first++) {
						position = ++(this->insert(position, *first));
					}
			}

			iterator erase (iterator position) {
				iterator	to_delete = position++;
				_delNode(to_delete.getNodePtr());
				return position;
			}
			iterator erase (iterator first, iterator last) {
				first++;
				for (; first != last; first++) {
					_delNode(first.getNodePtr()->prev);
				}
				_delNode(first.getNodePtr()->prev);
				return first;
			}

			void	swap (list &x) {
				nodePtr	tmpEnd = this->_end;
				size_type tmpSize = this->_size;

				_end = x._end;
				_size = x._size;

				x._end = tmpEnd;
				x._size = tmpSize;
			}
			
			void	resize (size_type n, value_type val = value_type()) {
				while (n < _size)
					this->pop_back();
				while (n > _size)
					this->push_back(val);
			}

			void	clear() {
				while (_size)
					this->pop_back();
			}

			void splice (iterator position, list& x) {
				position.getNodePtr()->next->prev =\
					x._end->prev;\
				x._end->prev->next =\
					position.getNodePtr()->next;
				position.getNodePtr()->next = x._end->next;
				x._end->next->prev = position.getNodePtr(); 
				x._end->next = x._end;
				x._end->prev = x._end;
				_size += x._size;
				x._size = 0;
			}

			void splice (iterator position, list& x, iterator i) {
				_newNode(*i, position.getNodePtr());
				this->insert(position, *i);
				x._delNode(i.getNodePtr());
			}

			void splice (iterator position, list& x, iterator first, iterator last) {
				this->insert(position, first, last);
				x.erase(first, last);
			}

			void remove (const value_type& val) {
				for (iterator it = this->begin() ; it != this->end();) {
					if (*it == val) {
						iterator tmp = it;
						tmp++;
						this->erase(it);
						it = tmp;
					}
					else
						it++;
				}
			}

			template <class Predicate>
			void remove_if (Predicate pred) {
				for (iterator it = this->begin() ; it != this->end() ; it++) {
					if (pred(*it)) {
						iterator tmp = it;
						tmp--;
						this->erase(it);
						it = tmp;
					}
				}
			}
			
			void	unique() {
				iterator it = this->begin();
				for (iterator it2 = ++(this->begin());\
					iterator(it.getNodePtr()->next) != this->end() ; it2 = iterator(it.getNodePtr()->next)) {
					if (*it == *it2) {
						this->erase(it2);
					}
					else
						it++;
				}
			}

			template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred) {
				iterator it = this->begin();
				for (iterator it2 = ++(this->begin());\
					iterator(it.getNodePtr()->next) != this->end() ;\
					it2 = iterator(it.getNodePtr()->next)) {
						if (binary_pred(*it, *it2)) {
							this->erase(it2);
						}
						else
							it++;
				}
			}

			void merge (list& x) {
				if (&x != this) {
					for (iterator it = x.begin() ; it != x.end() ; it = x.begin()) {
						this->push_back(*it);
						x.erase(it);
					}
				}
			}

			template <class Compare>
			void merge (list& x, Compare comp) {
				for (iterator it = x.begin() ; it != x.end() ; it++) {
					for (iterator it2 = this->begin() ; it2 != this->end() ; it2++) {
						if (comp(it, it2)) {
							_newNode(*it2, it->getNodePtr());
							break ;
						}
					}
				}
			}

			void sort() {
				for (iterator it = this->begin(); it.getNodePtr()->next != _end ; it++) {
					iterator it2 = it;
					++it2;
					for (; it2 != this->end() ; it2++) {
						if (*it < *it2) {
							value_type tmp = *it;
							*it = it2;
							it2 = tmp;
						}
					}
				}
			}

			template <class Compare>
			void sort (Compare comp) {
				for (iterator it = this->begin(); it.getNodePtr()->next != _end ; it++) {
					iterator it2 = it;
					++it2;
					for (; it2 != this->end() ; it2++) {
						if (comp(*it, *it2)) {
							value_type tmp = *it;
							*it = it2;
							it2 = tmp;
						}
					}
				}
			}
			
			friend bool operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
				if (lhs._size != rhs._size)
					return false;
				iterator	it = lhs.begin();
				iterator	it2 = rhs.begin();
				
				for (; it != lhs.end(), it2 != rhs.end() ; it++, it2++) {
					if (*it != *it2)
						return false;
				}
				return true;
			}

			friend bool operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
				return !(lhs == rhs);
			}

			friend bool operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
				iterator	it = lhs.begin();
				iterator	it2 = rhs.begin();

				for (; it != lhs.end(), it2 != rhs.end(); it++, it2++) {
					if (*it < *it2)
						return true;
				}
				return lhs._size < rhs._size;
			}

			friend bool operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
				return rhs < lhs;
			}

			friend bool operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
				return (lhs < rhs || lhs == rhs);
			}

			friend bool operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
				return (lhs > rhs || lhs == rhs);
			}

        private:
			allocator_type	_alloc;
            nodePtr			_end;
			size_type		_size;

			void			_setUp() {
				_end = new node;
				_end->prev = _end;
				_end->next = _end;
			}

			nodePtr			_newNode(const value_type &val, nodePtr prev) {
				nodePtr	ret = _alloc.allocate(sizeof(node));
				nodePtr next = prev->next;

				prev->next = ret;
				next->prev = ret;
	
				node	src;
				src.prev = prev;
				src.next = next;
				src.content = val;
				
				_alloc.construct(ret, src);

				_size++;
				return ret;
			}

			void			_delNode(nodePtr ptr) {
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;

				_alloc.destroy(ptr);
				_alloc.deallocate(ptr, sizeof(nodePtr));
				_size--;
			}
    };
}

#endif