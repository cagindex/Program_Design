#include<iostream>
using namespace std;

class id{
    private :
        int i;
    public :
        // Constructor
        id(int i_){
            i = i_;
            cout << i << " Constructor called" << " Position at: " << this << endl;
        }
        //Copy constructor
        id(const id &s){
            i = 2 + s.i;
            cout << "Copy called" << " New position: " << this << "Origin position: " << &s << endl;
        }
        //Destructor
        ~id(){
            cout << i << " Destructor called" << " Position at: " << this << endl;
        }
};

id ccc();

int main(){
    id a(1);
    a = ccc();
    return 0;
}

id ccc(){
    id b(10);
    return b;
}