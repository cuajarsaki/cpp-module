/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:41:59 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 18:41:59 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat default constructor called" << std::endl;
    m_type = "Cat";
    m_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    m_brain = new Brain(*other.m_brain); // Deep copy
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete m_brain;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete m_brain;
        m_brain = new Brain(*other.m_brain); // Deep copy
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow meow!" << std::endl;
}

Brain* Cat::getBrain() const {
    return m_brain;
}

void Cat::setIdea(int index, const std::string& idea) {
    m_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return m_brain->getIdea(index);
}