#include <iostream>
#include <cstring>
using namespace std;

//区分& 和 &&!!!!!!!!
template <int bitNum>
struct MyBitset 
{
	char a[bitNum/8+1];
	MyBitset() { memset(a,0,sizeof(a));};
	void Set(int i,int v) {
		char & c = a[i/8];
		int bp = i % 8;
		if( v ) 
			c |= (1 << bp);
		else 
			c &= ~(1 << bp);
	}
// 在此处补充你的代码
    struct littleBit{
        char& c; int i;
        littleBit(char& cc, int ii):c(cc),i(ii){}
		inline void f(char& c, int i, int v){if(v) c|=(1<<i);else c&= ~(1<<i);}
        void operator=(int v){
			f(c, i, v);
        }
		littleBit operator=(const littleBit& lother){
			int v = ((lother.c >> lother.i) & 0x1);
			f(c, i, v);
			return *this;
		}
		friend ostream& operator<< (ostream& os, const littleBit& l){
			char tmp = l.c;
			os << ((tmp >> l.i) & 0x1);
			return os;
		}
    };
    littleBit operator[](int j){
        return littleBit(a[j/8], j%8);
    }

void Print() {
		for(int i = 0;i < bitNum; ++i) 
			cout << (*this) [i];
		cout << endl;
	}

};

int main()
{
	int n;
	int i,j,k,v;
	while( cin >>  n) {
		MyBitset<20> bs;
		for(int i = 0;i < n; ++i) {
			int t;
			cin >> t;
			bs.Set(t,1);
		}
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[j] = v;
		bs[i] = bs[j] = bs[k];
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		(bs[i] = bs[j]) = bs[k];
		bs.Print();
	}
	return 0;
}