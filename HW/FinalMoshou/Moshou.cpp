/*****************************
 变量用下划线，class用非首字母大写，函数方法用大写。
完成对象的构造函数、对应属性以及基本变量。
*****************************/
#include<iostream>
#include<cstring>
#include<map>
#include<iomanip>
#define INTMAX 0x7fffffff
using std::cout;
using std::endl;
using std::string;
class gameMap;
class warrior;
class weapon;
class baseCity;
class dragon;
class ninja;
class lion;
class wolf;
class iceman;
class city;
class headquarter;
class sword;
class arrow;
class bomb;

/**
    basic variable
*/
int warrior_kind = 5; // only 5 kinds of warriors
int M, N, R, K, T;// N -> city num; R arrow atk; k loyalty decrease; T game max time
int battle_bonus = 8;
int city_health_round = 10;
gameMap* GAME;
std::map<int, string> red_headquarter_warrior = 
{
    {0, "iceman"}, {1, "lion"}, {2, "wolf"}, {3, "ninja"}, {4, "dragon"}
 };
std::map<int, string> blue_headquarter_warrior =
{
    {0, "lion"}, {1, "dragon"}, {2, "ninja"}, {3, "iceman"}, {4, "wolf"}
};

/**
 * basic function declartion
*/
int TellMeTheTime(gameMap* game);
void BornReport(char flag, int id);
void CreateWeapon(warrior*, weapon*& , int);


/**
 * base class start
*/
//base class for dragon ninja iceman lion wolf
class warrior
{
    protected:
        int id, health, atk;
        char flag;
    public:
        warrior(char _f, int _id = 0, int _health = 0, int _atk = 0):id(_id),health(_health),atk(_atk),flag(_f){}
        friend void CreateWeapon(warrior*, weapon*&, int);
};

//base class for headquarter and city
class baseCity
{
    private:
        int position;
        warrior* warrior_red = nullptr;
        warrior* warrior_blue = nullptr;
    public:
        baseCity(int _pos = 0):position(_pos){}
};

//base class for sword arrow and bomb
class weapon
{
    private:
        int atk;
    public:
        weapon(int _atk = 0):atk(_atk){}
};
/**
 * base class end
*/

/**
 * Derived class start
*/

// warrior class
class dragon : public warrior
{
    private:
        double morale;
        weapon* weapon_dragon;
    public:
        dragon(char _f, int _id = 0, int _health = 0, int _atk = 0, double _morale = 0):warrior(_f, _id, _health, _atk),morale(_morale)
        {
            CreateWeapon(this, weapon_dragon, _id%3);
            BornReport(_f, _id);
        }
};

class ninja : public warrior
{
    private:
        weapon* weapon_ninja1, weapon_ninja2;
    public:
        ninja(char _f, int _id = 0, int _health = 0, int _atk = 0):warrior(_f, _id, _health, _atk)
        {
            CreateWeapon(this, weapon_ninja1, _id%3);
            CreateWeapon(this, weapon_ninja1, (_id+1)%3);
            BornReport(_f, _id);
        }
};

class iceman : public warrior
{
    private:
        weapon* weapon_iceman;
    public:
        iceman(char _f, int _id = 0, int _health = 0, int _atk = 0):warrior(_f, _id, _health, _atk)
        {
            CreateWeapon(this, weapon_iceman, _id%3);
            BornReport(_f, _id);
        }
};

class lion : public warrior
{
    private:
        int loyalty;
    public:
        lion(char _f, int _id = 0, int _health = 0, int _atk = 0, int _loyalty = 0):warrior(_f, _id, _health, _atk),loyalty(_loyalty)
        {
            BornReport(_f, _id);
        }
};

class wolf : public warrior
{
    private:
        weapon** weapon_wolf;
    public:
        wolf(char _f, int _id = 0, int _health = 0, int _atk = 0):warrior(_f, _id, _health, _atk)
        {
            weapon_wolf = new weapon*[3];
            for(int i = 0; i < 3; ++i) weapon_wolf[i] = nullptr;
            BornReport(_f, _id);
        }
};

// city class
class city : public baseCity
{
    private:
        int cityFlag = 0;
        int city_health = 0;
    public:
        city(int _pos = 0):baseCity(_pos){}
};

// headquarter class for both side
class headquarter : public baseCity
{
    private:
        char flag;        
        int health = M;
        warrior* Other_warrior = nullptr;
    public:
        headquarter(char _f, int _pos = 0):baseCity(_pos),flag(_f){}
};

// weapon class
class sword : public weapon
{
    public:
        sword(int _atk):weapon((int)(_atk/5)){}
};

class arrow : public weapon
{
    private:
        int durity = 3;
    public:
        arrow(int _atk):weapon(_atk){}
};

class bomb : public weapon
{
    public:
        bomb():weapon(INTMAX){}
};
/**
 * Derived class end
*/

/**
 * game map class
*/
class gameMap
{
    private:
        int game_time = 0;
        baseCity** citys;
    public:
        gameMap(int n)
        {
            citys = new baseCity*[n+2];
            for(int i = 0; i <= n+1; ++i)
            {
                if(i == 0) citys[i] = new headquarter('R', i);
                else if(i == n+1) citys[i] = new headquarter('B', i);
                else citys[i] = new city(i);
            }
        }

        // generate warriors
        void GenerateWarrior()
        {

        }

        friend int TellMeTheTime(gameMap* game);
};

/**
 * basic function implement start
*/
int TellMeTheTime(gameMap* game)
{
    return game->game_time;
}

void BornReport(char flag, int id)
{
    int time = TellMeTheTime(GAME);
    if(flag == 'R') 
    cout << std::setw(3) << std::setfill('0')
    << (time / 60) << ":" << std::setw(2) << std::setfill('0') << (time % 60) << " red " << 
    red_headquarter_warrior[id%5] << " " << id << " " << "born" << endl;
    if(flag == 'B') 
    cout << std::setw(3) << std::setfill('0')
    << (time / 60) << ":" << std::setw(2) << std::setfill('0') << (time % 60) << " blue " << 
    blue_headquarter_warrior[id%5] << " " << id << " " << "born" << endl;
}

void CreateWeapon(warrior* warrior_pointer, weapon*& weapon_pointer, int id)
{
    switch(id)
    {
        case 0 : weapon_pointer = new sword(warrior_pointer->atk); break;
        case 1 : weapon_pointer = new arrow(R); break;
        case 2 : weapon_pointer = new bomb(); break;
    }
}
/**
 * basic function implement end
*/


int main(){
    return 0;
}