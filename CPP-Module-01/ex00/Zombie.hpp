/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:17:17 by pchung            #+#    #+#             */
/*   Updated: 2025/04/19 17:45:18 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string name);
    ~Zombie();
    
    void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif