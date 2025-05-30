/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:02:52 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 21:09:30 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
private:
    int m_rawBits;
    static const int m_fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed &src);
    Fixed &operator=(const Fixed &src);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif