//Dameron Cook Week 11 Day 2 - More classes
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

//An enumerator is a custom variable type that evaluates to an integer.
//So in this case, an item can be classified as an item or tool
enum itemType {
    WEAPON,    // equal to 0
    CONSUMABLE    //equal to 2
};

enum elementType {
    BASIC,
    FIRE,
    ICE,
    CANDY,
    SLIME
};

class item {
public:
    itemType type;
    int damage;
    string name;
    elementType element;
    int remainingUses;
    int healAmount;

    //build a fancy constructor
    item(string n = "sword", itemType t = WEAPON, int d = 0, int h = 0) {
        name = n;    //assign the name of the item to the given name
        type = t;
        damage = d;
        healAmount = h;
        if (type == WEAPON) {
            element = (elementType)(rand() % 4);    //Typecast an int into an elementtype
            remainingUses = 999999;
            if (damage == 0) {
                damage = 4 + rand() % 3;
            }
        } else if (type == CONSUMABLE) {
            healAmount += rand() % 2;
            element = BASIC;
            remainingUses = 1;
        }
    }// end of item constructor
    void Inspect() {
        cout << name << " has the damage of " << damage << ", it's element is " << ElementToString(element) << ",\n";
        cout << "It can be used " << remainingUses << " more times, heals for " << healAmount << ", \n";
        cout << "And is of the item type " << TypeToString(type) << ". \n\n";
    }

    string ElementToString(elementType e) {
        switch(e) {
            case BASIC:
                return "BASIC";
                break;
            case FIRE:
                return "FIRE";
                break;
            case ICE:
                return "ICE";
                break;
            case CANDY:
                return "CANDY";
                break;
            case SLIME:
                return "SLIME";
                break;
            default:
                return "UNKNOWN";
                break;
        }
    }

    string TypeToString(itemType type) {
        switch(type) {
            case WEAPON:
                return "WEAPON";
                break;
            case CONSUMABLE:
                return "CONSUMABLE";
                break;
            default:
                return "UNKNOWN";
                break;
        }
    }
};

//Create a class named enmey based on the adventure assignment
class enemy {
public:
    itemType type = WEAPON;
    elementType weakness = BASIC;
    int health = 0;
    int attack = 0;
    string name = "";
    item heldItem;
    
    vector<string> names = {
        "Grommash",
        "Durotan",
        "Gul'dan",
        "Kargath",
        "Mannoroth",
        "Thrall",
        "Sylvanas",
        "Varok",
        "Garrosh",
        "Jaina",
        "Anduin",
        "Tyrande"
    };

    vector<string> weaponNames = {
        "Skullcrusher",
        "Bloodspiller",
        "Doomsayer",
        "Bonecrusher",
        "Soulreaper",
        "Nightfall",
        "Hellfire",
        "Demonboon",
        "Shadowstrike",
        "Deathharvester"
    };


    
    enemy() : heldItem("default", WEAPON, 0, 0) {
        //Shuffle up the names to get a new one for the enemy
        random_shuffle(names.begin(), names.end());
        name = names.front();    //gets first entry for the names vector

        //Generate the enemy's health and weakness
        weakness = (elementType)(rand() % 4);
        health = rand() % 10 + 5;

        // give the enemy an item
        //Shuffle up the names to get a new one for the enemy
        random_shuffle(weaponNames.begin(), weaponNames.end());
        string weaponName = weaponNames.front();    //gets first entry for the names vector
        heldItem.name = weaponName;

        //generate this enemies attack based on their item
        attack = heldItem.damage + rand() % 3;
    }

    void Inspect() {
        cout << name << " has an attack of " << attack << ", it's item's element is " << ElementToString(heldItem.element) << ", \n";
        cout << "it's item's name is " << heldItem.name << ". His health is " << health << ",\n" << "and his weakness is " << ElementToString(weakness) << ".\n\n";
    }

    string ElementToString(elementType e) {
        switch(e) {
            case BASIC:
                return "BASIC";
                break;
            case FIRE:
                return "FIRE";
                break;
            case ICE:
                return "ICE";
                break;
            case CANDY:
                return "CANDY";
                break;
            case SLIME:
                return "SLIME";
                break;
            default:
                return "UNKNOWN";
                break;
        }
    }

private:

};

//Rolls a random number between the number of sides and a minimum number. Defaults to a six sided die 
int RollDie(int sides = 6, int min = 1) {
    return rand() % (sides - min + 1) + min;
}

//Create an Attack function that returns true if the player attacks and false if the enemy attacks
bool AttackCheckWin(item playerItem, enemy enemyInst) {
    //Check if the player's item's element is equal to the enemies weakness
    //If so, return true that the player has won
    if (playerItem.element == enemyInst.weakness) {
        cout << "\nYou hit his weakness! Automatic win!\n";
        return true;
    }
    //If the player can't use a weakness, then they both opponents roll
    int playerAttack = playerItem.damage + RollDie(6, 1);
    cout << "\nThe player rolls for " << playerAttack << "!\n";

    int enemyAttack = enemyInst.attack + RollDie(6, 1);
    cout << "\nThe enemy rolls for " << enemyAttack << "!\n";
    
    if (playerAttack >= enemyAttack) {
        cout << "\nThe player attacks!\n";
        return true;
    } else {
        cout << "\nThe enemy attacks!\n";
        return false;
    }
}

int main() {
    srand(time(0));


    //initialize player variables
    int playerMaxHealth = rand() % 5 + 10;
    int playerCurHealth = playerMaxHealth;
    int totalGold = 0;
    bool alive = true;

    cout << "You decide that it's time for an adventure. You gather your courage and gather your arsenal: \n\n";
    
    //Player will be given 2 basic items. a WEAPON and a CONSUMABLE.
    //Put in a while loop for the battle with the player

    //Print out the player's stats they need to know
    item playerWeapon("FledglingSword", WEAPON, 6, 0);
    playerWeapon.Inspect();

    item playerConsumable("MomCookies", CONSUMABLE, 0, 3);
    playerConsumable.Inspect();

    cout << "You head toward the woods...\n";

    while (true) {

        //make sure to break out of this if the player is dead
        if (!alive) break;
        
        //Print the player's current stats at the start of the loop
        cout << "\nCurrent Health: " << playerCurHealth;

        cout << "\nCurrent Gold: " << totalGold << "\n";
        
        //Ask the player if they want to adventure
        string input = "";
        cout << "\nDo you wish to keep adventuring? YES/NO \n";
        cin >> input;
        
        //If no, break the loop, otherwise, they run into an ork
        if (input == "NO") {
            cout << "Your total gold was: " << totalGold << " before you ran back home.\n";
            break;
        }

        cout << "You venture further into the woods.\n\n";
        cout << "It's not long until... you run into an orc!\n\n";

        //Create the ork 
        enemy enemyInst;

        while (true) {
            //Display enemy stats
            cout << "Enemy stats: \n";
            enemyInst.Inspect();
            
            //Display the player stats
            cout << "Player stats: \n";
            playerWeapon.Inspect();
            playerConsumable.Inspect();

            cout << "\nCurrent Health: " << playerCurHealth;

            cout << "\nCurrent Gold: " << totalGold << "\n";
            
            //Ask if they want to ATTACK or CONSUME
            cout << "Do you wish to ATTACK or CONSUME?\n\n";
            cin >> input;
            
            /*If they ATTACK both the ENEMY and the PLAYER will roll for attack
            based on their WEAPON item's stats. Whoever's roll is higher will win.
            If the player's WEAPON type is equal to the enemies' WEAKNESS, they will
            automatically win. The winner's attack roll will do that much damage to 
            their opponent. Whoever's health reaches zero loses the match. If the 
            player's health is 0 break the loop. If the enemy's health is 0, the 
            player will gain some gold, have the choice to discard their old weapon
            and take the enemies, and find one randomized CONSUMABLE. Then,
            the round is over, and the game loop resets. If both opponents are alive
            by the end of the turn, then the battle loop resets.
            
            If the player uses a CONSUMABLE, the item will heal the player by the 
            amount of the item held, and the round will reset. If there is no 
            CONSUMABLE, print a short message and reset the battle loop.
            */

            if (input == "ATTACK") {
                if (AttackCheckWin(playerWeapon, enemyInst)) {
                    enemyInst.health -= playerWeapon.damage;
                    cout << enemyInst.name << " now has " << enemyInst.health << " health left!\n\n";
                } else {
                    playerCurHealth -= enemyInst.attack;
                    cout << "Your health is now: " << playerCurHealth << "!\n\n";
                }
            } else if (input == "CONSUME") {
                if (playerConsumable.remainingUses <= 0) {
                    cout << "You ran out of consumables!\n\n";
                } else {
                    cout << "You used your " << playerConsumable.name << "!\n\n";
                    playerCurHealth = min(playerCurHealth + playerConsumable.healAmount, playerMaxHealth);
                    playerConsumable.remainingUses -= 1;
                    cout << "Your health is now: " << playerCurHealth << "!\n\n";
                }
            } else {
                cout << "C'mon, buddy. Attack or consume.\n\n";
            }

            //Check player health and set the player to !alive
            if (playerCurHealth <= 0) {
                alive = false;
            }

            //Check enemy stats
            if (enemyInst.health <= 0) {
                cout << "The enemy is dead!\n";
                cout << "Do you want to take his weapon? YES/NO\n\n";
                cout << "Enemy Weapon: \n";
                enemyInst.heldItem.Inspect();
                cout << "Player Weapon: \n";
                playerWeapon.Inspect();

                cin >> input;
                if (input == "YES") {
                    playerWeapon = enemyInst.heldItem;
                }

                int enemyGold = 3 + rand() % 5;
                totalGold += enemyGold;
                cout << "The enemy dropped " << enemyGold << " gold!\n\n";

                if (playerConsumable.remainingUses <= 0) {
                    cout << "The enemy also dropped some ork meat!\n";
                    item tempConsumable("Ork Meat", CONSUMABLE, 0, 3 + rand() % 5);
                    playerConsumable = tempConsumable;
                    playerConsumable.Inspect();
                }
                break;
            }

            if (!alive) {
                cout << "You Died!\n";
                cout << "Your total gold was: " << totalGold;
                break;
            }
        }
    } 
}