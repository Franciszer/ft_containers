/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TMap_Constructors.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:03:56 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/21 09:18:01 by frthierr         ###   ########.fr       */
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

class	TMap_Constructors: public ::testing::Test {
	public:
		TMap_Constructors() {}

	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {}
};

TEST_F(TMap_Constructors, def) {
	ft::map<int, int>	m;
	EXPECT_TRUE(true);
}

TEST_F(TMap_Constructors, range) {
	vector<pair<int, int>>	v{{1, 2}, {2, 3}, {3, 4}};
	ft::map<int, int> m(v.begin(), v.end());
	auto it2 = v.begin();
	for (ft::map<int, int>::iterator it = m.begin() ; it != m.end() && it2 != v.end() ; it++, it2++)
		EXPECT_EQ(it->first, it2->first);
}

TEST_F(TMap_Constructors, copy) {
	map<string, int>	m;
	m.insert(make_pair("hello", 344));
	m.insert(make_pair("dfewf", 432));
	m.insert(make_pair("123123", 4324));
	m.insert(make_pair("r2332r34", 423));
	m.insert(make_pair("d332d23d", 23423565));
	m.insert(make_pair("34234324233", 75475465635345));
	map<string, int>	m2(m);
	auto it = m.begin();
	auto it2 = m2.begin();
	EXPECT_EQ(m.size(), m2.size());
	for (; it != m.end() && it2 != m2.end(); it++, it2++) {
		EXPECT_EQ(*it, *it2);
	}
}

TEST_F(TMap_Constructors, operator_eq) {
	map<double, float>	m;

	m.insert(make_pair(0.12312, 2211211.124121243));
	m.insert(make_pair(3123.321, 12346.213));
	m.insert(make_pair(1234.345, -2131.2454));
	m.insert(make_pair(-2112.23, -132.43124));
	m.insert(make_pair(124125.1231, 313.345345));
	auto m2 = m;
	EXPECT_EQ(m.size(), m2.size());
	auto it2 = m2.begin();
	for (auto it = m.begin() ; it != m.end(); it++, it2++)
		EXPECT_EQ(*it, *it2);
}