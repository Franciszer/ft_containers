/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TQueue.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:37:54 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/27 16:58:55 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <gtest/gtest.h>
#include <vector>

using namespace ft;
using std::string;

class	TQueue: public ::testing::Test {
	public:
		TQueue() {}

	protected:
		virtual void	SetUp() {}

		virtual void	TearDown() {}
};

TEST_F(TQueue, construct_def) {
	queue<int> q;
}

TEST_F(TQueue, construct_copy) {
	ft::list<std::string>	src(10, "hello");
	queue<std::string>			q(src);

	for (auto it = src.begin(); it != src.end(); it++) {
		auto val = q.front();
		q.pop();
		EXPECT_EQ(val, *it);
	}
}

TEST_F(TQueue, size) {
	list<int>	l(10, 21312);
	queue<int>	q(l);

	EXPECT_EQ(q.size(), l.size());
}

TEST_F(TQueue, front) {
	queue<int>	q;

	q.push(1);
	q.push(2);
	q.push(3);

	EXPECT_EQ(q.front(), 1);
}

TEST_F(TQueue, back) {
	queue<int>	q;

	q.push(1);
	q.push(2);
	q.push(3);

	EXPECT_EQ(q.back(), 3);
}

TEST_F(TQueue, push) {
	queue<int>	q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(23);
	EXPECT_EQ(q.back(), 23);
}

TEST_F(TQueue, pop) {
	queue<int>	q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(23);
	q.pop();
	EXPECT_EQ(q.front(), 2);
}
