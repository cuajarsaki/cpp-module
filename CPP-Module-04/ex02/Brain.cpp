/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:41:20 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 18:41:20 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        m_ideas[i] = "Empty idea";
    }
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        m_ideas[i] = other.m_ideas[i];
    }
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            m_ideas[i] = other.m_ideas[i];
        }
    }
    return *this;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return m_ideas[index];
    return "Invalid index";
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        m_ideas[index] = idea;
}