#include "Person.h"
#include <iostream>

using namespace std;

using std::string;

Person::Person(string first, string last, int arbitrary) : firstname(first), lastname(last), arbitrarynumber(arbitrary)
{

}

string Person::GetName() const
{
	return firstname + " " + lastname;
}

void Person::AddResource()
{
	pResource.reset();
	pResource = std::make_shared<Resource>("Resource for " + GetName());
}
