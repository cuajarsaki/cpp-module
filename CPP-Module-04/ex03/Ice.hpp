/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:14:42 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 17:14:43 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(Ice const &src);
    virtual ~Ice();
    Ice &operator=(Ice const &src);

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif