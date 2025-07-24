/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:17:33 by mjong             #+#    #+#             */
/*   Updated: 2025/07/23 13:48:58 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::getRawBits() const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(this->_rawBits) / (1 << this->_fractBits));
}

int Fixed::toInt() const
{
	return (this->_rawBits >> this->_fractBits);
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		_rawBits = (fixed.getRawBits());
	return (*this);
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int iNum)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = iNum << this->_fractBits;
}

Fixed::Fixed(const float fNum)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = static_cast<int>(std::roundf(fNum * (1 << this->_fractBits)));
}

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

const int	Fixed::_fractBits = 8;
