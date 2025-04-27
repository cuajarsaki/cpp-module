/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:11:12 by pchung            #+#    #+#             */
/*   Updated: 2025/04/27 20:55:39 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int N = 5;
    std::string name = "Horde Zombie";
    
    Zombie* horde = zombieHorde(N, name);
    
    for (int i = 0; i < N; i++) {
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }
    
    delete[] horde; 
    
    return 0;
}