#include"4_03.h"
#include<iostream>
using namespace std;
int main()
{
	Circle c1(3.5), c2;
	cout << c1.Area() <<"   "<< c1.Circumference() << "   " << c1.GetRadius() <<"   "  << endl;
	double a = c2.GetRadius();
	cout << c2.Area() << "   "<<c2.Circumference() <<"    "<< c2.GetRadius() << endl;
	getchar();
	return 0;
}