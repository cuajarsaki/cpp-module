/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:03:53 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 16:10:50 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point();
    Point(const float x, const float y);
    Point(const Point &src);
    ~Point();

    // コピー代入演算子
    Point &operator=(const Point &src);

    // ゲッター関数
    Fixed getX() const;
    Fixed getY() const;
};

// BSP関数の宣言
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif