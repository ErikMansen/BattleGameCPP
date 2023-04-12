//
// Created by Erik Mansén on 28/03/2023.
//

#ifndef UNTITLED_WEAPON_H
#define UNTITLED_WEAPON_H


#include <string>

class Weapon {

public:
    static Weapon createInstance();
    Weapon(std::string name, int damage);

    [[nodiscard]] const std::string &getName() const;

    [[nodiscard]] int getDamage() const;

private:
    std::string m_name;
    int m_damage;
};


#endif //UNTITLED_WEAPON_H
