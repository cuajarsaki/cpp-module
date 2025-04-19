/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:37:53 by pchung            #+#    #+#             */
/*   Updated: 2025/04/19 17:18:18 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

void Contact::setFirstName(const std::string &firstName) {
    this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName) {
    this->lastName = lastName;
}

void Contact::setNickname(const std::string &nickname) {
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
    this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const {
    return this->firstName;
}

std::string Contact::getLastName() const {
    return this->lastName;
}

std::string Contact::getNickname() const {
    return this->nickname;
}

std::string Contact::getPhoneNumber() const {
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return this->darkestSecret;
}