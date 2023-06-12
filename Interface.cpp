#include <iostream>
#include <iomanip>

#include "Interface.h"
#include "Level.h"

using namespace std;

Interface::Interface() {}

Interface::~Interface() {}

void Interface::showPlayerInterface(Player& player, Level& level, Enemy& enemy) {
    cout << endl << " Text Mode Game | Zombie Assault" << endl << endl;
    cout << left;
    cout << "   LEVEL - " << enemy.name << endl << endl;
    cout << "   " << setw(29) << player.name << endl;
    cout << " +--------------------------+" << endl;
    cout << setw(20) << "   Player Health:" << player.health << " HP" << endl;
    cout << setw(20) << "   Player Damage:" << player.damage << " DP" << endl;
    cout << setw(20) << "   Player Armor:" << player.armor << " AP" << endl;
    cout << setw(20) << "   First Aid Kits:" << player.firstAidKits << endl;
    cout << " +--------------------------+" << endl;
    cout << endl;
}

void Interface::showBattleInterface(Player& player, Enemy& enemy, Level& level) {

    string playerHealthSpace = "    ";
    string playerArmorSpace = "      ";

    if (player.health < 100 && player.health > 9) {
        playerHealthSpace = "     ";
    }
    else if (player.health < 10)
        playerHealthSpace = "      ";

    if (player.health < 0) player.health = 0;

    if (player.health > 100) player.health = 100;

    if (player.armor > 9)
        playerArmorSpace = "     ";

    if (enemy.health < 0) enemy.health = 0;

    cout << endl << " Text Mode Game | Zombie Assault" << endl << endl;
    cout << left;
    cout << "   LEVEL - " << enemy.name << endl << endl;
    cout << "   " << setw(29) << player.name << enemy.name << endl;
    cout << " +----------------------------+----------------------------+" << endl;
    cout << setw(20) << "   Player Health:" << player.health << " HP" << playerHealthSpace << "| Enemy Health:   " << enemy.health << " HP" << endl;
    cout << setw(20) << "   Player Damage:" << player.damage << " DP" << "     " << "| Enemy Damage:   " << enemy.damage << " DP" << endl;
    cout << setw(20) << "   Player Armor:" << player.armor << " AP" << playerArmorSpace << "| Enemy Armor:    " << enemy.armor << " AP" << endl;
    cout << setw(20) << "   First Aid Kits:" << player.firstAidKits << "         |" << endl;
    cout << " +----------------------------+----------------------------+" << endl;
    cout << endl;
}