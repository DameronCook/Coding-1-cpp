//Headers are a great way to organize your code
#include "includes.h"
#include "functions.h"
#include "robot.h"
#include <fstream> //for input and output of files

using namespace std;

int main() {
    Hello();            //Calling a function from our header file

    robot rob;
    cout << "My name is " << rob.name << "!\n";

    ofstream myFile;
    myFile.open("file.txt");
    myFile << "Here is a line of text. \n";
    myFile.close();

    // a new variable of the type "ifStream" named read from file
    ifstream readFile ("names.txt");
    string line;
    vector<string> names;
    if (readFile.is_open()) {
        while(getline(readFile, line)) {
            cout << line << "\n";
            names.push_back(line);
        }
        readFile.close();
    } else {
        cout << "Could not read from file.\n";
    }

    if (names.size() > 0) {
        cout << "The first name in names is " << names[0];
    }
    
}