#include <cstdlib>
#include <iostream>
using namespace std;
// int strlen(const char * s) 
// {	int i = 0;
// 	for(; s[i]; ++i);
// 	return i;
// }
// void strcpy(char * d,const char * s)
// {
// 	int i = 0;
// 	for( i = 0; s[i]; ++i)
// 		d[i] = s[i];
// 	d[i] = 0;
		
// }
// int strcmp(const char * s1,const char * s2)
// {
// 	for(int i = 0; s1[i] && s2[i] ; ++i) {
// 		if( s1[i] < s2[i] )
// 			return -1;
// 		else if( s1[i] > s2[i])
// 			return 1;
// 	}
// 	return 0;
// }
// void strcat(char * d,const char * s)
// {
// 	int len = strlen(d);
// 	strcpy(d+len,s);
// }
class MyString
{
// 在此处补充你的代码
    public:
        //Constructor
        MyString():p(new char[1]){p[0] = '\0';}
        MyString(const char* p_):p(new char[strlen(p_) + 1]){
            strcpy(p, p_);
        }
        //Copying constructor
        MyString(const MyString& m){
            p = new char[strlen(m.p) + 1];
            strcpy(p, m.p);
        }
        friend ostream& operator<<(ostream& os, const MyString& m){
            os << m.p;
			return os;
        }
		MyString& operator=(const MyString& m){
            p = new char[strlen(m.p) + 1];
            strcpy(p, m.p);
			return *this;
		}
		MyString& operator+(const MyString& m){
			char* new_p = new char[strlen(p) + strlen(m.p) + 1];
			strcpy(new_p, p);
			strcpy(new_p + strlen(p), m.p);
			MyString* res_p = new MyString(new_p);
			return *res_p;
		}
		char& operator[](int i){
			return p[i];
		}
		void operator+=(const MyString& m){
			// char* new_p = new char[strlen(p) + strlen(m.p) + 1];
			// strcpy(new_p, p);
			// strcpy(new_p + strlen(p), m.p);
			// delete[] p;
			// p = new_p;
			strcat(p, m.p);
		}
		friend MyString& operator+(const char* c, const MyString& m){
			MyString* res = new MyString(c);
			*res += m;
			return *res;
		}
		MyString& operator()(int start, int length){
			char* new_p = new char[strlen(p) - start + 1];
			strcpy(new_p, p + start);
			new_p[length] = '\0';
			MyString* res_p = new MyString(new_p);
			return *res_p;
		}

		bool operator<(const MyString& m){
			if (p[0] < m.p[0]){ return true; }
			return false;
		}
		bool operator==(const MyString& m){
			if (p[0] == m.p[0]){ return true; }
			return false;
		}
		bool operator>(const MyString& m){
			if (p[0] > m.p[0]){ return true; }
			return false;
		}

    private:
        char* p;
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}