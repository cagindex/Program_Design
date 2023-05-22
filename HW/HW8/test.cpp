#include<iostream>
using namespace std;

void get(istream& is, int& v){
    is >> v;
}

int main(){
    int n, m, c;
    get(cin, n);
    get(cin, m);
    get(cin, c);
    if (cin.peek() == '\n'){cout << "reach end" << endl;}
    cout << n << m << c << endl;
    return 0;
}