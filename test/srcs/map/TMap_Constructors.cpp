/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TMap_Constructors.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:03:56 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/20 15:42:08 by frthierr         ###   ########.fr       */
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

TEST_F(TMap_Constructors, def) {
	ft::map<int, int>	m;
	EXPECT_TRUE(true);
}

// TEST_F(TMap_Constructors, range) {
// 	std::map<int, int>	v{{1, 2}, {2, 3}, {3, 4}};
// 	ft::map<int, int> m(v.begin(), v.end());
// 	// auto it2 = v.begin();
// 	// for (ft::map<int, int>::iterator it = m.begin() ; it != m.end() && it2 != v.end() ; it++, it2++)
// 	// 	EXPECT_EQ(it->first, it2->first);
// }

