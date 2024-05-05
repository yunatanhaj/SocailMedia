#include <iostream>
#include "Pages.h"
#include "Friends.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
void Pages::getallstatus()
{
	for (int i = 0; i < this->statuses_m.size(); i++)
	{
		if (statuses_m[i]->getpathurl() == "0")
			cout << this->statuses_m[i]->getext() << endl;
		else
		{
			cout << this->statuses_m[i]->getext() << endl;
			const string path = "start" + statuses_m[i]->getpathurl();
			const int length = path.length();

			// declaring character array (+1 for null terminator)
			char* char_array = new char[length + 1];

			// copying the contents of the
			// string to char array
			strcpy_s(char_array, strlen(path.c_str()) + 1,path.c_str());
			system(char_array);
		}
	}

}
void Pages::getallfans()
{

	for (int i = 0; i < this->friends_m.size(); i++)
		cout << this->friends_m[i]->getname() << endl;
	
}
void Pages::addfriend(Friends* data)
{
			this->friends_m.push_back(data);
}
void Pages::removefan(Friends* data)
{
	int startind;
	for (auto i =friends_m.begin() ; i != friends_m.end(); i++)
	{
		if (data == *i)
		{
			friends_m.erase(i);
		
		}
	}

}
void Pages::addstatus(Status* data)
{
			this->statuses_m.push_back(data);
}
const string Pages::getname()
{
	return this->name_m;
}
void Pages::getfriends(vector<string>& new1)
{
	
	for (int i = 0; i < this->friends_m.size(); i++)
	{
		new1.push_back(this->friends_m[i]->getname());
	}

}
void Pages::getstatuses(vector<Status>& new1)
{
	for (int i = 0; i < this->statuses_m.size(); i++)
	{
		new1.push_back(*(this->statuses_m[i]));
	}
}

