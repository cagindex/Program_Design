/**
因为按的顺序不会对结果造成影响，
因为第一个按会对前一个造成影响，而且这个影响只有第一个按会造成
所以可以顺序贪心
但是对第一个需要考虑
*/
#include<iostream>
#include<cstring>
using namespace std;

inline void turn(char* llock, int index, int length){
    if(index >= length) return;
    if(llock[index] == '0') llock[index] = '1';
    else llock[index] = '0';
}

int check_first(char* tmp, const char* target, int length){
    int res = 0;
    turn(tmp, 0, length);
    turn(tmp, 1, length);
    res ++;
    for(int i = 0; i < length-1; ++i){
        if(tmp[i] != target[i]){
            turn(tmp, i, length);
            turn(tmp, i+1, length);
            turn(tmp, i+2, length);
            res ++;
        }
    }
    if(tmp[length-1] != target[length-1]) return -1;
    return res;
}

int check_second(char* tmp, const char* target, int length){
    int res = 0;
    for(int i = 0; i < length-1; ++i){
        if(tmp[i] != target[i]){
            turn(tmp, i, length);
            turn(tmp, i+1, length);
            turn(tmp, i+2, length);
            res ++;
        }
    }
    if(tmp[length-1] != target[length-1]) return -1;
    return res;
}
int check(char* origin, const char* target){
    int len = strlen(origin);
    int res1 = -1, res2 = -1;
    char* tmp = new char[50];
    memcpy(tmp, origin, len+1);
    res2 = check_first(tmp, target, len);
    memcpy(tmp, origin, len+1);
    res1 = check_second(tmp, target, len);

    if(res1 != -1 && res2 != -1) return (res1 > res2) ? res2 : res1;
    return res1 + res2 + 1;
}

int main(){
    char* origin = new char[50];
    char* target = new char[50];
    cin >> origin;
    cin >> target;
    int res = check(origin, target);
    if(res == -1) cout << "impossible" << endl;
    else cout << res << endl;
    return 0;
}