//
// Created by Erik Mansén on 28/03/2023.
//

#ifndef UNTITLED_ENEMY_H
#define UNTITLED_ENEMY_H

#include "Character.h"

class Enemy : public Character {

public:
    static Enemy createInstance();

private:
    Enemy(std::string name, int hitPoint, Weapon weapon ,float dexterity);

};


#endif //UNTITLED_ENEMY_H