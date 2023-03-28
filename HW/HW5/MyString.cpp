#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }
// 在此处补充你的代码
    MyString(const MyString& other){
		//copy constructor
		if(other.p){
			p = new char[strlen(other.p) + 1];
			strcpy(p, other.p);
		}
		else{
			p = NULL;
		}
	}

	void Copy(const char* s){
		if (p) delete[] p;
		p = new char[strlen(s) + 1];
		strcpy(p, s);
	}

	friend ostream& operator<<(ostream& os, const MyString& s){
		os << s.p;
		return os;
	}

	MyString& operator=(const char* s){
		if(p) delete[] p;
		p = new char[strlen(s) + 1];
		strcpy(p, s);
		return *this;
	}

	MyString& operator=(const MyString& m){
		if(p) delete[] p;
		p = new char[strlen(m.p) + 1];
		strcpy(p, m.p);
		return *this;
	}
};
int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;
		
	}
}
