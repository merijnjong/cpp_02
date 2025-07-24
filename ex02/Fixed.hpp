/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:53:31 by mjong             #+#    #+#             */
/*   Updated: 2025/07/24 13:22:24 by mjong            ###   ########.fr       */
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

		bool	operator<(const Fixed &fixed) const;
		bool	operator>(const Fixed &fixed) const;
		bool	operator<=(const Fixed &fixed) const;
		bool	operator>=(const Fixed &fixed) const;
		bool	operator==(const Fixed &fixed) const;
		bool	operator!=(const Fixed &fixed) const;
		
		Fixed	operator+(const Fixed &fixed) const;
		Fixed	operator-(const Fixed &fixed) const;
		Fixed	operator*(const Fixed &fixed) const;
		Fixed	operator/(const Fixed &fixed) const;
		
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
		
		static const Fixed &min(Fixed &fixed1, Fixed &fixed2);
		static const Fixed &max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
		static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);

		
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

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
