/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_wrapper.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:24:31 by frthierr          #+#    #+#             */
/*   Updated: 2021/04/04 15:50:06 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_WRAPPER

# define BST_WRAPPER

# include "ft_containers.hpp"

template<class TREE_TYPE>
friend class	bst_wrapper;
	public:

		typedef TREE_TYPE								tree_type;
		typedef	tree_type::value_type					value_type;
		typedef	tree_type::key_type						key_type;
		typedef tree_type::content_type					content_type;
		typedef	tree_type::difference_type				difference_type;
		typedef	tree_type::size_type					size_type;
		typedef	tree_type::key_compare					key_compare;
		typedef	tree_type::value_compare				value_compare;

		typedef	tree_type::content_reference			content_reference;
		typedef	tree_type::content_pointer				content_pointer;
		typedef	tree_type::content_const_pointer		content_const_pointer;
		typedef	tree_type::content_const_reference		content_const_reference;

		typedef tree_type&								tree_reference;
		typedef tree_type*								tree_pointer;
		typedef const tree_type*						tree_const_pointer;
		typedef const tree_type&						tree_const_reference;

		typedef	Alloc									allocator_type;
		typedef std::allocator<bst>						tree_allocator_type;

		bst_wrapper(void):
		_root(),
		_leftmost(),
		_rightmost() {
			_end = _new_node();
		}
		
		bst_wrapper(bst_wrapper const &src);
		
		virtual ~bst_wrapper(void) {
			_del_tree(_end);	
		}

		bst_wrapper   &operator=(bst_wrapper const &src);

	private:
		tree_pointer	_root;
		tree_pointer	_end;
		tree_pointer	_leftmost;
		tree_pointer	_rightmost;

		tree_type	*insert(tree_reference current, content_type val = content_type()) {
			// DETERMINING WHERE THE NODE WILL BE INSERTED
			if (current._key_comp(val.first, current._content->first)) {
				if (current._left)
					return current._left->insert(val);
				else
					return current._left = current._new_node(val, current);
			}
			else if (current._key_comp(current._content->first, val.first)) {
				if (current._right)
					return current._right->insert(val);
				else
					return current._right = current._new_node(val, current);
			}
			// IF THERE IS A DUPLICATE MEMBER
			else
				return NULL;
		}

		tree_type		*_del_node(tree_reference parent, tree_pointer bst::*child) {
			tree_pointer	replacement = NULL;
			tree_pointer	to_del = parent->child;
			
			if (parent->child->_left && parent->child->_right\
				&& parent->child->_left != _end && parent->child->_right != _end) {
				replacement = parent->child->_left->max();
				replacement->_right = _parent->child->_right;
				replacement->_left = _parent->child->_left;
			}
			else if (parent->child->_left && parent->child->_left != _end) {
				replacement = parent->child->_left;
			}
			else if (parent->child->_right && parent->child->_right != _end) {
				replacement = child->_right;
			}
			if (replacement)
				replacement->parent = &parent;
			parent->child = replacement;
			_end._alloc.destroy(to_del->content);
			_end._alloc.deallocate(to_del->content);
			_end._tree_alloc.destroy(to_del);
			_end._tree_alloc.deallocate(to_del);
		}

		tree_type		*_del_tree(tree_pointer current) {
			if (current._left && current._left != _end) {
				_del_tree(current_left);
			}
			if (current._right && current._right != _end) {
				_del_tree(current._right);
			}			
			_end._alloc.destroy(to_del->content);
			_end._alloc.deallocate(to_del->content);
			_end._tree_alloc.destroy(to_del);
			_end._tree_alloc.deallocate(to_del);
		}
};

#endif
