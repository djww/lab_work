#include <iostream>
#include "greet.h"
using namespace std;
void greet()
{
	char Name[20];
	cout << "please enter your name" << endl;
	cin.get(Name,19);
	cout << "Greetings:" << Name << endl;
}