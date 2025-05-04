/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:36:53 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 17:36:53 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Animal.cpp
#include "Animal.hpp"

Animal::Animal() : m_type("") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : m_type(other.m_type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other) {
        m_type = other.m_type;
    }
    return *this;
}

std::string Animal::getType() const {
    return m_type;
}

void Animal::makeSound() const {
    std::cout << "Animal makes no specific sound" << std::endl;
}