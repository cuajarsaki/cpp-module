/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:38:34 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 17:38:34 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
private:
    Brain* m_brain;

public:
    Cat();
    Cat(const Cat& other);
    virtual ~Cat();
    
    Cat& operator=(const Cat& other);
    
    virtual void makeSound() const;
    
    Brain* getBrain() const;
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif