/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 02:19:48 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 21:09:30 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : m_rawBits(0) {
}

Fixed::Fixed(const int value) {
    this->m_rawBits = value << this->m_fractionalBits;
}

Fixed::Fixed(const float value) {
    this->m_rawBits = roundf(value * (1 << this->m_fractionalBits));
}

Fixed::Fixed(const Fixed &src) {
    *this = src;
}

Fixed::~Fixed() {
}

Fixed &Fixed::operator=(const Fixed &src) {
    if (this != &src)
        this->m_rawBits = src.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &rhs) const {
    return this->m_rawBits > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const {
    return this->m_rawBits < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return this->m_rawBits >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return this->m_rawBits <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) const {
    return this->m_rawBits == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return this->m_rawBits != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->m_rawBits + rhs.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->m_rawBits - rhs.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    Fixed result;
    // 生のビットを掛けてから小数点以下のビットを調整
    long temp = (long)this->m_rawBits * (long)rhs.getRawBits();
    result.setRawBits(temp >> this->m_fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    // ゼロ除算のチェック
    if (rhs.getRawBits() == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed();
    }
    
    Fixed result;
    // 精度を保つためにまず左シフトし、その後除算
    long temp = ((long)this->m_rawBits << this->m_fractionalBits) / rhs.getRawBits();
    result.setRawBits(temp);
    return result;
}

Fixed &Fixed::operator++() {  // 前置インクリメント
    this->m_rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {  // 後置インクリメント
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--() {  // 前置デクリメント
    this->m_rawBits--;
    return *this;
}

Fixed Fixed::operator--(int) {  // 後置デクリメント
    Fixed temp(*this);
    --(*this);
    return temp;
}

// メンバ関数
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

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &o, const Fixed &rhs) {
    o << rhs.toFloat();
    return o;
}