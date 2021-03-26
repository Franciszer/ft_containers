/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TList_ElementAccess.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:53:09 by francisco         #+#    #+#             */
/*   Updated: 2021/03/22 19:59:58 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>
#include <list>
#include "container_macros.hpp"

// ELEMENT ACCESS TESTS

class	TList_ElementAccess: public ::testing::Test {
	public:
		TList_ElementAccess() {}

	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {
		}
};

TEST_F(TList_ElementAccess, front) {
    CONSTRUCT_STD_LIST(std_1, int, {1,2,3,4,5});
    CONSTRUCT_FT_LIST(ft_1, int, std_1.begin(), std_1.end());

    EXPECT_EQ(ft_1.front(), std_1.front());
    const int i = ft_1.front();
    const int i2 = std_1.front();
    EXPECT_EQ(i, i2);
}

TEST_F(TList_ElementAccess, back) {
    CONSTRUCT_STD_LIST(std_1, int, {1,2,3,4,5});
    CONSTRUCT_FT_LIST(ft_1, int, std_1.begin(), std_1.end());

    EXPECT_EQ(ft_1.back(), std_1.back());
    const int i = ft_1.back();
    const int i2 = std_1.back();
    EXPECT_EQ(i, i2);
}