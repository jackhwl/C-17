// StlLibrary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main0()
{
	vector<int> v{ 2, 7, 1, 61, 2, -2, 4, 0 };

	int twos = 0;
	int const target = 2;
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i] == target) {
			twos++;
		}
	}

	twos = count(v.begin(), v.end(), target);
	twos = count(begin(v), end(v), target);
	twos = count_if(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });

	map<int, int> monthlengths{ {1,31}, {2,28},{3,31},{4,30},{5,31},{ 6,30 },{ 7,31 },{ 8,31 },{ 9,30 },{ 10,31 },{ 11,30 },{ 12,31 } };
	int longmonths = count_if(begin(monthlengths), end(monthlengths), [](auto elem) {return elem.second == 31; });

	bool allof, noneof, anyof;

	allof = all_of(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
	noneof = none_of(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
	anyof = any_of(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
	

    return 0;
}

