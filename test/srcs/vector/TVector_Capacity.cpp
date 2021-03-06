/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TVector_Capacity.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:15:44 by frthierr          #+#    #+#             */
/*   Updated: 2021/03/06 16:34:25 by frthierr         ###   ########.fr       */
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

TEST_F(TVector_Capacity, TVector_Capacity_size) {
	ft_vec = new ft::vector<int>;

	EXPECT_EQ(0, ft_vec->size());
	for (int i = 0; i < 200; i++)
		ft_vec->push_back(0);
	EXPECT_EQ(200, ft_vec->size());
	for (int i = 0; i < 200; i++)
		ft_vec->pop_back();
	EXPECT_EQ(0, ft_vec->size());
}

TEST_F(TVector_Capacity, TVector_Capacity_maxsize) {
	ft_vec = new ft::vector<int>;
	std_vec = new std::vector<int>;

	EXPECT_EQ(std_vec->max_size(), ft_vec->max_size());
}

TEST_F(TVector_Capacity, TVector_Capacity_capacity) {
	ft_vec = new ft::vector<int>(10);

	EXPECT_EQ(10, ft_vec->capacity());
	
	ft::vector<std::string>	v;

	EXPECT_EQ(0, v.capacity());
}
