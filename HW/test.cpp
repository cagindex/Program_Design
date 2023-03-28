/**
 * Global variable's value will be initilized to zero
 * whlie local variable won't
*/
#include<iostream>
using namespace std;

int main(){
    string a;
    cin >> a;
    cout << (string::npos == a.find('+')) << "\n";
    cout << a << endl;
    return 0;
}