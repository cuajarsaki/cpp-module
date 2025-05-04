/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:14:37 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 17:14:38 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(Cure const &src);
    virtual ~Cure();
    Cure &operator=(Cure const &src);

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif