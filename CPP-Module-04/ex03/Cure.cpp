/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:14:35 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 17:14:36 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure()
: AMateria("cure")
{
    std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(Cure const &src)
: AMateria(src)
{
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &src)
{
    std::cout << "Cure assignment operator called" << std::endl;
    if (this != &src)
    {
        AMateria::operator=(src);
    }
    return (*this);
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}