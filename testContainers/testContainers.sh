# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    testContainers.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 15:43:15 by frthierr          #+#    #+#              #
#    Updated: 2021/02/16 17:19:21 by frthierr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CONTAINERS_LOC="./containers/"
CONTAINERS_SUFFIX="Test.cpp"
NAMESPACE="ft"

# vector list map stack queue
CONTAINERS="vector"

vector_BASICS="constructor operator="
vector_ITERATORS="begin end rbegin rend"
vector_CAPACITY="size max_size resize capacity empty reserve"
vector_ELEMENT_ACCESS="operator[] at front back"
vector_MODIFIERS="assign push_back pop_back insert erase swap clear"
vector_NON_MEMBER_OVERLOADS="operator== operator!= operator< operator> operator<= operator>= swap"

list_BASICS="constructor operator="
list_ITERATORS="begin end rbegin rend"
list_CAPACITY="empty size max_size"
list_ELEMENT_ACCESS="front back"
list_MODIFIERS="assign push_front pop_front push_back pop_back insert erase swap resize clear"
list_OPERATIONS="splice remove remove_if unique merge sort reverse"
list_NON_MEMBER_OVERLOADS="operator== operator!= operator< operator> operator<= operator>= swap"

map_BASICS="constructor operator="
map_ITERATORS="begin end rbegin rend"
map_CAPACITY="empty size max_size"
map_ELEMENT_ACCESS="operator[]"
map_MODIFIERS="insert erase swap clear"
map_OBERVERS="key_comp value_comp"
map_OPERATIONS="find count lower_bound upper_bound equal_range"

stack_BASICS="constructor empty size top push pop"
stack_NON_MEMBER_OVERLOADS="operator== operator!= operator< operator> operator<= operator>= swap"

stack_BASICS="constructor empty size front back push pop"
stack_NON_MEMBER_OVERLOADS="operator== operator!= operator< operator> operator<= operator>= swap"

# COLORS
GREEN="\033[0;32m"
LIGHT_BLUE="\033[0;34m"
RED="\033[0;31m"
YELLOW="\033[0;33m"
NC="\033[0m"

# $1: container_name
function run_container_tests() {
	[ -z "$vector_BASICS" ] && echo BASIC
}

for CONTAINER in $CONTAINERS
do
	echo $CONTAINER
	run_container_tests $CONTAINER
done