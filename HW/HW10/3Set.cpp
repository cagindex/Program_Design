#include<iostream>
#include<set>
using namespace std;

typedef multiset<int, less<int> > myMultiSet;
typedef set<int, less<int> > mySet;
myMultiSet container;
mySet recorder;

inline void ReadCommand(string& cmd){cin >> cmd;}

int ExcuteCommand(string& cmd){
    int x;
    cin >> x;
    if(cmd == "add"){
        // add container
        container.insert(x);
        // add recorder if it is the first add
        recorder.insert(x);
        // counting
        cout << container.count(x) << endl;
    }else if(cmd == "del"){
        // counting the x
        cout << container.count(x) << endl;
        // remove same elements in container
        container.erase(x);
    }else if(cmd == "ask"){
        // find the x added before or not
        if(recorder.find(x) != recorder.end()) cout << 1;
        else cout << 0;

        cout << " ";

        cout << container.count(x) << endl;
    }else{
        return 0;
    }
    return 1;
}

int main(){
    string cmd;
    int rounds, env = 1;
    cin >> rounds;

    while(rounds--){
        ReadCommand(cmd);
        if(!ExcuteCommand(cmd)){
            cerr << "no command" << endl;
            break;
        }
    }
    return 0;
}