#include<iostream>
#include<cmath>
#include<set>
using namespace std;

bool isPrime(int iVal){
    for (int i = 2; i <= sqrt((float)iVal); i++){
        if (iVal % i == 0)
            return false;
    }
    return true;
}
int count(int a){
    int sum = 0;
    int k = 0;
    for (int i = 2; i <= sqrt((float)a); i++){
        if (a % i == 0){
            k = a / i;
            if (i != k && isPrime(k))
                sum += 1;
            if (isPrime(i)){
                sum += 1;
            }
        }
    }
    return sum;
}

struct comp{
    bool operator()(const int& a1, const int& a2) const {
        int sum1 = count(a1);
        int sum2 = count(a2);

        if(sum1 < sum2){
            return true;
        }else if(sum1 == sum2){
            if(a1 < a2){
                return true;
            }
            return false;
        }
        else{
            return false;
        }
    }
};

typedef set<int, comp> mySet;
mySet sset;

int main(){
    int num, tmp;
    cin >> num;

    while(num--){
        for(int i = 0; i < 10; ++i){
            cin >> tmp;
            sset.insert(tmp);
        }
        int min = *(sset.begin());
        int max = *(sset.rbegin());
        sset.erase(min);
        sset.erase(max);
        cout << max << " " << min << endl;
    }
    return 0;
}