/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 03:11:10 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 03:11:59 by pchung           ###   ########.fr       */
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
    // 整数
    Fixed(const int value);
    // 浮動小数点
    Fixed(const float value);
    // コピー
    Fixed(const Fixed &src);
    ~Fixed();

    // コピー代入演算子
    Fixed &operator=(const Fixed &src);

    // メンバ関数
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

// ストリーム挿入演算子
std::ostream &operator<<(std::ostream &o, const Fixed &rhs);

#endif