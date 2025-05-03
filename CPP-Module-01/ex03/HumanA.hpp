/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:40:02 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 17:35:35 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA {
private:
    std::string m_name;
    Weapon& m_weapon;

public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();
    
    void attack() const;
};

#endif