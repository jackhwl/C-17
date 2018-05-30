#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

int main() {
	vector<int> source{ 3, 6, 1, 0, -2, 5 };
	vector<int> v2(source.size());

	copy(begin(source), end(source), begin(v2));

	auto v3 = source;

	auto position = find(begin(source), end(source), 1);
	vector<int> v4(source.size());
	copy(begin(source), position, begin(v4));

	vector<int> v5(source.size());
	copy_if(begin(source), end(source), begin(v5), [](int elem) {return elem % 2 == 0; });

	copy_n(begin(v5), 3, begin(v2));

	copy(begin(source), position + 1, position + 1);

	copy_backward(begin(v3), end(v3), end(source));

	copy_backward(begin(source), end(source)-1, end(source));
	return 0;
}