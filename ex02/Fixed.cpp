/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:53:29 by mjong             #+#    #+#             */
/*   Updated: 2025/07/24 13:18:17 by mjong            ###   ########.fr       */
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

bool Fixed::operator<(const Fixed &fixed) const
{
	return (this->_rawBits < fixed._rawBits);
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return (this->_rawBits > fixed._rawBits);
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (this->_rawBits <= fixed._rawBits);
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (this->_rawBits >= fixed._rawBits);
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (this->_rawBits == fixed._rawBits);
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (this->_rawBits != fixed._rawBits);
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed &Fixed::operator++()
{
	this->_rawBits++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_rawBits++;
	return (temp);
}

Fixed &Fixed::operator--()
{
	this->_rawBits--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_rawBits--;
	return (temp);
}

const Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
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
