/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:23:28 by pchung            #+#    #+#             */
/*   Updated: 2025/03/12 13:25:54 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    
    for (int i = 1; i < argc; i++) {
        std::string str = argv[i];
        for (size_t j = 0; j < str.length(); j++) {
            std::cout << static_cast<char>(std::toupper(str[j]));
        }
    }
    std::cout << std::endl;
    
    return 0;
}