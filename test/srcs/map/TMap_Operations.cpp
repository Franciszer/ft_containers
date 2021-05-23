/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TMap_Operations.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:03:36 by francisco         #+#    #+#             */
/*   Updated: 2021/05/23 13:04:09 by frthierr         ###   ########.fr       */
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

class	TMap_Operations: public ::testing::Test {
	public:
		TMap_Operations() {}

	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {}
};

TEST_F(TMap_Operations, find) {
	map<std::string, float> m;

	float f = 0.004F;
	m.insert(make_pair("hello", 23.12313));
	m.insert(make_pair("faasfsa", 234223.12313));
	m.insert(make_pair("fdsdfs", f));
	m.insert(make_pair("fasfsafs", 2543.16852313));
	m.insert(make_pair("fsafsaf", 2853.18652313));

	auto it = m.find("fdsdfs");
	EXPECT_EQ(it->first, "fdsdfs");
	EXPECT_EQ(it->second, f);
	it = m.find("does not exist");
	EXPECT_EQ(it, m.end());
}

TEST_F(TMap_Operations, count) {
	map<int, int>	m;

	m.insert(make_pair(1,43));
	m.insert(make_pair(2,43));
	EXPECT_EQ(m.count(2), 1);
	// EXPECT_EQ(m.count(3), 0);
}

TEST_F(TMap_Operations, lower_bound) {
	map<int, int> m;
	
	m.insert(make_pair(1,123));
	m.insert(make_pair(2,3));
	m.insert(make_pair(3,13123));
	m.insert(make_pair(4,21));
	m.insert(make_pair(5,544));
	m.insert(make_pair(6,3244324));
	m.insert(make_pair(8,12345));
	map<int, int>::iterator it = m.lower_bound(3);
	EXPECT_EQ(it->second, 13123);
	map<int, int>::const_iterator it2 = m.lower_bound(7);
	EXPECT_EQ(it2->second, 12345);
}

TEST_F(TMap_Operations, upper_bound) {
	map<int, int> m;
	
	m.insert(make_pair(1,123));
	m.insert(make_pair(2,3));
	m.insert(make_pair(3,13123));
	m.insert(make_pair(4,432325));
	m.insert(make_pair(5,123123));
	m.insert(make_pair(6,32432));
	m.insert(make_pair(8,12345));
	map<int, int>::iterator it = m.upper_bound(3);
	EXPECT_EQ(it->second, 432325);
	map<int, int>::const_iterator it2 = m.upper_bound(7);
	EXPECT_EQ(it2->second, 12345);
}

TEST_F(TMap_Operations, equal_range) {
	map<int, int> m;
	
	m.insert(make_pair(1,123));
	m.insert(make_pair(2,3));
	m.insert(make_pair(3,13123));
	m.insert(make_pair(4,432325));
	m.insert(make_pair(5,123123));
	m.insert(make_pair(6,32432));
	m.insert(make_pair(8,12345));

	auto p = m.equal_range(7);
	EXPECT_EQ(p.first->second, 12345);
	EXPECT_EQ(p.second->second, 12345);

	p = m.equal_range(4);
	EXPECT_EQ(p.first->second, 432325);
	EXPECT_EQ(p.second->second, 123123);
	p = m.equal_range(8);
	EXPECT_EQ(p.second, m.end());
}