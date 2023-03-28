#include <iostream>
using namespace std;
int gcd(int x, int y){
	return x%y==0?y:gcd(y,x%y);
}
class Fraction
{
    int num, den;
public:
    Fraction(int n, int d=1):num(n),den(d){}

    Fraction(const Fraction& f):num(f.num),den(f.den){}
    friend ostream& operator<<(ostream& os, Fraction& f){
        os << f.num << '/' << f.den;
        return os;
    }
    Fraction& operator*=(const Fraction& f){
        num *= f.num;
        return *this;
    }
    Fraction& operator/=(const Fraction& f){
        num /= f.num;
        return *this;
    }
    Fraction operator*(Fraction& f){
        return Fraction(this->num*f.num, this->den*f.den);
    }
    Fraction operator/(Fraction& f){
        return Fraction(this->num*f.den, this->den*f.num);
    }
    Fraction& operator=(const Fraction& f){
        num = f.num; den = f.den;
        return *this;
    }
    operator float(){return (float)num / (float)den;}

// 在此处补充你的代码
};
 
int main() {
	int a,b,c;
	cin >> a >> b >> c;
    Fraction f(a, b), g(c);
	f *= g;
	cout << f << endl;
	f /= g;
	cout << f << endl;
	f = f * f;
	cout << f << endl;
	f = f / g;
	cout << f << endl;
	cout << (float) f << endl;
    return 0;
}