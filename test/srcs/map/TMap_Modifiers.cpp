/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TMap_Modifiers.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:02:30 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/20 18:31:54 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>
#include <map>
#include <vector>

using std::vector;
using ft::pair;
using ft::map;

class	TMap_Constructors: public ::testing::Test {
	public:
		TMap_Constructors() {}

	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {}
};

TEST_F(TMap_Constructors, insert) {
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
}