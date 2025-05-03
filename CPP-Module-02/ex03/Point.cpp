/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:06:49 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 16:11:11 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

// 浮動小数点値を使用するコンストラクタ
Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point::Point(const Point &src) : _x(src._x), _y(src._y) {
}

Point::~Point() {
}

// コピー代入演算子
// 注意: x と y は const なので、この実装は実際には新しい値を設定できません
// これは単に Orthodox Canonical Form に従うために存在します
Point &Point::operator=(const Point &src) {
    // this と src が同じオブジェクトの場合、何もしない
    if (this != &src) {
        // const メンバは変更できないため、何もできません
        // 通常はここで値をコピーしますが、このクラスでは不可能です
    }
    return *this;
}

Fixed Point::getX() const {
    return this->_x;
}

Fixed Point::getY() const {
    return this->_y;
}