//
// Created by Erik Mansén on 28/03/2023.
//

#include <utility>

#include "../include/Weapon.h"
#include "../include/Utils.h"

Weapon::Weapon(std::string name, int damage)
        : m_name{std::move(name)}, m_damage{damage} {}

Weapon Weapon::createInstance() {
    Weapon weaponNames[5] = {
            {"Flail of Nausea",   25},
            {"Rusty Spoon",       15},
            {"Axe of Bruising",   30},
            {"Sword of Damocles", 100},
            {"Fists",             10}
    };
    return weaponNames[Utils::intInRange(0, 4)];
}

const std::string &Weapon::getName() const {
    return m_name;
}

int Weapon::getDamage() const {
    return m_damage;
}
