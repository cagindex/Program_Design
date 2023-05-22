#include<iostream>
using namespace std;
int Int = 3;

void AddInt(int*& ap){
    ap = &Int;
}

int main(){
    int* a;
    AddInt(a);
    cout << *a << endl;
    return 0;
}