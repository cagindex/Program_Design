#include<iostream>
using namespace std;

class A{
    public :
        int val;
        A(int i){
            val = i;
        }

        int & GetObject(){
            int &a = val;
            return a;
        }

        int get(){
            return val;
        }
};

int main(){
    A a(1);
    A b(1);
    a.GetObject() = 2;
    a = A(1);
    cout << a.val << endl;
    cout << b.val << endl;
    return 0;
}