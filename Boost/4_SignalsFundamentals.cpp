
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

int main4(int argc, char* argv[]) 
{
	Player p("John");
	
	auto c = p.Scores.connect([](string name, int count) {
		cout << "playe " << name << " has scored " << count << " goals already" << endl;
	});

	p.Score();
	p.Score();
	{
		shared_connection_block b(c);
		p.Score();
		p.Score();
	}
	p.Score();
	p.Score();
	p.Score();
	p.Score();

	getchar();
	return 0;
}