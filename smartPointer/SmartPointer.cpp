// smartPointer.cpp : Defines the entry point for the console application.
#include "Person.h"
#include "Resource.h"
#include <string>

using std::string;

int main()
{
	{
		Person Jack("Jack", "Huang", 123);
		Jack.AddResource();
		string s1 = Jack.GetResourceName();
		Jack.AddResource();
	}

	return 0;
}
