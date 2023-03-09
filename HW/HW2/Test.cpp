#include<iostream>
using namespace std;

class student{
    private :
        string a[7];
    public :
        student(){
            cout << "Constructed with 0 parameters" << endl;
        }
        student(int i){
            cout << "Constructed with 1 parameters" << endl;
        }
        student(int i, int j){
            cout << "Constructed with 2 parameters" << endl;
        }
        student(const student &s){
            cout << "Copy construction called" << endl;
        }

        ~student(){
            cout << "Destuctor called" << endl;
        }
};

student test1func(student a[]){
    return student(1);
}
student test2func(student a){
    student ttt;
    return ttt;
}

int main(){
    cout << "test 1" << endl;
    student test1[3] = {1, student(2, 3), 3};

    cout << "test2" << endl;
    int a[3][2] = {{2, 3}};
    cout << a[2][1] << endl;

    cout << "test3" << endl;
    student tt(1);
    test1func(test1);
    test2func(tt);

    cout << "test4" << endl;
    student a1, a2;
    a1 = a2;

    cout << "test5" << endl;
    student* p = new student(1, 3);
    delete p;
    return 0;
}