/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TVector_Operator.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:13:36 by francisco         #+#    #+#             */
/*   Updated: 2021/05/27 14:41:41 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>

// OPERATOR TESTS
class	TVector_Operator: public ::testing::Test {
	public:
		TVector_Operator() {}

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

TEST_F(TVector_Operator, operator_square_brackets) {
    ft_vec = new ft::vector<int>();

    ft::vector<int> *vec2 = new ft::vector<int>;
    vec2->push_back(54);
    vec2->push_back(-213);
    vec2->push_back(23123);
    vec2->push_back(-888);
    vec2->push_back(777);
    ft_vec->push_back(54);
    ft_vec->push_back(-213);
    ft_vec->push_back(23123);
    ft_vec->push_back(-888);
    ft_vec->push_back(777);

    for (ft::vector<int>::size_type i = 0; i < vec2->size(); i++) {
        EXPECT_EQ((*vec2)[i], (*ft_vec)[i]);
    }
	delete vec2;
    SUCCEED();
}

TEST_F(TVector_Operator, at) {
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

TEST_F(TVector_Operator, front) {
    ft_vec = new ft::vector<int>;

    ft_vec->push_back(5);
    int &ref = ft_vec->front();
    ref = 999;
    EXPECT_EQ(999, (*ft_vec)[0]);
}

TEST_F(TVector_Operator, back) {
    ft_vec = new ft::vector<int>;

    ft_vec->push_back(5);
    ft_vec->push_back(5);
    int &ref = ft_vec->back();
    ref = 999;
    EXPECT_EQ(5, (*ft_vec)[0]);
    EXPECT_EQ(999, (*ft_vec)[1]);
}
