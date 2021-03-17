# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    setup.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francisco <francisco@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/28 10:56:29 by francisco         #+#    #+#              #
#    Updated: 2021/03/17 18:29:40 by francisco        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BUILDING THE PROJECT, BUT IT IS BETTER TO USE THE VSCODE CMAKE EXTENSION

# DEPENDENCIES: CMAKE, CTEST

cmake --version
if [ "$?" -ne "0" ]; then
    echo "Installing cmake..."
    sudo apt-get install cmake
fi

ls build > /dev/null 2>&-
if [ "$?" -ne "0" ]; then
    rm -rf build
    mkdir build
fi

cd build
cmake ..
make