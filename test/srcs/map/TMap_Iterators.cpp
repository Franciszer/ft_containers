/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TMap_Iterators.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 09:43:25 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/21 18:31:37 by francisco        ###   ########.fr       */
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

class	TMap_Iterators: public ::testing::Test {
	public:
		TMap_Iterators() {}

	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {}
};

TEST_F(TMap_Iterators, iterators) {
	map<int, int> m;
	auto p = make_pair(-12321, 213321);
	m.insert(make_pair(2,3));
	m.insert(make_pair(1,123213));
	m.insert(make_pair(412412,312412412));
	m.insert(make_pair(412412,4124));
	m.insert(p);
	m.insert(make_pair(41421,214142));
	m.insert(make_pair(1424,41144));
	m.insert(make_pair(414124124,2141));
	EXPECT_TRUE(m.begin()->first == p.first && m.begin()->second == p.second);
} 

TEST_F(TMap_Iterators, reverse_iterators) {
	map<int, int>	m;
	pair<int, int>	p[5];
	p[0] = make_pair(1,2);
	p[1] = make_pair(2,3);
	p[2] = make_pair(3,4);
	p[3] = make_pair(4,5);
	p[4] = make_pair(5,6);
	for (int i = 0; i < 5 ; i++)
		m.insert(p[i]);
	int i = 4;
	for (auto it = m.rbegin(); it != m.rend(); it++, i--) {
		EXPECT_TRUE(it->first == p[i].first && it->second == p[i].second);
	}
}