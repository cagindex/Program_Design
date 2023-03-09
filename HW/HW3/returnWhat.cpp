#include <iostream>
using namespace std;
class A {
public:
	int val;

    A():val(123){}
    A(int i):val(i){}
    int &GetObj(){
        return val;
    }

    //影试类型转换
    operator int() {
        return val;
    }
};

int main()
{
    int b = A(45).operator int();
    int c = A(45);
	int m,n;
	A a;
	cout << a.val << endl;
	while(cin >> m >> n) {
		a.GetObj() = m;
		cout << a.val << endl;
		a.GetObj() = A(n);
		cout << a.val<< endl;
	}
	return 0;
}