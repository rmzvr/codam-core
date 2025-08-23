#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

// Colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

// Utility: colored section titles
void section(const std::string &title) {
	std::cout << CYAN << "\n=== " << title << " ===" << RESET << "\n";
}

// Sleep helper for dramatic effect
void wait(float sec = 0.6) {
	usleep((useconds_t)(sec * 1'000'000));
}

// Show status of all fighters
void showStatus(ClapTrap *traps[], int size) {
	std::cout << MAGENTA << "\n[ STATUS ]" << RESET << "\n";
	for (int i = 0; i < size; i++) {
		std::cout
				<< traps[i]->getName()
				<< " has " << traps[i]->getHitPoints()
				<< " HP\n";
	}
}

// Pick a random target different from attacker
ClapTrap* getRandomTarget(ClapTrap *attacker, ClapTrap *traps[], int size) {
	ClapTrap *candidates[10]; // max fighters
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

	// === Create fighters ===
	DiamondTrap d1("DiamondOne");
	ScavTrap    s1("ScavvyOne");
	FragTrap    f1("FraggyOne");
	ClapTrap    c1("ClappyOne");

	// Array of fighters
	ClapTrap *traps[4] = { &d1, &s1, &f1, &c1 };
	const int size = 4;

	// === Intro ===
	section("⚔️ BATTLE ROYALE STARTS ⚔️");
	showStatus(traps, size);
	wait(1.5);

	// === Battle Loop ===
	int round = 1;
	while (true) {
		std::cout << YELLOW << "\n--- ROUND " << round++ << " ---" << RESET << "\n";

		// Count alive traps
		int aliveCount = 0;
		ClapTrap *lastAlive = NULL;
		for (int i = 0; i < size; i++) {
			if (traps[i]->getHitPoints() > 0) {
				aliveCount++;
				lastAlive = traps[i];
			}
		}

		// Check winner
		if (aliveCount <= 1) {
			if (lastAlive)
				std::cout << GREEN << "\n🏆 " << lastAlive->getName() << " WINS THE BATTLE! 🏆\n" << RESET;
			else
				std::cout << RED << "\n☠️ Everyone died! ☠️\n" << RESET;
			break;
		}

		// Each alive fighter attacks
		for (int i = 0; i < size; i++) {
			ClapTrap *attacker = traps[i];
			if (attacker->getHitPoints() <= 0)
				continue;

			ClapTrap *target = getRandomTarget(attacker, traps, size);
			if (!target)
				break;

			// Random damage between 5 and 25
			unsigned int damage = 5 + (rand() % 21);

			attacker->attack(target->getName());
			target->takeDamage(damage);

			// Small chance to repair
			if ((rand() % 100) < 20) {
				unsigned int heal = 5 + (rand() % 10);
				attacker->beRepaired(heal);
			}

			// DiamondTrap special moves
			if (attacker == &d1 && attacker->getHitPoints() <= 30)
				d1.whoAmI();

			// ScavTrap special move
			if (attacker == &s1 && attacker->getHitPoints() <= 20)
				s1.guardGate();

			// FragTrap special move
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

