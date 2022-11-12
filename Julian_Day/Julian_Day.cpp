#include<iostream>

/*
Assignment: Counting Julian Day.
Author:     Deepti Sharma
Due Date:   10-23-2022
*/

using namespace std;

//Prototypes
long  query_for_long(string);
bool  is_a_leap_year(long);
long  return_days_in_month(long, long);
long  return_julian_date(long, long, long);

//Constants 
const long JAN = 1;
const long FEB = 2;
const long MAR = 3;
const long APR = 4;
const long MAY = 5;
const long JUN = 6;
const long JUL = 7;
const long AUG = 8;
const long SEP = 9;
const long OCT = 10;
const long NOV = 11;
const long DEC = 12;

long query_for_long(string prompt) {
	long return_value = 0;

	cout << prompt;
	cin  >> return_value;

	return return_value;
}

bool is_a_leap_year(long year) {
	bool return_value = false;

	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		return_value = true;

	return return_value;
}

long return_days_in_month(long in_year, long in_month) {
	long days_in_month = 0;

	if ((in_month == JAN) || (in_month == MAR) || (in_month == MAY) || (in_month == JUL) || (in_month == AUG) || (in_month == OCT) || (in_month == DEC))
		days_in_month = 31;
	else if ((in_month == APR) || (in_month == JUN) || (in_month == SEP) || (in_month == NOV))
		days_in_month = 30;
	else
		days_in_month = ((is_a_leap_year(in_year)) ? 29 : 28);

	return days_in_month;

}

long return_julian_date(long in_year, long in_month, long in_day) {
	long julian_date = 0;
	//cout << julian_date << endl;

	for (long month = JAN; month < in_month; month++) {
		julian_date += return_days_in_month(in_year, month);
		//cout << in_year << endl;
		//cout << in_month << endl;
		cout   << return_days_in_month(in_year, in_month) << endl;
	}
	julian_date += in_day;

	return julian_date;

}

int main() {

	long year_entered  = 0;
	long month_entered = 0;
	long day_entered   = 0;
	long julian_date   = 0;

	year_entered  = query_for_long("Enter a year: ");
	month_entered = query_for_long("Enter a month: ");
	day_entered   = query_for_long("Enter a day: ");

	julian_date   = return_julian_date(year_entered, month_entered, day_entered);

	cout << "The Julian Date is: " << julian_date << endl;

	return 0;
}

