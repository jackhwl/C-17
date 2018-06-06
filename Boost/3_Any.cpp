
#include "stdafx.h"

int main3(int argc, char* argv[])
{
	any w;
	any x{ 2.0 };
	vector<any> y{ 42, "life" };
	any z = string("test");

	if (!x.empty()) {
		cout << x.type().name() << endl;
	}

	int a = any_cast<int>(y[0]);
	cout << "The value is " << a << endl;
	try {
		int b = any_cast<int>(y[1]);
	}
	catch (const bad_any_cast& e) {
		cout << "wrong type " << endl;
	}

	for (any a : y) {
		int* value = any_cast<int>(&a);
		if (value != nullptr) {
			cout << *value << endl;
		}

		const char** text = any_cast<const char*>(&a);
		if (text != nullptr) {
			cout << *text << endl;
		}
	}

	getchar();
	return 0;
}