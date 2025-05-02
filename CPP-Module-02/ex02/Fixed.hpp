/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 02:19:54 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 03:03:56 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _rawBits;
    static const int _fractionalBits = 8;

public:

    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &src);
    ~Fixed();

    // 代入演算子
    Fixed &operator=(const Fixed &src);

    // 比較演算子
    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;

    // 算術演算子
    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;

    // インクリメント/デクリメント演算子
    Fixed &operator++();    // 前置インクリメント
    Fixed operator++(int);  // 後置インクリメント
    Fixed &operator--();    // 前置デクリメント
    Fixed operator--(int);  // 後置デクリメント

    // メンバー関数
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    // 静的メンバー関数
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

// ストリーム挿入演算子
std::ostream &operator<<(std::ostream &o, const Fixed &rhs);

#endif