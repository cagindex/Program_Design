#include<iostream>
#include<cstring>
using namespace std;
class character;

class A{
    private:
        friend class character;
        int durity;
    public:
        A(int a):durity(a){}
        ~A(){cout << "A deleted" << endl;}
        void use(){durity--;}
};

class character{
    public:
        A** container;
        character()
        {
            container = new A*[3];
            for(int i = 0; i < 3; ++i)
            {
                container[i] = new A(i+1);
            }
        }
        void use(int index)
        {
            container[index]->use();
            if(container[index]->durity == 0)
            {
                delete container[index];
                container[index] = nullptr;
            } 
        }
};

int main(){
    character windy;
    windy.use(1);
    windy.use(1);
    return 0;
}