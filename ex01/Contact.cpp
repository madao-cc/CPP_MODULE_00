#include "Contact.hpp"

void	Contact::set_firstname(std::string firstname)
{
	this->firstname = firstname;
}

void		Contact::set_lastname(std::string lastname)
{
	this->lastname = lastname;
}

void		Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void		Contact::set_darkestsecret(std::string secret)
{
	this->darkest_secret = secret;
}

void		Contact::set_phonenumber(std::string number)
{
	this->phonenumber = number;
}

std::string	Contact::get_firstname() const
{
	return (this->firstname);
}

std::string	Contact::get_lastname() const
{
	return (this->lastname);
}

std::string	Contact::get_nickname() const
{
	return (this->nickname);
}

std::string	Contact::get_phonenumber() const
{
	return (this->phonenumber);
}

std::string	Contact::get_darkestsecret() const
{
	return (this->darkest_secret);
}
