#include<iostream>
using namespace std;
int main(){
    int a, b, i, j;
    cin >> a >> b >> i >> j;
    int mask;
    if (i < j){
        mask = (-1 << i) & (~(-1 << (j+1)));
    }
    else{
        mask = (-1 << j) & (~(-1 << (i+1)));
    }

    printf("%x\n", mask);
    printf("0x%x 0x%x\n", a, b);
    printf("0x%x\n", 5871);
    cout << 0x1513 << endl;
    cout << ((a & ~mask) | (b&mask)) << endl;
    return 0;
}
