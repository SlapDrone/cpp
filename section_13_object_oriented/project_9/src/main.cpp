#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
    private:
        string name;
        int health;
        int xp;
    public:
        Player();
        Player(string name_val);
        Player(string name_val, int health_val, int xp_val);
};

// constructor initialisation lists
Player::Player() 
    : Player {"None", 0, 0} {
        cout << "No args constructor" << endl;
} 

Player::Player(string name_val)
    : Player {name_val, 0, 0} {
        cout << "One arg constructor" << endl;
}

Player::Player(string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {
        cout << "Three args constructor" << endl;
}

int main() {
    Player hero;
    Player another {"Another"};
    Player frank {"Frank", 100, 13};
    //frank.set_name("Frank");
    //cout << frank.get_name() << endl;
    return 0;
}