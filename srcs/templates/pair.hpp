/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:46:54 by frthierr          #+#    #+#             */
/*   Updated: 2021/03/28 17:24:31 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {
	
	template<class T1, class T2>
	struct pair {
		typedef T1	first_type;
		typedef T2	first_type;

		T1	first;
		T2	second;

		pair()
		: first(), second() { }

		pair(const T1& a, const T2& b)
       : first(a), second(b) { }

		pair&       operator=(pair&& p) { 
			first = p.first;
			second = p.second;
			return *this;
		}
		
		void		swap(pair &p) {
			pair	tmp = *this;

			*this = p;
			p = tmp;
		}
	};

	template<class T1, class T2>
	bool			operator==(const pair<T1, T2> x, const pair<T1, T2> y) {
		return x.first == y.first && x.second == y.second;
	}
}