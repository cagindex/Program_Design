/**
 * 写出函数中缺失的部分，使得函数返回值为一个整数,该整数的第i位和m的第i位相同，其他位和n相同。
 * 请使用【一行代码】补全bitManipulation1函数使得程序能达到上述的功能
*/
#include <iostream>
using namespace std;

int bitManipulation1(int n, int m, int i) {
	return (n & (~(1 << i))) | ((1 << i) & m);
}

int main() {
	int n, m, i, t;
	cin >> t;
	while (t--) { 
		cin >> n >> m >> i;
		cout << bitManipulation1(n, m, i) << endl;
	}
	return 0;
}