
#include "stdafx.h"

class Player
{
	int numberOfGoals;
public:
	string name;
	Player(string name) : name(name) {
		numberOfGoals = 0;
	}
	signal<void(string, int)> Scores;
	void Score() {
		numberOfGoals++;
		Scores(name, numberOfGoals);
	}
};

void third() 
{
	cout << "third" << endl;
}
int main(int argc, char* argv[])
{
	signal<void()> s;
	s.connect(third);

	{
		auto c = s.connect(1, []() {cout << "first" << endl; });
		scoped_connection sc(c);
		s.connect(0, []() {cout << "second" << endl; });
		s();
	}

	cout << "========" << endl;
	s.disconnect(third);
	s();


	getchar();
	return 0;
}