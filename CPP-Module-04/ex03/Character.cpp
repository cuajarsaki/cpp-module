/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:14:20 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 17:24:43 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character()
: m_name("unnamed")
{
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        m_inventory[i] = NULL;
}

Character::Character(std::string const &name)
: m_name(name)
{
    std::cout << "Character name constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        m_inventory[i] = NULL;
}

Character::Character(Character const &src)
{
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        m_inventory[i] = NULL;
    *this = src;
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (m_inventory[i])
            delete m_inventory[i];
    }
}

Character &Character::operator=(Character const &src)
{
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &src)
    {
        this->m_name = src.m_name;
        
        // Delete current inventory
        for (int i = 0; i < 4; i++)
        {
            if (m_inventory[i])
                delete m_inventory[i];
            m_inventory[i] = NULL;
        }
        
        // Deep copy inventory
        for (int i = 0; i < 4; i++)
        {
            if (src.m_inventory[i])
                m_inventory[i] = src.m_inventory[i]->clone();
        }
    }
    return (*this);
}

std::string const & Character::getName() const
{
    return (this->m_name);
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
        
    for (int i = 0; i < 4; i++)
    {
        if (!m_inventory[i])
        {
            m_inventory[i] = m;
            std::cout << m_name << " equipped with " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    std::cout << m_name << " can't equip more materias!" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && m_inventory[idx])
    {
        std::cout << m_name << " unequipped " << m_inventory[idx]->getType() << " from slot " << idx << std::endl;
        m_inventory[idx] = NULL;
    }
    else
        std::cout << "Nothing to unequip from slot " << idx << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && m_inventory[idx])
    {
        m_inventory[idx]->use(target);
    }
    else
        std::cout << "Nothing to use in slot " << idx << std::endl;
}