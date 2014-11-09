#include "assert.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

#include "lib/common.h"
#include "lib/linkedlist.h"

#define week 60 * 60 * 24 * 7

struct tm generateFirstDate(int day, int month, int year);
int daysInMonth(int month, int year);
bool isLeap(int year);
void addWeek(struct tm *date);

int main()
{
	int counter = 0;
	struct tm date = generateFirstDate(6, 1, 1901);

	while(date.tm_year < 101)
	{
		addWeek(&date);
		if(date.tm_mday == 1)
		{
			counter++;
		}
	}
	printf("Result: %d\n", counter);
	return 0;
}

struct tm generateFirstDate(int day, int month, int year)
{
	struct tm date;

	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;
	date.tm_isdst = 0;

	return date;
}

void addWeek(struct tm *date)
{
	int days = daysInMonth(date->tm_mon, date->tm_year);
	date->tm_mday += 7;
	if(date->tm_mday > days)
	{
		date->tm_mday = date->tm_mday % days;
		date->tm_mon += 1;
		if(date->tm_mon > 11)
		{
			date->tm_mon = 0;
			date->tm_year += 1;
		}
	}
}

int daysInMonth(int month, int year)
{
	const int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(month == 1)
	{
		if(isLeap(year) == true)
		{
			return daysPerMonth[1] + 1;
		}
		return daysPerMonth[1];
	}
	else
	{
		return daysPerMonth[month];
	}
}

bool isLeap(int year)
{
	year += 1900;
	if(year % 4 != 0)
	{
		return false;
	}
	else
	{
		if( year % 100 != 0)
		{
			return true;
		}
		else
		{
			if(year % 400 != 0)
			{
				return false;
			}
		}
	}
	return true;
}
