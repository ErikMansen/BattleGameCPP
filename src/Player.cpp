//
// Created by Erik Mansén on 28/03/2023.
//
#include <limits>
#include <iostream>
#include <iomanip>
#include "../include/Player.h"
#include "../include/Utils.h"


Player::Player(std::string name, int hitPoints, Weapon weapon, float dexterity)
        : Character{std::move(name), hitPoints, std::move(weapon), dexterity},
          m_inventory{getWeapon()} {}

void Player::getInventoryContent() const {
    if (m_inventory.empty()) {
        std::cout << "--Your inventory is empty--\n";
        return;
    }

    std::cout << "\nWeapons in inventory:\n";
    std::cout << std::left << std::setw(5) << "No." << std::setw(20) << "Name" << "Damage\n";
    std::cout << std::string(32, '-') << '\n';

    for (int i = 0; i < m_inventory.size(); i++) {
        std::cout << std::left << std::setw(5) << i + 1 << std::setw(20) << m_inventory[i].getName()
                  << m_inventory[i].getDamage() << '\n';
    }
}

int Player::getValidChoice() {
    int choice;
    while (true) {
        std::cin >> choice;
        if (!std::cin.fail()) {
            return choice;
        }
        std::cout << "Invalid input. Please enter a number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int Player::getWeaponChoice() const {
    std::cout << "Enter the number of the weapon to equip, or 0 to cancel: ";
    int choice = getValidChoice();
    while (choice < 0 || choice > m_inventory.size()) {
        std::cout << "Invalid choice. Please enter a number between 1 and " << m_inventory.size()
                  << ", or 0 to cancel.\n";
        choice = getValidChoice();
    }
    return choice;
}

void Player::addWeaponToInventory(const Weapon &weapon) {
    m_inventory.push_back(weapon);
}

void Player::changeWeapon(int choice) {
    setWeapon(m_inventory[choice - 1]);
}

int Player::heal() {
    int previousHitPoints = getHitPoints();
    int amountToHeal = Utils::intInRange(10, 30);
    setHitPoints(getHitPoints() + amountToHeal);

    int maxHitPoints = getMaxHitPoints();
    if (getHitPoints() > maxHitPoints) {
        setHitPoints(maxHitPoints);
    }

    int healedAmount = getHitPoints() - previousHitPoints;
    return healedAmount;
}
