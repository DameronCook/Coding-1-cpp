/* Recap of everything for the coding 1 class.
    Areas of struggle: Classes within class, enumerators
*/
#include <iostream>
#include <string>

using namespace std;

//Enumerators - should be upper case as they are constant values
enum difficulty {
    EASY,
    MEDIUM,
    HARD
};

enum shipTypes {
    ROWBOAT = 1,
    TUGBOAT = 25,
    FRIGAT = 50,
    BATTLESHIP = 250,
    CARRIER = 1000
};


//Classes within classes 
class robot {
public:
    string name = "Rob";
};

class weapon {
public:
    string name = "Mace";
    int damage = 20;
};

class human {
public:
    string name = "Vincent";
    robot buddy;
    weapon myWeapon;

    human() {
        SayHello();
    }

    void SayHello() {
        cout << "Hello, my name is " << name << " and my robot's name is " << buddy.name << ".\n";
        cout << "My weapon's name is " << myWeapon.name << " and it does " << myWeapon.damage << " damage.\n";
    }
};


int main() {

    shipTypes playerShip = TUGBOAT;

    int playerMoney = 500;

    if (playerShip == TUGBOAT) {
        cout << "You've got a tugboat. You're fucked!\n";
        playerMoney -= TUGBOAT;
        cout << "Money: " << playerMoney << "\n";
    }
    
    //Calling classes
    human firstHuman;
    weapon coolSword;
    coolSword.name = "Sword of go fuck yaself.";
    coolSword.damage = 9999;

    firstHuman.myWeapon = coolSword;
    firstHuman.SayHello();

    //Memory addresses where the data is actually physically stored
    cout << "The memory address of coolSword is " << &coolSword << ".\n";
    cout << "The memory address of coolSword is " << &firstHuman.myWeapon << ".\n";
}