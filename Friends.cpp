#include "Friends.h"
#include <iostream>
#include <algorithm>
#define CURRENTSTATUSES 10
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

void Friends::getallstatus()
{

	for (int i = 0; i < this->statuses_m.size(); i++)
	{
		if(statuses_m[i]->getpathurl() == "0")
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
			strcpy_s(char_array, strlen(path.c_str()) + 1, path.c_str());
			system(char_array);
		}

	}
}
void Friends::getallfriends()
{
		for (int i = 0; i < this->friends_m.size(); i++)
			cout << this->friends_m[i]->getname() << endl;
		

}
void Friends::addfanpage(Pages* page) {

		this->pages_m.push_back(page);

}
void Friends::removefanpage(Pages* page)
{
	
	for (auto i = pages_m.begin(); i != pages_m.end(); i++)
	{
		if(page==*i)
		{
			pages_m.erase(i);
		}
		
	}


}
void Friends::removefriend(Friends* ptr)
{
	for (auto i = friends_m.begin(); i != friends_m.end(); i++)
	{
		if (ptr == *i)
		{
			friends_m.erase(i);
		}

	}

}
void Friends::addfriend(Friends* ptr)
{

		this->friends_m.push_back( ptr);
}

void Friends::show10status()
{
	int size = 0;
	vector<Status*> allstatus;
	for (int i = 0; i < this->friends_m.size(); i++)
	{
		for (int j = 0; j < this->friends_m[i]->statuses_m.size(); j++)
		{
			allstatus.push_back(this->friends_m[i]->statuses_m[j]);
			size++;
		}
	}
	sort(allstatus.begin(), allstatus.end());

	int max;
	if (size < CURRENTSTATUSES)max = size;
	else
		max = CURRENTSTATUSES;
	for (int i = 0; i < max; i++)
	{
		if (allstatus[i]->getpathurl() == "0")
			cout << allstatus[i]->getext() << endl;
		else
		{
			cout << allstatus[i]->getext() << endl;
			const string path = "start" + allstatus[i]->getpathurl();
			const int length = path.length();

			// declaring character array (+1 for null terminator)
			char* char_array = new char[length + 1];

			// copying the contents of the
			// string to char array
			strcpy_s(char_array, strlen(path.c_str()) + 1, path.c_str());
			system(char_array);
		}

	}
}
void Friends::addstatus(Status* data)
{
		this->statuses_m.push_back( data);
}
const string Friends:: getname()
{
	return this->name_m;
}
int Friends::getnos()
{
	return this->statuses_m.size();
}
void Friends::getfriends(vector<string>& new1)
{
	
	for (int i = 0; i < this->friends_m.size(); i++)
	{
		new1.push_back(this->friends_m[i]->getname());
	}

}
void Friends::getstatuses(vector<Status>& new1)
{
	for (int i = 0; i < this->statuses_m.size(); i++)
	{
		new1.push_back(*(this->statuses_m[i]));
	}
}
void Friends::getpages(vector<Pages>& new1)
{
	for (int i = 0; i < this->pages_m.size(); i++)
	{
		new1.push_back(*(this->pages_m[i]));
	}
}
