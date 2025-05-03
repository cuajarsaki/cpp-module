/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:02:45 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 21:09:21 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// Fixed型のオブジェクトを作るときに、_rawBits というメンバ変数を 0 で初期化
Fixed::Fixed() : m_rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &src) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->m_rawBits = src.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->m_rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->m_rawBits = raw;
}