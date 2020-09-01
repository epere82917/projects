/* -------------------------------------------------------------------
  
Program:    p2.c

Objective:
		A C program that takes a date as input and outputs the day of the week that
the date corresponds to. 
		                     
---------------------------------------------------------------------- */

#include <stdio.h>

/* Struct declarations */

struct date	/* Represents a date in time */
{
	int month; 
	int day;
	int year;
};

/* Function declarations */

struct date 	enter_date(void);	/* Function for entering the date to be processed */
char 			leap_year_check(struct date); /* Function that checks if a date falls on a leap year */
long int 		calc_date_number(struct date); /* Function that calculates the raw number of a date */
int 			calc_day_number(long int n); /* Function that calculates the day of the week that a date corresponds to */
void 			display_day_of_week(struct date, int); /* Function that prints out what day of the week a date corresponds to */

int main()
{
	
	/* Variable Declarations */
	
	struct date 	target_date;	/* Date structure */
	long int 		n;				/* Raw number representing the numerical date */
	int 			day_number;		/* Number index representing the day of the week of the date */
	
	target_date = enter_date(); 
	
	n = calc_date_number(target_date);
	
	day_number = calc_day_number(n);
	
	display_day_of_week(target_date, day_number);
	
	getchar();
	
	return 0;
	
} /* end main */

struct date enter_date(void)
{
	
	struct date target_date;
	int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char valid_month, valid_day, valid_year;
	
	do /* do-while loop for prompting for dates and checking if valid */
	{

		valid_month = 'T';
		valid_day = 'T';
		valid_year = 'T';

		printf("The program will give the day of the week for any date from 1/1/1900\n\n");
		
		printf("Enter date (mm/dd/yyyy): "); /* Prompt user for date */
		scanf("%i/%i/%i", &target_date.month, &target_date.day, &target_date.year);
		fflush(stdin); /* clear buffer */
		
		if (leap_year_check(target_date) == 'T') /* If date is leap year, change February's number of days */
			days_in_month[1] = 29;
	
		else
			days_in_month[1] = 28;
			
		if (target_date.year < 1900) /* Error for entering an invalid year */
		{
			printf("Invalid year. Please re-enter date.\n\n");
			valid_year = 'F';
		}
		
		if ((target_date.day > days_in_month[target_date.month-1] || target_date.day < 1) && valid_year == 'T') /* Error for entering an invalid day */
		{
			printf("Invalid day. Please re-enter date.\n\n");
			valid_day = 'F';
		}
		
		if ((target_date.month > 12 || target_date.month < 1) && (valid_year = 'T' && valid_day == 'T')) /* Error for entering an invalid month */
		{
			printf("Invalid month. Please re-enter date.\n\n");
			valid_month = 'F';
		}
		
	} while (valid_month == 'F' || valid_day == 'F' || valid_year == 'F'); /* end do-while loop */
	
	return target_date;
	
} /* end function */

char leap_year_check(struct date target_date)
{
	
	if ((target_date.year % 4 == 0 && target_date.year % 100 != 0) || target_date.year % 400 == 0)
		return 'T';
		
	else
		return 'F';
		
} /* end function */

long int calc_date_number(struct date target_date)
{
	
	long int n;
	
	if (target_date.month <= 2)
	{
		n = (1461 * (target_date.year - 1) / 4) + (((153 * (target_date.month + 13))/5) + target_date.day);
	}
	
	else
		n = ((1461 * target_date.year) / 4) + ((153 * (target_date.month + 1)/5) + target_date.day);
		
	return n;
	
} /* end function */

int calc_day_number(long int n)
{
	
	int day_number;
	
	day_number = (n - 621049) % 7;
	
	return day_number;
	
} /* end function */

void display_day_of_week(struct date target_date, int day_number)
{
	
	char day_of_week[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	
	printf("%.2i/%.2i/%.2i falls on a %s.\n\n", target_date.month, target_date.day, target_date.year, day_of_week[day_number]);

} /* end function */


