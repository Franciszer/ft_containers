/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TList_Constructor.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:11:25 by frthierr          #+#    #+#             */
/*   Updated: 2021/03/18 14:10:18 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>
#include <list>

// CONSTRUCTOR  TESTS
class	TList_Constructor: public ::testing::Test {
	public:
		TList_Constructor() {}

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

TEST_F(TList_Constructor, def) {
	ft_list = new ft::list<int>;
	std_list = new std::list<int>;

	compare();
}

TEST_F(TList_Constructor, fill) {
	ft_list = new ft::list<int>(10, 55);
	std_list = new std::list<int>(10, 55);

	compare();
}

TEST_F(TList_Constructor, range) {
	ft::list<int> l2;
	
	l2.push_back(5);
	l2.push_back(7);
	ft_list = new ft::list<int>(l2.begin(), l2.end());
	ASSERT_EQ(l2.size(), ft_list->size());
	ft::list<int>::iterator it = ft_list->begin();
	ft::list<int>::iterator it2 = l2.begin();
	for (; it != ft_list->end() ; it++, it2++)
		EXPECT_EQ(*it, *it2);
	TearDown();
	--it2;
	ft_list = new ft::list<int>(l2.begin(), it2);
	it2 = l2.begin();
	ASSERT_EQ(l2.size() - 1, ft_list->size());
	for (; it != ft_list->end() ; it++, it2++) {
			EXPECT_EQ(*it, *it2);
	}
}

TEST_F(TList_Constructor, copy) {
	ft::list<std::string>	src(10, "hello");
	ft::list<std::string>	copy(src);

	ft::list<std::string>::iterator it = src.begin();
	ft::list<std::string>::iterator it2 = copy.begin();
	for (; it != src.end(); it++, it2++)
		EXPECT_EQ(*it, *it2);
}