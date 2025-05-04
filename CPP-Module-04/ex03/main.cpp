/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:41:01 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 18:45:46 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    // 追加テスト
    std::cout << "\n=== 以下追加test： ===\n" << std::endl;

    // 装備解除
    me->unequip(0);
    me->use(0, *bob); // 失敗するはず

    // 未知のマテリア
    tmp = src->createMateria("fire"); // NULLが返される
    if (!tmp)
        std::cout << "未知のマテリア 'fire' の生成に失敗" << std::endl;

    // Character のコピー
    Character* originalChar = new Character("original");
    tmp = src->createMateria("ice");
    originalChar->equip(tmp);

    Character* copiedChar = new Character(*originalChar);
    std::cout << "オリジナルキャラクターの名前: " << originalChar->getName() << std::endl;
    std::cout << "コピーされたキャラクターの名前: " << copiedChar->getName() << std::endl;

    originalChar->use(0, *bob);
    copiedChar->use(0, *bob);

    // 後始末
    delete bob;
    delete me;
    delete src;
    delete originalChar;
    delete copiedChar;

    return 0;
}