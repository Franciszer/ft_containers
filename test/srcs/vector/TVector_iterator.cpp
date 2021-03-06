/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TVector_Iterator.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 10:34:16 by francisco         #+#    #+#             */
/*   Updated: 2021/03/06 15:15:28 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>

// ITERATOR TESTS
class	TVector_Iterator: public ::testing::Test {
	public:
		TVector_Iterator() {}

		ft::vector<int>		*ft_vec = nullptr;

	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {
			if (ft_vec != nullptr) {
				delete ft_vec;
				ft_vec = nullptr;
			}
		}
};

TEST_F(TVector_Iterator, TVector_Iterator_begin) {
	ft_vec = new ft::vector<int>;

	// checking is ft::vector::begin segaults on empty vector
	ft_vec->begin();
	
	ft_vec->push_back(5);
	ft_vec->push_back(-123);
	ft_vec->push_back(21312);
	ft_vec->push_back(213114414);
	ft_vec->push_back(-2131321);
	ft_vec->push_back(2048123128);

	EXPECT_EQ(*(ft_vec->begin()), 5);

	ft::vector<int>::const_iterator cit = ft_vec->begin();
	
	try {
		ft::vector<int>::iterator it = dynamic_cast<ft::vector<int>::iterator&>(cit);
	}
	catch (std::bad_cast &e) {
		SUCCEED();
		return ;
	}
	FAIL();
}

TEST_F(TVector_Iterator, TVector_Iterator_end) {
	ft_vec = new ft::vector<int>;
	EXPECT_EQ(ft_vec->begin(), ft_vec->end());
	
	ft_vec->push_back(5);
	ft_vec->push_back(-123);
	ft_vec->push_back(21312);
	ft_vec->push_back(213114414);
	ft_vec->push_back(-2131321);
	ft_vec->push_back(2048123128);

	EXPECT_EQ(*(--ft_vec->end()), 2048123128);
}

TEST_F(TVector_Iterator, TVector_Iterator_rbegin) {
	ft_vec = new ft::vector<int>;
	ft::vector<int>::reverse_iterator	rit = ft_vec->rbegin();

	EXPECT_EQ(rit, ft_vec->rend());
	ft_vec->push_back(5);
	ft_vec->push_back(-123);
	ft_vec->push_back(21312);
	ft_vec->push_back(213114414);
	ft_vec->push_back(-2131321);
	ft_vec->push_back(2048123128);

	ft::vector<int> ft_vec2(ft_vec->rbegin(), ft_vec->rend());
	ft::vector<int> ft_vec3(ft_vec2.rbegin(), ft_vec2.rend());

	ft::vector<int>::reverse_iterator it = ft_vec->rbegin();
	for (int i = ft_vec->size() - 1; it != ft_vec->rend() && i >= 0; i--, it++) {
		EXPECT_EQ(*it, (*ft_vec)[i]);
	}
}

TEST_F(TVector_Iterator, TVector_Iterator_rend) {
	ft_vec = new ft::vector<int>;
	ft::vector<int>::reverse_iterator rit = ft_vec->rend();

	EXPECT_EQ(ft_vec->rbegin(), rit);
	ft_vec->push_back(5);
	ft_vec->push_back(-123);
	ft_vec->push_back(21312);
	ft_vec->push_back(213114414);
	ft_vec->push_back(-2131321);
	ft_vec->push_back(2048123128);

	ft::vector<int> ft_vec2(ft_vec->rbegin(), ft_vec->rend());
	ft::vector<int> ft_vec3(ft_vec2.rbegin(), ft_vec2.rend());

	ft::vector<int>::reverse_iterator it = ft_vec->rend();
	--it;
	for (int i = 0; i < ft_vec->size(); i++, it--) {
		EXPECT_EQ(*it, (*ft_vec)[i]);
	}
}
