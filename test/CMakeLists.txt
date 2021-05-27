cmake_minimum_required(VERSION 3.10)

set(This gtest_ft_containers)
set(CMAKE_CXX_STANDARD 17)

set(LIB_DIR srcs/lib)

set(VECTOR_DIR srcs/vector)
set(LIST_DIR srcs/list)
set(MAP_DIR srcs/map)
set(HELPERS_DIR srcs/helpers)

set(Sources
	# ${LIB_DIR}/container_macros.hpp

	# ${VECTOR_DIR}/TVector_Constructor.cpp
	# ${VECTOR_DIR}/TVector_Iterator.cpp
	# ${VECTOR_DIR}/TVector_Capacity.cpp
	# ${VECTOR_DIR}/TVector_Operator.cpp
	# ${VECTOR_DIR}/TVector_Modifiers.cpp
	# ${VECTOR_DIR}/TVector_NonMembers.cpp

	# ${LIST_DIR}/TList_Constructor.cpp
	# ${LIST_DIR}/TList_Iterators.cpp
	# ${LIST_DIR}/TList_Capacity.cpp
	# ${LIST_DIR}/TList_ElementAccess.cpp
	# ${LIST_DIR}/TList_Modifiers.cpp
	# ${LIST_DIR}/TList_Operators.cpp
	# ${LIST_DIR}/TList_NonMembers.cpp

	# ${HELPERS_DIR}/Tpair.cpp
	# ${HELPERS_DIR}/Tcompare.cpp

	# ${MAP_DIR}/TMap_Constructors.cpp
	# ${MAP_DIR}/TMap_Iterators.cpp
	# ${MAP_DIR}/TMap_Capacity.cpp
	# ${MAP_DIR}/TMap_ElementAccess.cpp
	${MAP_DIR}/TMap_Modifiers.cpp
	# ${MAP_DIR}/TMap_Operations.cpp
)

add_executable(${This} ${Sources})

target_include_directories(${This} PUBLIC ${LIB_DIR})

target_link_libraries(${This} PUBLIC
	gtest_main
	ft_containers)

add_test(
	NAME ${This}
	COMMAND ${This}
)
