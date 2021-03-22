/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TList_Modifiers.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:25:25 by francisco         #+#    #+#             */
/*   Updated: 2021/03/20 21:08:43 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>
#include <list>
#include "container_macros.hpp"

// ELEMENT ACCESS TESTS

class	TList_Modifiers: public ::testing::Test {
	public:
		TList_Modifiers() {}

		ft::list<int>		*ft_list = nullptr;
		std::list<int>		*std_list = nullptr;
	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {
			if (ft_list != nullptr) {
				delete ft_list;
				ft_list = nullptr;
			}
			if (std_list != nullptr) {
				delete std_list;
				std_list = nullptr;
			}
		}
		void		compare() {
			if (ft_list == nullptr)
				FAIL() << "bad_test: ft_list is uninitialized";
			else if (std_list == nullptr)
				FAIL() << "bad_test: std_list is uninitialized";
			EXPECT_EQ(std_list->size(), ft_list->size());
			ft::list<int>::const_iterator it = ft_list->begin();
			std::list<int>::const_iterator it2 = std_list->begin();
			ASSERT_EQ(std_list->size(), ft_list->size());
			for (; it2 != std_list->end() ; it++, it2++)
				EXPECT_EQ(*it, *it2);
			this->TearDown();
		}
};

TEST_F(TList_Modifiers, assign) {
    std::list<int> 	std_1{5,4,3,2,1};
    CONSTRUCT_FT_LIST(ft_1, int, 10, 10);

    ft_1.assign(std_1.rbegin(), std_1.rend());
    containers_test::equalsRange(ft_1, std_1.rbegin(), std_1.rend());
	CONSTRUCT_FT_LIST(ft_2, std::string, 10, "ola_mundo");
    CONSTRUCT_STD_LIST(std_2, std::string, 7, "hello_world");
	ft_2.assign(7, "hello_world");
	COMP_CONTAINERS(ft_2, std_2);
}

TEST_F(TList_Modifiers, push_front) {
	CONSTRUCT_FT_LIST(ft_1, int, 1, 10);
	CONSTRUCT_STD_LIST(std_1, int, 1, 10);

	APPLY_BOTH(ft_1, std_1, push_front, 77);
	COMP_CONTAINERS(ft_1, std_1);
}

TEST_F(TList_Modifiers, pop_front) {
	CONSTRUCT_FT_LIST(ft_1, int, 1, 2);
	CONSTRUCT_STD_LIST(std_1, int, 1, 2);
	APPLY_BOTH(ft_1, std_1, push_front, 88);
	APPLY_BOTH(ft_1, std_1, push_front, 123);
	APPLY_BOTH(ft_1, std_1, push_front, 3425);
	APPLY_BOTH(ft_1, std_1, push_front, 5345345);
	APPLY_BOTH(ft_1, std_1, push_front, 345345345);
	APPLY_BOTH(ft_1, std_1, push_front, 234234234);
	APPLY_BOTH(ft_1, std_1, pop_front);
	while (!std_1.empty()) {
		APPLY_BOTH(ft_1, std_1, pop_front);
		COMP_CONTAINERS(ft_1, std_1);
	}
	EXPECT_TRUE(ft_1.empty());
}

TEST_F(TList_Modifiers, push_back) {
	CONSTRUCT_FT_LIST(ft_1, int, 1, 2);
	CONSTRUCT_STD_LIST(std_1, int, 1, 2);

	APPLY_BOTH(ft_1, std_1, push_back, 989);
	COMP_CONTAINERS(ft_1, std_1);
	APPLY_BOTH(ft_1, std_1, push_back, 12312);
	COMP_CONTAINERS(ft_1, std_1);
	APPLY_BOTH(ft_1, std_1, push_back, -12312312);
	COMP_CONTAINERS(ft_1, std_1);
	APPLY_BOTH(ft_1, std_1, push_back, 12312312);
	COMP_CONTAINERS(ft_1, std_1);
	APPLY_BOTH(ft_1, std_1, push_back, -123123124);
	COMP_CONTAINERS(ft_1, std_1);
	APPLY_BOTH(ft_1, std_1, push_back, 3434234);
	COMP_CONTAINERS(ft_1, std_1);
	APPLY_BOTH(ft_1, std_1, push_back, 423423423);
	COMP_CONTAINERS(ft_1, std_1);
}

TEST_F(TList_Modifiers, pop_back) {
	CONSTRUCT_FT_LIST(ft_1, int, 1, 2);
	CONSTRUCT_STD_LIST(std_1, int, 1, 2);

	APPLY_BOTH(ft_1, std_1, push_back, 989);
	APPLY_BOTH(ft_1, std_1, push_back, 12312);
	APPLY_BOTH(ft_1, std_1, push_back, -12312312);
	APPLY_BOTH(ft_1, std_1, push_back, 12312312);
	APPLY_BOTH(ft_1, std_1, push_back, -123123124);
	APPLY_BOTH(ft_1, std_1, push_back, 423423423);
	APPLY_BOTH(ft_1, std_1, push_back, -1234124 );

	while (!std_1.empty()) {
		APPLY_BOTH(ft_1, std_1, pop_back);
		COMP_CONTAINERS(ft_1, std_1);
	}
	EXPECT_TRUE(ft_1.empty());
}

TEST_F(TList_Modifiers, insert) {
	// SINGLE ELEMENT
	CONSTRUCT_FT_LIST(ft_1, int, 22, 17);
	CONSTRUCT_STD_LIST(std_1, int, 22, 17);

	EXPECT_EQ(*(ft_1.insert(ft_1.end(), 8273897)) ,\
		*(std_1.insert(std_1.end(), 8273897)));

	COMP_CONTAINERS(ft_1, std_1);

	ft_1.insert(ft_1.begin(), 8273897);
	std_1.insert(std_1.begin(), 8273897);

	COMP_CONTAINERS(ft_1, std_1);
	ft::list<int>::iterator	ft_it = ft_1.begin();
	std::list<int>::iterator	std_it = std_1.begin();

	for (int i = 0; i < 4; i++, ft_it++, std_it++);

	ft_1.insert(ft_it, -213123123);
	std_1.insert(std_it, -213123123);
	COMP_CONTAINERS(ft_1, std_1);

	// FILL
	CONSTRUCT_FT_LIST(ft_2, int, 22, 17);
	CONSTRUCT_STD_LIST(std_2, int, 22, 17);

	COMP_CONTAINERS(ft_2, std_2);

	ft_2.insert(ft_2.end(), 4, 7);
	std_2.insert(std_2.end(), 4, 7);
	COMP_CONTAINERS(ft_2, std_2);

	ft_2.insert(ft_2.begin(), 6, 8273897);
	std_2.insert(std_2.begin(), 6, 8273897);
	COMP_CONTAINERS(ft_2, std_2);

	COMP_CONTAINERS(ft_2, std_2);
	ft::list<int>::iterator		ft_it2 = ft_2.begin();
	std::list<int>::iterator	std_it2 = std_2.begin();
	for (int i = 0; i < 4; i++, ft_it2++, std_it2++);

	ft_2.insert(ft_it2, 4, 23);
	std_2.insert(std_it2, 4, 23);
	COMP_CONTAINERS(ft_2, std_2);

	// RANGE
	CONSTRUCT_FT_LIST(ft_3, int, 22, 2);
	CONSTRUCT_STD_LIST(std_3, int, 22, 2);
	std::list<int>  l({1,2,3,4,5});

	COMP_CONTAINERS(ft_3, std_3);

	ft_3.insert(ft_3.begin(), l.rbegin(), l.rend());
	std_3.insert(std_3.begin(), l.rbegin(), l.rend());
	COMP_CONTAINERS(ft_3, std_3);

	ft_3.insert(ft_3.begin(), l.rbegin(), l.rend());
	std_3.insert(std_3.begin(), l.rbegin(), l.rend());
	COMP_CONTAINERS(ft_3, std_3);

	ft::list<int>::iterator		ft_it3 = ft_3.begin();
	std::list<int>::iterator	std_it3 = std_3.begin();
	for (int i = 0; i < 4; i++, ft_it3++, std_it3++);
	ft_3.insert(ft_it3, 4, 23);
	std_3.insert(std_it3, 4, 23);
	COMP_CONTAINERS(ft_3, std_3);
}

TEST_F(TList_Modifiers, erase) {
	// SINGLE ELEMENT
	std::list<int>	std_1({1,2,3,4,5,6,7,8,9});
	CONSTRUCT_FT_LIST(ft_1, int, std_1.begin(), std_1.end());

	auto ft_it1 = ft_1.erase(ft_1.begin());
	auto std_it1 = std_1.erase(std_1.begin());
	COMP_CONTAINERS(ft_1, std_1);
	EXPECT_EQ(*ft_it1, *std_it1);
	for (int i = 0; i < 4; i++, ft_it1++, std_it1++);
	ft_it1 = ft_1.erase(ft_it1);
	std_it1 = std_1.erase(std_it1);
	COMP_CONTAINERS(ft_1, std_1);
	EXPECT_EQ(*ft_it1, *std_it1);

	ft_it1 = --(ft_1.end());
	std_it1 = --(std_1.end());
	ft_it1 = ft_1.erase(ft_it1);
	std_it1 = std_1.erase(std_it1);
	COMP_CONTAINERS(ft_1, std_1);
	EXPECT_EQ(ft_it1, ft_1.end());
	EXPECT_EQ(std_it1, std_1.end());

	// RANGE
	std::list<int>	std_2({1,2,3,4,5,6,7,8,9});
	CONSTRUCT_FT_LIST(ft_2, int, std_2.begin(), std_2.end());

	auto ft_it2 = ft_2.begin();
	auto std_it2 = std_2.begin();
	for (int i = 0; i < 4; i++, ft_it2++, std_it2++);

	EXPECT_EQ(*(std_2.erase(std_2.begin(), std_it2)),\
		*(ft_2.erase(ft_2.begin(), ft_it2)));

	ft_2.erase(ft_2.begin(), ft_2.end());
	std_2.erase(std_2.begin(), std_2.end());
}

TEST_F(TList_Modifiers, swap) {
	CONSTRUCT_STD_LIST(std_1, int, {1,2,3,4,5});
	ft::list<int> ft_1;
	CONSTRUCT_FT_LIST(ft_2, int, std_1.begin(), std_1.end());

	ft_1.swap(ft_2);
	// EXPECT_TRUE(ft_2.empty());
	// COMP_CONTAINERS(ft_1, std_1);
}

TEST_F(TList_Modifiers, resize) {
	CONSTRUCT_FT_LIST(ft_1, int, 2);
	CONSTRUCT_STD_LIST(std_1, int, 2);

	APPLY_BOTH(ft_1, std_1, resize, 5, 17);
	COMP_CONTAINERS(ft_1, std_1);

	APPLY_BOTH(ft_1, std_1, resize, 10, -232);
	COMP_CONTAINERS(ft_1, std_1);
}