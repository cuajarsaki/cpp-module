// main.cpp
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Creating and testing animals ===" << std::endl;
    
    // 以下の行はコンパイルエラーになる（抽象クラスのインスタンス化はできない）
    // const Animal* meta = new Animal();
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound();
    j->makeSound();
    
    // 直接Animal型の変数も作れない
    // Animal a;
    
//     std::cout << "\n=== コピtest ===" << std::endl;
    
//      // 犬を作成し、いくつかのアイデアを設定
//     Dog* originalDog = new Dog();
//     originalDog->setIdea(0, "I want to chase a ball");
//     originalDog->setIdea(1, "I want to eat a bone");
    
//     // 犬のコピーを作成
//     Dog* copyDog = new Dog(*originalDog);
    
//    // 両方の犬が同じアイデアを持っていることを確認
//     std::cout << "Original dog idea 0: " << originalDog->getIdea(0) << std::endl;
//     std::cout << "Copy dog idea 0: " << copyDog->getIdea(0) << std::endl;
    
//     // オリジナルの犬のアイデアを変更
//     originalDog->setIdea(0, "I want to chase a cat");
    
//      // 犬たちが異なるアイデアを持つようになったことを確認 (コピーの確認)
//     std::cout << "Original dog idea 0 (after modification): " << originalDog->getIdea(0) << std::endl;
//     std::cout << "Copy dog idea 0 (should not change): " << copyDog->getIdea(0) << std::endl;
    
//     delete originalDog;
//     delete copyDog;
//     delete j;
//     delete i;
    
//     std::cout << "\n=== 動物の配列の作成と削除 ===" << std::endl;
    
//     // 動物の配列を作成
//     const int numAnimals = 10;
//     Animal* animals[numAnimals];
    
//    // 半分を犬、半分を猫で埋める
//     for (int idx = 0; idx < numAnimals; idx++) {
//         if (idx < numAnimals / 2)
//             animals[idx] = new Dog();
//         else
//             animals[idx] = new Cat();
//     }
    
//     // すべての動物を削除
//     for (int idx = 0; idx < numAnimals; idx++) {
//         std::cout << "Deleting animal " << idx << " (" << animals[idx]->getType() << ")" << std::endl;
//         delete animals[idx];
//     }
    
    return 0;
}