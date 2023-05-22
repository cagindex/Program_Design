#include <iostream>
using namespace std;
// 在此处补充你的代码
//(define(f n) (lambda(x)(+ x n))) -> ((f 7) 9) -> f ()
template<class T1, class T2>
auto f(T1 a){
    return [a](T2 b) -> decltype(a + b){ return b + a; };
}

int main()
{
   cout << f<int,int>(7)(9) << endl;   //16
   cout << f<string,string> (" hello!")("world")  <<endl; // world hello!
   cout << f<char,string> ('!')("world") << endl;
   
   
   return 0;    //world!
}