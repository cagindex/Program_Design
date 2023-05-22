#include<iostream>
#include<numeric>
#include<iomanip>
#define pi 3.141592653589793
using namespace std;
struct pai{
    double v;
    pai(int r = 0):v(pi*r*r){}
    int get(double each){return (int)(v/each);}
};

int Check(pai** set, int n, double each){
    int res = 0;
    for(int i = 0; i < n; ++i)
        res += set[i]->get(each);
    return res;
}

double Find(pai** set, int n, int frd, double lower, double upper){
    double mid = (lower+upper)/2;
    int tmp = Check(set, n, mid);
    if(upper - lower < 0.00001) return mid;
    if(tmp < frd) return Find(set, n, frd, lower, mid);
    else return Find(set, n, frd, mid, upper);
}

double op(double init, pai* i){
    return init + i->v;
}

double Get(pai** set, int n, int frd){
    double res = accumulate(set, set+n, 0.0, op);
    res = Find(set, n, frd, 0, res);
    return res;
}

int main(){
    int N, F, r;
    cin >> N >> F;
    pai** pai_set = new pai*[N]; 
    for(int i = 0; i < N; ++i){
        cin >> r;
        pai_set[i] = new pai(r);
    }
    double res = Get(pai_set, N, F+1);
    cout << fixed << setprecision(3) << res << endl;
    return 0;
}