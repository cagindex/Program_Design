#include<iostream>
#include<map>
#define GET_SECOND(iter) (*iter).second
#define GET_FIRST(iter) (*iter).first
using namespace std;

typedef map<int, long long, less<int> > myMap;
myMap container;
myMap::iterator iter_myMap;
myMap::iterator iter_myMap_left;
myMap::iterator iter_myMap_right;

int main(){
    int rounds;
    int tmp_id, tmp_atk;
    int leftDis, rightDis;
    cin >> rounds;
    
    container.insert(myMap::value_type(1000000000, 1));
    while(rounds--){
        cin >> tmp_id >> tmp_atk;
        iter_myMap = (container.insert(myMap::value_type(tmp_atk, tmp_id))).first;
        if(iter_myMap == container.begin()){
            cout << tmp_id << " " << GET_SECOND(++iter_myMap) << endl;
            continue;
        }
        iter_myMap_left = ((--iter_myMap)++);
        iter_myMap_right = ((++iter_myMap)--);
        if(iter_myMap_right == container.end()){
            cout << tmp_id << " " << GET_SECOND(iter_myMap_left) << endl;
            continue;
        }
        leftDis = GET_FIRST(iter_myMap) - GET_FIRST(iter_myMap_left);
        rightDis = GET_FIRST(iter_myMap_right) - GET_FIRST(iter_myMap);
        if(rightDis < leftDis){
            cout << tmp_id << " " << GET_SECOND(iter_myMap_right) << endl;
            continue;
        }
        cout << tmp_id << " " << GET_SECOND(iter_myMap_left) << endl;
    }
    return 0;
}