#include "Person.h"
#include "Resource.h"
#include <string>

using std::string;

int main()
{
	//{
	//	Resource localResource("local");
	//	string localString = localResource.GetName();
	//}

	//Resource* pResource = new Resource("created with new");
	//string newString = pResource->GetName();
	//int j = 3;
	//delete pResource;
	//pResource = nullptr;
	//delete pResource;
	//delete pResource;

	Person Jack("Jack", "Huang", 123);
	Person Jack4("Jack4", "Huang", 123);
	Jack.AddResource();
	Jack.SetFirstName("Jack2");
	Jack.AddResource();
	Person Jack3 = Jack;
	Jack4 = Jack;
	//string string3 = pResource->GetName();

	return 0;
}
