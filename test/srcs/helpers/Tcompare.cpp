/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tcompare.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 08:40:27 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/20 08:49:55 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>

class	Tcompare: public ::testing::Test {
	public:
		Tcompare() {}

	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {}
};

using ft::less;
using ft::equal_to;

TEST_F(Tcompare, less) {
	EXPECT_TRUE(less<int>{}(5, 6));
	EXPECT_FALSE(less<float>{}(234.3, 23.332221));
}

TEST_F(Tcompare, equal_to) {
	EXPECT_TRUE(equal_to<std::string>{}("hello world", "hello world"));
	EXPECT_FALSE(equal_to<int>{}(123123, 321231));
}
