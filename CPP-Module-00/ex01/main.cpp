/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:30:39 by pchung            #+#    #+#             */
/*   Updated: 2025/03/12 13:38:55 by pchung           ###   ########.fr       */
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
        std::getline(std::cin, input);
    } while (input.empty());
    contact.setFirstName(input);
    
    do {
        std::cout << "Enter last name: ";
        std::getline(std::cin, input);
    } while (input.empty());
    contact.setLastName(input);
    
    do {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, input);
    } while (input.empty());
    contact.setNickname(input);
    
    do {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, input);
    } while (input.empty());
    contact.setPhoneNumber(input);
    
    do {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, input);
    } while (input.empty());
    contact.setDarkestSecret(input);
    
    return contact;
}

int main() {
    PhoneBook phoneBook;
    std::string command;
    
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
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