#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
    public:
        explicit CHugeInt(const char* s_){
            s = new char[strlen(s_) + 1];
            strcpy(s, s_);
        }
        explicit CHugeInt(int i){
            s = this->convertIntToChar(i);
        }

        char* add(const char* other) {
            int thisLen = strlen(s), otherLen = strlen(other);
            int len = ((thisLen > otherLen) ? thisLen : otherLen) + 2;
            char* p = new char[len];
            p[len - 1] = '\0';
            int index = 0, forward = 0;
            int s_, other_;
            while(len - 2 - index != -1){
                s_ = int(s[thisLen - 1 - index]) - 48; 
                other_ = int(other[otherLen - 1 - index]) - 48;

                if(index >= thisLen) {s_ = 0;}
                if(index >= otherLen) {other_ = 0;}
                p[len - 2 - index] = char((s_ + other_ + forward)%10) + 48; 
                forward = (s_ + other_ + forward) / 10;
                index ++;
            }
            if (p[0] == '0'){return p + 1;}
            return p;
        }

        char* convertIntToChar(int i) {
            char* p = new char[30];
            p[29] = '\0';
            if (i == 0){p[28] = char(48); p = p + 28; return p;}
            int len = 0;
            while(i){
                p[28 - len] = char(i%10 + 48);
                i = i/10;
                len ++;
            }
            return p + 29 - len;
        }

        CHugeInt& operator+(const CHugeInt& other){
            CHugeInt* p = new CHugeInt(add(other.s));
            return *p;
        }

        CHugeInt& operator+(int n){
            CHugeInt* p = new CHugeInt(add(convertIntToChar(n)));
            return *p;
        }

        friend CHugeInt& operator+(int n, CHugeInt& other){
            CHugeInt* p = new CHugeInt(other.add(other.convertIntToChar(n)));
            return *p;
        }

        void operator+=(int n){
            s = add(convertIntToChar(n));
        }

        CHugeInt& operator++(){
            s = add(convertIntToChar(1));
            return *this;
        }
        CHugeInt& operator++(int){
            CHugeInt* p = new CHugeInt(s);
            s = add(convertIntToChar(1));
            return *p;
        }

        friend ostream& operator<<(ostream& os, const CHugeInt& a){
            os << a.s;
            return os;
        }
    private:
        char* s;
};

int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}