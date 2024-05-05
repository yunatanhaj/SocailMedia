#pragma once
#include "Friends.h"
#include "Pages.h"
#include <vector>
#include <string>
#include <fstream>
#define SIZE 3
class Parsofsefer {
	vector<Friends*> allfriends_m;
	vector<Pages*> allpages_m;
public:
	~Parsofsefer()
	{
		
		
	
	}
	Parsofsefer()
	{
		ifstream inFile("meda3.txt");
		int numberoffriends;
		int numberofpages;
		inFile >> numberoffriends;
		if (!inFile.eof())
		{
			Date* date = new Date(2002, 3, 3);
			Pages* page1 = new Pages("aas");

			Pages* page2 = new Pages("is");
			Pages* page3 = new Pages("you");
			Status* status1 = new Status(1, date, "hii", "0");
			Status* status2 = new Status(2, date, "bye", "0");
			Friends* friend1 = new Friends("dode", date);
			Friends* friend2 = new Friends("dode2", date);
			Friends* friend3 = new Friends("dode3", date);
			this->allfriends_m.push_back(friend1);	this->allfriends_m.push_back(friend2); this->allfriends_m.push_back(friend3);
			this->allpages_m.push_back(page1); this->allpages_m.push_back(page2); this->allpages_m.push_back(page3);
			page1->addstatus(status1);	page1->addstatus(status2); page2->addstatus(status1);	page2->addstatus(status2); page3->addstatus(status1);	page3->addstatus(status2);
			friend1->addstatus(status1); friend1->addstatus(status2); friend2->addstatus(status1); friend2->addstatus(status2); friend3->addstatus(status1); friend3->addstatus(status2);
			this->addfantopage("aas", "dode"); this->addfantopage("is", "dode2"); this->addfantopage("you", "dode3");
		}
		else{
		//	cout << "file is full";
		for (int i = 0; i < numberoffriends; i++)
		{
			string s;
			int day, month, year;
			getline(inFile,s);
			inFile >> day >> month >> year;
			Date* d = new Date(day, month, year);
			Friends* f = new Friends(s, d);
			this->allfriends_m.push_back(f);
		}
		
		inFile >> numberofpages;
		for (int i = 0; i < numberofpages; i++)
		{
			string s;
			getline(inFile, s);
			Pages* p = new Pages(s);
			this->allpages_m.push_back(p);
		}
		for (int i = 0; i < numberoffriends; i++)
		{
			string s;
			getline(inFile, s);
			int nof;
			inFile >> nof;
			string d;
			int ind;
			for (int j = 0; j < nof; j++)
			{
				getline(inFile, d);
				ind = this->findfbyname(d);
				this->allfriends_m[i]->addfriend(this->allfriends_m[ind]);
			}
		}
		for (int i = 0; i < numberofpages; i++)
		{
			string s;
			getline(inFile, s);
			int nof;
			inFile >> nof;
			string d;
			int ind;
			for (int j = 0; j < nof; j++)
			{
				getline(inFile, d);
				ind = this->findfbyname(d);
				this->allpages_m[i]->addfriend(this->allfriends_m[ind]);
			}
		}
		for (int i = 0; i < numberoffriends; i++)
		{
			int sizeofsttus;
			inFile >> sizeofsttus;
			for (int j = 0; j < sizeofsttus; j++)
			{
				string s, d;
				int hour, day, month,year;
				getline(inFile, s);
				inFile >> day >> month >> year;
				inFile >> hour;
				getline(inFile, d);
				Date* date = new Date(day, month, year);
				Status* status = new Status(hour, date, s, d);
				this->allfriends_m[i]->addstatus(status);
			}
		}
		for (int i = 0; i < numberofpages; i++)
		{
			int sizeofsttus;
			inFile >> sizeofsttus;
			for (int j = 0; j < sizeofsttus; j++)
			{
				string s, d;
				int hour, day, month, year;
				getline(inFile, s);
				inFile >> day >> month >> year;
				inFile >> hour;
				getline(inFile, d);
				Date* date = new Date(day, month, year);
				Status* status = new Status(hour, date, s, d);
				this->allpages_m[i]->addstatus(status);
			}
		}
		for (int i = 0; i < numberoffriends; i++)
		{
			int sizeofpages;
			inFile >> sizeofpages;
			for (int j = 0; j < sizeofpages; j++)
			{
				string s;
				getline(inFile, s);
				int ind = this->findpbyname(s);
				this->allfriends_m[i]->addfanpage(this->allpages_m[ind]);

			}
		}
		inFile.close();
	}
	}
	void addfriend(Friends* data);
	void addpage(Pages* data);
	void getallunrolled();
	int findfbyname(const string name);
	int findpbyname(const string name);
	void addfantopage(const string pagename,const string fanname);
	void removefanfrompage(string pagename, string fanname);
	void removefriend(string name1, string name2);
	void addftof(string name1, string name2);
	void show10status(string name);
	void run();
	void saveToFile();
	

};
