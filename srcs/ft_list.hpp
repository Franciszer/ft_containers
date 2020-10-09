/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 18:16:00 by frthierr          #+#    #+#             */
/*   Updated: 2020/10/09 18:18:12 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_HPP

# define FT_LIST_HPP

# include <iostream>
# include <iomanip>
# include <string>

class List {
	public:
		List(void);
		List(List const &src);
		virtual ~List(void);

		List   &operator=(List const &src);

	private:
		
};

#endif
