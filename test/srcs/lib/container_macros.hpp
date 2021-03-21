/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container_macros.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:23:36 by francisco         #+#    #+#             */
/*   Updated: 2021/03/21 17:28:05 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_LIB_HPP

# define TEST_LIB_HPP

# include "ft_containers.hpp"

namespace containers_test {
        # define CONSTRUCT_FT_CONTAINER(ft_name, container_type, value_type, args...) \
            ft::container_type<value_type>  ft_name(args);

        # define CONSTRUCT_STD_CONTAINER(std_name, container_type, value_type, args...) \
            std::container_type<value_type>  std_name(args);

        # define CONSTRUCT_FT_LIST(ft_name, value_type, args...) \
            CONSTRUCT_FT_CONTAINER(ft_name, list, value_type, args);

        # define CONSTRUCT_STD_LIST(std_name, value_type, args...) \
            CONSTRUCT_STD_CONTAINER(std_name, list, value_type, args);

        # define CONSTRUCT_FT_VECTOR(std_name, value_type, args...) \
            CONSTRUCT_STD_CONTAINER(std_name, vector, value_type, args);

        # define CONSTRUCT_STD_VECTOR(std_name, value_type, args...) \
            CONSTRUCT_STD_CONTAINER(std_name, vector, value_type, args);
        
        # define COMP_CONTAINERS(ft_container, std_container)\
            EXPECT_EQ(ft_container.size(), std_container.size());\
            containers_test::equalsRange(ft_container, std_container.begin(), std_container.end());

        # define APPLY_BOTH(ft_container, std_container, func, args...) \
            ft_container.func(args);\
            std_container.func(args);

        template<class Container, class InputIterator>
		void		equalsRange(Container &cont, InputIterator first, InputIterator last) {
			typename Container::const_iterator it = cont.begin();
			for (; it != cont.end() && first != last; it++, first++) {
					EXPECT_EQ(*first, *it);
			}
            EXPECT_EQ(first, last);
            EXPECT_EQ(it, cont.end());
		}


}

#endif
