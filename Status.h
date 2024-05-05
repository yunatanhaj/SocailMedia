#pragma once
#include "Date.h"
#include <string>
using namespace std;

class Status {

	int hour_m;
	Date* date_m;
	 const string text_m;
	 string path;
public:
	Status(int hour, Date* date,const  string text,string path) :date_m(date), hour_m(hour), text_m(text),path(path)
	{
		
	}
	~Status()
	{
		//delete this->date_m;
	
	}
	const string getext();
	 string getpathurl() const
	{
		 return this->path;
	}
	int gethour();

	Date* getdate();
	bool operator>(const Status& other) const
	{
		if (this->date_m->getyear() > other.date_m->getyear())
		{
			return true;
		}
		else {if(this->date_m->getyear() == other.date_m->getyear())
			{
				if (this->date_m->getmonth()> other.date_m->getmonth())
				{
					return true;
				}
				else {
					if (this->date_m->getmonth() == other.date_m->getmonth())
					{
						if (this->date_m->getday() > other.date_m->getday())
						{
							return true;
						}
						else {
							if (this->date_m->getday() == other.date_m->getday())
							{
								if (this->hour_m > other.hour_m)
								{
									return true;
								}

							}

						}
					}
				}
			}
		}
	
	}
	bool operator==(const Status& other)const
	{
		return (this->text_m == other.text_m);
	}
	bool operator!=(const Status& other)const
	{
		return (this->text_m != other.text_m);
	}

};