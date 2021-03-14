/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TVector_Operator.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:13:36 by francisco         #+#    #+#             */
/*   Updated: 2021/03/13 21:46:38 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>

// OPERATOR TESTS
class	TVector_ElementAccess: public ::testing::Test {
	public:
		TVector_ElementAccess() {}

		ft::vector<int>		*ft_vec = nullptr;
		std::vector<int>		*std_vec = nullptr;        

	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {
			if (ft_vec != nullptr) {
				delete ft_vec;
				ft_vec = nullptr;
			}
			if (std_vec != nullptr) {
				delete std_vec;
				std_vec = nullptr;
			}
		}
};

TEST_F(TVector_ElementAccess, operator_square_brackets) {
    ft_vec = new ft::vector<int>(10);

    for (int i = 0; i < 10; i++) {
        (*ft_vec)[i] = 0;
    }

    std_vec = new std::vector<int>();
    std_vec->push_back(54);
    std_vec->push_back(-213);
    std_vec->push_back(23123);
    std_vec->push_back(-888);
    std_vec->push_back(777);

    for (ft::vector<int>::size_type i = 0; i < std_vec->size(); i++) {
        (*ft_vec)[i] = (*std_vec)[i];
        EXPECT_EQ((*std_vec)[i], (*ft_vec)[i]);
    }
    SUCCEED();
}

TEST_F(TVector_ElementAccess, at) {
    ft_vec = new ft::vector<int>;

    ft_vec->push_back(-2);
    ft_vec->push_back(-1);
    ft_vec->push_back(0);
    ft_vec->push_back(1);
    ft_vec->push_back(2);

    EXPECT_EQ(-2, ft_vec->at(0));
    EXPECT_EQ(-1, ft_vec->at(1));
    EXPECT_EQ(0, ft_vec->at(2));
    EXPECT_EQ(1, ft_vec->at(3));
    EXPECT_EQ(2, ft_vec->at(4));

    try {
        ft_vec->at(5);
    }
    catch (std::out_of_range &e) {
        SUCCEED();
        return ;
    }
    FAIL();
}

TEST_F(TVector_ElementAccess, front) {
    ft_vec = new ft::vector<int>;

    ft_vec->push_back(5);
    int &ref = ft_vec->front();
    ref = 999;
    EXPECT_EQ(999, (*ft_vec)[0]);
}

TEST_F(TVector_ElementAccess, back) {
    ft_vec = new ft::vector<int>;

    ft_vec->push_back(5);
    ft_vec->push_back(5);
    int &ref = ft_vec->back();
    ref = 999;
    EXPECT_EQ(5, (*ft_vec)[0]);
    EXPECT_EQ(999, (*ft_vec)[1]);
}
