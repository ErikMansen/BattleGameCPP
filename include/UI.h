//
// Created by Erik Mansén on 19/03/2023.
//

#ifndef UNTITLED_UI_H
#define UNTITLED_UI_H


#include "Character.h"
#include <string>
#include "../include/Enemy.h"
#include "Player.h"

class UI {

public:
    static void startGame();

private:

    static void fight(Character &attacker, Enemy &defender);

    static void dropItem(Enemy enemy, Player& player);

    static void restLoop(Player &player);

    static void gameLoop(Player &player);
};


#endif //UNTITLED_UI_H
