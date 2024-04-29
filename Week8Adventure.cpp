#include <iostream>
#include <string> //For strings
#include <ctime> //to get the time function
#include <cstdlib>
using namespace std;

//Returns the players input to any question
string askYesNo(string question) {
    //Prints the string onto the console
    cout << question << "\n";

    //Gets and returns input from the player
    string input = "";
    cin >> input;
    return input;
}

//Rolls a random number between the number of sides and a minimum number. Defaults to a six sided die 
int RollDie(int sides = 6, int min = 1) {
    return rand() % (sides - min + 1) + min;
}

int main() {
    
    //Randomize the seed so every time the game is different
    srand(time(0));
    
    //Initialize variables that will be kept out of the loop
    int health = 10;
    int totalGold = 0;
    int turns = 0;
    bool alive = true;

    while (true) {
        //Display the players current health so they can see if they wanna keep adventuring or not
        cout << "\nCurrent Health: " << health << "\n";

        //Get a response to see if the player wants to keep adventuring
        string response = "";
        if (turns == 0) {
            response = askYesNo("Would you like to start an adventure? WARNING: THERE MIGHT BE ORCS Yes/No");

        } else {
            response = askYesNo("Would you like to keep adventuring? WARNING: THERE MIGHT BE ORCS Yes/No");
        }

        //If the player says "No" kick them out of the loop
        if (response == "No") break;

        //Increment the total number of turns taken
        turns++;
        
        //Introduce the orc
        cout << "It's an orc! Who could've seen this coming?!?!? \nThe orc... it's attacking!\n";

        //Calculate the orcs attack damage
        int attack = RollDie(6,1);
        cout << "The orc attacks for... " << attack << " damage! \n... but did you block in time?\n";

        //Calculate if the player blocks
        int block = RollDie(6,1);
        cout << "You block for... " << block << "!\n";

        //If the player's block is greater than or equal to the orcs attack, they block the attack and get some gold
        if (block >= attack) {
            //The player loses some health (so the loop isn't necessarily infinite and adds risk to the game)
            health -= 1;
            
            //If the player is especially greedy double check that they don't die this round... and give 'em some shit for it
            if (health <= 0) {
                cout << "You blocked but it didn't matter regardless. Your hubris took over and now you're dead! FOOL!\n";
                alive = !alive;
                break;
            }
            
            cout << "You blocked just in time!\nYou have lost one health point for a total of: " << health << "\n";
            
            //Calculate how much gold the player stumbles on in this loop
            int gold = RollDie(6,1);
            
            //Add that gold to the total gold score that will be posted in the end
            totalGold += gold;
            cout << "You run as fast as your legs can carry you!\nWhile you are busy chastising yourself for forgetting to bring a sword, you trip over something. It's gold! \nYou find that you tripped over: " << gold << " gold!\n";
            
        } else {
            
            // if the player's block is less than the attack, they take the full damage of the attack
            health -= attack;
            cout << "You missed your block! Ouch! \nYou're health is now: " << health << "\n";
            cout << "You manage to get up and run far, far away from the orc.\n";
            
            //Check if they're dead, and if so, break the loop (and my heart)
            if (health <= 0) {
                cout << "Oh shit. You Died! Like, for real!\n";
                alive = !alive;
                break;
            }
        }
    }
    
    //check if the player is alive and change the responses to the end stats depending on that
    if (alive) {
        cout << "You've come out of this adventure alive!\n";
        cout << "You survived: " << turns << " total turns!\n";
        cout << "You gathered: " << totalGold << " total gold!\n";
        cout << "You're health is: " << health << ".\n";
        if (health < 5) cout << "Damn, you should get check out by a medical professional though.";
    } else {
        cout << "Well, you're dead now... so that's cool I guess.\n";
        cout << "You lasted: " << turns << " turns until the bitter end.\n";
        cout << "You're greedy corpse has: " << totalGold << " gold left on it waiting to be plundered by some grave robber.\n";
        if (totalGold == 0) cout << "Wait... you're dead AND broke. Hah!";
    }
    
}