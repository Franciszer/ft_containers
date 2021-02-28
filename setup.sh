# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    setup.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francisco <francisco@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/28 10:56:29 by francisco         #+#    #+#              #
#    Updated: 2021/02/28 10:56:54 by francisco        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

git clone https://github.com/google/googletest.git
mkdir build
cd build
cmake ..
make