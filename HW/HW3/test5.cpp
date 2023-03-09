#include<iostream>
using namespace std;

class machine {
    string material;

    public :
        void watch(){
            cout << "it looks clean tough...\n";
        }
};

class moblie : public machine {
    string battery;

    public :
        void phone(){
            cout << "Calling to your lover...\n";
        }
};

int main(){
    moblie vivo_50;
    vivo_50.watch();
    vivo_50.phone();
    return 0;
}