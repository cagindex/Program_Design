#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
    private :
        string info[7];
        float average_grade;
    
    public :
        void input(){
            int i, index = 0;
            string in, buffer;
            getline(cin, in);

            for(i = 0; i < in.length(); i++){
                if (in[i] == ','){
                    info[index] = buffer;
                    buffer = "";
                    index ++;
                    continue;
                }
                buffer += in[i];
            }
            info[index] = buffer;
        }

        void calculate(){
            int i, sum_grade = 0;
            for (i = 3; i < sizeof(info)/sizeof(string); i ++){
                sum_grade += stoi(info[i]);
            }
            average_grade = (float) sum_grade / 4;
        }

        void output(){
            cout << info[0] << "," << info[1] << "," << info[2] << "," ;
            cout << average_grade << endl;
        }
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}