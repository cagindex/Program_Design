#include<iostream>
#include<cstring>
#include<map>
#define KIND_NUM 5
using namespace std;

typedef string FLAG;
typedef string Weapon;

int TIME = 0;
map<string, int> warriors_health;
string RED[KIND_NUM] = {"iceman", "lion", "wolf", "ninja", "dragon"};
string BLUE[KIND_NUM] = {"lion", "dragon", "ninja", "iceman", "wolf"};
string DEFALUT[KIND_NUM] = {"dragon", "ninja", "iceman", "lion", "wolf"};
string WEAPON[3] = {"sword", "bomb", "arrow"};

class warrior{
    protected:
        FLAG property;
    public:
        int num;
        int HEALTH; 
        int ATK;

        warrior():num(0),HEALTH(0),ATK(0){}
        warrior(int num_, int HEALTH_, int ATK_, FLAG c):num(num_),HEALTH(HEALTH_),ATK(ATK_),property(c){}
};

class dragon:public warrior{
    public:
        Weapon weapon;
        float morale;
        dragon(int num_, int HEALTH_, int ATK_, int headHealth, FLAG c):warrior(num_, HEALTH_, ATK_, c){
            weapon = WEAPON[warrior::num % 3];
            morale = (float) headHealth / (float) warrior::HEALTH;
            printf("It has a %s,and it's morale is %.2f\n", weapon.c_str(), morale);
        }
};
class ninja:public warrior{
    public:
        Weapon weapon1;
        Weapon weapon2;
        ninja(int num_, int HEALTH_, int ATK_, FLAG c):warrior(num_, HEALTH_, ATK_, c){
            weapon1 = WEAPON[warrior::num % 3];
            weapon2 = WEAPON[(warrior::num + 1) % 3];
            printf("It has a %s and a %s\n", weapon1.c_str(), weapon2.c_str());
        }

};
class iceman:public warrior{
    public:
        Weapon weapon;
        iceman(int num_, int HEALTH_, int ATK_, FLAG c):warrior(num_, HEALTH_, ATK_, c){
            weapon = WEAPON[warrior::num % 3];
            printf("It has a %s\n", weapon.c_str());
        }

};
class lion:public warrior{
    public:
        int loyalty;
        lion(int num_, int HEALTH_, int ATK_, int headHealth, FLAG c):warrior(num_, HEALTH_, ATK_, c){
            loyalty = headHealth;
            printf("It's loyalty is %d\n", loyalty);
        }

};
class wolf:public warrior{
    public:
        wolf(int num_, int HEALTH_, int ATK_, FLAG c):warrior(num_, HEALTH_, ATK_, c){}
};

class headquarter{
    private:
        FLAG property;
        warrior** warriors_set;
        int warriors_len;
        int warriors_max;
        map<string, int> warrior_cnt;
        map<int, string> warrior_num;
        int index;
        bool LOCK;
    public:
        int HEALTH;

        headquarter(FLAG c, int h, const string * a, int str_len):HEALTH(h),property(c){
            index = 0;
            LOCK = false;
            warriors_len = 0;
            warriors_set = new warrior*[10];
            warriors_max = 10;

            for(int i = 0; i < str_len; i++){
                warrior_num[i] = a[i];
                warrior_cnt[a[i]] = 0;
            }
        }

        bool produce(){
            if (LOCK){return false;}

            int thisOne = chooseOne();
            string thisTime;
            if (thisOne == -1){
                thisTime = "";
            }
            else{
                thisTime = warrior_num[thisOne];
            }
            if (warriors_len == warriors_max) { expand_warriors_set(); }

            if (thisTime == "dragon"){
                warriors_len++;
                warrior_cnt[thisTime]++;

                printf("%03d %s dragon %d born with strength %d,%d dragon in %s headquarter\n",
                        TIME, property.c_str(), warriors_len , warriors_health[thisTime], 
                        warrior_cnt[thisTime], property.c_str());
                warriors_set[warriors_len] = new dragon(warriors_len, warriors_health[thisTime], 0, HEALTH, property); 
                return true;
            }
            else if (thisTime == "ninja"){
                warriors_len++;
                warrior_cnt[thisTime]++;
                printf("%03d %s ninja %d born with strength %d,%d ninja in %s headquarter\n",
                        TIME, property.c_str(), warriors_len, warriors_health[thisTime], 
                        warrior_cnt[thisTime], property.c_str());
                warriors_set[warriors_len] = new ninja(warriors_len, warriors_health[thisTime], 0, property); 
                return true;
            }
            else if (thisTime == "iceman"){
                warriors_len++;
                warrior_cnt[thisTime]++;
                printf("%03d %s iceman %d born with strength %d,%d iceman in %s headquarter\n",
                        TIME, property.c_str(), warriors_len, warriors_health[thisTime], 
                        warrior_cnt[thisTime], property.c_str());
                warriors_set[warriors_len] = new iceman(warriors_len, warriors_health[thisTime], 0, property); 
                return true;
            }
            else if (thisTime == "lion"){
                warriors_len++;
                warrior_cnt[thisTime]++;
                printf("%03d %s lion %d born with strength %d,%d lion in %s headquarter\n",
                        TIME, property.c_str(), warriors_len, warriors_health[thisTime], 
                        warrior_cnt[thisTime], property.c_str());
                warriors_set[warriors_len] = new lion(warriors_len, warriors_health[thisTime], 0, HEALTH, property); 
                return true;
            }
            else if (thisTime == "wolf"){
                warriors_len++;
                warrior_cnt[thisTime]++;
                printf("%03d %s wolf %d born with strength %d,%d wolf in %s headquarter\n",
                        TIME, property.c_str(), warriors_len, warriors_health[thisTime], 
                        warrior_cnt[thisTime], property.c_str());
                warriors_set[warriors_len] = new wolf(warriors_len, warriors_health[thisTime], 0, property); 
                return true;
            }
            else{
                LOCK = true;
                printf("%03d %s headquarter stops making warriors\n", TIME, property.c_str());
                return false;
            }
        }

        int chooseOne(){
            for(int i = index; i < index + KIND_NUM; i++){
                string thisOne = warrior_num[i%5];
                if((HEALTH - warriors_health[thisOne]) >= 0){
                    HEALTH -= warriors_health[thisOne];
                    index = (i+1)%5;
                    return i%5;
                }
            }
            return -1;
        }
        void expand_warriors_set(){
            warrior** new_p = new warrior*[warriors_max*2];
            memcpy(new_p, warriors_set, sizeof(warrior*)*warriors_max);
            warriors_max = warriors_max*2;
            delete[] warriors_set;
            warriors_set = new_p;
        }
};


int main(){
    int round, r = 0;
    int health, tmp;
    int res_red, res_blue;
    cin >> round;
    while (r < round){
        TIME = 0;
        cin >> health;
        for(int i = 0; i < KIND_NUM; i++){
            cin >> tmp;
            warriors_health[DEFALUT[i]] = tmp;
        }
        headquarter red("red", health, RED, KIND_NUM);
        headquarter blue("blue", health, BLUE, KIND_NUM);

        cout << "Case:" << r+1 << endl;
        while (1){
            res_red = red.produce();
            res_blue = blue.produce();
            if (!(res_red || res_blue)){break;}
            TIME ++;
        }

        r++;
    } 
}