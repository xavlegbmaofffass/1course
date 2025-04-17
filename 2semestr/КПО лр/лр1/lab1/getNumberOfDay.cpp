#include "stdafx.h"
int getNumberOfDay(int day, int month, bool isLeap) {
	int number = 0;

	if (!isLeap) {
		months[1].second = 28;
	}

	for (int i = 0; i != month - 1;++i) {
		number += months[i].second;
	}
	number += day;
	return number;
}

int getNumberByBD(int currentDay, int currentMonth, int currentYear, int BDDay, int BDMonth, bool isLeap) {
	if (BDDay == 29 && BDMonth == 2) {
		int daysBefore = (4 - (currentYear % 4)) * 365;
		if (isLeap) {
			daysBefore = 0;
		}
		return getNumberOfDay(BDDay, BDMonth, isLeap) - getNumberOfDay(currentDay, currentMonth, isLeap) + daysBefore;
	}

	return getNumberOfDay(BDDay, BDMonth, isLeap) - getNumberOfDay(currentDay, currentMonth, isLeap);
}