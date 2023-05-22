#include<iostream>
#include<cstring>
using namespace std;
int a[3][3] = {0};
int tmp[3][3] = {0};
int movement[100] = {0};
bool llock = false;
inline void turn(int i, int j){tmp[i][j] = (tmp[i][j]+1)%4;}

void move(int sequence){
    switch(sequence){
        case 1: turn(0,0); turn(0,1); turn(1,0); turn(1,1); break;
        case 2: turn(0,0); turn(0,1); turn(0,2); break;
        case 3: turn(0,1); turn(0,2); turn(1,1); turn(1,2); break;
        case 4: turn(0,0); turn(1,0); turn(2,0); break;
        case 5: turn(0,1); turn(1,0); turn(1,1); turn(1,2); turn(2,1); break;
        case 6: turn(0,2); turn(1,2); turn(2,2); break;
        case 7: turn(1,0); turn(1,1); turn(2,0); turn(2,1); break;
        case 8: turn(2,0); turn(2,1); turn(2,2); break;
        case 9: turn(1,1); turn(1,2); turn(2,1); turn(2,2); break;
    }
}

bool check(int len){
    int t = 0;
    memcpy(tmp, a, sizeof(a));
    for(int i = 0; i < len; ++i)
        move(movement[i]);
    
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            t += tmp[i][j];
    if(t == 0) return true;
    return false;
}

void print(int len){
    for(int i = 0; i < len; ++i) cout << movement[i] << " ";
    cout << endl;
}

void generate(int start, int lowerBound, int len){
    if(start == len){
        if(check(len)){
            print(len);
            llock = true;
        }
        return ;
    } 
    for(int i = lowerBound; i < 10; ++i){
        movement[start] = i;
        generate(start+1, i, len);
    }
}

int main(){
    int i, j;
    for(i = 0; i < 3; ++i){
        for(j = 0; j < 3; ++j)
            cin >> a[i][j];
    }

    for(int i = 0; i < 1000; ++i){
        if(llock) break;
        generate(0, 1, i);
    }
    return 0;
}