/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TStack.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:01:16 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/27 17:08:15 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>

using namespace ft;
using std::string;

class	TStack: public ::testing::Test {
	public:
		TStack() {}

	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {}
};

TEST_F(TStack, construct_def) {
	stack<int> q;
}

TEST_F(TStack, construct_copy) {
	ft::list<std::string>	src(10, "hello");
	stack<std::string>			q(src);

	for (auto it = src.begin(); it != src.end(); it++) {
		auto val = q.top();
		q.pop();
		EXPECT_EQ(val, *it);
	}
}

TEST_F(TStack, size) {
	list<int>	l(10, 21312);
	stack<int>	q(l);

	EXPECT_EQ(q.size(), l.size());
}

TEST_F(TStack, top) {
	stack<int>	q;

	q.push(1);
	q.push(2);
	q.push(3);

	EXPECT_EQ(q.top(), 3);
}

TEST_F(TStack, push) {
	stack<int>	q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(23);
	EXPECT_EQ(q.top(), 23);
}

TEST_F(TStack, pop) {
	stack<int>	q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(23);
	q.pop();
	EXPECT_EQ(q.top(), 3);
}
