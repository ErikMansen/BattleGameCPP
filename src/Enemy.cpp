//
// Created by Erik Mansén on 28/03/2023.
//

#include <utility>

#include "../include/Enemy.h"
#include "../include/Utils.h"

Enemy::Enemy(std::string name, int hitPoints, Weapon weapon, float dexterity)
        : Character{std::move(name), hitPoints, std::move(weapon)} {}

Enemy Enemy::createInstance() {
    Enemy enemyNames[6] = {
            {"fearsome goblin",   Utils::intInRange(20, 35), {"poisoned dagger", 15}, 0.7},
            {"dimwitted troll",   Utils::intInRange(50, 75), {"large club",      20}, 0.6},
            {"towering ogre",     Utils::intInRange(60, 80), {"huge boulder",    30}, 0.4},
            {"raging orc",        Utils::intInRange(35, 50), {"Battle axe",      22}, 0.9},
            {"rattling skeleton", Utils::intInRange(15, 25), {"rusted crowbar",  13}, 0.65},
            {"scary zombie",      Utils::intInRange(35, 45), {"severed leg",     10}, 0.75}
    };

    return {enemyNames[Utils::intInRange(0, 5)]};
}


