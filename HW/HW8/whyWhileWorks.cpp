#include <iostream>
using namespace std;
class MyCin
{
// 在此处补充你的代码
    private:
        bool value;
    public:
        MyCin():value(true){}
        operator bool(){return value;}
        MyCin& operator>> (int& i){
            cin >> i;
            if (i == -1){value = false;}
            return *this;
        }
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}