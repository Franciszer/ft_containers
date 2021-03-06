# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    setup.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/28 10:56:29 by francisco         #+#    #+#              #
#    Updated: 2021/03/06 15:00:20 by frthierr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BUILDING THE PROJECT, BUT IT IS BETTER TO USE THE VSCODE CMAKE EXTENSION

# DEPENDENCIES: CMAKE, CTEST

mkdir build
cd build
cmake ..
make