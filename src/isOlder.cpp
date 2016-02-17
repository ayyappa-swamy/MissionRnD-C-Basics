/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

struct date {
	int day;
	int month;
	int year;
};

typedef struct date Date;

int strlen(char * string)
{
	int index = 0;
	for (index = 0; string[index] != '\0'; index++);
	return index;
}

int isLeapYear(int year)
{
	if ((year % 4) != 0)
		return 0;
	else {
		if ((year % 100) != 0)
			return 1;
		else if ((year % 400) == 0)
			return 1;
		else return 0;
	}
}

int numOfDays(int month, int year)
{
	if (month != 2){
		return (30 + ((month + (int)(month / 8)) % 2));
	}
	else if (isLeapYear(year))
		return 29;
	else return 28;
}

int isValidDateFormat(char* dob){
	int len = strlen(dob), index = 0;
	if (len != 10)
		return 0;
	for (index = 0; index < len; index++){
		if (dob[index] != '-'){
			if ((dob[index] - '0') > 9)
				return 0;
		}
	}
	return 1;
}

Date getDateFromString(char *dob){
	Date date1;
	date1.day = 0; date1.month = 0; date1.year = 0;

	date1.day = (dob[0] - '0') * 10 + dob[1] - '0';
	date1.month = (dob[3] - '0') * 10 + dob[4] - '0';
	date1.year = (dob[6] - '0') * 1000 + (dob[7] - '0') * 100 + (dob[8] - '0') * 10 + (dob[9] - '0');

	return date1;
}

int isValidDate(Date date)
{
	if ((date.day == 0) || (date.month == 0) || (date.year == 0))
		return 0;
	else{
		if (date.month > 12)
			return 0;
		else {
			if (date.day > 31)
				return 0;
			else {
				if (date.day <= numOfDays(date.month, date.year))
					return 1;
				return 0;
			}
		}
	}
}

int structCompare(Date date1, Date date2)
{
	if (date1.year < date2.year)
		return 1;
	else if (date1.year > date2.year)
		return 2;
	else {
		if (date1.month < date2.month)
			return 1;
		else if (date1.month > date2.month)
			return 2;
		else {
			if (date1.day < date2.day)
				return 1;
			else if (date1.day > date2.day)
				return 2;
			else
				return 0;
		}
	}
}

int isOlder(char *dob1, char *dob2){
	Date date1, date2;
	if (isValidDateFormat(dob1) && isValidDateFormat(dob2)){
		date1 = getDateFromString(dob1);
		date2 = getDateFromString(dob2);
		if (isValidDate(date1) && isValidDate(date2)){
			return structCompare(date1, date2);
		}
		else return -1;
	}
	else return -1;
}
