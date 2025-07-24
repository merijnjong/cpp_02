/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:17:36 by mjong             #+#    #+#             */
/*   Updated: 2025/07/23 14:00:34 by mjong            ###   ########.fr       */
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
#include <cmath>

class Fixed
{
	public:
		int		getRawBits() const;
		void	setRawBits(int const raw);
		
		float	toFloat(void) const;
		int		toInt(void) const;
		
		Fixed	&operator=(const Fixed &fixed);
		
		Fixed(const Fixed &fixed);
		Fixed(const int value);
		Fixed(const float value);
		
		Fixed();
		~Fixed();

	private:
		int					_rawBits;
		static const int	_fractBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
