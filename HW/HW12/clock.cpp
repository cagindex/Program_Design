/**
A 1 2 4
B 1 2 3 5
C 2 3 6
D 1 4 5 7
E 1 3 5 7 9
F 3 5 4 9
G 4 7 8
H 5 7 8
I 6 8 9
我们就按照时钟来看，这样可以避免无意义的延伸。
*/
#include<iostream>
using std::cout;
using std::cin;
#define LEN 9
int clockclock[LEN];
int op[LEN];

int main(){
    int i, sum;
    for(i = 0; i < LEN; i++)
        cin >> clockclock[i];
    
    for(op[0] = 0; op[0] < 4; ++op[0])
    for(op[1] = 0; op[1] < 4; ++op[1])
    for(op[2] = 0; op[2] < 4; ++op[2])
    for(op[3] = 0; op[3] < 4; ++op[3])
    for(op[4] = 0; op[4] < 4; ++op[4])
    for(op[5] = 0; op[5] < 4; ++op[5])
    for(op[6] = 0; op[6] < 4; ++op[6])
    for(op[7] = 0; op[7] < 4; ++op[7])
    for(op[8] = 0; op[8] < 4; ++op[8]){
        sum = 0;
        sum += (clockclock[0] + op[0] + op[1] + op[3])%4;
        sum += (clockclock[1] + op[0] + op[1] + op[2] + op[4])%4;
        sum += (clockclock[2] + op[1] + op[2] + op[5])%4;
        sum += (clockclock[3] + op[0] + op[3] + op[4] + op[6])%4;
        sum += (clockclock[4] + op[0] + op[2] + op[4] + op[6] + op[8])%4;
        sum += (clockclock[5] + op[2] + op[4] + op[5] + op[8])%4;
        sum += (clockclock[6] + op[3] + op[6] + op[7])%4;
        sum += (clockclock[7] + op[4] + op[6] + op[7] + op[8])%4;
        sum += (clockclock[8] + op[5] + op[7] + op[8])%4;
        if (sum == 0){
            for(i = 0; i < LEN; ++i)
                while(op[i] --)
                    cout << (i + 1) << " ";
            return 0;
        }
    }
    return 0;
}