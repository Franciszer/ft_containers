/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TList_Constructor.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:11:25 by frthierr          #+#    #+#             */
/*   Updated: 2021/03/17 19:42:11 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>
#include <list>

// CAPACITY TESTS
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
			EXPECT_EQ(std_list->size(), ft_list->size());
			ft::list<int>::const_iterator it = ft_list->begin();
			std::list<int>::const_iterator it2 = std_list->begin();
			EXPECT_EQ(std_list->size(), ft_list->size());
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

	for (ft::list<int>::iterator it = ft_list->begin() ; it != ft_list->end(); it++)
		EXPECT_EQ(55, *it);
}