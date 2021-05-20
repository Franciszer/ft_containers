/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tpair.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 08:01:30 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/20 08:17:23 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>

class	Tpair: public ::testing::Test {
	public:
		Tpair() {}

	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {}
};

using ft::pair;

TEST_F(Tpair, constructors) {
	pair<std::string, std::string>	p("hello", "world");

	EXPECT_EQ(p.first, "hello");
	EXPECT_EQ(p.second, "world");

	auto p2(p);
	EXPECT_EQ(p, p2);
}

TEST_F(Tpair, make_pair) {
	pair p(1, 2);

	pair p2 = ft::make_pair(p.first, p.second);
	EXPECT_TRUE(p2.first == 1 && p2.second == 2);
}

TEST_F(Tpair, relational_operators) {
	pair p(1, 2);
	pair p2(0,0);
	pair p3(1, 1);

	EXPECT_TRUE(p2 < p);
	EXPECT_TRUE(p3 < p);
	EXPECT_TRUE(p2 <= p);
	EXPECT_TRUE(p3 <= p);

	EXPECT_FALSE(p2 > p);
	EXPECT_FALSE(p3 > p);
	EXPECT_FALSE(p2 >= p);
	EXPECT_FALSE(p3 >= p);

	p2 = ft::make_pair(p.first, p.second);
	EXPECT_EQ(p, p2);
	EXPECT_NE(p2, pair(0, 0));
}