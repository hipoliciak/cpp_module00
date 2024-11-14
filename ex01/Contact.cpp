/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:07:24 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/11/14 19:44:20 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setFirstName(const std::string &firstName)
{
    if (firstName.empty())
    {
        throw std::invalid_argument("First name cannot be empty");
    }
    this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
    if (lastName.empty())
    {
        throw std::invalid_argument("Last name cannot be empty");
    }
    this->lastName = lastName;
}

void Contact::setNickname(const std::string &nickname)
{
    if (nickname.empty())
    {
        throw std::invalid_argument("Nickname cannot be empty");
    }
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
    for (size_t i = 0; i < phoneNumber.length(); ++i)
    {
        if (!std::isdigit(phoneNumber[i]))
        {
            throw std::invalid_argument("Phone number must contain only digits");
        }
    }
	if (phoneNumber.empty())
	{
		throw std::invalid_argument("Phone number cannot be empty");
	}
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
    if (darkestSecret.empty())
    {
        throw std::invalid_argument("Darkest secret cannot be empty");
    }
    this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }
