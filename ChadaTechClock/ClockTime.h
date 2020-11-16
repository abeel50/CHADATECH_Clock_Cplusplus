#pragma once
#ifndef CLOCK_TIME_H
#define CLOCK_TIME_H
#define _CRT_SECURE_NO_WARNINGS

#include<string>
#include<iostream>
#include <ctime>
#include <iomanip>

using namespace std;

class ClockTime
{
private:
	int hour;
	int minute;
	int second;

	void display_12_HourTime();
	void display_24_HourTime();
public:

	ClockTime();
	ClockTime(int , int, int );

	void addSecond(int );
	void addMinute(int );
	void addHour(int );

	string getAM_PM();
	int gethour_12();

	void displayClock();
};

#endif