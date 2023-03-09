#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
    private:
        double r,i;
    public:
        void Print() {
            cout << r << "+" << i << "i" << endl;
        }

        Complex(){
            r = 0.0;
            i = 0.0;
        }
        Complex(const char num[]){
            int index = 0, index_ = 0;
            double res[2] = {};
            string buffer = "";
            while (num[index] != '\0'){
                if (num[index] == '+'){
                    res[index_++] = atof(buffer.c_str());
                    buffer = "";
                }
                buffer += num[index];
                index ++;
            }
            res[index_] = atof(buffer.c_str());

            r = res[0];
            i = res[1];
        }
};

int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}