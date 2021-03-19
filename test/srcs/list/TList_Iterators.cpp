/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TList_Iterators.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:19:15 by frthierr          #+#    #+#             */
/*   Updated: 2021/03/19 22:40:43 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>
#include <list>

// ITERATOR TESTS
class	TList_Iterator: public ::testing::Test {
	public:
		ft::list<int>	*ft_list = nullptr;
		std::list<int>	*std_list = nullptr;
		TList_Iterator() {}
	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {
			if (ft_list != nullptr)
				delete ft_list;
			if (std_list != nullptr)
				delete std_list;
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

TEST_F(TList_Iterator, end) {
	ft_list = new ft::list<int>;
	EXPECT_EQ(ft_list->begin(), ft_list->end());
	
	ft_list->push_back(5);
	ft_list->push_back(-123);
	ft_list->push_back(21312);
	ft_list->push_back(213114414);
	ft_list->push_back(-2131321);
	ft_list->push_back(2048123128);

	EXPECT_EQ(*(--ft_list->end()), 2048123128);
}

TEST_F(TList_Iterator, rbegin) {
	ft_list = new ft::list<int>;
	std_list = new std::list<int>;

	EXPECT_EQ(ft_list->rbegin(), ft_list->rend());
	
	ft_list->push_back(5);
	ft_list->push_back(-123);
	ft_list->push_back(21312);
	ft_list->push_back(213114414);
	ft_list->push_back(-2131321);
	ft_list->push_back(2048123128);

	for (ft::list<int>::iterator it = ft_list->begin(); it != ft_list->end(); it++)
		std_list->push_back(*it);

	std::list<int>::reverse_iterator	std_rit = std_list->rbegin();
	ft::list<int>::reverse_iterator		ft_rit = ft_list->rbegin();

	ASSERT_EQ(std_list->size(), ft_list->size());

	for (; std_rit != std_list->rend() && ft_rit != ft_list->rend(); ft_rit++, std_rit++) {
		EXPECT_EQ(*std_rit, *ft_rit);
	}
}

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
// }
