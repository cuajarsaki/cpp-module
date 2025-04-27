/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:37:33 by pchung            #+#    #+#             */
/*   Updated: 2025/04/27 20:04:17 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    // const⇒この関数は、クラスの中身（メンバ変数）を変更しませんという意味
    // 読み取り専用と明示し、間違えてデータを変えたらコンパイルエラーになる。
};

#endif