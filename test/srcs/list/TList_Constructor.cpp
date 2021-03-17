/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TList_Constructor.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:11:25 by frthierr          #+#    #+#             */
/*   Updated: 2021/03/17 17:04:57 by frthierr         ###   ########.fr       */
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
};

TEST_F(TList_Constructor, def) {
	ft_list = new ft::list<int>;

	EXPECT_EQ(0, ft_list->size());
}

TEST_F(TList_Constructor, fill) {
	ft_list = new ft::list<int>(10, 55);

	for (ft::list<int>::iterator it = ft_list->begin() ; it != ft_list->end(); it++)
		EXPECT_EQ(55, *it);
}