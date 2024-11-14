/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:57:14 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/11/14 19:45:35 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	contactCount = 0;
	nextIndex = 0;
}

Phonebook::~Phonebook()
{
}

std::string	formatOutput(const std::string &text, unsigned int width)
{
    if (text.length() > width)
    {
        return text.substr(0, width - 1) + ".";
    }
    else
    {
        return std::string(width - text.length(), ' ') + text;
    }
}

void	Phonebook::searchContact()
{
	if (contactCount == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
	}
	else
	{
		std::cout << "     index|first name| last name|  nickname" << std::endl;
		for (int i = 0; i < contactCount; i++)
		{
			std::cout << std::setw(10) << i + 1 << "|";
			std::cout << formatOutput(contacts[i].getFirstName(), 10) << "|";
			std::cout << formatOutput(contacts[i].getLastName(), 10) << "|";
			std::cout << formatOutput(contacts[i].getNickname(), 10) << std::endl;
		}
		printContact();
	}
}

void	Phonebook::printContact()
{
    int index;

    while (true)
    {
        std::cout << "Enter index: ";
        std::cin >> index;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid index." << std::endl;
        }
        else if (index > 0 && index <= contactCount)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "First name: " << contacts[index - 1].getFirstName() << std::endl;
            std::cout << "Last name: " << contacts[index - 1].getLastName() << std::endl;
            std::cout << "Nickname: " << contacts[index - 1].getNickname() << std::endl;
            std::cout << "Phone number: " << contacts[index - 1].getPhoneNumber() << std::endl;
            std::cout << "Darkest secret: " << contacts[index - 1].getDarkestSecret() << std::endl;
            break;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid index. Please enter a valid index." << std::endl;
        }
    }
}

void Phonebook::addContact()
{
	Contact		newContact;
    std::string	input;

	while (true)
	{
        try
        {
            std::cout << "Enter first name: ";
            std::getline(std::cin, input);
            newContact.setFirstName(input);
            break;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    while (true)
    {
        try
        {
            std::cout << "Enter last name: ";
            std::getline(std::cin, input);
            newContact.setLastName(input);
            break;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    while (true)
    {
        try
        {
            std::cout << "Enter nickname: ";
            std::getline(std::cin, input);
            newContact.setNickname(input);
            break;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    while (true)
    {
        try
        {
            std::cout << "Enter phone number: ";
            std::getline(std::cin, input);
            newContact.setPhoneNumber(input);
            break;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    while (true)
    {
        try
        {
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, input);
            newContact.setDarkestSecret(input);
            break;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    contacts[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8;
    if (contactCount < 8)
    {
        contactCount++;
    }
}
