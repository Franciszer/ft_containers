/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TList_Operators.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:51:57 by francisco         #+#    #+#             */
/*   Updated: 2021/03/26 23:12:15 by francisco        ###   ########.fr       */
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
        static bool     isGreater(const int &i, const int &i2) {
            return i > i2 ? true : false;
        }
};

TEST_F(TList_Operators, splice) {
    // ENTIRE LIST
    CONSTRUCT_STD_LIST(std_src, int, {1,2,3,4,5,6,7,8,9,10});
    CONSTRUCT_STD_LIST(std_copy, int, std_src);
    CONSTRUCT_FT_LIST(ft_src, int, std_src.begin(), std_src.end());
    CONSTRUCT_FT_LIST(ft_1, int, 5, 5);
    CONSTRUCT_STD_LIST(std_1, int, 5, 5);
    std_1.splice(std_1.end(), std_src);
    ft_1.splice(ft_1.end(), ft_src);
    COMP_CONTAINERS(ft_1, std_1);

    // SINGLE ELEMENT
    CONSTRUCT_STD_LIST(std_2_src, int, {1, 2, 3, 4, 5})
    CONSTRUCT_FT_LIST(ft_2_src, int, std_2_src.begin(), std_2_src.end());
    CONSTRUCT_STD_LIST(std_2, int, 1, 5);
    CONSTRUCT_FT_LIST(ft_2, int, 1, 5);

    ft_2.splice(ft_2.begin(), ft_2_src, ft_2_src.begin());
    std_2.splice(std_2.begin(), std_2_src, std_2_src.begin());
    COMP_CONTAINERS(ft_2, std_2);

    ft_2.splice(ft_2.end(), ft_2_src, ft_2_src.begin());
    std_2.splice(std_2.end(), std_2_src, std_2_src.begin());
    COMP_CONTAINERS(ft_2, std_2);

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

TEST_F(TList_Operators, merge) {
    // VOID PARAMETER
    CONSTRUCT_STD_LIST(std_copy_1, int, {1,3,5,7,9});
    CONSTRUCT_STD_LIST(std_1, int, {2,4,5,10});
    CONSTRUCT_FT_LIST(ft_copy_1, int, std_copy_1.begin(), std_copy_1.end());
    CONSTRUCT_FT_LIST(ft_1, int, std_1.begin(), std_1.end());
    std_1.merge(std_copy_1);
    ft_1.merge(ft_copy_1);
	COMP_CONTAINERS(ft_1, std_1);
    CONSTRUCT_STD_LIST(std_copy_2, int, {1,3,5,7,9});
    CONSTRUCT_STD_LIST(std_2, int, {2,4,5,10});
    CONSTRUCT_FT_LIST(ft_copy_2, int, std_copy_2.begin(), std_copy_2.end());
    CONSTRUCT_FT_LIST(ft_2, int, std_2.begin(), std_2.end());
    std_2.merge(std_copy_2);
    ft_2.merge(ft_copy_2);
	COMP_CONTAINERS(ft_2, std_2);

    // COMPARE FUNCTION PARAMETER
    CONSTRUCT_STD_LIST(std_copy_3, int, {9,6,5,3,2});
    CONSTRUCT_STD_LIST(std_3, int, {6,5,4,3});
    CONSTRUCT_FT_LIST(ft_copy_3, int, std_copy_3.begin(), std_copy_3.end());
    CONSTRUCT_FT_LIST(ft_3, int, std_3.begin(), std_3.end());
    std_3.merge(std_copy_3, isGreater);
    ft_3.merge(ft_copy_3, isGreater);
	COMP_CONTAINERS(ft_3, std_3);
    CONSTRUCT_STD_LIST(std_copy_4, int, {9,5,3,2});
    CONSTRUCT_STD_LIST(std_4, int, {9,3,2});
    CONSTRUCT_FT_LIST(ft_copy_4, int, std_copy_4.begin(), std_copy_4.end());
    CONSTRUCT_FT_LIST(ft_4, int, std_4.begin(), std_4.end());
    std_4.merge(std_copy_4, isGreater);
    ft_4.merge(ft_copy_4, isGreater);
	COMP_CONTAINERS(ft_4, std_4);
}

TEST_F(TList_Operators, sort) {
	// VOID PARAMETER
	CONSTRUCT_STD_LIST(std_1, int, {5,4, 1,3,2,1});
    CONSTRUCT_FT_LIST(ft_1, int, std_1.begin(), std_1.end());
	APPLY_BOTH(std_1, ft_1, sort);
	COMP_CONTAINERS(ft_1, std_1);

	CONSTRUCT_STD_LIST(std_2, int, {1});
    CONSTRUCT_FT_LIST(ft_2, int, std_2.begin(), std_2.end());
	APPLY_BOTH(std_2, ft_2, sort);
	COMP_CONTAINERS(std_2, ft_2);

	CONSTRUCT_STD_LIST(std_3, int, {1, -2});
    CONSTRUCT_FT_LIST(ft_3, int, std_3.begin(), std_3.end());
	APPLY_BOTH(std_3, ft_3, sort);
	COMP_CONTAINERS(std_3, ft_3);

	// COMPARE FUNCTION PARAMETER
	CONSTRUCT_STD_LIST(std_4, int, {5,4, 1,3,2,1});
    CONSTRUCT_FT_LIST(ft_4, int, std_4.begin(), std_4.end());
	APPLY_BOTH(std_4, ft_4, sort, isGreater);
	COMP_CONTAINERS(ft_4, std_4);
	CONSTRUCT_STD_LIST(std_5, int, {1});
    CONSTRUCT_FT_LIST(ft_5, int, std_5.begin(), std_5.end());
	APPLY_BOTH(std_5, ft_5, sort, isGreater);
	COMP_CONTAINERS(std_5, ft_5);

	CONSTRUCT_STD_LIST(std_6, int, {1, -2});
    CONSTRUCT_FT_LIST(ft_6, int, std_6.begin(), std_6.end());
	APPLY_BOTH(std_6, ft_6, sort, isGreater);
	COMP_CONTAINERS(std_6, ft_6);
}

TEST_F(TList_Operators, reverse) {
	CONSTRUCT_STD_LIST(std_1, int, {1, -2,231,3,213,122,2});
    CONSTRUCT_FT_LIST(ft_1, int, std_1.begin(), std_1.end());
    APPLY_BOTH(std_1, ft_1, reverse);
    COMP_CONTAINERS(ft_1, std_1);
}