#include <iostream>
using namespace std;
#include "myDate.h";
#include <string>

//Set default constructor in order to set the date to May 11, 1959
myDate::myDate() {
	month = 5;
	day = 11;
	year = 1959;
}

//Overloaded constructor in order to set the date to the values passed in through the parameter list represented by month, day and year. 
myDate::myDate(int M, int D, int Y) {
	//month = M;
	//day = D;
	//year = Y;
	if (M > 0 && M < 13) {
		month = M;
		if (D > 0 && D < 32) {
			day = D;
			year = Y;
		}
	}
	else {
		month = 5;
		day = 11;
		year = 1959;
	}

}

//Display the date in the following format(May 11, 1959) and no linefeed after the date.
void myDate::display()
{
	string monthStr = "";
	switch (month)
	{
	case 1:
		monthStr = "January";
		break;
	case 2:
		monthStr = "February";
		break;
	case 3:
		monthStr = "March";
		break;
	case 4:
		monthStr = "April";
		break;
	case 5:
		monthStr = "May";
		break;
	case 6:
		monthStr = "June";
		break;
	case 7:
		monthStr = "July";
		break;
	case 8:
		monthStr = "August";
		break;
	case 9:
		monthStr = "September";
		break;
	case 10:
		monthStr = "October";
		break;
	case 11:
		monthStr = "November";
		break;
	case 12:
		monthStr = "December";
		break;
	}
	cout << monthStr << " " << this->day << ", " << this->year;


}

//Increment date by N days.
void myDate::incrDate(int N) {
	int j = JD(year, month, day);
	//Convert negative number into positive for correct value
	if (N < 0) {
		N = -N;
	}
	j += N;
	int x, y, z;
	GDate(j, x, y, z);
	year = x;
	month = y;
	day = z;
}

//Decrement date by N days.
void myDate::decrDate(int N) {
	int j = JD(year, month, day);

	if (N < 0) {
		N = -N;
	}

	j -= N;
	int x, y, z;
	GDate(j, x, y, z);
	year = x;
	month = y;
	day = z;
}

//Return number of days between this date and the date D. If date D is a future date return value as positive int. If date D is in the past return value as a negative int.
int myDate::daysBetween(myDate D) {

	int a, b, c;
	a = JD(D.getYear(), D.getMonth(), D.getDay());
	b = JD(year, month, day);
	c = b - a;
	if (c < 0)
	{
		c = c * -1;
	}
	//Return the difference in days
	return c;
}

//Return month in integer form
int myDate::getMonth() {
	return month;
}

//Return day of the month
int myDate::getDay() {
	return day;
}

//Return the year
int myDate::getYear() {
	return year;
}


//Return number of days since the current year began.Example Jan 1 is 1, Feb 1 is 32.
int myDate::dayOfYear() {
	int a = 0;;
	//Is leap year?
	if (((year % 4) == 0) && (((year % 100) != 0) || ((year % 400) == 0))) {
		switch (month) {
		case 2: a = 31;
			break;
		case 3: a = 60;
			break;
		case 4:	a = 91;
			break;
		case 5: a = 121;
			break;
		case 6: a = 152;
			break;
		case 7:	a = 182;
			break;
		case 8:	 a = 213;
			break;
		case 9:	a = 244;
			break;
		case 10: a = 274;
			break;
		case 11: a = 305;
			break;
		case 12: a = 335;
			break;
		default: a = 0;
			break;
		}//end switch

		a = a + day;
	}//end if

	 //If not a leap yaer
	else {
		switch (month) {
		case 2: a = 31;
			break;
		case 3: a = 59;
			break;
		case 4:	a = 90;
			break;
		case 5: a = 120;
			break;
		case 6: a = 151;
			break;
		case 7:	a = 181;
			break;
		case 8:	 a = 212;
			break;
		case 9:	a = 243;
			break;
		case 10: a = 273;
			break;
		case 11: a = 304;
			break;
		case 12: a = 334;
			break;
		default: a = 0;
			break;
		}//end switch

		a = a + day;
	}//end else

	 //Return day of the year
	return a;
}

//Returns Monday, Tuesday, etc according to the day of the week.
string myDate::dayOfWeek() {
	int m, d, y;
	m = month;
	y = year;
	d = day;

	if (m == 1 || m == 2) {
		m = m + 12;
		y = y - 1;
	}
	//Cool method to convert a date into the day of week
	int z = (d + (int)floor((13 * (m + 1)) / 5) + y % 100 + (int)floor((y % 100) / 4) + (int)floor(((int)floor(y / 100)) / 4) + 5 * (int)floor(y / 100)) % 7;

	string dow;
	switch (z) {
	case 0: dow.append("Saturday");
		break;
	case 1: dow.append("Sunday");
		break;
	case 2: dow.append("Monday");
		break;
	case 3: dow.append("Tuesday");
		break;
	case 4: dow.append("Wednesday");
		break;
	case 5: dow.append("Thursday");
		break;
	case 6: dow.append("Friday");
		break;
	}

	return dow;
}

void myDate::GDate(int JD, int &year, int &month, int &day) {
	int I, J, K;
	int L, N;

	L = JD + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	year = I;
	month = J;
	day = K;

}

int myDate::JD(int y, int m, int d) {
	int Julian = d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 * (m - 2 - (m - 14) / 12 * 12) / 12 - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4;


	return Julian;
}