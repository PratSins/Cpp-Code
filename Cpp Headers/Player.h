#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

using namespace std;

class Player
{
private:
   static int num_players ;
   string name;
   int health;
   int xp;
public:
    string get_name() { return name; }
    int get_health() { return health; }
    int get_xp() {return xp; } 
    Player(string name_val ="None", int health_val = 0, int xp_val = 0)
    : name{name_val}, health{health_val}, xp{xp_val} {
        ++num_players;
    }
    // Copy constructor
    Player(const Player &source): Player {source.name, source.health, source.xp}  {}
    // Destructor
    ~Player(){
        --num_players;
    }
    
    static int get_num_players(){
        return num_players;
    }
    
};
int Player::num_players {0};
#endif // _PLAYER_H_
