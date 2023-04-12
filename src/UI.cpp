//
// Created by Erik Mansén on 19/03/2023.
//

#include <iostream>
#include <sstream>
#include "../include/UI.h"
#include "../include/Utils.h"

void UI::startGame() {
    using std::cout;
    int timesPlayed;
    std::string playerName;
    try {
        timesPlayed = Utils::deserializeInt("timesPlayed.txt");
        timesPlayed++;
        Utils::serializeInt(timesPlayed, "timesPlayed.txt");
        playerName = Utils::deserializeString("playerName.txt");

        cout << "Times played: " << timesPlayed << "\nWelcome back " << playerName
             << "\nWhile you were gone, you slipped on some spaghetti and lost all of your items.\n"
                "But on the bright side, you're now fully healed up.\n";

    } catch (const std::exception &ex) {
        cout << "Welcome, brave warrior, to the world of mediocre text-based adventure games.\n"
                "Please enter your name: ";
        std::cin >> playerName;
        timesPlayed = 0;
    }

    Player player{playerName, 100, {Weapon::createInstance()}, 0.9};

    cout << "\nyou have embarked on an epic adventure, \n"
            "Leaving your hometown behind in pursuit of becoming a successful adventurer, you're heading to\n"
            "the capital. It seems like there is an astronomical amount of monsters appearing everywhere.\n"
            "Well, I guess there's nothing you can do but beat their skulls in.\n";

    gameLoop(player);
}

void UI::gameLoop(Player &player) {
    using std::cout;
    while (true) {
        Enemy enemy = Enemy::createInstance();
        bool enemyOrPlayerDead = false;
        while (!enemyOrPlayerDead) {
            cout << "\nYou see a " << enemy.getName() << " will you attack (A), escape (E) or quit the game (Q): ";
            std::string input;
            std::cin >> input;

            switch (std::tolower(input[0])) {
                case 'a':
                    fight(player, enemy);
                    if (enemy.getHitPoints() <= 0) {
                        dropItem(enemy, player);
                    }
                    break;
                case 'e':
                    cout << "You make a run for it\n";
                    enemy.setHitPoints(0);
                    break;
                case 'q':
                    cout << "\nThanks for playing!";
                    Utils::serializeString(player.getName(), "playerName.txt");
                    exit(0);
                default:
                    cout << "That's not a valid input\n";
                    break;
            }

            if (enemy.getHitPoints() <= 0) enemyOrPlayerDead = true;
            else if (player.getHitPoints() <= 0) {
                cout << "Game Over\n Better luck next time\n";
                remove("playerName.txt");
                system("pause");
                exit(0);
            }
        }
        restLoop(player);
    }
}

void UI::fight(Character &attacker, Enemy &defender) {
    Character *currentChr = &attacker;
    Character *nextChr = &defender;

    std::cout << std::string(50, '-') << '\n';
    while (attacker.getHitPoints() > 0 && defender.getHitPoints() > 0) {
        int damage = currentChr->attack(*nextChr);

        std::cout << currentChr->getName() << " hits " << nextChr->getName() << " with "
                  << currentChr->getWeapon().getName() << " for " << damage << ".\n --> "
                  << nextChr->getName() << " has " << nextChr->getHitPoints() << " HP left\n";

        std::swap(currentChr, nextChr);
    }
    std::cout << std::string(50, '-') << '\n';
}

void UI::dropItem(Enemy enemy, Player &player) {
    using std::cout;
    int drop = Utils::intInRange(1, 10);
    if (drop > 6) {
        cout << "\nThe slain enemy seems to have dropped a "
             << enemy.getWeapon().getName() << "\nDo you want to pick it up?\n";

        cout << "(F) to pickup the weapon or (D) to leave it: \n";
        while (true) {
            std::string input;
            std::cin >> input;
            switch (std::tolower(input[0])) {
                case 'f':
                    cout << "You collect your loot and continue on your journey\n";
                    player.addWeaponToInventory(enemy.getWeapon());
                    return;
                case 'd':
                    cout << "You decide that you do not need any more burdens and proceed on your journey.\n";
                    return;
                default:
                    cout << "That's not a valid input\n";
                    break;
            }
        }
    }
}

void UI::restLoop(Player &player) {
    using std::cout;
    while (true) {
        cout << "\nDo you want to switch weapons or heal?\n"
                "(I) to open your inventory or change weapon, (H) to heal, and (A) to continue on your journey: ";
        std::string input;
        std::cin >> input;
        int choice;
        switch (std::tolower(input[0])) {
            case 'i':
                player.getInventoryContent();
                choice = player.getWeaponChoice();
                if (choice != 0) player.changeWeapon(choice);
                break;
            case 'h':
                cout << "You bandage yourself up and heal for " << player.heal() << "hp\n";
                break;
            case 'a':
                return;
            default:
                cout << "That's not a valid input";
                break;
        }
    }
}


