cmake_minimum_required(VERSION 3.10)

set(This ft_containers_gtest)
set(CMAKE_CXX_STANDARD 17)

set(VECTOR_DIR srcs/vector)

set(Sources
	${VECTOR_DIR}/TVector_Constructor.cpp
	${VECTOR_DIR}/TVector_Iterator.cpp
	${VECTOR_DIR}/TVector_Capacity.cpp
	${VECTOR_DIR}/TVector_Operator.cpp
	${VECTOR_DIR}/TVector_Modifiers.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
	gtest_main
	ft_containers)

add_test(
	NAME ${This}
	COMMAND ${This}
)
