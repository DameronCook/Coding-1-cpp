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
    TOOL,    // equal to 1
    CONSUMABLE    //equal to 2
};

enum elementType {
    BASIC,
    FIRE,
    ICE,
    CANDY,
    SLIME
};

//Create a class named enmey based on the adventure assignment with a constructor
class enemy {
public:
    enemy() {
        
    }

private:

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
    item(string n, itemType t) {
        name = n;    //assign the name of the item to the given name
        type = t;
        if (type == WEAPON) {
            //calculate damage and element
            damage = rand() % 5 + 3;
            element = (elementType)(rand() % 4);    //Typecast an int into an elementtype
            healAmount = 0;
            remainingUses = 999999;
        } else if (type == TOOL) {
            remainingUses = rand() % 5 + 1;
            damage = 1;
            element = BASIC;
            healAmount = 0;
        } else if (type == CONSUMABLE) {
            healAmount = rand() % 5 + 1;
            damage = -healAmount;
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
            case TOOL:
                return "TOOL";
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

int main() {
    srand(time(0));
    cout << "Prepare for classes...\n";


    
    vector<string> weaponNames = {
        "Excalibur",
        "Mjolnir",
        "Frostmourne",
        "Sting",
        "Sword of Omens",
        "Masamune",
        "Anduril",
        "Soul Edge",
        "Master Sword",
        "Gunblade"
    };
    
    random_shuffle(weaponNames.begin(), weaponNames.end()); // #include algorithm
    
    item sting("Sting", WEAPON);
    sting.Inspect();
    
    vector<item> weapons;
    
    for (int i = 0; i < weaponNames.size(); i++) {
        weapons.push_back(item(weaponNames[i], WEAPON)); //create a weapon
        weapons[i].Inspect();
    }
}