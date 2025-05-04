/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:29:41 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 17:29:41 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Animal.hpp
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
protected:
    std::string m_type;

public:
    Animal();
    Animal(const Animal& other);
    virtual ~Animal();
    
    Animal& operator=(const Animal& other);
    
    std::string getType() const;
    virtual void makeSound() const;
};

#endif