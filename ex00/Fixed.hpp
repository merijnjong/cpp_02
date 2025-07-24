/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:32:43 by mjong             #+#    #+#             */
/*   Updated: 2025/07/23 14:00:39 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cctype>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

class Fixed
{
	public:
		int		getRawBits() const;
		void	setRawBits(int const raw);

		Fixed	&operator=(const Fixed &fixed);
		
		Fixed(const Fixed &fixed);
		
		Fixed();
		~Fixed();

	private:
		int					_rawBits;
		static const int	_fractBits;
};

#endif
