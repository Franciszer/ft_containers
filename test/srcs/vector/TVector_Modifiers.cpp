/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TVector_Modifiers.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:54:18 by francisco         #+#    #+#             */
/*   Updated: 2021/03/10 01:39:35 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>

// MODIFIER TESTS
class	TVector_Modifiers: public ::testing::Test {
	public:
		TVector_Modifiers() {}

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

TEST_F(TVector_Modifiers, assign) {
    ft_vec = new ft::vector<int>;

    ft_vec->push_back(1);
    ft_vec->push_back(23);
    ft_vec->push_back(-123);
    ft_vec->push_back(3455);
    ft_vec->push_back(-1231);

    ft::vector<int> ft_vec2(*ft_vec);

    ft_vec2.assign(2, 10);
    EXPECT_EQ(2, ft_vec2.size());

    ft_vec2.assign(ft_vec->begin(), ft_vec->end());
    EXPECT_EQ(ft_vec->size(), ft_vec2.size());
    for (ft::vector<int>::size_type i = 0; i < ft_vec->size(); i++) {
        EXPECT_EQ((*ft_vec)[i], ft_vec2[i]);
    }
}

TEST_F(TVector_Modifiers, push_back) {
    ft_vec = new ft::vector<int>;

    EXPECT_EQ(0, ft_vec->capacity());
    ft_vec->push_back(5);
    EXPECT_EQ(1, ft_vec->capacity());
    EXPECT_EQ(1, ft_vec->size());
}

TEST_F(TVector_Modifiers, pop_back) {
    ft_vec = new ft::vector<int>;

    ft_vec->push_back(2);
    ft_vec->push_back(2);
    ft_vec->push_back(2);
    ft_vec->push_back(2);

    ft::vector<int>::size_type  size = ft_vec->size();
    ft_vec->pop_back();
    EXPECT_EQ(size, ft_vec->size() + 1);
}

TEST_F(TVector_Modifiers, insert) {
    ft_vec = new ft::vector<int>;

    ft_vec->insert(ft_vec->begin(), 2);
    EXPECT_EQ(2, (*ft_vec)[0]);
    for (int i = 0; i < 10; i++)
        ft_vec->insert(ft_vec->end(), 2);
    for (int i = 0; i < ft_vec->size(); i++)
        EXPECT_EQ(2, (*ft_vec)[i]);
    EXPECT_EQ(11, ft_vec->size());
    ft_vec->insert(ft_vec->begin(), 10, 4);
    EXPECT_EQ(21, ft_vec->size());
    for (int i = 0; i < ft_vec->size(); i++) {
        if (i < 10)
            EXPECT_EQ(4, (*ft_vec)[i]);
        else
            EXPECT_EQ(2, (*ft_vec)[i]);
    }
    ft::vector<int> v;
    v.push_back(8);
    v.insert(v.begin(), ft_vec->begin(), ft_vec->end());
    EXPECT_EQ(8, v[ft_vec->size()]);
    EXPECT_EQ(ft_vec->size() + 1, v.size());
    for (int i = 0; i < ft_vec->size(); i++) {
        EXPECT_EQ((*ft_vec)[i], v[i]);
    }
}

TEST_F(TVector_Modifiers, erase) {
    ft_vec = new ft::vector<int>;

    ft_vec->push_back(5);
    ft_vec->push_back(15);
    ft_vec->erase(ft_vec->begin());
    EXPECT_EQ(1, ft_vec->size());
    EXPECT_EQ(15, (*ft_vec)[0]);

    ft_vec->clear();
    ft_vec->push_back(5);
    ft_vec->push_back(5);
    ft_vec->push_back(5);
    ft_vec->push_back(5);
    ft_vec->push_back(5);
    ft_vec->push_back(15);

    ft::vector<int>::iterator it = ft_vec->end();
    it--;
    ft_vec->erase(ft_vec->begin(), it);
    ASSERT_EQ(1, ft_vec->size());
    EXPECT_EQ(15, (*ft_vec)[0]);
}

TEST_F(TVector_Modifiers, swap) {
    ft_vec = new ft::vector<int>;

    ft_vec->push_back(8);
    ft_vec->push_back(8213123);
    ft_vec->push_back(-1231238);
    ft_vec->push_back(0);
    ft_vec->push_back(INT32_MAX);
    ft_vec->push_back(INT32_MIN);
    ft_vec->push_back(8);
    
    ft::vector<int> copy(*ft_vec);
    ft::vector<int> v;

    v.swap(*ft_vec);
    EXPECT_EQ(copy.size(), v.size());
    for (ft::vector<int>::size_type i = 0; i < copy.size(); i++) {
        EXPECT_EQ(copy[i], v[i]);
    }
}