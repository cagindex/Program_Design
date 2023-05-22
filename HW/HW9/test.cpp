#include<iostream>

using namespace std;

int main(){
    string* tmp = new string[10];
    string* i = tmp;
    for(; i != tmp+10; ++i){
        cout << (i - tmp) << endl;
    }
    return 0;
}