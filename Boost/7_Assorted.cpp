#include "stdafx.h"

void token_demo()
{
	char_separator<char> sep("o", " ", keep_empty_tokens);
	string s = "To be, or not to be?";
	tokenizer<char_separator<char>> t(s, sep);
	for (string part : t)
	{
		cout << "<" << part << ">" << endl;
	}
}
int main(int argc, char* argv[])
{
	token_demo();

	getchar();
	return 0;
}