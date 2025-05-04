/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:14:55 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 17:22:23 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        m_templates[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        m_templates[i] = NULL;
    *this = src;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (m_templates[i])
            delete m_templates[i];
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src)
{
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &src)
    {
         // 現在のテンプレートを削除
        for (int i = 0; i < 4; i++)
        {
            if (m_templates[i])
                delete m_templates[i];
            m_templates[i] = NULL;
        }
        
        // テンプレートをディープコピー
        for (int i = 0; i < 4; i++)
        {
            if (src.m_templates[i])
                m_templates[i] = src.m_templates[i]->clone();
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
        
    for (int i = 0; i < 4; i++)
    {
        if (!m_templates[i])
        {
            m_templates[i] = m;
            std::cout << "MateriaSource learned " << m->getType() << std::endl;
            return;
        }
    }
    std::cout << "MateriaSource can't learn more materias!" << std::endl;
    delete m; 
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (m_templates[i] && m_templates[i]->getType() == type)
        {
            std::cout << "MateriaSource created " << type << std::endl;
            return (m_templates[i]->clone());
        }
    }
    std::cout << "MateriaSource doesn't know " << type << std::endl;
    return (NULL);
}