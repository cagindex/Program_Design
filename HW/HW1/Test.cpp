/**
 * There's huge difference between "" and '' in c++
 * 
 * When passing parameters between function the class will create a temporary instance,
 * thus feel free to change the data;
 * 
 * strcpy transform from const char* to char*
*/
#include<iostream>
using namespace std;

void Test(string a, string *b){
    a = "hhhh";
    *b = "hhhh";
}

int main(){
    string a = "Hello";
    string b = "Hello";
    string d = "18";
    string e[10];

    Test(a, &b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    char c[100];
    strcpy(c, a.data());
    cout << c << endl;

    int *i;
    i = (int *)d.data();
    printf("%x\n", *i);
    printf("%d\n", *i);
    cout << *i << endl;
    cout << atoi(d.data()) << endl;

    cout << sizeof(e) << endl;
    cout << sizeof(string)<<endl;

    char o[10];
    char *u;
    u = (char *) a.data();
    strcpy(o, a.data());
    cout << o << endl;

    cout << typeid(o).name() << " " << typeid(u).name() << endl;

    char myword[] = "hello";

    return 0;
}