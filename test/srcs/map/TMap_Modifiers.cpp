/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TMap_Modifiers.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:02:30 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/21 09:10:39 by frthierr         ###   ########.fr       */
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

class	TMap_Constructors: public ::testing::Test {
	public:
		TMap_Constructors() {}

	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {}
};

TEST_F(TMap_Constructors, insert) {
	// VALUE_TYPE VERSION
	map<int, int> m;
	pair<int, int>	p[5];
	p[0] = ft::make_pair(-21313, 213123);
	p[1] = ft::make_pair(3, 5);
	p[2] = ft::make_pair(423, 3423);
	p[3] = ft::make_pair(4234234, -5);
	p[4] = ft::make_pair(4234234, -4);
	m.insert(p[0]);
	m.insert(p[1]);
	m.insert(p[2]);
	m.insert(p[3]);
	m.insert(p[4]);
	auto i = 0;
	for (auto it = m.begin() ; it != m.end(); it++, i++) {
		EXPECT_EQ(it->first, p[i].first);
		EXPECT_EQ(it->second, p[i].second);
	}

	// HINT VERSION
	map<int, int> m2;
	auto pa = make_pair(2, 4);
	auto it2 = m2.insert(pa).first;
	EXPECT_TRUE(it2->first == 2 && it2->second == 4);
	it2 = m2.insert(it2, make_pair(2, 434));
	EXPECT_TRUE(it2->first == 2 && it2->second == 4);

	// RANGE VERSION
	map<int, int> m3;
	m3.insert(m.begin(), m.end());
	auto it = m.begin();
	EXPECT_EQ(m.size(), m3.size());
	for (auto it3 = m3.begin(); it3 != m3.end(); it3++, it++) {
		EXPECT_EQ(*it, *it3);
	}
}