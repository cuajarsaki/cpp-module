/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:52:55 by pchung            #+#    #+#             */
/*   Updated: 2025/05/02 22:52:57 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;
    
    std::cout << "Testing different complaint levels:" << std::endl;
    std::cout << "------------------------" << std::endl;
    
    std::cout << "Calling DEBUG level:" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    
    std::cout << "Calling INFO level:" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    
    std::cout << "Calling WARNING level:" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    
    std::cout << "Calling ERROR level:" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    
    std::cout << "Calling invalid level:" << std::endl;
    harl.complain("INVALID");
    std::cout << std::endl;
    
    return 0;
}