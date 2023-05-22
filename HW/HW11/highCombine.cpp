#include <iostream>
using namespace std;
// 在此处补充你的代码
template<class F1, class F2, class para>
auto combine(F1 f1, F2 f2){
    return [f1, f2](para n) -> decltype(f1(f1(n) + f2(n))) {return f1(f1(n) + f2(n));};
}

int main()
{
    auto Square = [] (double a) { return a * a; };
    auto Inc = [] (double a) { return a + 1; };
    cout << combine<decltype(Square),decltype(Inc),int>(Square,Inc)(3) << endl;
    cout << combine<decltype(Inc),decltype(Square),double>(Inc,Square)(2.5) << endl;

    return 0;
}