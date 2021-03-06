/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:12:33 by frthierr          #+#    #+#             */
/*   Updated: 2021/02/16 12:36:57 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

#ifndef	ENABLE_IF_HPP

# define ENABLE_IF_HPP

namespace	ft {
	
template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };
}

#endif