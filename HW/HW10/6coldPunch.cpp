#include<iostream>
#include<set>
#include<map>
using namespace std;

typedef set<int, less<int> > mySet;
typedef map<int, mySet> myMap;
myMap mmap;

int main(){
    int rounds;
    int id, atk;
    cin >> rounds;

    mmap[1000000000] = mySet();
    mmap[1000000000].insert(1);
    while(rounds--){
        cin >> id >> atk;
        if(mmap.count(atk) == 0){
            mmap[atk] = mySet();
            mmap[atk].insert(id);
            myMap::iterator iter = mmap.find(atk);
            if(iter == mmap.begin()){
                cout << id << " " << *(((*(++iter)).second).begin()) << endl;
            }
            else if (((++iter)--) == mmap.end()){
                cout << id << " " << *(((*(--iter)).second).begin()) << endl;
            }
            else{
                int id1 = *(((*(--iter)).second).begin());
                ++iter;
                int id2 = *(((*(++iter)).second).begin());
                --iter;
                int leftDis = abs(atk - (*(--iter)).first);
                ++iter;
                int rightDis = abs(atk - (*(++iter)).first);
                --iter;
                if(rightDis > leftDis){
                    cout << id << " " << id1 << endl;
                }
                else if(leftDis > rightDis){
                    cout << id << " " << id2 << endl;
                }
                else{
                    cout << id << " " << ((id1 > id2) ? id2 : id1) << endl;
                }
            }
            continue;
        }
        else{
            int res = *(mmap[atk].begin());
            mmap[atk].insert(id);
            if((*(mmap[atk].begin())) == id) res = *(++(mmap[atk].begin()));
            cout << id << " " << res << endl;
        }
    }
    return 0;
}