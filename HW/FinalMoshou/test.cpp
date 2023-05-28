#include<iostream>
#include<cstring>
#include<map>
#include<iomanip>
using namespace std;
class A{
    public:
        int a;
        A(int k):a(k){}
        A(const A& b){a = b.a;cout << "copy constructor called" << endl;}
        virtual void use() = 0;
        virtual void show() = 0;
        virtual A* Clone() = 0;
};

class B : public A{
    private :
        int x;
    public:
        B(int k, int _x):A(k),x(_x){}
        B(const B& other):A(other),x(other.x){}
        virtual void use(){x--;}
        virtual void show(){cout <<x << " " << a << endl;}
        virtual A* Clone(){
            A* p = new B(*this);
            return p;
        }
};

int main(){
    A* newp = new B(4,3);
    newp->show();
    newp->use();
    A* p = newp->Clone();
    p->show();
    return 0;
}