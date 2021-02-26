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
#include <gtest/gtest.h>

class	VectorTests: public ::testing::Test {
	public:
		VectorTests() {}
	protected:
			ft::vector<std::string>		ft_vec;
			std::vector<std::string>	std_vec;
			int i = 0;
			int j = 0;
		virtual void	SetUp() {

		}

		virtual void	TearDown() {
			ft_vec.clear();
			std_vec.clear();
		}
};

TEST_F(VectorTests, VTEST_SIZE) {
	ft_vec.push_back("hello world");
	std_vec.push_back("hello world");
	EXPECT_EQ(ft_vec.size(), std_vec.size());
}

TEST_F(VectorTests, VTEST_TRUE) {
	EXPECT_TRUE(true);
}
