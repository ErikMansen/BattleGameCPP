//
// Created by Erik Mansén on 20/03/2023.
//

#include <cmath>
#include <string>
#include <utility>
#include "../include/Character.h"
#include "../include/Utils.h"

Character::Character(std::string name, int hitPoints, Weapon weapon, float dexterity)
        : m_name{std::move(name)}, m_hitPoints{hitPoints}, m_dexterity{dexterity}, m_weapon{std::move(weapon)},
          m_maxHitPoints{hitPoints} {}

int Character::attack(Character &opponent) {
    int minDamage = std::ceil(static_cast<float>(m_weapon.getDamage()) * m_dexterity);
    int damage = Utils::intInRange(minDamage, m_weapon.getDamage());

    if (damage < 0) damage = 0;
    opponent.takeDamage(damage);

    return damage;
}

void Character::takeDamage(int damage) {
    m_hitPoints -= damage;
    if (m_hitPoints < 0) {
        m_hitPoints = 0;
    }
}

std::string Character::getName() const {
    return m_name;
}

int Character::getHitPoints() const {
    return m_hitPoints;
}

void Character::setHitPoints(int hitPoints) {
    m_hitPoints = hitPoints;
}

Weapon Character::getWeapon() {
    return m_weapon;
}

int Character::getMaxHitPoints() const {
    return m_maxHitPoints;
}

void Character::setWeapon(const Weapon &weapon) {
    m_weapon = weapon;
}

