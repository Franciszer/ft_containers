/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TMap_Modifiers.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:02:30 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/20 18:23:31 by frthierr         ###   ########.fr       */
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
	auto p = ft::make_pair(3, 5);
	m.insert(p);
	EXPECT_EQ(m.begin()->first, p.first);
	EXPECT_EQ(m.begin()->second, p.second);
}