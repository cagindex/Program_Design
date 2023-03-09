#include<iostream>
#include<cstring>
using namespace std;

// string a[5] = {};
// #define WARRIOR a

// int main(){
//     cout << WARRIOR[3] << endl;
//     return 0;
// }

// class son {
//     private:
//         int contain;
//     public:
//         son(int n):contain(n){}
// };

// class father{
//     private:
//         int a;
//     public :
//         father(int i):a(i){}

//         void produce_a_son(){
//             son u(2);
//             return ;
//         }

//         son* return_a_son(){
//             son* u = new son(3);
//             return u;
//         }
// };

void con(int a[]){
    int b[10];
    memcpy(b, a, 10*sizeof(int));
    cout << b[2] << endl;
}

int main(){
    string s = "adf";
    printf("%s\n", s.c_str());

    int a[10];
    for(int i = 0; i < sizeof(a)/sizeof(int); i++){
        cin >> a[i];
    }
    con(a);
    return 0;
}