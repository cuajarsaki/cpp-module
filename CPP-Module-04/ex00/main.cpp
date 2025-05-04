/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:32:43 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 17:32:43 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    std::cout << "=== 基本的な動物のテスト ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); // 猫の鳴き声
    j->makeSound(); // 犬の鳴き声
    meta->makeSound(); // 動物の鳴き
    
    // メモリリーク防止のために削除
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n=== 間違った動物のテスト ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    
    wrongCat->makeSound(); // WrongAnimalの鳴き声が出力される（多態性が機能していない）
    wrongMeta->makeSound();
    
    // メモリリーク防止のために削除
    delete wrongMeta;
    delete wrongCat;
    
    std::cout << "\n=== 追加テスト：直接WrongCatインスタンスを使用 ===" << std::endl;
    WrongCat directWrongCat;
    directWrongCat.makeSound(); // WrongCatの鳴き声が出力される
    
    return 0;
}