/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:45:25 by francisco         #+#    #+#             */
/*   Updated: 2021/04/04 12:08:21 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_TREE_HPP

# define BST_TREE_HPP

# include "ft_containers.hpp"

# define _BST_TREE_TP template<\
		typename	Key,\
		typename 	V,\
		class		KCompare = std::less<Key>,\
		class		VCompare = std::less<V>,\
		class		Alloc = std::allocator<pair<Key, V> >\
		>

# define _BST_TREE_TP_INIT Key, V, KCompare, VCompare, Alloc

using ft::pair;
namespace ft {

	_BST_TREE_TP
	class bst_tree {
		public:
			typedef	V								value_type;
			typedef	Key								key_type;
			typedef pair<value_type, key_type>		content_type;
			typedef bst_tree						tree_type;
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
			typedef std::allocator<bst_tree>		tree_allocator_type;

			bst_tree(content_type val = content_type(),\
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

		bst_tree(const tree_type *parent, content_type val = content_type(),\
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

			bst_tree(const bst_tree<Key, V> &src):
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

			~bst_tree() {
				if (_left) 		~(*_left);
				if (_right) 	~(*_right);
				_del_node(this);
			}

			tree_type	&operator=(tree_const_reference src) {
				bst_tree	cpy(src);

				this->swap(cpy);
				return *this;
			}

			friend bst_tree	*insert(tree_reference current, content_type val = content_type()) {
				if (current._key_comp(val.first, current._content->first)) {
					if (current._content->first)
						return current.insert(val);
					 else
					 	return current._left = current._new_node(val);
				}
				else if (current._key_comp(current._content->first, val.first)) {
					if (current._content->first)
						return current.insert(val);
					 else
					 	return current._right = current._new_node(val);
				}
				else
					return NULL;
			}


			private:
				tree_type		*_new_node(content_const_reference val = content_type(),\
					const tree_type *parent = NULL) {
					tree_type	tree(parent, val);
					tree_type	*ptr = _tree_alloc.allocate(sizeof(tree_type));

					_tree_alloc.construct(ptr, tree);
					return ptr;
				}
			
				tree_type		*_del_node(tree_type* &target) {
					_alloc.destroy(target->_content);
					_alloc.deallocate(target->content);
					_tree_alloc.destoy(target);
					_tree_alloc.deallocate(target);
					target = NULL;
				}

				void	swap(bst_tree x) {
					bst_tree tmp(*this);

					this->value(x.value);
					this->left(x.left);
					this->right(x.right);
					this->parent(x.parent);

					x.value(tmp.value);
					x.left(tmp.left);
					x.right(tmp.right);
					x.parent(tmp.parent);
				}

				content_type		_content;
				tree_pointer		_left;
				tree_pointer		_right;
				tree_pointer		_parent;
				allocator_type		_alloc;
				tree_allocator_type	_tree_alloc;
				key_compare			_key_comp;
				value_compare		_value_comp;
	};


// COMPARAISON OPERATORS

_BST_TREE_TP
bool		operator==(const bst_tree<_BST_TREE_TP_INIT> &lhs,\
						const bst_tree<_BST_TREE_TP_INIT> &rhs)
{
	return !lhs._key_comp(lhs._content->first, rhs._content->first) &&\
			!lhs._key_comp(rhs._content->first, lhs._content->first);
}

_BST_TREE_TP
bool		operator!=(const bst_tree<_BST_TREE_TP_INIT> &lhs,\
						const bst_tree<_BST_TREE_TP_INIT> &rhs)
{
	return !(lhs == rhs);
}

_BST_TREE_TP
bool		operator<(const bst_tree<_BST_TREE_TP_INIT> &lhs,\
						const bst_tree<_BST_TREE_TP_INIT> &rhs)
{
	return lhs._key_comp(lhs._content->first, rhs._content->first);
}

_BST_TREE_TP
bool		operator<=(const bst_tree<_BST_TREE_TP_INIT> &lhs,\
						const bst_tree<_BST_TREE_TP_INIT> &rhs)
{
	return lhs < rhs || lhs == rhs;
}

_BST_TREE_TP
bool		operator>(const bst_tree<_BST_TREE_TP_INIT> &lhs,\
						const bst_tree<_BST_TREE_TP_INIT> &rhs)
{
	return !(lhs < rhs);
}

_BST_TREE_TP
bool		operator>=(const bst_tree<_BST_TREE_TP_INIT> &lhs,\
						const bst_tree<_BST_TREE_TP_INIT> &rhs)
{
	return lhs > rhs || lhs >= rhs;
}
}

#endif