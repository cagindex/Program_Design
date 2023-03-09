/**
 * int* p; Here p is a pointer
 * when applying * it means we want the value to which the pointer is pointing to
*/
#include<iostream>
using namespace std;

int a[3][4] = {};

int main(){
    cout << (uint64_t)(a + 1) - (uint64_t)(a) << endl;
    cout << (uint64_t)(&a + 1) - (uint64_t)(&a) << endl;
    cout << (uint64_t)(*a + 1) - (uint64_t)(*a) << endl;
    return 0;
}