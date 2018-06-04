#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
	int a{ 4 }, b{ 5 };
	swap(a, b);

	vector<int> evens{ 2,4,6,8,10 };
	vector<int> odds{ 1,3,5,7,9 };

	auto v1 = evens;
	swap(v1[0], v1[1]);
	iter_swap(begin(v1), begin(v1) + 1);

	auto v2 = odds;
	swap(v1[0], v2[0]);
	iter_swap(begin(v1), find(begin(v2), end(v2), 5));

	v1 = evens;
	v2 = odds;
	swap_ranges(begin(v1), find(begin(v1), end(v1), 6), begin(v2));

	vector<int> tasks(6);
	iota(begin(tasks), end(tasks), 1);

	auto two = find(begin(tasks), end(tasks), 2);
	auto three = find(begin(tasks), end(tasks), 3);
	auto four = find(begin(tasks), end(tasks), 4);
	rotate(two, three, four + 1);

	vector<int> numbers(8);
	iota(begin(numbers), end(numbers), 1);
	auto selected = stable_partition(begin(numbers), end(numbers), [](int i) {return i % 2 != 0; });
	four = find(begin(numbers), end(numbers), 4);
	rotate(begin(numbers), selected, four);

	return 0;
}