#include <iostream>
using namespace std;
int gcd(int a, int b) { // 计算两个数的最大公约数
    return (!b) ? a : gcd(b, a % b);
}
class Fraction {
    int p, q;
public:
    Fraction(int x, int y = 1):p(x),q(y){}
    Fraction(){}
    int findMax(int a, int b){
        if (b > a) {int tmp = a; a = b; b = tmp;}
        if (a % b == 0){
            return b;
        }
        int tmp = a % b;
        return findMax(b, tmp);
    }
    friend istream& operator>>(istream& is, Fraction& f){
        int a, b, res;
        cin >> a >> b;
        res = f.findMax(a, b);
        f.p = a/res;
        f.q = b/res;
        return is;
    }
    Fraction operator*(const Fraction& f){
        int up = this->findMax(p, f.q);
        int down = this->findMax(q, f.p);
        int u = (p/up) * (f.p/down);
        int d = (q/down) * (f.q /up);
        return Fraction(u, d);
    }
    Fraction operator*(int a){
        return *this * Fraction(a);
    }
    friend ostream& operator<<(ostream& os, const Fraction& f){
        if (f.q == 1){os << f.p;}
        else{os << f.p << '/' << f.q;}
        return os;
    }
};

int main(){
    int testcases;
    cin >> testcases;
    while (testcases --) {
        Fraction a, b, two(2);
        cin >> a >> b;
        cout << a << " * " << b << " = " << a * b << endl;
        cout << "2 * " << a << " = " << two * a << endl;
        cout << b << " * 3 = " << b * 3 << endl;
    }
    return 0;
}