#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
template<class T1, class T2>
void MyForeach(T1* start, T1* end, T2 op){
    T1* i;
    for(i = start; i != end; ++i){
        op(*i);
    }
}

void Print(string s)
{
	cout << s;
}
void Inc(int & n)
{
	++ n;
}
string arr[100];
int a[100];
int main() {
	int m,n;
	while(cin >> m >> n) {
		for(int i = 0;i < m; ++i)
			cin >> arr[i];
		for(int j = 0; j < n; ++j)
			cin >> a[j];
		MyForeach(arr,arr+m,Print);		 
		cout << endl;
		MyForeach(a,a+n,Inc);		 
		for(int i = 0;i < n; ++i)
			cout << a[i] << ",";
		cout << endl;
	}
	return 0;
}