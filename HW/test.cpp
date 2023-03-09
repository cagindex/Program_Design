/**
 * Global variable's value will be initilized to zero
 * whlie local variable won't
*/
#include<iostream>
using namespace std;


int *b;
int main(){
    int* a;
    int c = 123;
    cout << (void *) a << endl;
    // cout <<  *b << endl; Segmentation falut
    cout << (void *) b << endl;
    cout << sizeof(c) << endl;
    return 0;
}