/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:39:05 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 17:39:05 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "=== 基本的な動物の作成とテスト ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();

    // std::cout << "\n=== 以下追加テスト ===" << std::endl;

    // // 犬を作成し、いくつかのアイデアを設定
    // Dog* originalDog = new Dog();
    // originalDog->setIdea(0, "ボールを追いかけたい");
    // originalDog->setIdea(1, "骨を食べたい");

    // // 犬のコピーを作成
    // Dog* copyDog = new Dog(*originalDog);

    // // 両方の犬が同じアイデアを持っていることを確認
    // std::cout << "オリジナルの犬のアイデア 0: " << originalDog->getIdea(0) << std::endl;
    // std::cout << "コピーされた犬のアイデア 0: " << copyDog->getIdea(0) << std::endl;

    // // オリジナルの犬のアイデアを変更
    // originalDog->setIdea(0, "猫を追いかけたい");

    // // 犬たちが異なるアイデアを持つようになったことを確認 (コピーの確認)
    // std::cout << "オリジナルの犬のアイデア 0 (変更後): " << originalDog->getIdea(0) << std::endl;
    // std::cout << "コピーされた犬のアイデア 0 (変更されないはず): " << copyDog->getIdea(0) << std::endl;

    // // 後始末
    // delete originalDog;
    // delete copyDog;
    // delete j;
    // delete i;

    // std::cout << "\n=== 動物の配列の作成と削除 ===" << std::endl;

    // // 動物の配列を作成
    // const int numAnimals = 10;
    // Animal* animals[numAnimals];

    // // 半分を犬、半分を猫で埋める
    // for (int i = 0; i < numAnimals; i++) {
    //     if (i < numAnimals / 2)
    //         animals[i] = new Dog();
    //     else
    //         animals[i] = new Cat();
    // }

    // // すべての動物を削除
    // for (int i = 0; i < numAnimals; i++) {
    //     std::cout << "動物 " << i << " (" << animals[i]->getType() << ") を削除" << std::endl;
    //     delete animals[i];
    // }

    // std::cout << "\n=== 代入演算子のテスト ===" << std::endl;
    // Dog dog1;
    // dog1.setIdea(0, "私は犬 1 のオリジナルのアイデア");

    // Dog dog2;
    // dog2 = dog1; // 代入 (構築ではない)

    // std::cout << "犬 1 のアイデア: " << dog1.getIdea(0) << std::endl;
    // std::cout << "犬 2 のアイデア: " << dog2.getIdea(0) << std::endl;

    // // 犬 1 のアイデアを変更
    // dog1.setIdea(0, "私は犬 1 の新しいアイデア");

    // // 犬 2 のアイデアが変更されていないことを確認 (深いコピー)
    // std::cout << "犬 1 のアイデア (変更後): " << dog1.getIdea(0) << std::endl;
    // std::cout << "犬 1 の変更後の犬 2 のアイデア (変更されないはず): " << dog2.getIdea(0) << std::endl;

    return 0;
}