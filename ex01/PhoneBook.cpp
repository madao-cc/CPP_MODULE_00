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

void	PhoneBook::add_contact(std::string contact_info[5])
{
	for (int i = 0; i < 5; i++)
	{
		if (contact_info[i].empty())
		{
			std::cout << RED << "❌ Error: All fields must be filled." << RESET << std::endl;
			return;
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