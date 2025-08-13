#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string const & name, Weapon & weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack() const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
