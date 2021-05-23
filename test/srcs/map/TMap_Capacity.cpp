/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TMap_Capacity.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:01:40 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/23 14:06:17 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>
#include <map>
#include <vector>

using std::vector;
using ft::pair;
using ft::map;
using ft::make_pair;
using std::string;

class	TMap_Capacity: public ::testing::Test {
	public:
		TMap_Capacity() {}

	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {}
};

TEST_F(TMap_Capacity, size) {
	map<int,int>	m;

	m.insert(make_pair(1,2));
	m.insert(make_pair(6,2));
	m.insert(make_pair(1,2));
	EXPECT_EQ(m.size(), 2);
}

TEST_F(TMap_Capacity, empty) {
	map<int,int>	m;

	EXPECT_TRUE(m.empty());
	m.insert(make_pair(1,2));
	EXPECT_FALSE(m.empty());
}

TEST_F(TMap_Capacity, max_size) {
	map<string, string>	m;
	std::allocator<ft::bst<pair<string, string>>>	alloc;

	EXPECT_EQ(m.max_size(), alloc.max_size());
}