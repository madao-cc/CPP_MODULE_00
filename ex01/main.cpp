#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;
	std::string	contact_info[5];
	int		index;

	clear_screen();
	std::cout << YELLOW << "📖 Welcome to the PhoneBook!" << RESET << std::endl;

	while (42)
	{
		std::cout << GREEN << "📞 PhoneBook$ " << RESET;
		std::getline(std::cin, input);

		if (input == "ADD")
		{
			clear_screen();
			std::cout << YELLOW << "📝 Enter Contact Information" << RESET << std::endl;
			std::cout << YELLOW << "Enter First Name: " << RESET; std::getline(std::cin, contact_info[0]);
			std::cout << YELLOW << "Enter Last Name: " << RESET; std::getline(std::cin, contact_info[1]);
			std::cout << YELLOW << "Enter Nickname: " << RESET; std::getline(std::cin, contact_info[2]);
			std::cout << YELLOW << "Enter Phone Number: " << RESET; std::getline(std::cin, contact_info[3]);
			std::cout << YELLOW << "Enter Darkest Sectret: " << RESET; std::getline(std::cin, contact_info[4]);
			
			phonebook.add_contact(contact_info);
			std::cout << YELLOW << "✅ Contact Added Sucessfully!" << RESET << std::endl;
		}
		else if (input == "SEARCH")
		{
			clear_screen();
			phonebook.display_phonebook();
			std::cout << YELLOW << "🔎 Insert Index: " << RESET;
			std::cin >> index;

			if (std::cin.fail() || index < 0  || index >= phonebook.get_current_size())
			{
				std::cout << RED << "❌ Invalid Index" << RESET << std::endl;
				std::cin.clear();
				std::getline(std::cin, input);
				continue ;
			}

			clear_screen();
			phonebook.display_contact(index);
			std::cin.clear();
			std::getline(std::cin, input);
			continue ;
		}
		else if (input == "EXIT")
		{
			std::cout << RED << "\n⚠️  You are about to leave the PhoneBook." << RESET << std::endl;
			std::cout << "Make sure you have memorized your contacts as they will be lost forever..." << std::endl;
			std::cout << YELLOW << "👋 Goodbye!" << RESET << std::endl;
			break;
		}
		else
			std::cout << RED << "❌ Invalid Command" << RESET << std::endl;
	}
}