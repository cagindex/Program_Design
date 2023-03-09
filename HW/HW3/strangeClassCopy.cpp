#include <iostream>
using namespace std;
class Sample {
    public:
        int v;
        Sample():v(0){}

        Sample(int n):v(n){}

        Sample(const Sample &a){
            v = a.v + 2;
        }
         

};
void PrintAndDouble(Sample o)
{
	cout << o.v;
	cout << endl;
}
/**
 * sample b = a;
 * sample b; b = a;
 * sample b = a;
 * 都是初始化函数，都是调用构造函数（无论是构造函数还是复制构造函数）
 * b = a;
 * b = 1;
 * 都是赋值函数，本质上都是bits的拷贝。但是后者会隐式的进行类型转换。
 * 赋值不等于初始化
*/
int main()
{
	Sample a(5);
	Sample b = a;
	PrintAndDouble(b);
	Sample c = 20;
	PrintAndDouble(c);
	Sample d;
	d = a;
	cout << d.v;
	return 0;
}