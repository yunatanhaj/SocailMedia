#pragma once

class Date {
	int month_m;
	int day_m;
	int year_m;
public:
	Date();
	Date(int year, int month, int day)
	{
			this->month_m = month;
			this->day_m = day;
			this->year_m = year;
	
	}


	int getmonth();

	int getday();

	int getyear();
	
	



};