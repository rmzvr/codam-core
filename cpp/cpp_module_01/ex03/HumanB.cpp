#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string const & name) : _name(name), _weapon(nullptr) {}

HumanB::~HumanB() {}

void	HumanB::attack() const
{
	if (_weapon != nullptr)
	{
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	}
	else
	{
		std::cout << this->_name << " has no weapon to fight!" << std::endl;
	}
}

void	HumanB::setWeapon(Weapon & weapon)
{
	_weapon = &weapon;
}
