#include<iostream>
#include<cstring>
#include<map>
#include<iomanip>
using namespace std;
class A{
    private:
        int a= 3;
    public:
        int& show(){return a;}
        int see(){return a;}
};

int main(){
    A a;
    int&  c = a.show(); 
    c = 4;
    cout << a.see() << endl;
    return 0;
}