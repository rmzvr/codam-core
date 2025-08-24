#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

void section(const std::string &title) {
	std::cout << CYAN << "\n=== " << title << " ===" << RESET << "\n";
}

void wait(float sec = 0.6) {
	usleep((useconds_t)(sec * 1'000'000));
}

void showStatus(ClapTrap *traps[], int size) {
	std::cout << MAGENTA << "\n[ STATUS ]" << RESET << "\n";
	for (int i = 0; i < size; i++) {
		std::cout
				<< traps[i]->getName()
				<< " has " << traps[i]->getHitPoints()
				<< " HP\n";
	}
}

ClapTrap* getRandomTarget(ClapTrap *attacker, ClapTrap *traps[], int size) {
	ClapTrap *candidates[4];
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (traps[i] != attacker && traps[i]->getHitPoints() > 0)
			candidates[count++] = traps[i];
	}

	if (count == 0)
		return NULL;

	return candidates[rand() % count];
}

int main() {
	srand(time(0));

	DiamondTrap	d1("DiamondOne");
	ScavTrap	s1("ScavvyOne");
	FragTrap	f1("FraggyOne");
	ClapTrap	c1("ClappyOne");

	ClapTrap *traps[4] = { &d1, &s1, &f1, &c1 };
	const int size = 4;

	section("⚔️ BATTLE ROYALE STARTS ⚔️");
	showStatus(traps, size);
	wait(1.5);

	int round = 1;
	while (true) {
		std::cout << YELLOW << "\n--- ROUND " << round++ << " ---" << RESET << "\n";

		int aliveCount = 0;
		ClapTrap *lastAlive = NULL;
		for (int i = 0; i < size; i++) {
			if (traps[i]->getHitPoints() > 0) {
				aliveCount++;
				lastAlive = traps[i];
			}
		}

		if (aliveCount <= 1) {
			if (lastAlive)
				std::cout << GREEN << "\n🏆 " << lastAlive->getName() << " WINS THE BATTLE! 🏆\n" << RESET;
			else
				std::cout << RED << "\n☠️ Everyone died! ☠️\n" << RESET;
			break;
		}

		for (int i = 0; i < size; i++) {
			ClapTrap *attacker = traps[i];
			if (attacker->getHitPoints() <= 0)
				continue;

			ClapTrap *target = getRandomTarget(attacker, traps, size);
			if (!target)
				break;

			unsigned int damage = 5 + (rand() % 21);

			attacker->attack(target->getName());
			target->takeDamage(damage);

			if ((rand() % 100) < 20) {
				unsigned int heal = 5 + (rand() % 10);
				attacker->beRepaired(heal);
			}

			if (attacker == &d1 && attacker->getHitPoints() <= 30)
				d1.whoAmI();

			if (attacker == &s1 && attacker->getHitPoints() <= 20)
				s1.guardGate();

			if (attacker == &f1 && attacker->getHitPoints() <= 20)
				f1.highFivesGuys();

			wait(0.5);
		}

		showStatus(traps, size);
		wait(1.2);
	}

	section("⚡ BATTLE OVER ⚡");
	return 0;
}

