/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:30:39 by pchung            #+#    #+#             */
/*   Updated: 2025/04/19 15:57:29 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "PhoneBook.hpp"
#include <iostream>

Contact getNewContact() {
    Contact contact;
    std::string input;
    
    do {
        std::cout << "Enter first name: ";
        if (!std::getline(std::cin, input)) {
    std::cout << "\nEOF detected. Cancelling ADD." << std::endl;
    return Contact(); 
}
    } while (input.empty());
    contact.setFirstName(input);
    
    do {
        std::cout << "Enter last name: ";
        if (!std::getline(std::cin, input)) {
    std::cout << "\nEOF detected. Cancelling ADD." << std::endl;
    return Contact(); 
}
    } while (input.empty());
    contact.setLastName(input);
    
    do {
        std::cout << "Enter nickname: ";
        if (!std::getline(std::cin, input)) {
    std::cout << "\nEOF detected. Cancelling ADD." << std::endl;
    return Contact(); 
}
    } while (input.empty());
    contact.setNickname(input);
    
    do {
        std::cout << "Enter phone number: ";
        if (!std::getline(std::cin, input)) {
    std::cout << "\nEOF detected. Cancelling ADD." << std::endl;
    return Contact(); 
}
    } while (input.empty());
    contact.setPhoneNumber(input);
    
    do {
        std::cout << "Enter darkest secret: ";
        if (!std::getline(std::cin, input)) {
    std::cout << "\nEOF detected. Cancelling ADD." << std::endl;
    return Contact(); 
}
    } while (input.empty());
    contact.setDarkestSecret(input);
    
    return contact;
}

int main() {
    PhoneBook phoneBook;
    std::string command;
    
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";      
        if (!std::getline(std::cin, command)) {
        std::cout << "\nEOF detected. Exiting." << std::endl;
        break;
    }
        if (command == "EXIT") {
            break;
        } else if (command == "ADD") {
            Contact newContact = getNewContact();
            phoneBook.addContact(newContact);
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        }
    }
    
    return 0;
}