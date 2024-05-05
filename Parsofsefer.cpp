#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <ctime>
#include "Parsofsefer.h"
#include <string>
#include <fstream>



using namespace std;
void Parsofsefer::getallunrolled()
{
	cout << "friends are: " << endl;
	for (int i = 0; i < this->allfriends_m.size(); i++)
		cout << this->allfriends_m[i]->getname() << endl;
	cout << "pages are: " << endl;
	for (int i = 0; i < this->allpages_m.size(); i++)
		cout << this->allpages_m[i]->getname() << endl;


}
int Parsofsefer::findfbyname(const string name)
{
	for (int i = 0; i < this->allfriends_m.size(); i++)
	{
		if (name == this->allfriends_m[i]->getname())
			return i;

	}
	return -1;
}
int Parsofsefer::findpbyname(const string name)
{
	for (int i = 0; i < this->allpages_m.size(); i++)
	{
		if (name == this->allpages_m[i]->getname())
			return i;

	}
	return -1;
}
void Parsofsefer::addfantopage(const string pagename,const string fanname)
{
	int indop = this->findpbyname(pagename);
	int indof = this->findfbyname(fanname);
	this->allpages_m[indop]->addfriend(this->allfriends_m[indof]);
	this->allfriends_m[indof]->addfanpage(this->allpages_m[indop]);
}
void Parsofsefer::removefanfrompage(string pagename, string fanname)
{
	int indop = this->findpbyname(pagename);
	int indof = this->findfbyname(fanname);
	this->allpages_m[indop]->removefan(this->allfriends_m[indof]);
	this->allfriends_m[indof]->removefanpage(this->allpages_m[indop]);
}
void Parsofsefer::removefriend(string name1, string name2)
{
	int ind1 = this->findfbyname(name1);
	int ind2 = this->findfbyname(name2);
	this->allfriends_m[ind1]->removefriend(this->allfriends_m[ind2]);
	this->allfriends_m[ind2]->removefriend(this->allfriends_m[ind1]);

}
void Parsofsefer::addftof(string name1, string name2)
{
	int ind1 = this->findfbyname(name1);
	int ind2 = this->findfbyname(name2);
	this->allfriends_m[ind1]->addfriend(this->allfriends_m[ind2]);
	this->allfriends_m[ind2]->addfriend(this->allfriends_m[ind1]);

}
void Parsofsefer::show10status(string name)
{
	int ind = this->findfbyname(name);
	this->allfriends_m[ind]->show10status();

}
void  Parsofsefer::addfriend(Friends* data)
{

			this->allfriends_m.push_back(data);
		
}

void  Parsofsefer::addpage(Pages* data)
{

			this->allpages_m.push_back(data); 
	

}
void Parsofsefer::run()
{
	int option;
	cout << "1-Add friend \n 2-Add page \n 3-Add Status for friend/page \n 4-Show all Status for friend/page \n 5-Show 10 current Status for friend \n 6-Add friend to friend \n 7-Remove link betwen friends \n 8-Add friend to page \n 9-Remove friend from page \n 10-Show all users \n 11-Show all friend for friend/page \n 12-Exit" << endl;
	cin >> option;
	bool flag = true;
	string nameofuser, nameofuser1;
	while (flag)
	{
		
		switch (option)
		{
			int i;
			
			int indoff;
		case 1:
		{
		
			cout << "Enter friend name : " << endl;
			string friendname;
			getline(cin>>ws,friendname);
			i = 0;
			while (i < this->allfriends_m.size())
			{
				while (friendname == this->allfriends_m[i]->getname())
				{
					cout << "this name already used " << endl;
					cout << "Enter friend name : " << endl;
					getline(cin>>ws, friendname);
					i = 0;
				}
				i++;
			}
			int year, month, day;
			cout << "Enter year of birth:" << endl;
			cin >> year;
			cout << "Enter month of birth:" << endl;
			cin >> month;
			cout << "Enter day of birth:" << endl;
			cin >> day;
			Date* birthday;
			while (month < 1 || month>12 || day > 31 || day < 1 || year < 1 || year>2022)
			{
				cout << "Invaild date!" << endl;
				cout << "Enter year of birth:" << endl;
				cin >> year;
				cout << "Enter month of birth:" << endl;
				cin >> month;
				cout << "Enter day of birth:" << endl;
				cin >> day;
			}
			
			birthday = new Date(year, month, day);
			Friends* f = new Friends(friendname, birthday);
			this->addfriend(f);
			cout << "Friend has been added" << endl;
		}
		break;
		case 2:
		{
			cout << "Enter page name : " << endl;
			string pagename;
			getline(cin>>ws, pagename);
			i = 0;
			while (i < this->allpages_m.size())
			{
				while (pagename== this->allfriends_m[i]->getname())
				{
					cout << "this name already used " << endl;
					cout << "Enter page name : " << endl;
					getline(cin>>ws, pagename);
					i = 0;
				}
				i++;
			}
			Pages* page = new Pages(pagename);
			this->addpage(page);
			cout << "Page has been added" << endl;
		}
		break;
		case 3:
		{
			int option2;
			cout << "1-Friend\n2-Page" << endl;
			cin >> option2;
			switch (option2)
			{
			case 1:
			{
				cout << "Write friend name: " << endl;
				getline(cin >> ws, nameofuser);
				while (this->findfbyname(nameofuser) == -1)
				{
					cout << "Invaild input!" << endl;
					cout << "Write friend name: " << endl;
					getline(cin >> ws, nameofuser);
				}
				indoff = this->findfbyname(nameofuser);
				string status;
				int tmp;
				cout << " 1 - Add text \n 2 - Add picture or video" << endl;
				cin >> tmp;
				switch (tmp)
				{
				case 1:
				{
					cout << "Write the status:" << endl;
					getline(cin >> ws, status);
					time_t now = time(0);
					tm* ltm = localtime(&now);
					Date* date = new Date(ltm->tm_year, ltm->tm_mon, ltm->tm_mday);
					Status* st = new Status(ltm->tm_hour, date, status, "0");
					this->allfriends_m[indoff]->addstatus(st);
				}
				break;
				case 2:
				{
					cout << "Write the status:" << endl;
					getline(cin >> ws, status);
					time_t now = time(0);
					tm* ltm = localtime(&now);
					Date* date = new Date(ltm->tm_year, ltm->tm_mon, ltm->tm_mday);
					string path;
					cout << "write the full path of the img or video" << endl;
					getline(cin >> ws, path);
					Status* st = new Status(ltm->tm_hour, date, status, path);
					this->allfriends_m[indoff]->addstatus(st);
				}
				break;
				default:break;

				}

			}
			break;
			case 2:
			{
				cout << "Write page name: " << endl;
				getline(cin >> ws, nameofuser);
				while (this->findpbyname(nameofuser) == -1)
				{
					cout << "Invaild input!" << endl;
					cout << "Write friend name: " << endl;
					getline(cin >> ws, nameofuser);
				}
				indoff = this->findpbyname(nameofuser);
				string status1;
				int tmp;
				cout << " 1 - Add text \n 2 - Add picture or video" << endl;
				cin >> tmp;
				switch (tmp)
				{
				case 1:
				{
					cout << "Write the status:" << endl;
					getline(cin >> ws, status1);
					time_t now = time(0);
					tm* ltm = localtime(&now);
					Date* date = new Date(ltm->tm_year, ltm->tm_mon, ltm->tm_mday);
					Status* st = new Status(ltm->tm_hour, date, status1, "0");
					this->allpages_m[indoff]->addstatus(st);
				}
				break;
				case 2:
				{
					cout << "Write the status:" << endl;
					getline(cin >> ws, status1);
					time_t now = time(0);
					tm* ltm = localtime(&now);
					Date* date = new Date(ltm->tm_year, ltm->tm_mon, ltm->tm_mday);
					string path;
					cout << "write the full path of the img or video" << endl;
					getline(cin >> ws, path);
					Status* st = new Status(ltm->tm_hour, date, status1, path);
					this->allpages_m[indoff]->addstatus(st);
				}
				break;
				default:break;
				}
			}
			}
		}
		break;
		case 4:
		{
			int option3;
			cout << "1-Friend\n2-Page" << endl;
			cin >> option3;
			switch (option3)
			{
			case 1:
			{
				cout << "Write friend name: " << endl;
				getline(cin >> ws, nameofuser);
				while (this->findfbyname(nameofuser) == -1)
				{
					cout << "Invaild input!" << endl;
					cout << "Write friend name: " << endl;
					getline(cin >> ws, nameofuser);
				}
				indoff = this->findfbyname(nameofuser);
				this->allfriends_m[indoff]->getallstatus();
			}
			break;
			case 2:
			{
				cout << "Write page name: " << endl;
				getline(cin >> ws, nameofuser);
				while (this->findpbyname(nameofuser) == -1)
				{
					cout << "Invaild input!" << endl;
					cout << "Write page name: " << endl;
					getline(cin >> ws, nameofuser);
				}
				indoff = this->findpbyname(nameofuser);
				this->allpages_m[indoff]->getallstatus();
			}
			break;
			default:break;
				
			}
		}
		break;
		case 5:
		{
			cout << "Write friend name: " << endl;
			getline(cin >> ws, nameofuser);
			while (this->findfbyname(nameofuser) == -1)
			{
				cout << "Invaild input!" << endl;
				cout << "Write friend name: " << endl;
				getline(cin >> ws, nameofuser);
			}
			indoff = this->findfbyname(nameofuser);
			this->allfriends_m[indoff]->show10status();
		}
		break;
		case 6:
		{
			cout << "Write first friend name: " << endl;
			getline(cin >> ws, nameofuser);
			while (this->findfbyname(nameofuser) == -1)
			{
				cout << "Invaild input!" << endl;
				cout << "Write first friend name: " << endl;
				getline(cin >> ws, nameofuser);
			}

			cout << "Write seconde friend name: " << endl;
			getline(cin >> ws, nameofuser1);
			while (this->findfbyname(nameofuser1) == -1)
			{
				cout << "Invaild input!" << endl;
				cout << "Write seconde friend name: " << endl;
				getline(cin >> ws, nameofuser);
			}
			if (nameofuser == nameofuser1)
			{
				cout << "Invaild command" << endl;
				cout << "1-Add friend \n 2-Add page \n 3-Add Status for friend/page \n 4-Show all Status for friend/page \n 5-Show 10 current Status for friend \n 6-Add friend to friend \n 7-Remove link betwen friends \n 8-Add friend to page \n 9-Remove friend from page \n 10-Show all users \n 11-Show all friend for friend/page \n 12-Exit" << endl;
				cin >> option;
				continue;
			}
			this->addftof(nameofuser, nameofuser1);
		}
		break;
		case 7:
		{
			cout << "Write first friend name: " << endl;
			getline(cin >> ws, nameofuser);
			while (this->findfbyname(nameofuser) == -1)
			{
				cout << "Invaild input!" << endl;
				cout << "Write first friend name: " << endl;
				getline(cin >> ws, nameofuser);
			}

			cout << "Write seconde friend name: " << endl;
			getline(cin >> ws, nameofuser1);
			while (this->findfbyname(nameofuser1) == -1)
			{
				cout << "Invaild input!" << endl;
				cout << "Write seconde friend name: " << endl;
				getline(cin >> ws, nameofuser);
			}
			if (nameofuser == nameofuser1)
			{
				cout << "Invaild command" << endl;
				cout << "1-Add friend \n 2-Add page \n 3-Add Status for friend/page \n 4-Show all Status for friend/page \n 5-Show 10 current Status for friend \n 6-Add friend to friend \n 7-Remove link betwen friends \n 8-Add friend to page \n 9-Remove friend from page \n 10-Show all users \n 11-Show all friend for friend/page \n 12-Exit" << endl;
				cin >> option;
				continue;
			}
			this->removefriend(nameofuser, nameofuser1);
		}
		break;
		case 8:
		{
			cout << "Write page name: " << endl;
			getline(cin>>ws, nameofuser);
			while (this->findpbyname(nameofuser) == -1)
			{
				cout << "Invaild input!" << endl;
				cout << "Write page name: " << endl;
				getline(cin >> ws, nameofuser);
			}
			cout << "Write friend name: " << endl;
			getline(cin>>ws, nameofuser1);
			while (this->findfbyname(nameofuser1) == -1)
			{
				cout << "Invaild input!" << endl;
				cout << "Write friend name: " << endl;
				getline(cin >> ws, nameofuser1);
			}
			this->addfantopage(nameofuser, nameofuser1);
		}
		break;
		case 9:
		{
			cout << "Write page name: " << endl;
			getline(cin >> ws, nameofuser);
			while (this->findpbyname(nameofuser) == -1)
			{
				cout << "Invaild input!" << endl;
				cout << "Write page name: " << endl;
				getline(cin >> ws, nameofuser);
			}
			cout << "Write friend name: " << endl;
			getline(cin >> ws, nameofuser1);
			while (this->findfbyname(nameofuser1) == -1)
			{
				cout << "Invaild input!" << endl;
				cout << "Write friend name: " << endl;
				getline(cin >> ws, nameofuser1);
			}
			this->removefanfrompage(nameofuser, nameofuser1);
		}
		break;
		case 10:
		{
			this->getallunrolled();
		}
		break;
		case 11:
		{
			
			int option4;
			cout << "1-Friend\n2-Page" << endl;
			cin >> option4;
			switch (option4)
			{
			case 1:
			{
				cout << "Write friend name: " << endl;
				getline(cin >> ws, nameofuser);
				while (this->findfbyname(nameofuser) == -1)
				{
					cout << "Invaild input!" << endl;
					cout << "Write friend name: " << endl;
					getline(cin >> ws, nameofuser);
				}
				indoff = this->findfbyname(nameofuser);

				this->allfriends_m[indoff]->getallfriends();
			}
			break;
			case 2:
			{
				cout << "Write page name: " << endl;
				getline(cin >> ws, nameofuser);
				while (this->findpbyname(nameofuser) == -1)
				{
					cout << "Invaild input!" << endl;
					cout << "Write page name: " << endl;
					getline(cin >> ws, nameofuser);
				}
				indoff = this->findpbyname(nameofuser);
				this->allpages_m[indoff]->getallfans();
			}
			break;
			default:break;
				
			}
		}
		break;
		case 12:
		{
			
			this->saveToFile();
			
			for (auto i : allpages_m)
				delete i;
			for (auto i : allfriends_m)
			{

				delete i;
			
			}
			flag = false;
			cout << "See you again!!!" << endl;
			continue;
		}
		break;
		default:break;
		
		}
		cout << "1-Add friend \n 2-Add page \n 3-Add Status for friend/page \n 4-Show all Status for friend/page \n 5-Show 10 current Status for friend \n 6-Add friend to friend \n 7-Remove link betwen friends \n 8-Add friend to page \n 9-Remove friend from page \n 10-Show all users \n 11-Show all friend for friend/page \n 12-Exit" << endl;
		cin >> option;





	}

}
void Parsofsefer::saveToFile()
{
	//fstream outFile;
	//outFile.open("meda3.txt", fstream::trunc);
	ofstream outFile("meda3.txt", ios::out|ios::trunc);
	
	if (outFile.is_open())
	{
		outFile << this->allfriends_m.size() << endl;
		for (int i = 0; i < allfriends_m.size(); i++)
		{
			outFile << this->allfriends_m[i]->getname() << endl;
			outFile << this->allfriends_m[i]->getdate().getday() << " " << this->allfriends_m[i]->getdate().getmonth() << " " << this->allfriends_m[i]->getdate().getyear() << endl;
		}
		outFile << this->allpages_m.size() << endl;
		for (int i = 0; i < allpages_m.size(); i++)
		{
			outFile << this->allpages_m[i]->getname() << endl;
		}

		for (int i = 0; i < allfriends_m.size(); i++)
		{
			outFile << this->allfriends_m[i]->getname() << endl;
			//outFile << this->allfriends_m[i]->getdate().getday() << " " << this->allfriends_m[i]->getdate().getmonth() << " " << this->allfriends_m[i]->getdate().getyear() << endl;
			vector<string> dof;
			this->allfriends_m[i]->getfriends(dof);
			outFile << dof.size() << endl;
			for (int j = 0; j < dof.size(); j++)
			{
				outFile << dof[i] << endl;
			}
		}

		for (int i = 0; i < this->allpages_m.size(); i++)
		{
			outFile << this->allpages_m[i]->getname() << endl;
			//outFile << this->allfriends_m[i]->getdate().getday() << " " << this->allfriends_m[i]->getdate().getmonth() << " " << this->allfriends_m[i]->getdate().getyear() << endl;
			vector<string> dof1;
			this->allpages_m[i]->getfriends(dof1);
			outFile << dof1.size() << endl;
			for (int j = 0; j < dof1.size(); j++)
			{
				outFile << dof1[j] << endl;
			}
		}
		for (int i = 0; i < this->allfriends_m.size(); i++)
		{
			vector<Status> dos;
			this->allfriends_m[i]->getstatuses(dos);
			outFile << dos.size() << endl;
			for (int j = 0; j < dos.size(); j++)
			{
				outFile << dos[j].getext() << endl;
				outFile << dos[j].getdate()->getday() << " " << dos[j].getdate()->getmonth() << " " << dos[j].getdate()->getyear() << endl;
				outFile << dos[j].gethour() << endl;
				outFile << dos[j].getpathurl() << endl;


			}
		}
		for (int i = 0; i < this->allpages_m.size(); i++)
		{
			vector<Status> dos;
			this->allpages_m[i]->getstatuses(dos);
			outFile << dos.size() << endl;
			for (int j = 0; j < dos.size(); j++)
			{
				outFile << dos[j].getext() << endl;
				outFile << dos[j].getdate()->getday() << " " << dos[j].getdate()->getmonth() << " " << dos[j].getdate()->getyear() << endl;
				outFile << dos[j].gethour() << endl;
				outFile << dos[j].getpathurl() << endl;


			}
		}
		for (int i = 0; i < this->allfriends_m.size(); i++)
		{
			vector<Pages> dos;
			this->allfriends_m[i]->getpages(dos);
			outFile << dos.size() << endl;
			for (int j = 0; j < dos.size(); j++)
			{
				outFile << dos[j].getname() << endl;
			}
		}
		outFile.close();
	}
	else cout << "Unable to open file";

}
