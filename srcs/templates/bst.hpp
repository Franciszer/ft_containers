/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:12:11 by frthierr          #+#    #+#             */
/*   Updated: 2021/04/04 15:41:05 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP

# define BST_HPP

# include "ft_containers.hpp"

# define _BST_TP template<\
		typename	Key,\
		typename 	V,\
		class		KCompare = std::less<Key>,\
		class		VCompare = std::less<V>,\
		class		Alloc = std::allocator<pair<Key, V> >\
		>

# define _BST_TP_INIT Key, V, KCompare, VCompare, Alloc

using ft::pair;
namespace ft {

	_BST_TP
	class bst {
		public:
			typedef	V								value_type;
			typedef	Key								key_type;
			typedef pair<value_type, key_type>		content_type;
			typedef bst								tree_type;
			typedef	long int						difference_type;
			typedef	size_t							size_type;
			typedef	KCompare						key_compare;
			typedef	VCompare						value_compare;

			typedef	content_type&					content_reference;
			typedef	content_type*					content_pointer;
			typedef	const content_type*				content_const_pointer;
			typedef	const content_type&				content_const_reference;

			typedef tree_type&						tree_reference;
			typedef tree_type*						tree_pointer;
			typedef const tree_type*				tree_const_pointer;
			typedef const tree_type&				tree_const_reference;

			typedef	Alloc							allocator_type;
			typedef std::allocator<bst>				tree_allocator_type;
			
			content_pointer	_content;
			tree_pointer	_left;
			tree_pointer	_right;
			tree_pointer	_parent;
			allocator_type	_alloc;
			tree_allocator_type	_tree_alloc;
			key_compare		_key_comp;
			value_compare	_value_comp;
			
			bst(content_type val = content_type(),\
				key_compare k = key_compare(), value_compare v = value_compare()):
			_content(),
			_left(NULL),
			_right(NULL),
			_parent(NULL),
			_alloc(),
			_tree_alloc(),
			_key_comp(k),
			_value_comp(v)
			{
				_content = _new_content(val);
			}

		bst(const tree_type *parent, content_type val = content_type(),\
				key_compare k = key_compare(), value_compare v = value_compare()):
			_content(),
			_left(NULL),
			_right(NULL),
			_parent(parent),
			_alloc(),
			_tree_alloc(),
			_key_comp(k),
			_value_comp(v)
			{
				_content = _new_content(val);
			}

			bst(const bst<Key, V> &src):
			_content(),
			_left(src._left),
			_right(src._right),
			_parent(src._parent),
			_alloc(src._alloc),
			_tree_alloc(src._tree_alloc),
			_key_comp(src._key_comp),
			_value_comp(src._value_comp)
			{
				_content = _new_content(src._content);
			}

			~bst() {
				if (_left) 		~(*_left);
				if (_right) 	~(*_right);
				_alloc.destroy(_content);
				_alloc.deallocate(_content);
			}

			tree_type	&operator=(tree_const_reference src) {
				bst	cpy(src);

				this->swap(cpy);
				return *this;
			}

			private:
				
				static tree_pointer _new_node(content_const_reference val = content_type(),\
					tree_const_pointer parent = NULL, tree_type t = tree_type()) {
					tree_type	tree(parent, val);
					tree_type	*ptr = t._tree_alloc.allocate(sizeof(tree_type));

					t._tree_alloc.construct(ptr, tree);
					return ptr;
				}
			
};

}

#endif