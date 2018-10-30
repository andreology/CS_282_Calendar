#include <iostream>
using namespace std;
#include <string>
#ifndef MYDATE_H
#define MYDATE_H

class myDate {

public:

	//Set default constructor.
	
	myDate(); //Constructor set the date to May 11, 1959 (A very important date.)

	//Overloaded constructor in order to set the date to the values 
	//passes in through the parameter list represented by Month, Day and Year.
	myDate(int M, int D, int Y);

	// display the date in the following format(May 11, 1959) 
	//Do NOT print a linefeed after the date.
	void display();

	//Increment the date by N days.
	void incrDate(int N);

	//Decrement the date by N days.
	void decrDate(int N);

	//Return the number of days between this date and 
	//Date D. If date D is a future date 
	//ohterwise return value will be a positive int.
	//If date D is in the past, the return value will be a negative int.
	int daysBetween(myDate D);

	//Return month in integer form
	int getMonth();

	//Return day of the month
	int getDay();

	//Return year
	int getYear();

	////Return days since the current year began.
	//For instance Jan 1 is 1, Feb 1 is 32.
	int dayOfYear();

	//Returns Monday, Tuesday, etc according to the day of the week.
	string dayOfWeek();

	//Convert and set Julian Dates day into Gregorian Calendar Dates
	void GDate(int JD, int &y, int &m, int &d);

	//Convert and return from Gregorian dates into Julian dates
	int JD(int y, int m, int d);

private:

	int month;
	int day;
	int year;

};

#endif