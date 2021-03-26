/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TList_NonMember.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 09:10:10 by frthierr          #+#    #+#             */
/*   Updated: 2021/03/26 10:10:34 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>
#include <list>
#include "container_macros.hpp"

// NON MEMBER TESTS
class	TList_NonMembers: public ::testing::Test {
	public:
		TList_NonMembers() {}

		ft::list<int>		*ft_list = nullptr;
	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {
			if (ft_list != nullptr) {
				delete ft_list;
				ft_list = nullptr;
			}
		}
};

TEST_F(TList_NonMembers, equality_operator) {
	CONSTRUCT_STD_LIST(std_1, std::string, {"HELLO", "world", "how", "is", "your", "mifa"});
	CONSTRUCT_FT_LIST(ft_1, std::string, std_1.begin(), std_1.end());
	CONSTRUCT_STD_LIST(std_1_copy, std::string, std_1.begin(), std_1.end());
	CONSTRUCT_FT_LIST(ft_1_copy, std::string, std_1.begin(), std_1.end());

	EXPECT_EQ(ft_1 == ft_1_copy, std_1 == std_1_copy);
}

TEST_F(TList_NonMembers, inequality_operator) {
	CONSTRUCT_STD_LIST(std_1, std::string, {"HELLO", "world", "how", "is", "your", "mifa"});
	CONSTRUCT_FT_LIST(ft_1, std::string, std_1.begin(), std_1.end());
	CONSTRUCT_STD_LIST(std_1_copy, std::string, std_1.begin(), std_1.end());
	CONSTRUCT_FT_LIST(ft_1_copy, std::string, std_1.begin(), std_1.end());

	EXPECT_EQ(ft_1 != ft_1_copy, std_1 != std_1_copy);
}

TEST_F(TList_NonMembers, less_operator) {
	CONSTRUCT_STD_LIST(std_1, std::string, {"HELLO", "world", "how", "is", "your", "mifa"});
	CONSTRUCT_FT_LIST(ft_1, std::string, std_1.begin(), std_1.end());
	CONSTRUCT_STD_LIST(std_1_copy, std::string, std_1.begin(), std_1.end());
	CONSTRUCT_FT_LIST(ft_1_copy, std::string, std_1.begin(), std_1.end());

	EXPECT_EQ(ft_1 < ft_1_copy, std_1 < std_1_copy);
}

TEST_F(TList_NonMembers, more_operator) {
	CONSTRUCT_STD_LIST(std_1, std::string, {"HELLO", "world", "how", "is", "your", "mifa"});
	CONSTRUCT_FT_LIST(ft_1, std::string, std_1.begin(), std_1.end());
	CONSTRUCT_STD_LIST(std_1_copy, std::string, std_1.begin(), std_1.end());
	CONSTRUCT_FT_LIST(ft_1_copy, std::string, std_1.begin(), std_1.end());

	EXPECT_EQ(ft_1 > ft_1_copy, std_1 > std_1_copy);
}

TEST_F(TList_NonMembers, less_equality_operator) {
	CONSTRUCT_STD_LIST(std_1, std::string, {"HELLO", "world", "how", "is", "your", "mifa"});
	CONSTRUCT_FT_LIST(ft_1, std::string, std_1.begin(), std_1.end());
	CONSTRUCT_STD_LIST(std_1_copy, std::string, std_1.begin(), std_1.end());
	CONSTRUCT_FT_LIST(ft_1_copy, std::string, std_1.begin(), std_1.end());

	EXPECT_EQ(ft_1 <= ft_1_copy, std_1 <= std_1_copy);
}

TEST_F(TList_NonMembers, more_equality_operator) {
	CONSTRUCT_STD_LIST(std_1, std::string, {"HELLO", "world", "how", "is", "your", "mifa"});
	CONSTRUCT_FT_LIST(ft_1, std::string, std_1.begin(), std_1.end());
	CONSTRUCT_STD_LIST(std_1_copy, std::string, std_1.begin(), std_1.end());
	CONSTRUCT_FT_LIST(ft_1_copy, std::string, std_1.begin(), std_1.end());

	EXPECT_EQ(ft_1 >= ft_1_copy, std_1 >= std_1_copy);
}

TEST_F(TList_NonMembers, swap) {
	CONSTRUCT_STD_LIST(std_1, std::string, {"HELLO", "world", "how", "is", "your", "mifa"});
	CONSTRUCT_FT_LIST(ft_1, std::string, std_1.begin(), std_1.end());
	CONSTRUCT_STD_LIST(std_1_copy, std::string, std_1.begin(), std_1.end());
	CONSTRUCT_FT_LIST(ft_1_copy, std::string, std_1.begin(), std_1.end());
	swap(ft_1, ft_1_copy);
	swap(std_1, std_1_copy);

	COMP_CONTAINERS(ft_1, std_1);
	COMP_CONTAINERS(ft_1_copy, std_1_copy);
}
