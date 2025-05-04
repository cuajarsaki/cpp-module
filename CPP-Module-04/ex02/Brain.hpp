/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:40:58 by pchung            #+#    #+#             */
/*   Updated: 2025/05/04 18:40:58 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
private:
    std::string m_ideas[100];

public:
    Brain();
    Brain(const Brain& other);
    ~Brain();
    
    Brain& operator=(const Brain& other);
    
    std::string getIdea(int index) const;
    void setIdea(int index, const std::string& idea);
};

#endif