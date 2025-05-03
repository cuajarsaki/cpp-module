/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:10:14 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 16:10:16 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
    // 三角形の頂点を作成
    Point a(0, 0);
    Point b(10, 30);
    Point c(20, 0);

    // 三角形の内部にある点
    Point inside(10, 15);
    
    // 三角形の外部にある点
    Point outside(30, 15);
    
    // 三角形の辺上にある点
    Point onEdge(10, 0);
    
    // 三角形の頂点にある点
    Point onVertex(0, 0);

    // 各点が三角形の内部にあるかどうかをテスト
    std::cout << "点(10, 15)は三角形の内部にありますか？ " 
              << (bsp(a, b, c, inside) ? "はい" : "いいえ") << std::endl;
    
    std::cout << "点(30, 15)は三角形の内部にありますか？ " 
              << (bsp(a, b, c, outside) ? "はい" : "いいえ") << std::endl;
    
    std::cout << "点(10, 0)は三角形の内部にありますか？ " 
              << (bsp(a, b, c, onEdge) ? "はい" : "いいえ") << std::endl;
    
    std::cout << "点(0, 0)は三角形の内部にありますか？ " 
              << (bsp(a, b, c, onVertex) ? "はい" : "いいえ") << std::endl;

    // 別の三角形でテスト
    Point d(1.5f, 1.5f);
    Point e(6.2f, 3.1f);
    Point f(3.6f, 7.4f);
    
    Point p1(3.5f, 3.5f);  // 内部
    Point p2(2.0f, 5.0f);  // 外部
    
    std::cout << "\n別の三角形でのテスト:" << std::endl;
    std::cout << "点(3.5, 3.5)は三角形の内部にありますか？ " 
              << (bsp(d, e, f, p1) ? "はい" : "いいえ") << std::endl;
    
    std::cout << "点(2.0, 5.0)は三角形の内部にありますか？ " 
              << (bsp(d, e, f, p2) ? "はい" : "いいえ") << std::endl;

    return 0;
}