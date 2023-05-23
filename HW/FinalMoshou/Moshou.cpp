/*****************************
完成对象的构造函数、对应属性以及基本变量。
*****************************/
#include<iostream>
#include<cstring>
#define INTMAX 0x7fffffff
using std::cout;
using std::endl;
using std::string;
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
int M, N, R, K, T;
int battle_bonus = 8;
int city_health_round = 10;

/**
 * basic function declartion
*/
void CreateWeapon(warrior*, weapon*& , int);

/**
 * base class start
*/
//base class for dragon ninja iceman lion wolf
class warrior
{
    private:
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
        char flag;
        warrior* warrior_red = nullptr;
        warrior* warrior_blue = nullptr;
    public:
        baseCity(char _f, int _pos = 0):position(_pos),flag(_f){}
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
        }
};

class lion : public warrior
{
    private:
        int loyalty;
    public:
        lion(char _f, int _id = 0, int _health = 0, int _atk = 0, int _loyalty = 0):warrior(_f, _id, _health, _atk),loyalty(_loyalty){}
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
        }
};

// city class
class city : public baseCity
{
    private:
        int city_health = 0;
    public:
        city(char _f, int _pos = 0):baseCity(_f, _pos){}
};

// headquarter class for both side
class headquarter : public baseCity
{
    private:
        int health = M;
        warrior* Other_warrior = nullptr;
    public:
        headquarter(char _f, int _pos = 0):baseCity(_f, _pos){}
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
 * basic function implement
*/
void CreateWeapon(warrior* warrior_pointer, weapon*& weapon_pointer, int id)
{
    switch(id)
    {
        case 0 : weapon_pointer = new sword(warrior_pointer->atk); break;
        case 1 : weapon_pointer = new arrow(R); break;
        case 2 : weapon_pointer = new bomb(); break;
    }
}


int main(){
    return 0;
}