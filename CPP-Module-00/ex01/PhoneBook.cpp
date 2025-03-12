/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:37:17 by pchung            #+#    #+#             */
/*   Updated: 2025/03/12 13:41:32 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PhoneBook.cpp
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() : count(0), oldestIndex(0) {}

std::string PhoneBook::formatField(const std::string &field) const {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

void PhoneBook::addContact(const Contact &contact) {
    if (count < 8) {
        contacts[count] = contact;
        count++;
    } else {
        contacts[oldestIndex] = contact;
        oldestIndex = (oldestIndex + 1) % 8;
    }
}

void PhoneBook::displayAllContacts() const {
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << formatField(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << formatField(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::displayContact(int index) const {
    if (index < 0 || index >= count) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    
    std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::searchContact() const {
    if (count == 0) {
        std::cout << "Phone book is empty!" << std::endl;
        return;
    }
    
    displayAllContacts();
    
    std::string input;
    int index;
    
    std::cout << "Enter the index of the contact to display: ";
    std::cin >> input;
    
    // 入力が数字かどうかチェック
    for (size_t i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            std::cout << "Invalid index!" << std::endl;
            std::cin.ignore(10000, '\n');
            return;
        }
    }
    
    index = std::atoi(input.c_str());
    displayContact(index);
    std::cin.ignore(10000, '\n');
}
