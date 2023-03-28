#include<iostream>
using namespace std;
class A{
    private:
        int AVal;
    public:
        A(int n):AVal(n){}
        virtual void print(){ cout << "A::Print" << endl;}
};

class B:public A{
    private:
        int BVal;
    public:
        B(int i):A(i),BVal(i){}
        void print(){ cout << "B::Print" << endl;}
};

int main(){
    B* b;
    A* a;
    b = new B(3);
    a = new B(3);

    a->print();
    b->print();
    return 0;
}