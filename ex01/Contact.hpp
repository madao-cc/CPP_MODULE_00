#include <string>

class Contact
{
private:
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phonenumber;
	std::string	darkest_secret;
public:
	void		set_firstname(std::string firstname);
	void		set_lastname(std::string lastname);
	void		set_nickname(std::string nickname);
	void		set_darkestsecret(std::string secret);
	void		set_phonenumber(std::string number);
	std::string	get_firstname() const;
	std::string	get_lastname() const;
	std::string	get_nickname() const;
	std::string	get_phonenumber() const;
	std::string	get_darkestsecret() const;
};