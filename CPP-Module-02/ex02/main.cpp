/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 02:19:36 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 22:05:08 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    // std::cout << "\n以下追加のテスト:" << std::endl;

    // // 算術演算子
    // Fixed c(42.42f);
    // Fixed d(10);
    
    // std::cout << "c = " << c << std::endl;
    // std::cout << "d = " << d << std::endl;
    // std::cout << "c + d = " << c + d << std::endl;
    // std::cout << "c - d = " << c - d << std::endl;
    // std::cout << "c * d = " << c * d << std::endl;
    // std::cout << "c / d = " << c / d << std::endl;

    // std::cout << "\n比較演算子:" << std::endl;
    // std::cout << "c > d: " << (c > d) << std::endl;
    // std::cout << "c < d: " << (c < d) << std::endl;
    // std::cout << "c >= d: " << (c >= d) << std::endl;
    // std::cout << "c <= d: " << (c <= d) << std::endl;
    // std::cout << "c == d: " << (c == d) << std::endl;
    // std::cout << "c != d: " << (c != d) << std::endl;

    // std::cout << "\n最小値/最大値:" << std::endl;
    // std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
    // std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;

    // std::cout << "\nインクリメント/デクリメント:" << std::endl;
    // Fixed e(1);
    // std::cout << "e = " << e << std::endl;
    // std::cout << "--e = " << --e << std::endl;
    // std::cout << "++e = " << ++e << std::endl;
    // std::cout << "e = " << e << std::endl;
    // std::cout << "e-- = " << e-- << std::endl;
    // std::cout << "e++ = " << e++ << std::endl;
    // std::cout << "e = " << e << std::endl;

    return 0;
}