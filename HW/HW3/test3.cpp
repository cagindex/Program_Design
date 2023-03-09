#include<iostream>
using namespace std;

class Base {
	public:
		int k;
		Base(int n):k(n) { }
};

class Big
{
	public:
        int v;
        Base b;

        Big():v(123){
            Base c = Base(1);
            b = c;
        }
};

int main(){
    Big a;
    cout << a.v << endl;
    return 0;
}