#include<iostream>
#include<map>
#include<list>
using namespace std;

typedef list<int> mySet;
typedef map<int, mySet> myMap; 
myMap container;
myMap::iterator  iter_myMap;
mySet::iterator  iter_mySet;

string& ReadCommand(string& cmd){
    cin >> cmd;
    return cmd;
}

void ExcuteCommand(string& cmd, int& env){
    if(cmd == "new"){
        int id;
        cin >> id;
        iter_myMap = container.find(id);
        if(!(iter_myMap == container.end())){
            env = -2;
            return;
        }
        container[id] = mySet();
    }else if(cmd == "add"){
        int id, num;
        cin >> id >> num;
        iter_myMap = container.find(id);
        if(iter_myMap == container.end()){
            env = -3;
            return ;
        }
        container[id].push_back(num);
    }else if(cmd == "merge"){
        int id1, id2;
        cin >> id1 >> id2;
        if (id1 == id2){return ;} //这段没有写会memory limit exceed
        if((container.find(id1) == container.end()) || (container.find(id2) == container.end())){
            env = -4;
            return ;
        }
        iter_mySet = container[id2].begin();
        for(; iter_mySet != container[id2].end(); ++iter_mySet){
            container[id1].push_back(*iter_mySet);
        }
        container[id2].clear();
    }else if(cmd == "unique"){
        int id;
        cin >> id;
        iter_myMap = container.find(id);
        if(iter_myMap == container.end()){
            env = -5;
            return ;
        }
        container[id].sort();
        container[id].unique();
    }else if(cmd == "out"){
        int id;
        cin >> id;
        iter_myMap = container.find(id);
        if(iter_myMap == container.end()){
            env = -6;
            return ;
        }
        container[id].sort();
        for(iter_mySet = (*iter_myMap).second.begin(); iter_mySet != container[id].end(); ++iter_mySet){
            cout << (*iter_mySet) << " ";
        }
        cout << endl;
    }else{
        env = -1;
    }
    return ;
}


int main(){
    int rounds, env = 0;
    string cmd;

    cin >> rounds;
    while(rounds--){
        ReadCommand(cmd);
        ExcuteCommand(cmd, env);
        if (env == -1){ cerr << env <<  " Command Error!" << endl; break; }
        if (env == -2){ cerr << env << " New id has already exists!" << endl; break; }
        if (env == -3){ cerr << env << " Added id does not exists!" << endl; break; }
        if (env == -4){ cerr << env << " Input id does not exists!" << endl; break; }
        if (env == -5){ cerr << env << " Input id does not exists!" << endl; break; }
        if (env == -6){ cerr << env << " Input id does not exists!" << endl; break; }
    }
    return 0;
}