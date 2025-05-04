/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:14:06 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 17:24:22 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
: m_type("")
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
: m_type(type)
{
    std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &src)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = src;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &src)
{
    std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &src)
    {
        this->m_type = src.m_type;
    }
    return (*this);
}

std::string const & AMateria::getType() const
{
    return (this->m_type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria " << this->m_type << " used on " << target.getName() << std::endl;
}