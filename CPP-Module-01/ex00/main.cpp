/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:17:08 by pchung            #+#    #+#             */
/*   Updated: 2025/04/19 17:45:05 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    
    std::cout << "Creating a zombie on the stack:" << std::endl;
    randomChump("Stack Zombie");
    
    
    std::cout << "\nCreating a zombie on the heap:" << std::endl;
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    
    std::cout << "\nCleaning up the heap-allocated zombie:" << std::endl;
    delete heapZombie;
    
    return 0;
}