#include<iostream>
#include<vector>
using namespace std;
vector<int> container;

vector<int>::iterator FindMin(vector<int>& container){
    vector<int>::iterator itr, res;
    int min = *container.begin();
    for(itr = container.begin(); itr != container.end(); ++itr){
        if(min >= *itr){ res = itr; min = *itr; }
    }
    return res;
} 

void Remove(vector<int>& container, int m){
    if(m == 0) return ;
    vector<int>::iterator minItr = FindMin(container);
    if(minItr == container.begin()){
        *(minItr+1) += *minItr;
        container.erase(minItr);
        Remove(container, m-1);
        return;
    }
    if(minItr == (container.end() - 1)){
        *(minItr - 1) += *minItr;
        container.erase(minItr);
        Remove(container, m-1);
        return;
    }
    if(*(minItr + 1) > *(minItr - 1)){
        *(minItr - 1) += *minItr;
        container.erase(minItr);
        Remove(container, m-1);
        return;
    }
    else{
        *(minItr + 1) += *minItr;
        container.erase(minItr);
        Remove(container, m-1);
        return;
    }
}

int main(){
    int L, N, M, i;
    cin >> L >> N >> M;
    int pre = 0, now;
    for(i = 0; i < N; ++i){
        cin >> now;
        container.push_back(now-pre);
        pre = now;
    }
    container.push_back(L - pre);

    Remove(container, M);
    cout << *FindMin(container) << endl;
    return 0;
}