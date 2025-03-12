/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:37:33 by pchung            #+#    #+#             */
/*   Updated: 2025/03/12 13:37:35 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PhoneBook.hpp
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int count;
    int oldestIndex;
    
    std::string formatField(const std::string &field) const;

public:
    PhoneBook();
    
    void addContact(const Contact &contact);
    void searchContact() const;
    void displayAllContacts() const;
    void displayContact(int index) const;
};

#endif