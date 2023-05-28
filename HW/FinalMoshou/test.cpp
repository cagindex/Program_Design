#include<iostream>
#include<cstring>
#include<map>
#include<iomanip>
using namespace std;
class A{
    public:
        int a = 3;
        A(){}
        A(const A& b){cout << "copy constructor called" << endl;}
};
void innerChange(A* b){b->a = 4;}
void change(A b){innerChange(&b); cout << "this is b" << b.a << endl;}

int main(){
    A a;
    change(a);
    cout << a.a << endl;
    return 0;
}