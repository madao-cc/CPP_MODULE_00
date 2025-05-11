/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:08:59 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/10 16:09:00 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <iostream>
# include <cctype>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"
# define CLEAR   "\033[2J\033[H"

class PhoneBook
{
private:
	Contact	contacts[8];
	int	size;
	int	index;
public:
	PhoneBook();
	~PhoneBook();
	int	add_contact(std::string contact_info[5]);
	void	display_phonebook();
	void	truncate_output(std::string str);
	int	get_current_size() const;
	void	display_contact(int index);
	// Member functions
	bool	has_valid_phone_number(const std::string &number);
	bool	is_only_whitespace(const std::string &str);
};

void	clear_screen();

#endif