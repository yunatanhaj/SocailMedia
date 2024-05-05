#pragma once
#include "Date.h"
#include "Pages.h"
#include "Status.h"
#include <string>
#include <vector>
using namespace std;
class Friends {
	const string name_m;
	Date* birthdate_m;
	vector<Friends*> friends_m;
	vector<Pages*> pages_m;
	vector<Status*> statuses_m;
	
public:
	Friends(const string name,Date *date):name_m(name),birthdate_m(date){ }
	~Friends(){}
	void addstatus(Status* data);
	const string getname();
	int getnos();
	void getallstatus();
	void getallfriends();
	void getfriends(vector<string>& new1);
	void getstatuses(vector<Status>& new1);
	void getpages(vector<Pages>& new1);
	void addfanpage(Pages* page);
	void removefanpage(Pages* page);
	void removefriend(Friends* ptr);
	void addfriend(Friends* ptr);
	void show10status();
	Date& getdate()
	{
		return *(this->birthdate_m);
	}
	void operator+=(Friends* other)
	{
		this->friends_m.push_back(other);
	}
	bool operator>(const Friends& other)
	{
		return (this->friends_m.size() > other.friends_m.size());
	}
	
	
};