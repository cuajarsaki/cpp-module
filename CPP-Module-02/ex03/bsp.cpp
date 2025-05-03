/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:07:14 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 16:07:16 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// 三角形の面積を計算する補助関数
static Fixed calculateArea(Point const &a, Point const &b, Point const &c) {
    // 三角形の面積の公式: |Ax(By - Cy) + Bx(Cy - Ay) + Cx(Ay - By)| / 2
    Fixed area = ((a.getX() * (b.getY() - c.getY())) + 
                  (b.getX() * (c.getY() - a.getY())) + 
                  (c.getX() * (a.getY() - b.getY()))) / Fixed(2);
    
    // 絶対値を取得（面積は正の値）
    if (area < Fixed(0))
        area = area * Fixed(-1);
    
    return area;
}

// BSP (Binary Space Partitioning) 関数
// 点が三角形の内部にあるかどうかをチェック
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // 三角形の全体面積を計算
    Fixed totalArea = calculateArea(a, b, c);
    
    // 点と三角形の各頂点を使用して3つの小さな三角形を作成
    Fixed area1 = calculateArea(point, a, b);
    Fixed area2 = calculateArea(point, b, c);
    Fixed area3 = calculateArea(point, c, a);
    
    // 点が三角形の辺上や頂点にある場合は除外
    if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
        return false;
    
    // 3つの小さな三角形の面積の合計が元の三角形の面積と等しいかどうかをチェック
    // 等しい場合、点は三角形の内部にある
    return (totalArea == area1 + area2 + area3);
}