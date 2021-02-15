/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:50:11 by frthierr          #+#    #+#             */
/*   Updated: 2021/02/15 13:59:56 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	IS_INTEGRAL_HPP

# define IS_INTEGRAL_HPP

namespace	ft {

template <class T>
struct	is_integral{static const bool value = false;};

template<>
struct	is_integral<bool>{static const bool value = true;};

template<>
struct	is_integral<char>{static const bool value = true;};

template<>
struct	is_integral<short>{static const bool value = true;};

template<>
struct	is_integral<int>{static const bool value = true;};

template<>
struct	is_integral<long>{static const bool value = true;};

template<>
struct	is_integral<long long>{static const bool value = true;};

template<>
struct	is_integral<unsigned char>{static const bool value = true;};

template<>
struct	is_integral<unsigned short>{static const bool value = true;};

template<>
struct	is_integral<unsigned int>{static const bool value = true;};

template<>
struct	is_integral<unsigned long>{static const bool value = true;};

template<>
struct	is_integral<unsigned long long>{static const bool value = true;};

}

#endif