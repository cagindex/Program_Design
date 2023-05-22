#include<iostream>
#include<cstring>
#include<map>
using namespace std;

int TIME = 0;
map<string, int> WARRIOR_HEALTH;
string DEFAULT_WARRIOR_SET[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
string RED_WARRIOR_SET[5] = {"iceman", "lion", "wolf", "ninja", "dragon"};
string BLUE_WARRIOR_SET[5] = {"lion", "dragon", "ninja", "iceman", "wolf"};
string WEAPON[3] = {"sword", "bomb", "arrow"};

/**
 * Class of WARRIOR
*/
class warrior{
    private:
        const int ID;
        int HEALTH;
    
    public:
        /**
         * Constructor
        */
        explicit warrior(const int id, int health):ID(id), HEALTH(health){}

        /**
         * Get the ID 
        */
        const int Get_Id(){return ID;}

        /**
         * Get the HEALTH
        */
        int Get_Health(){return HEALTH;}
};

/**
 * Class of iceman 
 * Derived class
 * Base class -> warrior
*/
class ICEMAN: public warrior{
    private:
        int weapon;
    public:
        ICEMAN(const int id, int health):warrior(id, health), weapon(id%3){}
};

/**
 * Class of lion 
 * Derived class
 * Base class -> warrior
*/
class LION: public warrior{
    private:
        int loyalty;
    public:
        LION(const int id, int health, int loyal_):warrior(id, health), loyalty(loyal_){}
};

/**
 * Class of ninja 
 * Derived class
 * Base class -> warrior
*/
class NINJA: public warrior{
    private:
        int weapon1, weapon2;
    public:
        NINJA(const int id, int health):warrior(id, health), weapon1(id%3), weapon2((id + 1)%3){}
};

/**
 * Class of dragon 
 * Derived class
 * Base class -> warrior
*/
class DRAGON: public warrior{
    private:
        int weapon;
        float morale;
    public:
        DRAGON(const int id, int health, float morale_):warrior(id, health), weapon(id%3), morale(morale_){}
};

/**
 * Class of wolf 
 * Derived class
 * Base class -> warrior
*/
class WOLF: public warrior{
};


/**
 * Class of the headquarter
*/
class headquarter{
    private :
        bool LOCK;
        int HEALTH;
        int IDENTIFIER;

        int NOW_WARRIOR_INDEX;
        int NUM_WARRIOR[5];
        string *WARRIOR_SET;
        string NAME;
    public :
        /**
         * Constructor
        */
        explicit headquarter(string name, int health, string s[]):HEALTH(health){
            // memcpy(&NAME, &name, sizeof(string));
            // memcpy(WARRIOR_SET, s, sizeof(WARRIOR_SET));
            // memmove(WARRIOR_SET, s, sizeof(WARRIOR_SET));
            memset(NUM_WARRIOR, 0, sizeof(NUM_WARRIOR));
            NAME = name;
            WARRIOR_SET = s;
            // NUM_WARRIOR = new int[5];
            LOCK = false;
            IDENTIFIER = 1;
            NOW_WARRIOR_INDEX = 0;
        }

        /**
         * Get the health
        */
        int Get_Health(){return HEALTH;} 

        /**
         * Change health
         * if health reach the bottom set the lack_health to true
         * return the changed health
        */
        bool Change_Health(int value){
            int a = value + HEALTH;
            if (a < 0) {
                return false;
            }
            HEALTH = a;
            return true;
        }

        /**
         * Produce warrior according to the NOW_WARRIOR_INDEX and the WARRIOR_SET
         * if LACK_HEALTH to all warriors, return false
         * else return ture
        */
        bool Warrior_Produce(){
            string warrior_to_produce;
            int health_to_cost;

            if (LOCK){return false;}

            for (int index = NOW_WARRIOR_INDEX; index < NOW_WARRIOR_INDEX + 5; index++){
                warrior_to_produce = WARRIOR_SET[index % 5];
                health_to_cost = WARRIOR_HEALTH[warrior_to_produce];

                if (Change_Health(-1*health_to_cost)){
                    NUM_WARRIOR[index%5] ++;
                    annouce(index%5); 
                    if (WARRIOR_SET[index%5] == "dragon"){
                        printf("It has a %s,and it's morale is %.2f\n", WEAPON[IDENTIFIER%3].c_str(), (float)HEALTH/(float)health_to_cost);
                    }
                    else if (WARRIOR_SET[index%5] == "ninja"){
                        printf("It has a %s and a %s\n", WEAPON[IDENTIFIER%3].c_str(), WEAPON[(IDENTIFIER + 1)%3].c_str());
                    }
                    else if (WARRIOR_SET[index%5] == "iceman"){
                        printf("It has a %s\n", WEAPON[IDENTIFIER%3].c_str());
                    }
                    else if (WARRIOR_SET[index%5] == "lion"){
                        printf("It's loyalty is %d\n", HEALTH);
                    }
                    NOW_WARRIOR_INDEX = index+1;
                    IDENTIFIER ++;
                    return true;
                }
            }
            LOCK = true;
            annouce(-1);
            return false;
        }

        /**
         * Annouce the corrsponding message
        */
        void annouce(int index){
            if (LOCK == false && index >= 0){
                string warrior_name = WARRIOR_SET[index];
                printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
                TIME, NAME.c_str(), warrior_name.c_str(), IDENTIFIER, WARRIOR_HEALTH[warrior_name],
                NUM_WARRIOR[index], warrior_name.c_str(), NAME.c_str());
            }
            else{
                printf("%03d %s headquarter stops making warriors\n", 
                TIME, NAME.c_str());
            }
        }
};

int main(){
    int round, index = 1;
    int max_health;
    int default_health_set[5];
    cin >> round;
    while (index <= round){
        cin >> max_health;
        for (int i = 0; i < 5; i++){ 
            cin >> default_health_set[i];
            WARRIOR_HEALTH[DEFAULT_WARRIOR_SET[i]] = default_health_set[i];
        }
        printf("Case:%d\n", index);
        headquarter red("red", max_health, RED_WARRIOR_SET);
        headquarter blue("blue", max_health, BLUE_WARRIOR_SET);
        bool t = true;
        while(t){
            bool t1 = red.Warrior_Produce();
            bool t2 = blue.Warrior_Produce();
            t = t1 || t2;
            TIME ++;
        }
        TIME = 0;
        index ++;
    }
    return 0;
}