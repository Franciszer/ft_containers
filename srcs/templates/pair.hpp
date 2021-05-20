/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 07:45:44 by frthierr          #+#    #+#             */
/*   Updated: 2021/05/20 18:23:01 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP

# define PAIR_HPP

# include "ft_containers.hpp"

namespace ft {
	

template<class T1, class T2>
class pair {
	public:
		typedef T1 first_type;
		typedef T2 second_type;

		first_type	first;
		second_type	second;
		
		pair() {}
		pair(const first_type& x, const second_type& y): first(x), second(y) {}
		
		template<class U1, class U2>
		pair(const pair<U1, U2>& p): first(p.first), second(p.second) {}
		~pair() {}

		pair   &operator=(pair const &src) {
			if (this != &src) {
				first = src.first;
				second = src.second;
			}
			return *this;
		}

	private:
		
};

template<class T1, class T2>
pair<T1, T2> make_pair(T1 t, T2 u) {
	return pair<T1, T2>(t, u);
}

template<class T1, class T2>
bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
	return lhs.first == rhs.first && lhs.second == rhs.second;
}

template<class T1, class T2>
bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
	return !(lhs == rhs);
}

template<class T1, class T2>
bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
	return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second);
}

template<class T1, class T2>
bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
	return lhs < rhs || lhs == rhs;
}

template<class T1, class T2>
bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
	return rhs < lhs;
}

template<class T1, class T2>
bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
	return rhs < lhs || lhs == rhs;
}


}
#endif
