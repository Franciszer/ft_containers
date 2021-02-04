/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constBool.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:48:58 by frthierr          #+#    #+#             */
/*   Updated: 2021/02/04 11:55:09 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_BOOL_HPP

# define CONST_BOOL_HPP

# include "ft_containers.hpp"

namespace ft {
	template<bool isConst, typename isFalse, typename isTrue>
	struct ConstBool{};

	template<typename isFalse, typename isTrue>
	struct ConstBool<true, isFalse, isTrue>{
		typedef isTrue type;
	};

	template<typename isFalse, typename isTrue>
	struct	ConstBool<false, isFalse, isTrue> {
		typedef isFalse type;
	};
}

#endif
