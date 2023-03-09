#include <string>
#include <iostream>

class First {
    public:
    First(int someVal): a(someVal) {

    }
    int a;
};

class Second {
    public:
    First first;

    public:
    explicit Second(int input) : first(input) {}
    // Second()  {   // The other option would be to add default value as ": first(0)"
    //     first = First(123);

    // }
};

int main()
{
    Second second(123);
    std::cout << "hello" << second.first.a << std::endl;
}