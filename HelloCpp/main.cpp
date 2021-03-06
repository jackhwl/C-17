// HelloCpp.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cassert>
using namespace std;
#include "foo.h"
#include "../StaticLib/foo.h"
#include "../DynamicLib/DynamicLib.h"

#if ABC
void foo() {}
#endif

#define MUL(a,b) (a)*(b)
int main()
{
	assert(MUL(2, 2+2) == 8);

	foo();
	cout << "Hello, C++" << endl;
	cout << "2+1=" << add1(2) << endl;
	cout << "2+3=" << add(2, 3) << endl;
	cout << "2*3=" << multiply(2, 3) << endl;
	getchar();

    return 0;
}

