/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:40:16 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 17:35:57 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : m_name(name), m_weapon(NULL) {
}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon& weapon) {
    this->m_weapon = &weapon;
}

void HumanB::attack() const {
    if (this->m_weapon)
        std::cout << this->m_name << " attacks with their " << this->m_weapon->getType() << std::endl;
    else
        std::cout << this->m_name << " has no weapon to attack with" << std::endl;
}