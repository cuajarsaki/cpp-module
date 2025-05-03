/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:39:53 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 17:35:35 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : m_name(name), m_weapon(weapon) {
}

HumanA::~HumanA() {
}

void HumanA::attack() const {
    std::cout << this->m_name << " attacks with their " << this->m_weapon.getType() << std::endl;
}