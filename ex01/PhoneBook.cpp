/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:08:54 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/10 16:08:55 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->size = 0;
	this->index = 0;
	std::cout << "PhoneBook created" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destroyed" << std::endl;
}

int	PhoneBook::add_contact(std::string contact_info[5])
{
	for (int i = 0; i < 5; i++)
	{
		if (contact_info[i].empty())
		{
			std::cout << RED << "❌ Error: All fields must be filled." << RESET << std::endl;
			return (1);
		}
	}
	if (!has_valid_phone_number(contact_info[3]))
	{
		std::cout << RED << "❌ Error: Invalid phone number format." << RESET << std::endl;
		return (1);
	}
	for (int i = 0; i < 5; i++)
	{
		if (is_only_whitespace(contact_info[i]))
		{
			std::cout << RED << "❌ Error: Fields cannot be just whitespaces." << RESET << std::endl;
			return (1);
		}
	}
	int index = this->index;
	this->contacts[index].set_firstname(contact_info[0]);
	this->contacts[index].set_lastname(contact_info[1]);
	this->contacts[index].set_nickname(contact_info[2]);
	this->contacts[index].set_phonenumber(contact_info[3]);
	this->contacts[index].set_darkestsecret(contact_info[4]);
	this->index = (index + 1) % 8;
	if (this->size < 8)
		this->size++;
	return (0);
}

bool	PhoneBook::has_valid_phone_number(const std::string &number)
{
	if (number.length() != 9)
		return false;
	for(size_t i = 0; i < number.length(); i++)
	{
		if (!isdigit(number[i]))
			return false;
	}
	if (number[0] != '9')
		return false;
	if (number[1] != '1' && number[1] != '2' && number[1] != '3' && number[1] != '6' && number[1] != '9')
		return false;
	return true;
}

bool	PhoneBook::is_only_whitespace(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isspace(str[i]))
			return false;
	}
	return true;
}

void	PhoneBook::display_phonebook()
{
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|  " << BLUE << "Index" << RESET << "   |" <<BLUE << "First Name" << RESET <<"|" << BLUE << "Last Name" << RESET << " |" << BLUE << " Nickname " << RESET << "|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < this->size; i++)
	{
		std::cout << "|    " << i << "     |";
		truncate_output(this->contacts[i].get_firstname());
		std::cout << "|";
		truncate_output(this->contacts[i].get_lastname());
		std::cout << "|";
		truncate_output(this->contacts[i].get_nickname());
		std::cout << "|" << std::endl;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

void	PhoneBook::truncate_output(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::string((10 - str.length()) / 2, ' ') << str << std::string(10 - ((10 - str.length()) / 2 + str.length()), ' ');
}

int	PhoneBook::get_current_size() const
{
	return (this->size);
}

void	PhoneBook::display_contact(int index)
{
	std::cout << std::endl << "Contact Information" << std::endl;
	std::cout << "First Name: " << this->contacts[index].get_firstname() << std::endl;
	std::cout << "Last Name: " << this->contacts[index].get_lastname() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].get_nickname() << std::endl;
	std::cout << "Phone Number: " << this->contacts[index].get_phonenumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[index].get_darkestsecret() << std::endl;
}

void	clear_screen()
{
	std::cout << CLEAR;
}