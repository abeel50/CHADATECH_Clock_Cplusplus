#include "ClockTime.h"

//default Constructor
ClockTime::ClockTime()
{
	time_t now = time(0); //gets current Time
	tm *ltm = localtime(&now); //converts current Time to struct tm type

	this->hour = ltm->tm_hour;
	this->minute = ltm->tm_min;
	this->second = ltm->tm_sec;
}

// parameter constructor
ClockTime::ClockTime(int hour, int min, int sec)
{
	this->hour = hour;
	this->minute = min;
	this->second = sec;
}

void ClockTime::addHour(int hour = 1)
{
	this->hour = (this->hour + hour) % 24;
}

void ClockTime::addMinute(int min = 1)
{
	if (min == 59){
		this->addHour();
	}
	this->minute = (this->minute + min) % 60;
}

void ClockTime::addSecond(int sec = 1)
{
	if (this->second == 59){
		this->addMinute();
	}
	this->second = (this->second + sec) % 60;
}

// function return AM/PM respect to hour of time
string ClockTime::getAM_PM()
{
	return this->hour >= 12 ? "PM" : "AM";
}


// function returns integer used in 12 hour format
int ClockTime::gethour_12()
{
	return (this->hour == 0 || this->hour == 12) ? 12 : this->hour % 12;
}


// function displays 12 hour formatClock
void ClockTime::display_12_HourTime()
{
	cout.fill('0');
	cout << setw(2) << this->gethour_12()<< ":" << setw(2) << this->minute << ":" << setw(2) << this->second 
		<< " " << this->getAM_PM();
}

// function displays 24 hour formatClock
void ClockTime::display_24_HourTime()
{
	cout.fill('0');
	cout << setw(2) << this->hour << ":" << setw(2) << this->minute << ":" << setw(2) << this->second;
}

// Function Displays Both Clocks
void ClockTime::displayClock()
{
	cout << "**************************" << "     " << "**************************\n";
	cout << "*      12-Hour Clock     *" << "     " << "*      24-Hour Clock     *\n";
	cout << "*      "; this->display_12_HourTime();
	cout << "       *     *        ";
	this->display_24_HourTime(); cout << "        *\n";
	cout << "**************************" << "     " << "**************************\n";
}