#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
    public:
        Array2(){}
        Array2(int row_, int column_):p(new int*[row]), row(row_),column(column_){
            for (int j = 0; j < column; j++){
                p[j] = new int[column];
            }
        }

        Array2(const Array2& a){
            row = a.row;
            column = a.column;
            p = new int*[row];
            for (int j = 0; j < column; j++){
                p[j] = new int[column];
                memcpy(p[j], a.p[j], sizeof(int)*column);
            }
        }

        int* operator[](int i){
            return p[i];
        }
        int operator()(int i, int j){
            return p[i][j];
        }
    private:
        int row, column;
        int** p;
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
                cout << endl;
    }
    return 0;
}