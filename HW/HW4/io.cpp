#include<iostream>

class Complex {
    public:
        Complex(double a=0, double i=0):real(a),imag(i){}
        friend std::ostream& operator<<(std::ostream& os, Complex& c);
        friend std::istream& operator>>(std::istream& is, Complex& c);
    private:
        double real;
        double imag; 
};

std::istream& operator>>(std::istream& is, Complex& c){
    std::string tmp;
    short midIndex, endIndex;

    is >> tmp;
    if ((midIndex = tmp.find('+')) == std::string::npos){
        midIndex = tmp.find('-');
    }
    endIndex = tmp.find('i');

    c.real = stod(tmp.substr(0, midIndex)); 
    c.imag = stod(tmp.substr(midIndex+1, endIndex-midIndex-1));
    return is;
}

std::ostream& operator<<(std::ostream& os, Complex& c){
    std::cout << c.real << "+" << c.imag;
    return os;
}


int main(){
    Complex c;
    int n;
    std::cin >> c >> n;
    std::cout << c << "," << n << std::endl;
    return 0;
}