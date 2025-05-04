/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:37:45 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 17:37:45 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* m_brain;

public:
    Dog();
    Dog(const Dog& other);
    virtual ~Dog();
    
    Dog& operator=(const Dog& other);
    
    virtual void makeSound() const;
    
    Brain* getBrain() const;
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif