#include<iostream>
#include<set>
using namespace std;

int main(){
    const int SIZE = 7;
    int a[] = {3, 2, 5, 1, 3};
    multiset<int> mul(a, a+SIZE);
    multiset<int>::iterator iter_multiset = mul.begin();
    multiset<int>::iterator iter_multiset_tmp = iter_multiset;
    cout << *iter_multiset << " " << *iter_multiset_tmp << endl; 
    iter_multiset++;
    iter_multiset--;
    cout << *iter_multiset << " " << *iter_multiset_tmp << endl; 
    return 0;
}