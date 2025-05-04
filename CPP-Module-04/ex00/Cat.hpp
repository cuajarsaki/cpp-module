/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:30:52 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 17:30:52 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
public:
   
    Cat();
    Cat(const Cat& other);
    virtual ~Cat();
    
    Cat& operator=(const Cat& other);
    
    virtual void makeSound() const;
};

#endif