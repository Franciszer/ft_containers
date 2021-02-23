cmake_minimum_required(VERSION 3.17)

set(This ft_containers_gtest)

set(Sources
	ExampleTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
	gtest_main
	ft_containers)

add_test(
	NAME ${This}
	COMMAND ${This}
)
