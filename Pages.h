#pragma once
#include "Date.h"
#include "Status.h"
#include <string>
#include <vector>
using namespace std;
class Friends;
class Pages {

	const string name_m;
	vector<Friends*> friends_m;
	vector<Status*> statuses_m;

public:
	Pages(const string name):name_m(name){ }
	~Pages()
	{
	}

	void addstatus(Status* data);
	
	const string getname();
	void getfriends(vector<string>& new1);
	void getallstatus();
	void getstatuses(vector<Status>& new1);
	void getallfans();
	void addfriend(Friends* data);
	void removefan(Friends* data);
	bool operator>(const Pages& other)const
	{
		return (this->friends_m.size() > other.friends_m.size());
	}
	void operator+=(Friends* other)
	{
		this->friends_m.push_back(other);
	}
	
};