class warrior;
class weapon;
class baseCity;
/**
 * basic function declartion
*/
void AddWeapon(weapon*& , int);

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
};

//base class for headquarter and city
class baseCity
{
    private:
        int position;
        char flag;
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
            AddWeapon(weapon_dragon, _id%3);
        }
};

class ninja : public warrior
{
    private:
        weapon* weapon_ninja1, weapon_ninja2;
    public:
        ninja(char _f, int _id = 0, int _health = 0, int _atk = 0):warrior(_f, _id, _health, _atk)
        {
            AddWeapon(weapon_ninja1, _id%3);
            AddWeapon(weapon_ninja1, (_id+1)%3);
        }
};

class iceman : public warrior
{
    private:
        weapon* weapon_iceman;
    public:
        iceman(char _f, int _id = 0, int _health = 0, int _atk = 0):warrior(_f, _id, _health, _atk)
        {
            AddWeapon(weapon_iceman, _id%3);
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
        warrior* warrior_red = nullptr;
        warrior* warrior_blue = nullptr;
    public:
        city(char _f, int _pos = 0):baseCity(_f, _pos){}
};

class headquarter : public baseCity
{
    private:
        warrior** warrior_red;
        warrior** warrior_blue;
    public:
        headquarter(char _f, int _pos = 0):baseCity(_f, _pos){}
};

// weapon class

/**
 * Derived class end
*/

/**
 * basic function
*/
