/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:17:15 by pchung            #+#    #+#             */
/*   Updated: 2025/04/19 17:45:27 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
    std::cout << "Zombie " << this->name << " is created" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << this->name << " is destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}