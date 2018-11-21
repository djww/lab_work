#include"student.h"
int Student::count = 0;
Student::Student()
{
	name = NULL;
	age = 0;
}
Student::Student(char *na, char *id, char *num, char *spe, int ag)
{
	if (na)
	name = new char[strlen(na) + 1];
	strcpy(name, na);
	strcpy(ID, id);
	strcpy(number, num);
	strcpy(speciality, spe);
	age = ag;
	count++;
}
Student::Student(const Student &per)
{
	if(per.name)
	{
		name = new char[strlen(per.name) + 1];
		strcpy(name, per.name);
	}
	strcpy(name, per.name);
	strcpy(ID, per.ID);
	strcpy(number, per.number);
	strcpy(speciality, per.speciality);
	age = per.age;
	count++;
}
Student::~Student()
{
	cout << "disCon" << endl;
	if(name)
	{
		delete[]name;
		count--;
	}
}
char* Student::GetName()const
{
	return name;
}
char* Student::GetID()
{
	return ID;
}
int  Student::GetAge()const
{
	return age;
}
char* Student::Getspec()
{
	return speciality;
}
char* Student::GetNumber()
{
	return number;
}
void Student::Display()const
{
	cout << "*************************" << endl;
	cout << "  Name    : " << name << endl;
	cout << "    ID    : " << ID << endl;
	cout << " Number   : " << number << endl;
	cout << "speciality: " << speciality << endl;
	cout << "     age    : " << age << endl;
	cout << "*************************" << endl;
}
void Student::Input()
{
	char na[10];
	cout << "please input your name--" << endl;
	cin >> na;
	if (na)
		delete[]name;
	name = new char[strlen(na) + 1];
	strcpy(name, na);
	cout << "please input your id" << endl;
	cin >> ID;
	cout << "please input your number" << endl;
	cin >> number;
	cout << "please input your specality" << endl;
	cin >> speciality;
	cout << "please input your age" << endl;
	cin >> age;
	count++;
}
void Student::Insert()
{
	if (!age)
		Input();
}
void Student::Delete()
{
	age = 0;
	name = NULL;
	count--;
}
int Student::GetCount()
{
	return count;
}