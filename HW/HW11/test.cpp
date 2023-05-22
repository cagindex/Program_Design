#include<iostream>
using namespace std;

void PRINT(const void* p, int size){
    for (int i = 0; i < size; ++i){
        cout << hex << (int)*((char*)p + i) << " ";
    }
    cout << endl;
};

class A{
    public:
        int i;
        A(int k):i(k){}
    class B {
        public:
        int& a;
        int j;
        B(int& s, int i):j(i),a(s){}
        void operator=(int k){
            a = k;
        }
        B operator=(const B& otherb){
            a = otherb.j;
            j = otherb.j;
            return *this;
        }
    };
    B operator[](int j){
        return B(i, j);
    }
};

int main(){
    A a(1);
    cout << a.i << endl;
    a[9] = 3;
    cout << a.i << endl;
    a[2] = a[3] = a[4];
    cout << a.i << endl;
    return 0;
}