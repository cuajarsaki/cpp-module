/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 03:12:10 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 21:09:30 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : m_rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->m_rawBits = value << this->m_fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->m_rawBits = roundf(value * (1 << this->m_fractionalBits));
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->m_rawBits = src.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    return this->m_rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->m_rawBits = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->m_rawBits / (1 << this->m_fractionalBits);
}

int Fixed::toInt(void) const {
    return this->m_rawBits >> this->m_fractionalBits;
}

std::ostream &operator<<(std::ostream &o, const Fixed &rhs) {
    o << rhs.toFloat();
    return o;
}