/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 12:27:55 by francisco         #+#    #+#             */
/*   Updated: 2021/05/27 17:03:10 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP

# define LIST_HPP

# include "ft_containers.hpp"
# include "list_node.hpp"

namespace ft {
    template<typename T, class Alloc=std::allocator<T > >
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
				return _alloc.max_size();
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
				x._end->next->prev = position.getNodePtr()->prev;
				x._end->prev->next =\
					position.getNodePtr();
				position.getNodePtr()->prev->next =\
					x._end->next;
				position.getNodePtr()->prev = x._end->prev;
				x._end->next = x._end;
				x._end->prev = x._end;
				_size += x._size;
				x._size = 0;
			}

			void splice (iterator position, list& x, iterator i) {
				i.getNodePtr()->prev->next = i.getNodePtr()->next;
				i.getNodePtr()->next->prev = i.getNodePtr()->prev;
				position.getNodePtr()->prev->next =\
					i.getNodePtr();\
				i.getNodePtr()->next =\
					position.getNodePtr();
				i.getNodePtr()->prev =\
					position.getNodePtr()->prev;
				position.getNodePtr()->prev = i.getNodePtr();
				_size += 1;
				x._size -= 1;
			}

			void splice (iterator position, list& x, iterator first, iterator last) {
				iterator	tmp = first;

				tmp++;
				while(first != last)
				{
					splice(position, x, first);
					first = tmp;
					tmp++;
				}
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
				if (&x == this || x.empty())
					return ;
				iterator	it = this->begin();
				while (!x.empty()) {
					if (it == end() || *(x.begin()) < *it) {
						this->splice(it, x, x.begin());
					}
					else
						it++;
				}
			}

			template <class Compare>
			void merge (list& x, Compare comp) {
				if (&x == this || x.empty())
					return ;
				iterator	it = this->begin();
				while (!x.empty()) {
					if (it == end() || comp(*(x.begin()), *it)) {
						this->splice(it, x, x.begin());
					}
					else
						it++;
				}
			}

			void sort() {
				for (size_t i = 0; i < this->_size; i++) {
					for (iterator it = ++(this->begin()); it != end() ; it++) {
						iterator it2 = it;
						--it2;
						if (*it < *it2) {
							value_type tmp = it.getNodePtr()->content;
							it.getNodePtr()->content = it2.getNodePtr()->content;
							it2.getNodePtr()->content = tmp;
						}
					}
				}
			}

			template <class Compare>
			void sort (Compare comp) {
				for (size_t i = 0; i < this->_size; i++) {
					for (iterator it = ++(this->begin()); it != end() ; it++) {
						iterator it2 = it;
						--it2;
						if (comp(*it, *it2)) {
							value_type tmp = it.getNodePtr()->content;
							it.getNodePtr()->content = it2.getNodePtr()->content;
							it2.getNodePtr()->content = tmp;
						}
					}
				}
			}
			
			void	reverse() {
				if (this->empty())
					return ;
				iterator	front(this->begin());
				iterator	back(--(this->end()));

				while (front != back) {
					std::swap(*front, *back);
					front++;
					if (front == back)
						break ;
					back--;
				}
			}
			
        private:
			typename Alloc::template rebind<node>::other		_alloc;
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
			
		friend bool operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			typename ft::list<T, Alloc>::const_iterator	it = lhs.begin();
			typename ft::list<T, Alloc>::const_iterator	it2 = rhs.begin();
			
			for (; it != lhs.end() ; it++, it2++) {
				if (*it != *it2)
					return false;
			}
			return true;
		}

		friend bool operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
			return !(lhs == rhs);
		}

		friend bool operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
			typename ft::list<T, Alloc>::const_iterator	it = lhs.begin();
			typename ft::list<T, Alloc>::const_iterator	it2 = rhs.begin();

			for (; it != lhs.end() && it2 != rhs.end(); it++, it2++) {
				if (*it < *it2)
					return true;
			}
			if (lhs.size() < rhs.size())
				return true;
			return false;
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

		friend void swap (list<T,Alloc>& x, list<T,Alloc>& y) {
				x.swap(y);
		}
    };

}

#endif