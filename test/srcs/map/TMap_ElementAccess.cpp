/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TMap_ElementAccess.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:13:17 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/23 14:20:51 by frthierr         ###   ########.fr       */
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

class	TMap_ElementAccess: public ::testing::Test {
	public:
		TMap_ElementAccess() {}

	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {}
};

TEST_F(TMap_ElementAccess, operator_sqbrackets) {
	map<int, int>	m;

	EXPECT_EQ(m[23], 0);

	m[213]= 323;
	EXPECT_EQ(m.find(213)->second, 323);
}