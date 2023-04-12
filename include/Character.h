//
// Created by Erik Mansén on 20/03/2023.
//

#ifndef UNTITLED_CHARACTER_H
#define UNTITLED_CHARACTER_H

#include <string>
#include "../include/Weapon.h"


class Character {
public:
    Character(std::string name, int hitPoints, Weapon weapon = {"Fists", 1}, float dexterity = 1);

    int attack(Character &opponent);

    void takeDamage(int damage);

    [[nodiscard]] std::string getName() const;

    [[nodiscard]] int getHitPoints() const;

    [[nodiscard]] float getDexterity() const;

    void setHitPoints(int hitPoints);

    Weapon getWeapon();

    [[nodiscard]] int getMaxHitPoints() const;

    void setWeapon(const Weapon &weapon);

private:
    std::string m_name;
    int m_hitPoints;
    float m_dexterity;
    Weapon m_weapon;
    const int m_maxHitPoints;



};


#endif //UNTITLED_CHARACTER_H

