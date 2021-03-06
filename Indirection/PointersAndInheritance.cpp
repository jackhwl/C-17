// Indirection.cpp : Defines the entry point for the console application.
#include "Person.h"
#include "Tweeter.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Person Jack("Jack", "Huang", 123);
	Person & rJack = Jack;
	Person* pJack = &Jack;

	Tweeter JackHuang("Jack", "Huang", 345, "@jackhwl");
	Person* pJackHuang = &JackHuang;
	Person& rpJackHuang = JackHuang;
	Tweeter& rtJackHuang = JackHuang;
	Tweeter* ptJackHuang = &JackHuang;

	cout << rJack.GetName() << endl;
	cout << pJack->GetName() << endl;
	cout << JackHuang.GetName() << endl;
	cout << rpJackHuang.GetName() << endl;
	cout << rtJackHuang.GetName() << endl;
	cout << pJackHuang->GetName() << endl;
	cout << ptJackHuang->GetName() << endl;

	Person* Someone = new Tweeter("Someone", "Else", 567, "@someone");
	cout << Someone->GetName() << endl;
	delete Someone;

    return 0;
}

