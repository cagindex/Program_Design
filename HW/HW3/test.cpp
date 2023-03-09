#include<iostream>
using namespace std;

class A {
    public :
        int id;
        A(){
            id = 0;
            cout << "Constructor with no parameter called" << endl;
        }

        A (int i){
            id = i;
            cout << id << " Constructor called at: " << this << endl;
        }

        A (const A& a){
            id = a.id;
            cout << "Copy constructor called : " << "Origin : " << &a << " Dest: " << this << endl;
        }

        ~A(){
            cout << id << " Destructor called at : " << this << endl;
        }

        A &operator =(const A&a) {
            cout << "赋值函数" << endl;
            memcpy(this, &a, sizeof(A));
            return *this;
        }
        //Deep Copy
        void operator ==(const A&a){
            cout << "Deep copy\n";
            this->id = a.id;
        }
};

A fun(const A &a){
    return a;
}

int main(){
    A a, b;
    a = 1;
    b = A(10);
    fun(a);

    cout << "##############\n";

    A c,d,y;
    c = 1;
    d = y;

    A f = 3;
    A g = f;

    cout << "##############\n";
    return 0;
}
