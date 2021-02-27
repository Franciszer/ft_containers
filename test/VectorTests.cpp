/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:51:12 by frthierr          #+#    #+#             */
/*   Updated: 2021/02/26 14:51:18 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <stdarg.h>
#include <gtest/gtest.h>

// CONSTRUCTOR TESTS
class	TVector_Constructor: public ::testing::Test {
	public:
		TVector_Constructor() {}

		std::vector<int>	*std_vec = nullptr;
		ft::vector<int>		*ft_vec = nullptr;
		void		compare() {
			_size = std_vec->size();
			EXPECT_EQ(_size, ft_vec->size());
			for (size_t i = 0; i < _size; i++)
				EXPECT_EQ((*std_vec)[i], (*ft_vec)[i]);
			this->TearDown();
		}
	protected:
		std::vector<int>::size_type	_size;
		virtual void	SetUp() {

		}

		virtual void	TearDown() {
			if (std_vec != nullptr) {
				delete std_vec;
				std_vec = nullptr;
			}
			if (ft_vec != nullptr) {
				delete ft_vec;
				ft_vec = nullptr;
			}
		}
};

TEST_F(TVector_Constructor, TVector_Constructor_default) {
	std_vec = new std::vector<int>;
	ft_vec = new ft::vector<int>;
	this->compare();
}

TEST_F(TVector_Constructor, TVector_Constructor_fill) {
	

	std_vec = new std::vector<int>(10);
	ft_vec = new ft::vector<int>(10);

	this->compare();
	try {
		ft_vec = new ft::vector<int>(1'000'000'000'000'000'000);
	}
	catch (std::bad_alloc &e) {
		return ;
	}
	FAIL();
}

TEST_F(TVector_Constructor, TVector_Constructor_range) {
	ft::vector<int>	src;

	src.push_back(10);
	src.push_back(2);
	src.push_back(-3123131);
	src.push_back(124);
	src.push_back(-124);
	src.push_back(12312324);
	
	ft_vec = new ft::vector<int>(src.begin(), src.end());
	for (ft::vector<int>::size_type i = 0; i < src.size(); i++) {
		EXPECT_EQ(src[i], (*ft_vec)[i]);
	}
	this->TearDown();

	ft::vector<int>::iterator it = src.end();
	ft::vector<int>::size_type	offset = 0;
	for (size_t i = 0; i < 3; i++, offset++)
		--it;
	ft_vec = new ft::vector<int>(src.begin(), it);
	for (ft::vector<int>::size_type i = 0; i < src.size() - offset; i++) {
		EXPECT_EQ(src[i], (*ft_vec)[i]);
	}
}