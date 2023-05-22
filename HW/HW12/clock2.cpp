/**
因为由前三项就可以算出后面的步骤了
*/
#include<iostream>
#define LEN 9
using namespace std;
int clockclock[LEN];
int op[LEN];

int main(){
    int i, sum;
    for(i = 0; i < LEN; ++i)
        cin >> clockclock[i];
    
    for(op[0] = 0; op[0] < 4; ++op[0])
    for(op[1] = 0; op[1] < 4; ++op[1])
    for(op[2] = 0; op[2] < 4; ++op[2]){
        op[3] = (4 - (clockclock[0] + op[0] + op[1])%4)%4;
        op[4] = (4 - (clockclock[1] + op[0] + op[1] + op[2])%4)%4;
        op[5] = (4 - (clockclock[2] + op[1] + op[2])%4)%4;
        op[6] = (4 - (clockclock[3] + op[0] + op[3] + op[4])%4)%4;
        op[7] = (4 - (clockclock[6] + op[3] + op[6])%4)%4;
        op[8] = (4 - (clockclock[4] + op[0] + op[2] + op[4] + op[6])%4)%4;

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
