#include<iostream>
using namespace std;
class Student {
private:
	int num;
	char name[20];
public:
	static int total;//静态变量，放在public下
	Student() {
		total++;
	}
	~Student() {
		total--;
	}
	Student(int n, char *p = "wang");
	void GetName();
	int Getnum();
};
int Student::total= 0;//初始化total




Student::Student(int n, char* p) {
	num = n;
	strcpy(name, p);
	total++;
}
void Student::GetName() {
	cout << "the name  of Student is" << name << endl;
}
int Student::Getnum() {
	cout << "  the num of student is" << num << endl;
	return num;
}
int main() {
	cout << "the number of all students :" << Student::total << endl;
	//用类名调用静态对象，
	Student *p = new Student(13);
	cout << "The number of all students :" << Student::total << endl;
	cout << "The number of all students :" << p->total << endl;
	delete p;
	cout << "The numebr of all students :" << Student::total << endl;
	Student s[2];
	cout << "The numebr of all students :" << s[0].total << endl;
	cout << "The numebr of all students :" << s[1].total << endl;
	getchar();
	return 0;
	
}