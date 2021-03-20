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
    std_list = new std::list<int>{5,4,3,2,1};
    ft_list = new ft::list<int>(10, 10);

    ft_list->assign(std_list->rbegin(), std_list->rend());
    int n = 1;
    for (ft::list<int>::const_iterator it = ft_list->begin(); it != ft_list->end(); it++, n++) {
        EXPECT_EQ(n, *it);
    }

    ft::list<std::string> l(10, "eewefwejikfbhkjwfjkbwejfwbjkfbwejkbfwke");
    l.assign(10, "hello_world");
    for (ft::list<std::string>::const_iterator it = l.begin(); it != l.end(); it++) {
        EXPECT_EQ("hello_world", *it);
    }
}