/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:25:52 by pchung            #+#    #+#             */
/*   Updated: 2025/05/03 17:38:12 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl {
private:
    void m_debug(void);
    void m_info(void);
    void m_warning(void);
    void m_error(void);

public:
    Harl();
    ~Harl();
    
    void complain(std::string level);
};

#endif