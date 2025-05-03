/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:39:21 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 17:37:31 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
private:
    std::string m_type;

public:
    Weapon(std::string type);
    ~Weapon();
    
    const std::string& getType() const;
    void setType(std::string newType);
};

#endif