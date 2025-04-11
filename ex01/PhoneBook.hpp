#include "Contact.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define CLEAR   "\033[2J\033[H"

class PhoneBook
{
private:
	Contact	contacts[8];
	int	size;
	int	index;
public:
	PhoneBook();
	~PhoneBook();
	void	add_contact(std::string contact_info[5]);
	void	display_phonebook();
	void	truncate_output(std::string str);
	int	get_current_size() const;
	void	display_contact(int index);
};

void	clear_screen();