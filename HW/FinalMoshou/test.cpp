#include<iostream>
#include<cstring>
#include<map>
#include<iomanip>
using namespace std;
class A{
    public:
        int a = 3;
        virtual void show(){cout << "this is A" << endl;}
};

class B : public A
{
    public:
        virtual void show()
        {
            [](int a){cout << "this is in B" << endl; cout << a << endl;}(1);
            cout << "this is B" << endl;
        }
};

int main(){
    A* a = new B();
    a->show();
    return 0;
}