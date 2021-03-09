/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TVector_Capacity.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:15:44 by frthierr          #+#    #+#             */
/*   Updated: 2021/03/09 12:11:25 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>

// CAPACITY TESTS
class	TVector_Capacity: public ::testing::Test {
	public:
		TVector_Capacity() {}

		ft::vector<int>		*ft_vec = nullptr;
		std::vector<int>	*std_vec = nullptr;
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

TEST_F(TVector_Capacity, size) {
	ft_vec = new ft::vector<int>;

	EXPECT_EQ(0, ft_vec->size());
	for (int i = 0; i < 200; i++)
		ft_vec->push_back(0);
	EXPECT_EQ(200, ft_vec->size());
	for (int i = 0; i < 200; i++)
		ft_vec->pop_back();
	EXPECT_EQ(0, ft_vec->size());
}

// TEST_F(TVector_Capacity, maxsize) {
// 	ft_vec = new ft::vector<int>;
// 	std_vec = new std::vector<int>;

// 	EXPECT_EQ(std_vec->max_size(), ft_vec->max_size());
// }

TEST_F(TVector_Capacity, capacity) {
	ft_vec = new ft::vector<int>(10);

	EXPECT_EQ(10, ft_vec->capacity());
	
	ft::vector<std::string>	v;

	EXPECT_EQ(0, v.capacity());
}

TEST_F(TVector_Capacity, resize) {
	ft_vec = new ft::vector<int>;

	ft_vec->resize(10, 1);
	
	EXPECT_EQ(10, ft_vec->size());
	ft_vec->resize(7);
	EXPECT_EQ(7, ft_vec->size());
	ft_vec->clear();
	ft_vec->push_back(3);
	ft_vec->push_back(7);

	ft_vec->resize(20);
	ft::vector<int>::size_type	i = 0;
	EXPECT_EQ((*ft_vec)[i++], 3);
	EXPECT_EQ((*ft_vec)[i++], 7);
	for (; i < 20; i++)
		EXPECT_EQ((*ft_vec)[i], 0);
	EXPECT_EQ(20, ft_vec->size());
}

TEST_F(TVector_Capacity, empty) {
	ft_vec = new ft::vector<int>;
	
	EXPECT_TRUE(ft_vec->empty());
	ft_vec->push_back(1);
	EXPECT_FALSE(ft_vec->empty());
}

TEST_F(TVector_Capacity, reserve) {
	ft_vec = new ft::vector<int>;

	ft_vec->reserve(10);
	
	EXPECT_EQ(10, ft_vec->capacity());
	ft_vec->reserve(7);
	EXPECT_EQ(10, ft_vec->capacity());
	ft_vec->clear();
	ft_vec->push_back(3);
	ft_vec->push_back(7);

	ft::vector<int>::size_type	size = ft_vec->size();
	ft_vec->reserve(20);
	EXPECT_EQ(size, ft_vec->size());
	ft::vector<int>::size_type	i = 0;
	EXPECT_EQ((*ft_vec)[i++], 3);
	EXPECT_EQ((*ft_vec)[i], 7);
	EXPECT_EQ(20, ft_vec->capacity());
}