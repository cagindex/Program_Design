#include<iostream>
#include<cstring>
#include<map>
#define INTMAX 0x7fffffff
using std::cin;
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
 
gameMap* GAME;
int warrior_kind = 5;
std::map<int, string> warrior_set =
{
    {0, "dragon"}, {1, "ninja"}, {2, "iceman"}, {3, "lion"}, {4, "wolf"}
};
std::map<string, int> warrior_set_reverse =
{
    {"dragon", 0}, {"ninja", 1}, {"iceman", 2}, {"lion", 3}, {"wolf", 4}
};

/**
 * basic function declartion
*/
void BornReport(char flag, int id, double morale = 0.0, int loyalty = 0);
void AssignWarriorValue(warrior*, string&, string&, int&);
void AssignWeaponList(weapon*&, weapon**);
void CreateWeapon(warrior*, weapon*&, int);
void TransformWeaponReport(string&, string&, string&);
void UseArrowReport(warrior* user, warrior* other);
void UseBombReport(warrior* user, warrior* other);
char SimulateBattle(warrior* red_warrior, warrior* blue_warrior, baseCity* city);
int TellMeTheHour();
int TellMeTheMin();

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
        warrior(const warrior& other){id = other.id; health = other.health; atk = other.atk; flag = other.flag;}
        virtual ~warrior(){}
        void ChangeHealth(int i) {health += i;}
        void ChangeHealthTo(int h) {health = h;}
        int TellMeYourHealth(){return health;}
        bool CheckBomb(warrior* other_warrior, baseCity* this_city)
        {
            char winner;
            if (flag == 'R'){winner = SimulateBattle(this, other_warrior, this_city); if(winner == 'B') return true; else return false;}
            else{winner = SimulateBattle(other_warrior, this, this_city); if(winner == 'R') return true; else return false;}
        }
        void UseBomb(warrior*& other){other = nullptr;}
        virtual void ChangeLoyalty(int i) {}
        virtual bool IsNinja() {return false;}
        virtual bool IsIceman() {return false;}
        virtual bool IsDragon() {return false;}
        virtual bool IsLion() {return false;}
        virtual bool IsWolf() {return false;}
        virtual int TellMeYourLoyalty() {return 1;};
        virtual bool HasArrow() = 0;
        virtual bool HasBomb() = 0;
        virtual void UseArrow(warrior* other_warrior) = 0;
        virtual void ReportYourWeapon() = 0;
        virtual void Attack(warrior* other) = 0;
        virtual void FightBack(warrior* other) = 0;
        virtual void AddDis(){}
        virtual weapon** ShowMeYourWeapon() = 0;
        virtual void Yell(baseCity* city){}
        virtual void ResetDis(){}
        virtual void Rob(warrior* loser){}
        virtual double TellMeYourMorale(){return 0.0;}
        virtual void ChangeMorale(double i){}
        virtual int TellTheDis(){return 0;}
        virtual warrior* Clone() = 0;
        friend void CreateWeapon(warrior*, weapon*&, int);
        friend void AssignWarriorValue(warrior*, string&, string&, int&);
        friend class gameMap;
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
        int TellMeThePos() {return position;}
        virtual int TellMeTheHealth() = 0;
        virtual void ChangeHealth(int i) = 0;
        virtual int TellMeCityFlag() {return 0x1111;}
        virtual warrior*& GetTheOtherPosition() {return warrior_red;}
        virtual warrior* TellMeTheOtherPosition() {return warrior_red;}
        virtual int& TellMeNowIndex() {return position;}
        virtual int& GiveMeBuffFlag() {return position;}
        virtual int& GiveMeCityFlag() {return position;}
        virtual void AddEnemeyNum(){}
        virtual int TellMeEnemyNum(){return 0;}
        virtual char TellMeTheFlag() {return 'N';};
        virtual bool IsHeadquater() = 0;
        friend class gameMap;
};

//base class for sword arrow and bomb
class weapon
{
    protected:
        int atk;
    public:
        weapon(int _atk = 0):atk(_atk){}
        weapon(const weapon& other){atk = other.atk;}
        virtual ~weapon(){}
        int& GiveMeYourAtk() {return atk;}
        int CheckWeapon()
        {
            if(IsSword()) return 0;
            else if(IsArrow()) return 1;
            else if(IsBomb()) return 2;
            return 3;
        }
        virtual bool IsArrow() = 0;
        virtual bool IsSword() = 0;
        virtual bool IsBomb() = 0;
        virtual weapon* Clone() = 0;
        virtual int TellMeYourDurity() {return atk;}
        virtual void Attack(warrior* other_warrior) = 0;
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
            CreateWeapon(this, weapon_dragon, (_id+1)%3);
            BornReport(_f, _id, morale);
        }
        dragon(const dragon& other):warrior(other){
            morale = other.morale;
            if(other.weapon_dragon == nullptr) weapon_dragon = nullptr;
            else weapon_dragon = other.weapon_dragon->Clone();
        }
        virtual double TellMeYourMorale(){return morale;}
        virtual void ChangeMorale(double i){morale += i;}
        virtual bool IsDragon() {return true;};
        virtual bool HasArrow() {if(weapon_dragon != nullptr){if(weapon_dragon->IsArrow()) return true;}return false;}
        virtual bool HasBomb() {if(weapon_dragon != nullptr){if(weapon_dragon->IsBomb()) return true;} return false;}
        virtual void UseArrow(warrior* other_warrior)
        {
            if(weapon_dragon == nullptr) return;
            if(weapon_dragon->IsArrow())
            {
                weapon_dragon->Attack(other_warrior);
                if(weapon_dragon->TellMeYourDurity() == 0) weapon_dragon = nullptr;
            }
        }
        virtual void ReportYourWeapon()
        {
            int hour = TellMeTheHour(), min = TellMeTheMin();
            string f = ((flag == 'R') ? "red" : "blue");

            printf("%03d:%02d ", hour, min);
            if(weapon_dragon == nullptr){printf("%s dragon %d has no weapon\n", f.c_str(), id+1);}
            else if(weapon_dragon->IsArrow()){printf("%s dragon %d has arrow(%d)\n", f.c_str(), id+1, weapon_dragon->TellMeYourDurity());}
            else if(weapon_dragon->IsSword()){printf("%s dragon %d has sword(%d)\n", f.c_str(), id+1, weapon_dragon->GiveMeYourAtk());}
            else if(weapon_dragon->IsBomb()){printf("%s dragon %d has bomb\n", f.c_str(), id+1);}
        }
        virtual void Attack(warrior* other)
        {
            other->ChangeHealth(-1*atk);
            if(weapon_dragon != nullptr && weapon_dragon->IsSword()){
                weapon_dragon->Attack(other);
                if(weapon_dragon->GiveMeYourAtk() == 0) weapon_dragon = nullptr;
            }
        }
        virtual void FightBack(warrior* other)
        {
            other->ChangeHealth(-1*(atk/2));
            if(weapon_dragon != nullptr && weapon_dragon->IsSword()){
                weapon_dragon->Attack(other);
                if(weapon_dragon->GiveMeYourAtk() == 0) weapon_dragon = nullptr;
            }
        }
        virtual void Yell(baseCity* city){
            int hour = TellMeTheHour(), min = TellMeTheMin();
            string flag, name; int __id;
            AssignWarriorValue(this, flag, name, __id);
            printf("%03d:%02d %s %s %d yelled in city %d\n", hour, min, flag.c_str(), name.c_str(), __id+1, city->TellMeThePos());
        }
        virtual weapon** ShowMeYourWeapon(){
            weapon** res = new weapon*[3];
            for(int i = 0; i < 3; ++i) res[i] = nullptr;
            if(weapon_dragon != nullptr) AssignWeaponList(weapon_dragon, res);
            return res;
        }
        virtual warrior* Clone(){ warrior* p = new dragon(*this); return p;}
};

class ninja : public warrior
{
    private:
        weapon* weapon_ninja1;
        weapon* weapon_ninja2;
    public:
        ninja(char _f, int _id = 0, int _health = 0, int _atk = 0):warrior(_f, _id, _health, _atk)
        {
            CreateWeapon(this, weapon_ninja1, (_id+1)%3);
            CreateWeapon(this, weapon_ninja2, (_id+2)%3);
            BornReport(_f, _id);
        }
        ninja(const ninja& other):warrior(other){
            if(other.weapon_ninja1 == nullptr) weapon_ninja1 = nullptr;
            else weapon_ninja1 = other.weapon_ninja1->Clone();
            if(other.weapon_ninja2 == nullptr) weapon_ninja2 = nullptr;
            else weapon_ninja2 = other.weapon_ninja2->Clone();
        }
        virtual bool IsNinja() {return true;}
        virtual bool HasArrow() 
        {
            if(weapon_ninja1 != nullptr){if(weapon_ninja1->IsArrow()) return true;}
            if(weapon_ninja2 != nullptr){if(weapon_ninja2->IsArrow()) return true;}
            return false;
        }
        virtual bool HasBomb() 
        {
            if(weapon_ninja1 != nullptr){if(weapon_ninja1->IsBomb()) return true;}
            if(weapon_ninja2 != nullptr){if(weapon_ninja2->IsBomb()) return true;}
            return false;
        }
        virtual void UseArrow(warrior* other_warrior)
        {
            if(weapon_ninja1 != nullptr){
                if(weapon_ninja1->IsArrow()){
                    weapon_ninja1->Attack(other_warrior);
                    if(weapon_ninja1->TellMeYourDurity() == 0) weapon_ninja1 = nullptr;
                }
            }
            if(weapon_ninja2 != nullptr){
                if(weapon_ninja2->IsArrow()){
                    weapon_ninja2->Attack(other_warrior);
                    if(weapon_ninja2->TellMeYourDurity() == 0) weapon_ninja2 = nullptr;
                }
            }
        }
        virtual void ReportYourWeapon()
        {
            int hour = TellMeTheHour(), min = TellMeTheMin();
            string f = ((flag == 'R') ? "red" : "blue");
            string arrow = "", bomb = "", sword = "", tmp;
            auto Allocate = [&arrow, &bomb, &sword](weapon* this_weapon)->void
            {   
                if(this_weapon == nullptr) return;
                int tmp;
                switch(this_weapon->CheckWeapon())
                {
                    case 0: tmp = this_weapon->GiveMeYourAtk(); sword = ("sword(" + std::to_string(tmp) + ")");break; 
                    case 1: tmp = this_weapon->TellMeYourDurity(); arrow = ("arrow(" + std::to_string(tmp) + ")"); break;
                    case 2: bomb = "bomb";
                }
            };
            Allocate(weapon_ninja1);
            Allocate(weapon_ninja2);
            if(arrow.length() == 0 && bomb.length() == 0 && sword.length() == 0)
            {printf("%03d:%02d %s ninja %d has no weapon\n", hour, min, f.c_str(), id+1); return;}
            TransformWeaponReport(arrow, bomb, sword);
            tmp = arrow+bomb+sword;
            printf("%03d:%02d %s ninja %d has %s\n", hour, min, f.c_str(), id+1, tmp.c_str());
        }
        virtual void Attack(warrior* other)
        {
            other->ChangeHealth(-1*atk);
            if(weapon_ninja1 != nullptr && weapon_ninja1->IsSword()){
                weapon_ninja1->Attack(other);
                if(weapon_ninja1->GiveMeYourAtk() == 0) weapon_ninja1 = nullptr;
            }
            if(weapon_ninja2 != nullptr && weapon_ninja2->IsSword()){
                weapon_ninja2->Attack(other);
                if(weapon_ninja2->GiveMeYourAtk() == 0) weapon_ninja2 = nullptr;
            }
        }
        virtual void FightBack(warrior* other){}
        virtual weapon** ShowMeYourWeapon(){
            weapon** res = new weapon*[3];
            for(int i = 0; i < 3; ++i) res[i] = nullptr;
            if(weapon_ninja1 != nullptr) AssignWeaponList(weapon_ninja1, res);
            if(weapon_ninja2 != nullptr) AssignWeaponList(weapon_ninja2, res);
            return res;
        }
        virtual warrior* Clone(){ warrior* p = new ninja(*this); return p;}
};

class iceman : public warrior
{
    private:
        weapon* weapon_iceman;
        int Dis = 0;
    public:
        iceman(char _f, int _id = 0, int _health = 0, int _atk = 0):warrior(_f, _id, _health, _atk)
        {
            CreateWeapon(this, weapon_iceman, (_id+1)%3);
            BornReport(_f, _id);
        }
        iceman(const iceman& other):warrior(other){
            if(other.weapon_iceman == nullptr) weapon_iceman = nullptr;
            else weapon_iceman = other.weapon_iceman->Clone();
        }
        virtual bool IsIceman(){return true;}
        virtual void AddDis(){Dis++;}
        virtual void ResetDis(){Dis =0;}
        virtual int TellTheDis(){return Dis;}
        virtual bool HasArrow() {if(weapon_iceman != nullptr){if(weapon_iceman->IsArrow()) return true;} return false;}
        virtual bool HasBomb() {if(weapon_iceman != nullptr){if(weapon_iceman->IsBomb()) return true;} return false;}
        virtual void UseArrow(warrior* other_warrior)
        {
            if(weapon_iceman != nullptr){
                if(weapon_iceman->IsArrow()){
                    weapon_iceman->Attack(other_warrior);
                    if(weapon_iceman->TellMeYourDurity() == 0) weapon_iceman = nullptr;
                }
            }
        }
        virtual void ReportYourWeapon()
        {
            int hour = TellMeTheHour(), min = TellMeTheMin();
            string f = ((flag == 'R') ? "red" : "blue");

            printf("%03d:%02d ", hour, min);
            if(weapon_iceman == nullptr){printf("%s iceman %d has no weapon\n", f.c_str(), id+1);}
            else if(weapon_iceman->IsArrow()){printf("%s iceman %d has arrow(%d)\n", f.c_str(), id+1, weapon_iceman->TellMeYourDurity());}
            else if(weapon_iceman->IsSword()){printf("%s iceman %d has sword(%d)\n", f.c_str(), id+1, weapon_iceman->GiveMeYourAtk());}
            else if(weapon_iceman->IsBomb()){printf("%s iceman %d has bomb\n", f.c_str(), id+1);}
        }
        virtual void Attack(warrior* other)
        {
            other->ChangeHealth(-1*atk);
            if(weapon_iceman != nullptr && weapon_iceman->IsSword()){
                weapon_iceman->Attack(other);
                if(weapon_iceman->GiveMeYourAtk() == 0) weapon_iceman = nullptr;
            }
        }
        virtual void FightBack(warrior* other)
        {
            other->ChangeHealth(-1*(atk/2));
            if(weapon_iceman != nullptr && weapon_iceman->IsSword()){
                weapon_iceman->Attack(other);
                if(weapon_iceman->GiveMeYourAtk() == 0) weapon_iceman = nullptr;
            }
        }
        virtual weapon** ShowMeYourWeapon(){
            weapon** res = new weapon*[3];
            for(int i = 0; i < 3; ++i) res[i] = nullptr;
            if(weapon_iceman != nullptr) AssignWeaponList(weapon_iceman, res);
            return res;
        }
        virtual warrior* Clone(){warrior* p = new iceman(*this); return p;}
};

class lion : public warrior
{
    private:
        int loyalty;
    public:
        lion(char _f, int _id = 0, int _health = 0, int _atk = 0, int _loyalty = 0):warrior(_f, _id, _health, _atk),loyalty(_loyalty)
        {
            BornReport(_f, _id, 0.0, loyalty);
        }
        lion(const lion& other):warrior(other){loyalty = other.loyalty;}
        ~lion(){}
        virtual bool IsLion(){return true;}
        virtual int TellMeYourLoyalty() {return loyalty;}
        virtual void ChangeLoyalty(int i) {loyalty += i;}
        virtual bool HasArrow() {return false;}
        virtual bool HasBomb() {return false;}
        virtual void UseArrow(warrior* other_warrior){}
        virtual void ReportYourWeapon()
        {
            int hour = TellMeTheHour(), min = TellMeTheMin();
            string f = ((flag == 'R') ? "red" : "blue");
            printf("%03d:%02d %s lion %d has no weapon\n", hour, min, f.c_str(), id+1);
        }
        virtual void Attack(warrior* other){
            other->ChangeHealth(-1*atk);
        }
        virtual void FightBack(warrior* other){
            other->ChangeHealth(-1*(atk/2));
        }
        virtual weapon** ShowMeYourWeapon(){
            weapon** res = new weapon*[3];
            for(int i = 0; i < 3; ++i) res[i] = nullptr;
            return res;
        }

        virtual warrior* Clone(){warrior* p = new lion(*this); return p;}
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
        wolf(const wolf& other):warrior(other)
        {
            weapon_wolf = new weapon*[3];
            for(int i = 0; i < 3; ++i){
                if(other.weapon_wolf[i] == nullptr) weapon_wolf[i] = nullptr;
                else weapon_wolf[i] = other.weapon_wolf[i]->Clone();
            }
        }
        virtual bool IsWolf(){return true;}
        virtual bool HasArrow() {if(weapon_wolf[1] != nullptr) return true; return false;}
        virtual bool HasBomb() {if(weapon_wolf[2] != nullptr) return true; return false;}
        virtual void UseArrow(warrior* other_warrior)
        {
            if(weapon_wolf[1] != nullptr)
            {
                weapon_wolf[1]->Attack(other_warrior);
                if(weapon_wolf[1]->TellMeYourDurity() == 0) weapon_wolf[1] = nullptr;
            }
        }
        virtual void ReportYourWeapon()
        {
            int hour = TellMeTheHour(), min = TellMeTheMin();
            string f = ((flag == 'R') ? "red" : "blue");
            string arrow = "", bomb = "", sword = "", tmp;
            auto Allocate = [&arrow, &bomb, &sword](weapon* this_weapon)->void
            {   
                if(this_weapon == nullptr) return;
                int tmp;
                switch(this_weapon->CheckWeapon())
                {
                    case 0: tmp = this_weapon->GiveMeYourAtk(); sword = ("sword(" + std::to_string(tmp) + ")");break; 
                    case 1: tmp = this_weapon->TellMeYourDurity(); arrow = ("arrow(" + std::to_string(tmp) + ")"); break;
                    case 2: bomb = "bomb";
                }
            };
            for(int i = 0; i < 3; i++) Allocate(weapon_wolf[i]);
            if(arrow.length() == 0 && bomb.length() == 0 && sword.length() == 0)
            {printf("%03d:%02d %s wolf %d has no weapon\n", hour, min, f.c_str(), id+1);return;}
            TransformWeaponReport(arrow, bomb, sword);
            tmp = arrow+bomb+sword;
            printf("%03d:%02d %s wolf %d has %s\n", hour, min, f.c_str(), id+1, tmp.c_str());
        }
        virtual void Attack(warrior* other){
            other->ChangeHealth(-1*atk);
            if(weapon_wolf[0] != nullptr){
                weapon_wolf[0]->Attack(other);
                if(weapon_wolf[0]->GiveMeYourAtk() == 0) weapon_wolf[0] = nullptr;
            }
        }
        virtual void FightBack(warrior* other){
            other->ChangeHealth(-1*(atk/2));
            if(weapon_wolf[0] != nullptr){
                weapon_wolf[0]->Attack(other);
                if(weapon_wolf[0]->GiveMeYourAtk() == 0) weapon_wolf[0] = nullptr;
            }
        }
        virtual weapon** ShowMeYourWeapon(){
            weapon** res = new weapon*[3];
            for(int i = 0; i < 3; ++i)
                if(weapon_wolf[i] != nullptr) AssignWeaponList(weapon_wolf[i], res);
                else res[i] = nullptr;
            return res;
        }
        virtual void Rob(warrior* loser){
            weapon** weapon_loser = loser->ShowMeYourWeapon();
            for(int i = 0; i < 3; ++i){
                if(weapon_loser[i] != nullptr && weapon_wolf[i] == nullptr){
                    weapon_wolf[i] = weapon_loser[i];
                    weapon_loser[i] = nullptr;
                }
            }
        }
        virtual warrior* Clone(){warrior* p = new wolf(*this); return p;}
};

// city class
class city : public baseCity
{
    private:
        int city_health_round; // health produce for each round
        int city_flag = 0; // 0 for mid, -1 for red. 1 for blue
        int buff_flag = 0;
        int city_health = 0;
    public:
        city(int health_round, int _pos = 0):city_health_round(health_round),baseCity(_pos){}
        virtual int TellMeTheHealth() {return city_health;}
        virtual void ChangeHealth(int i) {city_health += i;}
        virtual bool IsHeadquater() {return false;}
        virtual int TellMeCityFlag() {return city_flag;}
        virtual int& GiveMeBuffFlag() {return buff_flag;}
        virtual int& GiveMeCityFlag() {return city_flag;}
};

// headquarter class for both side
class headquarter : public baseCity
{
    private:
        char flag;        
        int now_index = 0;
        int health;
        int enmey_warrior_num = 0;
        warrior* Other_warrior = nullptr;
    public:
        headquarter(char _f, int _health, int _pos = 0):baseCity(_pos),flag(_f),health(_health){}
        virtual void AddEnemeyNum(){enmey_warrior_num++;}
        virtual int TellMeEnemyNum(){return enmey_warrior_num;}
        virtual int TellMeTheHealth() {return health;}
        virtual void ChangeHealth(int i) {health += i;}
        virtual int& TellMeNowIndex() {return now_index;}
        virtual char TellMeTheFlag() {return flag; }
        virtual warrior*& GetTheOtherPosition() {return Other_warrior;}
        virtual warrior* TellMeTheOtherPosition() {return Other_warrior;}
        virtual bool IsHeadquater() {return true;}
};

// weapon class
class sword : public weapon
{
    public:
        sword(int _atk):weapon((int)(_atk/5)){}
        sword(const sword& other):weapon(other){}
        virtual bool IsSword() {return true;}
        virtual bool IsArrow() {return false;}
        virtual bool IsBomb() {return false;}
        virtual void Attack(warrior* other_warrior)
        {
            int& now_atk = GiveMeYourAtk();
            other_warrior->ChangeHealth(-1*now_atk);
            now_atk = now_atk*4/5;
        }
        virtual weapon* Clone(){weapon* p = new sword(*this); return p;}
};

class arrow : public weapon
{
    private:
        int durity;
    public:
        arrow(int __durity, int _atk):durity(__durity),weapon(_atk){}
        arrow(const arrow& other):weapon(other){durity = other.durity;}
        virtual bool IsArrow() {return true;}
        virtual bool IsSword() {return false;}
        virtual bool IsBomb() {return false;}
        virtual int TellMeYourDurity() {return durity;}
        virtual void Attack(warrior* other_warrior)
        {
            int& now_atk = GiveMeYourAtk();
            other_warrior->ChangeHealth(-1*now_atk);
            durity -= 1;
        }
        virtual weapon* Clone(){weapon* p = new arrow(*this); return p;}
};

class bomb : public weapon
{
    private:
        int durity = 1;
    public:
        bomb():weapon(INTMAX){}
        bomb(const bomb& other):weapon(other){durity = other.durity;}
        virtual bool IsArrow() {return false;}
        virtual bool IsSword() {return false;}
        virtual bool IsBomb() {return true;}
        virtual int TellMeYourDurity() {return durity;}
        virtual void Attack(warrior* other_warrior)
        {
            other_warrior->ChangeHealthTo(0);
            durity--;
        }
        virtual weapon* Clone(){weapon* p = new bomb(*this); return p;}
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
        bool game_end_lock = false;
        int M, N, R, K, T;// N -> city num; R arrow atk; k loyalty decrease; T game max time
        int arrow_durity = 3;
        int battle_bonus = 8;
        int city_health_round = 10;
        int redRoundHealth = 0, blueRoundHealth = 0;
        std::map<int, string> red_headquarter_warrior = 
        {
            {0, "iceman"}, {1, "lion"}, {2, "wolf"}, {3, "ninja"}, {4, "dragon"}
        };
        std::map<int, string> blue_headquarter_warrior =
        {
            {0, "lion"}, {1, "dragon"}, {2, "ninja"}, {3, "iceman"}, {4, "wolf"}
        };
        std::map<string, int> warrior_init_health; 
        std::map<string, int> warrior_init_atk;

        int hour = 0, min = 0;
        baseCity** citys;
    public:
        gameMap(int _M, int _N, int _R, int _K, int _T, int* _init_health, int* _init_atk, int _warrior_kind):
        M(_M),N(_N),R(_R),K(_K),T(_T)
        {
            int i;
            citys = new baseCity*[_N+2];
            for(i = 0; i <= _N+1; ++i)
            {
                if(i == 0) citys[i] = new headquarter('R', M, i);
                else if(i == _N+1) citys[i] = new headquarter('B', M, i);
                else citys[i] = new city(city_health_round, i);
            }
            for(i = 0; i < _warrior_kind; ++i)
            {
                warrior_init_health[warrior_set[i]] = _init_health[i];
                warrior_init_atk[warrior_set[i]] = _init_atk[i];
            }
        }

        // generate warriors
        void GenerateWarrior()
        {
            baseCity* this_city;
            //For Red Headquarter
            this_city = citys[0];
            int& now_index_red = this_city->TellMeNowIndex();
            if(this_city->TellMeTheHealth() - warrior_init_health[red_headquarter_warrior[now_index_red%5]] >= 0)
            {
                this_city->ChangeHealth(-warrior_init_health[red_headquarter_warrior[now_index_red%5]]);
                __GenerateWarrior(this_city, now_index_red);
                now_index_red++;
            }
            //For Blue Headquarter
            this_city = citys[N+1];
            int& now_index_blue = this_city->TellMeNowIndex();
            if(this_city->TellMeTheHealth() - warrior_init_health[blue_headquarter_warrior[now_index_blue%5]] >= 0)
            {
                this_city->ChangeHealth(-warrior_init_health[blue_headquarter_warrior[now_index_blue%5]]);
                __GenerateWarrior(this_city, now_index_blue);
                now_index_blue++;
            }
        }

        //Check lion to run
        void CheckRunningLion()
        {
            for(int i = 0; i <= N+1; ++i)
            {
                ClearLowLoyalLion(citys[i]);
            }
        }

        //All warriors move forward
        void MoveForward()
        {
            int i;
            //red warrior move first
            if(citys[N+1]->warrior_red != nullptr) move(citys[N+1]->GetTheOtherPosition(), citys[N]->warrior_red);
            else {move(citys[N+1]->warrior_red, citys[N]->warrior_red);}
            for(i = N; i > 0; --i)
                move(citys[i]->warrior_red, citys[i-1]->warrior_red);
            //blue warrior move then
            if(citys[0]->warrior_blue != nullptr) move(citys[0]->GetTheOtherPosition(), citys[1]->warrior_blue);
            else {move(citys[0]->warrior_blue, citys[1]->warrior_blue);}
            for(i = 1; i < N+1; ++i)
                move(citys[i]->warrior_blue, citys[i+1]->warrior_blue);
            //report situation last
            for(i = 0; i < N+2; ++i)
                MoveReport(citys[i]);
        }

        //City generate health
        void CityGenerateHealth()
        {
            for(int i = 1; i < N+1; ++i)
                citys[i]->ChangeHealth(city_health_round);
        }

        //warriors claim city health and give it back to headquarter
        void ClaimCityHealth()
        {
            int this_city_health;
            warrior* this_warrior = nullptr;
            for(int i = 1; i < N+1; ++i)
            {
                this_city_health = citys[i]->TellMeTheHealth();
                this_warrior = __CheckAlone(citys[i]);
                if(this_warrior != nullptr)
                {
                    citys[i]->ChangeHealth(-1*this_city_health);
                    if(this_warrior->flag == 'R') citys[0]->ChangeHealth(this_city_health);
                    else citys[N+1]->ChangeHealth(this_city_health);
                    EarnElementsReport(this_warrior, this_city_health);
                }
            }
        }

        //Give Arrow attack
        void ArrowAttack()
        {
            int i;
            int redArrow[N+2], blueArrow[N+2];
            for(i = 0; i < N+2; ++i){redArrow[i] = 0; blueArrow[i] = 0;}
            //For red
            for(i = N-1; i > 0; --i)
            {
                if(citys[i+1]->warrior_blue != nullptr && citys[i]->warrior_red != nullptr)
                    if(citys[i]->warrior_red->HasArrow())
                    {
                        citys[i]->warrior_red->UseArrow(citys[i+1]->warrior_blue);
                        redArrow[i] = 1;
                    }
            }
            //For blue
            for(i = 2; i < N+1; ++i)
            {
                if(citys[i-1]->warrior_red != nullptr && citys[i]->warrior_blue != nullptr)
                    if(citys[i]->warrior_blue->HasArrow())
                    {
                        citys[i]->warrior_blue->UseArrow(citys[i-1]->warrior_red);
                        blueArrow[i] = 1;
                    }
            }
            for(i = 0; i < N+2; ++i){
                if(redArrow[i] == 1){
                    UseArrowReport(citys[i]->warrior_red, citys[i+1]->warrior_blue);
                }
                if(blueArrow[i] == 1){
                    UseArrowReport(citys[i]->warrior_blue, citys[i-1]->warrior_red);
                }
            }
        }

        //Use bomb
        void UseBomb()
        {
            for(int i = 1; i < N+1; ++i)
            {
                if(citys[i]->warrior_red == nullptr || citys[i]->warrior_blue == nullptr) continue;
                if(citys[i]->warrior_red->HasBomb() && citys[i]->warrior_red->health > 0 && citys[i]->warrior_red->CheckBomb(citys[i]->warrior_blue, citys[i]))
                {
                    UseBombReport(citys[i]->warrior_red, citys[i]->warrior_blue);
                    citys[i]->warrior_red->UseBomb(citys[i]->warrior_blue);
                    citys[i]->warrior_red = nullptr;
                    continue;
                }
                if(citys[i]->warrior_blue->HasBomb() && citys[i]->warrior_blue->health > 0 && citys[i]->warrior_blue->CheckBomb(citys[i]->warrior_red, citys[i]))
                {
                    UseBombReport(citys[i]->warrior_blue, citys[i]->warrior_red);
                    citys[i]->warrior_blue->UseBomb(citys[i]->warrior_red);
                    citys[i]->warrior_blue = nullptr;
                    continue;
                }
            }
        }

        //battle start
        void StartBattle()
        {
            char res;
            int red_lion = 0, blue_lion = 0;
            int result[N+2];
            int loserLion[N+2];
            redRoundHealth = 0; blueRoundHealth = 0;
            for(int i = 0; i < N+2; ++i){result[i] = 0; loserLion[i] = 0;}
            for(int i = 1; i < N+1; ++i){
                result[i] = 0;
                if(citys[i]->warrior_red != nullptr && citys[i]->warrior_blue != nullptr){
                    if(citys[i]->warrior_red->IsLion()) red_lion = citys[i]->warrior_red->TellMeYourHealth();
                    if(citys[i]->warrior_blue->IsLion()) blue_lion = citys[i]->warrior_blue->TellMeYourHealth();
                    res = __StartBattle(citys[i]->warrior_red, citys[i]->warrior_blue, citys[i], 1);
                    if(res == 'R'){result[i] = -1; if(citys[i]->warrior_blue->IsLion()) loserLion[i] = (blue_lion < 0 ? 0 : blue_lion);}
                    else if(res == 'B'){result[i] = 1; if(citys[i]->warrior_red->IsLion()) loserLion[i] = (red_lion < 0 ? 0 : red_lion);}
                }
            }
            //give battle bonus and claim city health
            int headquarter_health;
            //red
            for(int i = N; i > 0; --i){
                if(result[i] == -1){
                    headquarter_health = citys[0]->TellMeTheHealth();
                    if(headquarter_health-battle_bonus >= 0){citys[0]->ChangeHealth(-1*battle_bonus);citys[i]->warrior_red->ChangeHealth(battle_bonus);}
                }
            }
            //blue
            for(int i = 1; i < N+1; ++i){
                if(result[i] == 1){
                    headquarter_health = citys[N+1]->TellMeTheHealth();
                    if(headquarter_health-battle_bonus >= 0){citys[N+1]->ChangeHealth(-1*battle_bonus);citys[i]->warrior_blue->ChangeHealth(battle_bonus);}
                }
            }

            citys[0]->ChangeHealth(redRoundHealth);
            citys[N+1]->ChangeHealth(blueRoundHealth);
            //claimcity
            // int city_health;
            for(int i = 1; i < N+1; ++i){
            //     if(citys[i]->warrior_red != nullptr && citys[i]->warrior_blue != nullptr){
            //         if(result[i] == 1){
            //             city_health = citys[i]->TellMeTheHealth();
            //             citys[i]->ChangeHealth(-1*city_health);
            //             citys[N+1]->ChangeHealth(city_health);
            //             EarnElementsReport(citys[i]->warrior_blue, city_health);
            //             AfterBattle(citys[i]->warrior_blue, citys[i]->warrior_red, citys[i], loserLion[i]);
            //         }
            //         else if(result[i] == -1){
            //             city_health = citys[i]->TellMeTheHealth();
            //             citys[i]->ChangeHealth(-1*city_health);
            //             citys[0]->ChangeHealth(city_health);
            //             EarnElementsReport(citys[i]->warrior_red, city_health);
            //             AfterBattle(citys[i]->warrior_red, citys[i]->warrior_blue, citys[i], loserLion[i]);
            //         }
            //         else{
            //             if(citys[i]->warrior_red->TellMeYourHealth() > 0 && citys[i]->warrior_blue->TellMeYourHealth() > 0){
            //                 if(CheckFirst(citys[i]))
            //                     AfterEqualBattle(citys[i]->warrior_red, citys[i]->warrior_blue, citys[i]);
            //                 else 
            //                     AfterEqualBattle(citys[i]->warrior_blue, citys[i]->warrior_red, citys[i]);
            //             }
            //         }
            //     }
                if(citys[i]->warrior_red != nullptr && citys[i]->warrior_red->TellMeYourHealth() <= 0){ citys[i]->warrior_red = nullptr;}
                if(citys[i]->warrior_blue != nullptr && citys[i]->warrior_blue->TellMeYourHealth() <= 0){ citys[i]->warrior_blue = nullptr;}
            }
        }

        //Headquarter report its health
        void HeadquarterReport()
        {
            printf("%03d:%02d %d elements in red headquarter\n", hour, min, citys[0]->TellMeTheHealth());
            printf("%03d:%02d %d elements in blue headquarter\n", hour, min, citys[N+1]->TellMeTheHealth());
        }

        //Warriors report their situation
        void WarriorsReport()
        {
            int i;
            for(i = 0; i < N+2; ++i) if(citys[i]->warrior_red != nullptr) citys[i]->warrior_red->ReportYourWeapon();
            for(i = 0; i < N+2; ++i) if(citys[i]->warrior_blue != nullptr) citys[i]->warrior_blue->ReportYourWeapon();
        }

        void StartGame()
        {
            while(true)
            {
                if(GameOver(hour,min)) break;
                GenerateWarrior();
                min += 5;
                if(GameOver(hour,min)) break;
                CheckRunningLion();
                min += 5;
                if(GameOver(hour,min)) break;
                MoveForward();
                min += 10;
                if(GameOver(hour,min)) break;
                CityGenerateHealth(); 
                min += 10;
                if(GameOver(hour,min)) break;
                ClaimCityHealth();
                min += 5;
                if(GameOver(hour,min)) break;
                ArrowAttack();
                min += 3;
                if(GameOver(hour,min)) break;
                UseBomb();
                min += 2;
                if(GameOver(hour,min)) break;
                StartBattle();
                min += 10;
                if(GameOver(hour,min)) break;
                HeadquarterReport();
                min += 5;
                if(GameOver(hour,min)) break;
                WarriorsReport();
                hour ++; min = 0;
            }
        }
        inline bool GameOver(int hour, int min){return ((60*hour + min) > T) || (game_end_lock);}

        /**
        Aid function
        */
        void __GenerateWarrior(baseCity* this_city, int& index)
        {
            char flag = this_city->TellMeTheFlag();
            string tmp_name;
            warrior** this_warrior;
            if(flag == 'R'){tmp_name = red_headquarter_warrior[index%warrior_kind]; this_warrior = &(this_city->warrior_red);}
            else {tmp_name = blue_headquarter_warrior[index%warrior_kind]; this_warrior = &(this_city->warrior_blue);}

            switch(warrior_set_reverse[tmp_name])
            {
                case 0: *this_warrior = new dragon(flag, index, warrior_init_health[tmp_name], warrior_init_atk[tmp_name], (double)(this_city->TellMeTheHealth())/(double)(warrior_init_health[tmp_name])); break;
                case 1: *this_warrior = new ninja(flag, index, warrior_init_health[tmp_name], warrior_init_atk[tmp_name]); break;
                case 2: *this_warrior = new iceman(flag, index, warrior_init_health[tmp_name], warrior_init_atk[tmp_name]); break;
                case 3: *this_warrior = new lion(flag, index, warrior_init_health[tmp_name], warrior_init_atk[tmp_name], this_city->TellMeTheHealth()); break;
                case 4: *this_warrior = new wolf(flag, index, warrior_init_health[tmp_name], warrior_init_atk[tmp_name]); break;
            }
        }

        void move(warrior*& dest, warrior*& sour){
            dest = sour; sour = nullptr;
            if(dest == nullptr) return;
            if(dest->IsIceman()){
                dest->AddDis();
                if(dest->TellTheDis() == 2){
                    int heal = dest->health;
                    dest->atk += 20;
                    if(heal - 9 > 0){dest->health -= 9;}
                    else{dest->health = 1;}
                    dest->ResetDis();
                }
            }
        }

        void MoveReport(baseCity* this_city)
        {
            string name;
            warrior* this_warrior;
            if(this_city->position != 0 && this_city->position != N+1)
            {
                if(this_city->warrior_red != nullptr)
                    __MoveReport(this_city->warrior_red, this_city);
                if(this_city->warrior_blue != nullptr)
                    __MoveReport(this_city->warrior_blue, this_city);
            }
            else if(this_city->position == 0)
            {
                if(this_city->GetTheOtherPosition() == nullptr)
                { 
                    if(this_city->warrior_blue != nullptr && this_city->TellMeEnemyNum() == 0){ 
                        this_city->AddEnemeyNum();
                        __MoveReportRed(this_city->warrior_blue);
                    }
                }
                else
                {
                    __MoveReportRed(this_city->TellMeTheOtherPosition());
                    printf("%03d:%02d red headquarter was taken\n", hour, min);
                    game_end_lock = true;
                }
            }
            else if(this_city->position == N+1)
            {
                if(this_city->GetTheOtherPosition() == nullptr)
                { 
                    if(this_city->warrior_red != nullptr && this_city->TellMeEnemyNum() == 0){
                        this_city->AddEnemeyNum();
                        __MoveReportBlue(this_city->warrior_red);
                    }
                }
                else
                {
                    __MoveReportBlue(this_city->TellMeTheOtherPosition());
                    printf("%03d:%02d blue headquarter was taken\n", hour, min);
                    game_end_lock = true;
                }
            }
        }
        void __MoveReport(warrior* this_warrior, baseCity* this_city)
        {
            string f, name; int id;
            AssignWarriorValue(this_warrior, f, name, id); id++;
            printf("%03d:%02d %s %s %d marched to city %d with %d elements and force %d\n",
            hour, min, f.c_str(), name.c_str(), id, this_city->position, this_warrior->health, this_warrior->atk);
        }
        inline void __MoveReportRed(warrior* this_warrior)
        {
            string name = blue_headquarter_warrior[(this_warrior->id)%warrior_kind];
            printf("%03d:%02d blue %s %d reached red headquarter with %d elements and force %d\n",
            hour, min, name.c_str(), (this_warrior->id)+1,  this_warrior->health, this_warrior->atk);
        }
        inline void __MoveReportBlue(warrior* this_warrior)
        {
            string name = red_headquarter_warrior[(this_warrior->id)%warrior_kind];
            printf("%03d:%02d red %s %d reached blue headquarter with %d elements and force %d\n",
            hour, min, name.c_str(), (this_warrior->id)+1, this_warrior->health, this_warrior->atk);
        }

        void ClearLowLoyalLion(baseCity* this_city)
        {
            if(this_city->warrior_red != nullptr && this_city->position != N+1)
            {
                if(this_city->warrior_red->IsLion())
                    if(this_city->warrior_red->TellMeYourLoyalty() <= 0)
                    {
                        LionRunReport("red", this_city->warrior_red->id);
                        this_city->warrior_red = nullptr;
                    }
            }
            if(this_city->warrior_blue != nullptr && this_city->position != 0)
            {
                if(this_city->warrior_blue->IsLion())
                    if(this_city->warrior_blue->TellMeYourLoyalty() <= 0)
                    {
                        LionRunReport("blue", this_city->warrior_blue->id);
                        this_city->warrior_blue = nullptr;
                    }
            }
        }
        inline void LionRunReport(string flag, int id)
        {
            printf("%03d:%02d %s lion %d ran away\n", hour, min, flag.c_str(), id+1);
        }

        warrior* __CheckAlone(baseCity* this_city)
        {
            if(this_city->warrior_red != nullptr && this_city->warrior_blue != nullptr) return nullptr;
            else if(this_city->warrior_red != nullptr) return this_city->warrior_red;
            else if(this_city->warrior_blue != nullptr) return this_city->warrior_blue;
            else return nullptr;
        }

        void EarnElementsReport(warrior* this_warrior, int earn_elements)
        {
            string name, f; int id;
            AssignWarriorValue(this_warrior, f, name, id);
            id++;
            printf("%03d:%02d %s %s %d earned %d elements for his headquarter\n", hour, min, f.c_str(), name.c_str(), id, earn_elements);
        }

        char SimulateBattle(warrior* red_warrior, warrior* blue_warrior, baseCity* city)
        {
            return __StartBattle(red_warrior->Clone(), blue_warrior->Clone(), city, 0);
        }

        bool CheckFirst(baseCity* city){
            if(city->TellMeCityFlag() == -1 || (city->TellMeCityFlag() == 0 && city->TellMeThePos() % 2 == 1))
                return true;
            return false;
        }

        char __StartBattle(warrior* red_warrior, warrior* blue_warrior, baseCity* city, bool reportValue)
        {
            if(red_warrior->TellMeYourHealth() <= 0 && blue_warrior->TellMeYourHealth() <= 0) {return '0';}
            if(red_warrior->TellMeYourHealth() <= 0){if(reportValue) AfterBattle(blue_warrior, red_warrior, city); return 'B';}
            if(blue_warrior->TellMeYourHealth() <= 0){if(reportValue) AfterBattle(red_warrior, blue_warrior, city); return 'R';}

            warrior *first_warrior, *next_warrior;
            if(CheckFirst(city)){first_warrior = red_warrior; next_warrior = blue_warrior;}
            else{first_warrior = blue_warrior; next_warrior = red_warrior;}
            int first_lion_hp = 0, next_lion_hp = 0;
            if(first_warrior->IsLion()) first_lion_hp = first_warrior->TellMeYourHealth();
            if(next_warrior->IsLion()) next_lion_hp = next_warrior->TellMeYourHealth();
            
            if(reportValue) FirstAttack(first_warrior, next_warrior, city);
            first_warrior->Attack(next_warrior);
            if(next_warrior->TellMeYourHealth() <= 0){if(reportValue){WarriorDie(next_warrior, city); AfterBattle(first_warrior, next_warrior, city, next_lion_hp);} return first_warrior->flag;}
            if(next_warrior->IsNinja()){if(reportValue){AfterEqualBattle(first_warrior, next_warrior, city);} return '0';}
            if(reportValue) NextAttack(next_warrior, first_warrior, city);
            next_warrior->FightBack(first_warrior);
            if(first_warrior->TellMeYourHealth() <= 0){if(reportValue){WarriorDie(first_warrior, city); AfterBattle(next_warrior, first_warrior, city, first_lion_hp);} return next_warrior->flag;}

            if(reportValue)
                AfterEqualBattle(first_warrior, next_warrior, city);
            return '0';
        }

        void AfterBattle(warrior* winner, warrior* loser, baseCity* city, int loser_lion_hp = 0)
        {
            string name, flag;int id;
            AssignWarriorValue(winner, flag, name, id);
            if(name == "wolf"){
                winner->Rob(loser);
            }
            else if(name == "dragon"){
                if(CheckFirst(city) && (flag == "red")){winner->ChangeMorale(0.2); if(winner->TellMeYourMorale()>0.8) winner->Yell(city);} 
                if((CheckFirst(city) == false) && (flag == "blue")){winner->ChangeMorale(0.2); if(winner->TellMeYourMorale()>0.8) winner->Yell(city);} 
            }
            if(loser->IsLion()){
                winner->ChangeHealth(loser_lion_hp);
            }

            int city_health = city->TellMeTheHealth();
            if(flag == "red"){city->ChangeHealth(-1*city_health); redRoundHealth += city_health; EarnElementsReport(winner, city_health);}
            else if(flag == "blue"){city->ChangeHealth(-1*city_health); blueRoundHealth += city_health; EarnElementsReport(winner, city_health);}
            
            int& buff_flag = city->GiveMeBuffFlag();
            int& city_flag = city->GiveMeCityFlag();
            if(buff_flag == 0){if(flag == "red") buff_flag = -1; else buff_flag = 1;}
            else if(buff_flag == -1){
                if(flag == "blue") buff_flag = 1;
                else{
                    if(city_flag != -1){
                        city_flag = -1;
                        RaiseFlagReport(city);
                    }
                }
            }
            else if(buff_flag == 1){
                if(flag == "red") buff_flag = -1;
                else{
                    if(city_flag != 1){
                        city_flag = 1;
                        RaiseFlagReport(city);
                    }
                }
            }
        }
        void RaiseFlagReport(baseCity* city){
            if(city->TellMeCityFlag() == -1) printf("%03d:%02d red flag raised in city %d\n", hour, min, city->TellMeThePos());
            else printf("%03d:%02d blue flag raised in city %d\n", hour, min, city->TellMeThePos()); 
        }
        void AfterEqualBattle(warrior* first_warrior, warrior* next_warrior, baseCity* city)
        {
            //for dragon
            if(first_warrior->IsDragon()){first_warrior->ChangeMorale(-0.2);
                if(first_warrior->TellMeYourMorale() > 0.8) first_warrior->Yell(city);
            }
            if(next_warrior->IsDragon()){next_warrior->ChangeMorale(-0.2);}
            //for lion
            if(first_warrior->IsLion()){first_warrior->ChangeLoyalty(-1*K);}
            if(next_warrior->IsLion()){next_warrior->ChangeLoyalty(-1*K);}
            //change city flag
            int& city_buff_flag = city->GiveMeBuffFlag();
            city_buff_flag = 0;
        }

        void FirstAttack(warrior* first_warrior, warrior* next_warrior, baseCity* city)
        {
            string first_name, next_name, first_flag, next_flag;
            int first_id, next_id;
            AssignWarriorValue(first_warrior, first_flag, first_name, first_id);
            AssignWarriorValue(next_warrior, next_flag, next_name, next_id);
            int pos = city->TellMeThePos();
            printf("%03d:%02d %s %s %d attacked %s %s %d in city %d with %d elements and force %d\n", hour, min,
                    first_flag.c_str(), first_name.c_str(), first_id+1,
                    next_flag.c_str(), next_name.c_str(), next_id+1,
                    city->position, first_warrior->health, first_warrior->atk);
        }
        void NextAttack(warrior* first_warrior, warrior* next_warrior, baseCity* city)
        {
            string first_name, next_name, first_flag, next_flag;
            int first_id, next_id;
            AssignWarriorValue(first_warrior, first_flag, first_name, first_id);
            AssignWarriorValue(next_warrior, next_flag, next_name, next_id);
            int pos = city->TellMeThePos();
            printf("%03d:%02d %s %s %d fought back against %s %s %d in city %d\n", hour, min,
                    first_flag.c_str(), first_name.c_str(), first_id+1,
                    next_flag.c_str(), next_name.c_str(), next_id+1, city->position);
        }
        void WarriorDie(warrior* this_warrior, baseCity* city)
        {
            string flag, name; int id;
            AssignWarriorValue(this_warrior, flag, name, id);
            printf("%03d:%02d %s %s %d was killed in city %d\n", hour, min, flag.c_str(), name.c_str(), id+1, city->TellMeThePos());
        }

        void AssignWarriorValue(warrior* this_warrior, string& flag, string& name, int& id)
        {
            id = this_warrior->id;
            if(this_warrior->flag == 'R'){name = (red_headquarter_warrior)[id%warrior_kind]; flag = "red";}
            if(this_warrior->flag == 'B'){name = (blue_headquarter_warrior)[id%warrior_kind]; flag = "blue";}
        }

        static void CreateWeapon(warrior* warrior_pointer, weapon*& weapon_pointer, int id)
        {
            switch(id)
            {
                case 0 : if(warrior_pointer->atk/5 == 0){weapon_pointer = nullptr;}else{weapon_pointer = new sword(warrior_pointer->atk);} break;
                case 1 : weapon_pointer = new bomb(); break;
                case 2 : weapon_pointer = new arrow(GAME->arrow_durity, GAME->R); break;
            }
        }

        inline int TellMeHour() {return hour;}
        inline int TellMeMin() {return min;}

        friend void BornReport(char flag, int id, double morale, int loyalty);
        friend void AssignWarriorValue(warrior*, string&, string&, int&); 
};

/**
some basic function
*/
void BornReport(char flag, int id, double morale, int loyalty)
{
    string name, f;
    if(flag == 'R'){name = (GAME->red_headquarter_warrior)[id%warrior_kind]; f = "red";}
    if(flag == 'B'){name = (GAME->blue_headquarter_warrior)[id%warrior_kind]; f = "blue";}
    printf("%03d:%02d %s %s %d born\n", GAME->hour, GAME->min, f.c_str(), name.c_str(), id+1);
    if(name == "dragon"){
        printf("Its morale is %.2lf\n", morale);
    }
    if(name == "lion")
        printf("Its loyalty is %d\n", loyalty);
}

void AssignWarriorValue(warrior* this_warrior, string& flag, string& name, int& id){GAME->AssignWarriorValue(this_warrior, flag, name, id);}

void CreateWeapon(warrior* warrior_pointer, weapon*& weapon_pointer, int id)
{
    gameMap::CreateWeapon(warrior_pointer, weapon_pointer, id);
}

void TransformWeaponReport(string& arrow, string& bomb, string& sword)
{
    if(arrow.length() != 0 && bomb.length() != 0) bomb = "," + bomb;
    if((arrow.length() != 0 || bomb.length() != 0) && sword.length() != 0) sword = "," + sword;
}

void UseArrowReport(warrior* user, warrior* other)
{
    int hour = TellMeTheHour(), min = TellMeTheMin(), id;
    string name, f;
    AssignWarriorValue(user, f, name, id);
    if(other->TellMeYourHealth() > 0){printf("%03d:%02d %s %s %d shot\n", hour, min, f.c_str(), name.c_str(), id+1);}
    else
    {
        string other_name, other_f;
        int other_id;
        AssignWarriorValue(other, other_f, other_name, other_id);
        printf("%03d:%02d %s %s %d shot and killed %s %s %d\n", hour, min, f.c_str(), name.c_str(), id+1, other_f.c_str(), other_name.c_str(), other_id + 1);
    }
}

void UseBombReport(warrior* user, warrior* other)
{

    int hour = TellMeTheHour(), min = TellMeTheMin();
    int user_id, other_id;
    string user_flag, user_name, other_flag, other_name;
    AssignWarriorValue(user, user_flag, user_name, user_id);
    AssignWarriorValue(other, other_flag, other_name, other_id);
    printf("%03d:%02d %s %s %d used a bomb and killed %s %s %d\n", hour, min, 
            user_flag.c_str(), user_name.c_str(), user_id + 1,
            other_flag.c_str(), other_name.c_str(), other_id + 1);
}

char SimulateBattle(warrior* red_warrior, warrior* blue_warrior, baseCity* city)
{
    return GAME->SimulateBattle(red_warrior, blue_warrior, city);
}

void AssignWeaponList(weapon*& this_weapon, weapon** res){
    if(this_weapon->IsSword()){res[0] = this_weapon; this_weapon = nullptr; return;}
    if(this_weapon->IsArrow()){res[1] = this_weapon; this_weapon = nullptr; return;}
    if(this_weapon->IsBomb()){res[2] = this_weapon; this_weapon = nullptr; return;}
}

int TellMeTheHour(){return GAME->TellMeHour();}
int TellMeTheMin(){return GAME->TellMeMin();}

int main(){
    int t, round = 1, i;
    int M, N, R, K, T;
    int init_health[warrior_kind];
    int init_atk[warrior_kind];
    cin >> t;
    while(round <= t)
    {
        cin >> M >> N >> R >> K >> T;
        printf("Case %d:\n", round++);
        for(i = 0; i < warrior_kind; ++i) cin >> init_health[i];
        for(i = 0; i < warrior_kind; ++i) cin >> init_atk[i];
        GAME = new gameMap(M, N, R, K, T, init_health, init_atk, warrior_kind);
        GAME->StartGame();
    }
    return 0;
}