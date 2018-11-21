
#include<iostream>
using namespace std;
#include"student.h"
const int N = 10;
void menu();
void OutputStu(const Student *array);
void InputStu( Student *array);
int SearchStu(const Student *array, char *na);
bool InsertStu(Student *array);
bool DeleteStu(Student *array, char *na);
int main()
{
	Student array[N];
	int choice;
	char na[20];
	do
	{
		menu();
		cout << "please input your choice:";
		cin >> choice;
		if (choice >= 0 && choice <= 5)
		
			switch (choice)
			{
			case 1:InputStu(array); break;
			case 2:
				cout << "Input the name searched" << endl;
				cin >> na;
				int i;
				i = SearchStu(array,na);
				if (i == N)
					cout << "Error...." << endl;
				else
					array[i].Display();
				break;
			case 3:  OutputStu(array); break;
			case 4:if (InsertStu(array))
				cout << "insert a pice of message successfully" << endl;
				  else
					  cout << "//||Fail||\\" << endl;
				  break;
			case 5:cout << "Input the name deleted :" << endl;
				cin >> na;
				if (DeleteStu(array, na))
					cout << "delete successfully" << endl;
				else
					cout << "//||Fail||\\" << endl;
				break;
			default:break;
			}
	} while (choice);
	return 0;
}
void menu()
{
	cout << "***************1.input  your message************" << endl;
	cout << "***************2.search your message************" << endl;
	cout << "***************3.Skim   your message************" << endl;
	cout << "***************4.insert your message************" << endl;
	cout << "***************5.delete your message************" << endl;
	cout << "***************0.    OVER          *************" << endl;
}
void OutputStu(const Student *array)
{
	cout << "the number of students=" << Student::GetCount() << endl;
	for (int i = 0; i < N; i++)
		if (array[i].GetAge())
			array[i].Display();
}
int SearchStu(const Student*array,char *na)
{
	int i, j = N;
	for(i=0;i<N;i++)
		if(array[i].GetAge())
			if(strcmp(array[i].GetName(),na)==0)
			{
				j = i;
				break;
			}
	return j;
}
void InputStu(Student*array)
{
	char ch;
	int i = 0;
	do
	{
		if (Student::GetCount() == N)
			cout << "full" << endl;
		if (!array[i].GetAge())
			array[i++].Input();
		cout << "can I input (Y or N)" << endl;
		cin >> ch;
	} while (ch == 'Y');
}
bool InsertStu(Student *array)
{
	if(Student::GetCount()==N)
	{
		cout << "Full" << endl;
		return false;
	}
	for (int i = 0; array[i].GetAge(); i++)
	   array[i].Insert();
	return true;
}
bool DeleteStu(Student *array, char *na)
{
	if(Student::GetCount()==0)
	{
		cout << "can't delete" << endl;
		return false;
	}
	int i = SearchStu(array, na);
	if(i==N)
	{
		cout << "can't delete" << endl;
		return false;
	}
	array[i].Delete();
	return true;
}