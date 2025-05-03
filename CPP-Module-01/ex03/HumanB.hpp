/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:40:07 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 17:35:57 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB {
private:
    std::string m_name;
    Weapon* m_weapon; 
    
public:
    HumanB(std::string name);
    ~HumanB();
    
    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif