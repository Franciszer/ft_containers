cmake_minimum_required(VERSION 3.10)

set(This ft_containers)
set(CMAKE_CXX_STANDARD 98)
set(POSITION_INDEPENDENT_CODE ON)

project(${This} CXX)
enable_testing()

add_subdirectory(googletest)

include_directories(srcs
					srcs/iterators/
					srcs/templates/
					srcs/containers/
					.)

set(Headers
	srcs/ft_containers.hpp
	srcs/iterators/vector_iterator.hpp
	srcs/iterators/reverse_iterator.hpp
	srcs/templates/constBool.hpp
	srcs/templates/enable_if.hpp
	srcs/templates/is_integral.hpp
	srcs/containers/vector.hpp
)

set(Sources
	main.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

target_compile_options(${This} PRIVATE -Wall -Wextra -Werror -fsanitize=address)

add_subdirectory(test)