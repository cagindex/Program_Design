#include <stdio.h>
#include <iostream>
using namespace std;
class MyNum{
public:
    char C;
    MyNum(char c='0'): C(c) {}

    MyNum(const MyNum& m):C(m.C){}
    MyNum operator*(const MyNum& m){
        int res = ((int)C - 48)*((int)m.C - 48);
        return MyNum(char(res+48));
    }
    operator int(){ return (int)C - 48;}
};

int main() { 
    char m,n;
    cin >> m >>  n;
    MyNum n1(m), n2(n);
    MyNum n3;
    n3 = n1*n2;
    cout << int(n3) << endl;
    return 0;
}