#include <iostream>

class Contact
{
	public:
		int	index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

		Contact();
		Contact(
				const std::string&	firstName,
				const std::string&	lastName,
				const std::string&	nickname,
				const std::string&	phoneNumber,
				const std::string&	darkestSecret
				);
		~Contact();
};
