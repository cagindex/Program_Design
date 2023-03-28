#include <iostream>
using namespace std;
int getByte(int x, int i){
    int mask = 0xff;
    return mask&(x >> (8*i));
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int x, i;
        cin >> x >> i;
        cout << getByte(x, i) << endl;
    }
    return 0;
}