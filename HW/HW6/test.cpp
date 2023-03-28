#include<iostream>
using namespace std;

class A{
    public:
        char* p;
        A(const char* p_):p(new char[strlen(p_) + 1]){
            strcpy(p, p_);
        }
        A(const A& a){
            p = new char[strlen(a.p) + 1];
            strcpy(p, a.p);
        }

        void operator+=(const A& a){
            char* new_p = new char[strlen(p) + strlen(a.p) + 1];
            strcpy(new_p, p);
            strcpy(new_p + strlen(p), a.p);
            delete[] p;
            p = new_p;
        }
};

char& f(char* p){
    return p[1];
}

int main(){
    // const char* p = "asdf";
    // char* pp = new char[strlen(p) + 1];
    // strcpy(pp, p);
    // f(pp) = 'D';
    // cout << pp << endl;
    A a1("asdfasdf");
    cout << a1.p << "\n";
    a1 += "aa";
    cout << a1.p << "\n";
    cout << endl;
    return 0;
}