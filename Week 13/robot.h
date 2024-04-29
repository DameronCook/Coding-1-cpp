#include "includes.h"
#include "lists.h"
using std::string;
using std::vector;

class robot {
public:
    string name;

    robot() {
        srand(time(0));
        std::random_shuffle(std::begin(robotNames), std::end(robotNames));
        name = robotNames[0];
    }
};