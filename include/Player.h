//
// Created by Erik Mansén on 28/03/2023.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include <string>
#include <vector>
#include "Character.h"
#include "Weapon.h"

class Player : public Character {
public:
    Player(std::string name, int hitPoint, Weapon weapon, float dexterity);

    void getInventoryContent() const;

    [[nodiscard]] int getWeaponChoice() const;

    void addWeaponToInventory(const Weapon &weapon);

    void changeWeapon(int choice);

    int heal();

private:
    std::vector<Weapon> m_inventory;

    static int getValidChoice();
};


#endif //UNTITLED_PLAYER_H
