/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:31:49 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 17:31:49 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// WrongAnimal.cpp
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : m_type("") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : m_type(other.m_type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &other) {
        m_type = other.m_type;
    }
    return *this;
}

std::string WrongAnimal::getType() const {
    return m_type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes no specific sound" << std::endl;
}