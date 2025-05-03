/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:39:16 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 17:37:31 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : m_type(type) {
}

Weapon::~Weapon() {
}

const std::string& Weapon::getType() const {
    return this->m_type;
}

void Weapon::setType(std::string newType) {
    this->m_type = newType;
}