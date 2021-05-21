/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TMap_iterators.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 09:43:25 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/21 09:46:48 by frthierr         ###   ########.fr       */
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

TEST_F(TMap_Iterators, begin) {
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
