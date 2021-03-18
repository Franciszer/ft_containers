/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TList_Iterators.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:19:15 by frthierr          #+#    #+#             */
/*   Updated: 2021/03/18 16:30:47 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>
#include <list>

// ITERATOR TESTS
class	TList_Iterator: public ::testing::Test {
	public:
		ft::list<int>	*ft_list = nullptr;
		TList_Iterator() {}
	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {
			if (ft_list != nullptr)
				delete ft_list;
		}
};

TEST_F(TList_Iterator, begin) {
	ft_list = new ft::list<int>;

	// checking is ft::list::begin segaults on empty vector
	ft_list->begin();
	
	ft_list->push_back(5);
	ft_list->push_back(-123);
	ft_list->push_back(21312);
	ft_list->push_back(213114414);
	ft_list->push_back(-2131321);
	ft_list->push_back(2048123128);

	EXPECT_EQ(*(ft_list->begin()), 5);


	ft::list<int>	ft_list(5, 1);
	
	ft::list<int>::iterator cit = ft_list.begin();
	
	ft::list<int>::const_iterator it(cit);

}

// TEST_F(TList_Iterator, end) {
// 	ft_list = new ft::list<int>;
// 	EXPECT_EQ(ft_list->begin(), ft_list->end());
	
// 	ft_list->push_back(5);
// 	ft_list->push_back(-123);
// 	ft_list->push_back(21312);
// 	ft_list->push_back(213114414);
// 	ft_list->push_back(-2131321);
// 	ft_list->push_back(2048123128);

// 	EXPECT_EQ(*(--ft_list->end()), 2048123128);
// }

// TEST_F(TList_Iterator, rbegin) {
// 	ft_list = new ft::list<int>;
// 	ft::list<int>::reverse_iterator	rit = ft_list->rbegin();

// 	EXPECT_EQ(rit, ft_list->rend());
// 	ft_list->push_back(5);
// 	ft_list->push_back(-123);
// 	ft_list->push_back(21312);
// 	ft_list->push_back(213114414);
// 	ft_list->push_back(-2131321);
// 	ft_list->push_back(2048123128);

// 	ft::list<int> ft_list2(ft_list->rbegin(), ft_list->rend());
// 	ft::list<int> ft_list3(ft_list2.rbegin(), ft_list2.rend());

// 	ft::list<int>::reverse_iterator it = ft_list->rbegin();
// 	for (int i = ft_list->size() - 1; it != ft_list->rend() && i >= 0; i--, it++) {
// 		EXPECT_EQ(*it, (*ft_list)[i]);
// 	}
// }

// TEST_F(TList_Iterator, rend) {
// 	ft_list = new ft::list<int>;
// 	ft::list<int>::reverse_iterator rit(ft_list->rend());
// 	EXPECT_EQ(ft_list->rbegin(), rit);
// 	ft_list->push_back(5);
// 	ft_list->push_back(-123);
// 	ft_list->push_back(21312);
// 	ft_list->push_back(213114414);
// 	ft_list->push_back(-2131321);
// 	ft_list->push_back(2048123128);

// 	ft::list<int> ft_list2(ft_list->rbegin(), ft_list->rend());
// 	ft::list<int> ft_list3(ft_list2.rbegin(), ft_list2.rend());

// 	ft::list<int>::reverse_iterator it = ft_list->rend();
// 	--it;
// 	for (ft::list<int>::size_type i = 0; i < ft_list->size(); i++, it--) {
// 		EXPECT_EQ(*it, (*ft_list)[i]);
// 	}
// }
