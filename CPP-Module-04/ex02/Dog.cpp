/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:41:42 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 18:41:42 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog default constructor called" << std::endl;
    m_type = "Dog";
    m_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    m_brain = new Brain(*other.m_brain); // Deep copy
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete m_brain;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete m_brain;
        m_brain = new Brain(*other.m_brain); // Deep copy
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return m_brain;
}

void Dog::setIdea(int index, const std::string& idea) {
    m_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return m_brain->getIdea(index);
}