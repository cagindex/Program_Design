#include<iostream>
using namespace std;

class A{
    public:
        A(){}

    //string literal is const char[]
        A(const char a[]){
            int index = 0;
            while(a[index] != '\0'){
                cout << a[index++] << endl;
            }
        }
};

int main(){
    A a;
    a = "ass";
    return 0;
}