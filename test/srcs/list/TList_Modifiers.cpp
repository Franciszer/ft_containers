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
	CONSTRUCT_FT_LIST(ft_1, int, 1, 1);
	CONSTRUCT_STD_LIST(std_1, int, 1, 1);

	APPLY_BOTH(ft_1, std_1, push_front, 77);
	COMP_CONTAINERS(ft_1, std_1);
}
