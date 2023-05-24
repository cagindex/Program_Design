#include<iostream>
#include<cstring>
#include<map>
#include<iomanip>
using namespace std;


int main(){
    double a = 3.146;
    cout << fixed << setprecision(2) << a << endl;
    printf("%.2f\n", a);
    return 0;
}