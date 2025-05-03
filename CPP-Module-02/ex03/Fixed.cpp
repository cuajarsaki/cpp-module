/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:03:07 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 16:03:14 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// デフォルトコンストラクタ
Fixed::Fixed() : _rawBits(0) {
    // std::cout << "Default constructor called" << std::endl;
}

// 整数コンストラクタ
Fixed::Fixed(const int value) {
    // std::cout << "Int constructor called" << std::endl;
    this->_rawBits = value << this->_fractionalBits;
}

// 浮動小数点コンストラクタ
Fixed::Fixed(const float value) {
    // std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(value * (1 << this->_fractionalBits));
}

// コピーコンストラクタ
Fixed::Fixed(const Fixed &src) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// デストラクタ
Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

// コピー代入演算子
Fixed &Fixed::operator=(const Fixed &src) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->_rawBits = src.getRawBits();
    return *this;
}

// 比較演算子
bool Fixed::operator>(const Fixed &rhs) const {
    return this->_rawBits > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const {
    return this->_rawBits < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return this->_rawBits >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return this->_rawBits <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) const {
    return this->_rawBits == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return this->_rawBits != rhs.getRawBits();
}

// 算術演算子
Fixed Fixed::operator+(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->_rawBits + rhs.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->_rawBits - rhs.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    Fixed result;
    // 生のビットを掛け合わせてから、小数部分のビット数で調整
    long temp = (long)this->_rawBits * (long)rhs.getRawBits();
    result.setRawBits(temp >> this->_fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    // ゼロで割り算をチェック
    if (rhs.getRawBits() == 0) {
        std::cerr << "エラー: ゼロ除算" << std::endl;
        return Fixed();
    }
    
    Fixed result;
    // 精度を保持するために最初に左シフトし、その後で割る
    long temp = ((long)this->_rawBits << this->_fractionalBits) / rhs.getRawBits();
    result.setRawBits(temp);
    return result;
}

// インクリメント/デクリメント演算子
Fixed &Fixed::operator++() {  // 前置インクリメント
    this->_rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {  // 後置インクリメント
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--() {  // 前置デクリメント
    this->_rawBits--;
    return *this;
}

Fixed Fixed::operator--(int) {  // 後置デクリメント
    Fixed temp(*this);
    --(*this);
    return temp;
}

// 生のビット値を取得
int Fixed::getRawBits(void) const {
    return this->_rawBits;
}

// 生のビット値を設定
void Fixed::setRawBits(int const raw) {
    this->_rawBits = raw;
}

// 浮動小数点値に変換
float Fixed::toFloat(void) const {
    return (float)this->_rawBits / (1 << this->_fractionalBits);
}

// 整数値に変換
int Fixed::toInt(void) const {
    return this->_rawBits >> this->_fractionalBits;
}

// 最小値を取得（非const版）
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

// 最小値を取得（const版）
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

// 最大値を取得（非const版）
Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

// 最大値を取得（const版）
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

// ストリーム挿入演算子
std::ostream &operator<<(std::ostream &o, const Fixed &rhs) {
    o << rhs.toFloat();
    return o;
}