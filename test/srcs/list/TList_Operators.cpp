/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TList_Operators.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:51:57 by francisco         #+#    #+#             */
/*   Updated: 2021/03/22 23:33:08 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>
#include <list>
#include "container_macros.hpp"

// Operator TESTS

class	TList_Operators: public ::testing::Test {
	public:
		TList_Operators() {}

	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {
		}
        static bool     isNegative(const int &i) {
            return i >= 0 ? false : true;
        }
        static bool     is2021(const int &i) {
            return i == 2021 ? true : false;
        }
        static bool     isLower(const int &i, const int &i2) {
            return i < i2 ? true : false;
        }
};

TEST_F(TList_Operators, splice) {
    // ENTIRE LIST
    CONSTRUCT_STD_LIST(std_src, int, {1,2,3,4,5,6,7,8,9,10});
    CONSTRUCT_STD_LIST(std_copy, int, std_src);
    CONSTRUCT_FT_LIST(ft_src, int, std_src.begin(), std_src.end());
    ft::list<int>   ft_1;
    ft_1.splice(ft_1.end(), ft_src);
    EXPECT_TRUE(ft_src.empty());
    COMP_CONTAINERS(ft_1, std_copy);

    // SINGLE ELEMENT
    ft::list<int>   ft_2_src;
    
    ft_2_src.push_back(1);
    ft_2_src.push_back(2);
    ft_2_src.push_back(3);
    ft_2_src.push_back(4);
    ft_2_src.push_back(5);

    ft::list<int>  ft_2(1,5);

    ft_2.splice(ft_2.begin(), ft_2_src, ft_2_src.begin());
    EXPECT_EQ(1, ft_2.front());
    EXPECT_EQ(2, *(ft_2_src.begin()));
    ft_2.splice(ft_2.end(), ft_2_src, --ft_2_src.end());
    EXPECT_EQ(5, ft_2.back());

    // RANGE
    CONSTRUCT_STD_LIST(std_copy_3, int, {1,2,3,4,5,6,7});
    CONSTRUCT_FT_LIST(ft_copy_3, int, std_copy_3.begin(), std_copy_3.end());
    CONSTRUCT_STD_LIST(std_3, int, 10,1);
    CONSTRUCT_FT_LIST(ft_3, int, 10,1);

    std_3.splice(++(std_3.begin()), std_copy_3, ++(std_copy_3.begin()), --(std_copy_3.end()));
    ft_3.splice(++(ft_3.begin()), ft_copy_3, ++(ft_copy_3.begin()), --(ft_copy_3.end()));
    COMP_CONTAINERS(std_3, ft_3);
    COMP_CONTAINERS(std_copy_3, ft_copy_3);
}

TEST_F(TList_Operators, remove) {
    CONSTRUCT_STD_LIST(std_1, int, {2,1,1,23,3,4235,1,1,1,1,12323,1});
    CONSTRUCT_FT_LIST(ft_1, int, std_1.begin(), std_1.end());

    APPLY_BOTH(std_1, ft_1, remove, 0);
    COMP_CONTAINERS(std_1, ft_1);
    APPLY_BOTH(std_1, ft_1, remove, 1);
    COMP_CONTAINERS(std_1, ft_1);
}

TEST_F(TList_Operators, remove_if) {
    CONSTRUCT_STD_LIST(std_1, int, {-213123,-12312, 312312,321,3132,23-1231,-3123,31231,31,-2});
    CONSTRUCT_FT_LIST(ft_1, int, std_1.begin(), std_1.end());

    APPLY_BOTH(std_1, ft_1, remove_if, TList_Operators::is2021);
    COMP_CONTAINERS(std_1, ft_1);
    APPLY_BOTH(std_1, ft_1, remove_if, TList_Operators::isNegative);
    COMP_CONTAINERS(std_1, ft_1);
}

TEST_F(TList_Operators, unique) {
    CONSTRUCT_STD_LIST(std_1, int, {2,3,23,34,543,1,1,1231,1,323,11,1});
    CONSTRUCT_FT_LIST(ft_1, int, std_1.begin(), std_1.end());

    APPLY_BOTH(ft_1, std_1, unique, TList_Operators::isLower);
    COMP_CONTAINERS(ft_1, std_1);
}