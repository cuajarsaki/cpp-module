/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:26:17 by pchung            #+#    #+#             */
/*   Updated: 2025/05/02 23:44:46 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./harlFilter <level>" << std::endl;
        return 1;
    }
    
    Harl harl;
    harl.complain(argv[1]);
    
    return 0;
}

// ./harlFilter "WARNING"
// ./harlFilter "DEBUG"
// ./harlFilter "存在してない警告"
