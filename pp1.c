
#include <stdio.h>

void enter_class_name(char[]);	/* function for entering class name */
int enter_num_grades(void);		/* function for entering the number of grades */
int input_avg(int[], int);		/* function for entering the grades and calculating the average */
void bubble_sort(int[], int);	/* function that performs a bubble sort on the grade array */
void print_sorted_grades(int[], int); /* function for printing the sorted grade values */
float calc_median(int[], int);	/* function for calculating the median of the grade values */
void print_summary(char[], int[], int, float, int); /* function that prints a summary of the minimum and maxiumum,
													the median, and the average */

int main()
{
	/* Variable Declarations */
	
	char 			class_name[20]; /* name of class */
	int				average = 0;	/* average of grade values */
	int				num_grades;		/* number of grades */
	float			median = 0;		/* median of grades */
	static int		grades[50];		/* array of grades  */
	
	enter_class_name(class_name);
	
	num_grades = enter_num_grades();
	
	average = input_avg(grades, num_grades);
 		
	bubble_sort(grades, num_grades);

 	print_sorted_grades(grades, num_grades);
 	
 	median = calc_median(grades, num_grades);
 	
 	print_summary(class_name, grades, num_grades, median, average);
	
	return 0;
	
} /* end main */

void enter_class_name(char class_name[])
{

	/* Prompt user for company name and welcome user to program */
	
	printf("Enter Class Name: "); 																
	gets(class_name);
	fflush(stdin);	/* Clear input buffer */
	
	printf("\n");	/* Spacing */
																
	printf("Welcome to the %s Grade Calculator.\n\n", class_name);
	
} /* end function */

int enter_num_grades(void)
{
	
	int num_grades = 0;
	
	do	/* Start of while loop trap for entering number of grades */
	{	
	
		/* Prompt user for number of grades and gives errors if value is negative or greater than 50 */
		
		printf("Enter the number of grades to process(1-50): "); 
		scanf("%i", &num_grades);
		fflush(stdin);			/* Clear input buffer */
		
		printf("\n");			/* Spacing */
		
		if (num_grades < 0) 	/* Error for input of negative value */
			printf("ERROR: Value must be at least zero.\n\n");
			
		if (num_grades > 50)	/* Error for exceeding maximum number of entries */
			printf("ERROR: Value is greater than the maximum number of entries.\n\n");
					
	} while (num_grades < 0 || num_grades > 50);  /* end of while loop trap */
	
	return num_grades;
	
} /* end function */

int input_avg(int grades[], int num_grades)
{
	
	int x;
	int average = 0;
	
	for (x = 0; x < num_grades; x++) /* Start of for loop for entering grades and calculating average */
	{
		do  /* Start of do-while loop trap for entering class grades */
		{
			
			/* Prompt user for student grades */
			
			printf("Enter grade for student #%i: ", x + 1); 
			scanf("%i", &grades[x]);	/* Scan for grade */
			fflush(stdin);				/* Clear input buffer */
	
			if (grades[x] < 0) 			/* Error for input of negative value */
				printf("\nERROR: Please enter a positive number value.\n\n");
			if (grades[x] > 100)		/* Error for exceeding maximum number of entries */
				printf("\n*** Invalid grade entered. Please enter 0-100 ***\n\n");
				
		} while (grades[x] < 0 || grades[x] > 100);	/* end do-while loop */
		
		average += grades[x];			/* Accumulator for calculation of average */
	
	} /* end for loop */

	average =  average / num_grades;	/* Calculation of average */
	
	return average;
	
} /* end function */

void bubble_sort(int grades[], int num_grades)
{
	
	char swap_flag = 'T';				/* Flag that indicates whether a swap has occurred */
	int x;
	int temp;
	
	while (swap_flag == 'T') 			/* Start of while loop for swapping numbers */
	{
	 	swap_flag = 'F';
	 	
 		/* Test if element is greater than the next element */
 		
	 	for (x = 0; x < num_grades - 1; x++) /* Start of for loop for swapping numbers */
	 	{
	 		if (grades[x] > grades[x + 1])
	 		{
				 /* Swap */
				 temp = grades[x];
				 grades[x] = grades[x + 1];
				 grades[x + 1] = temp;
				 
				 /* Set swap flag*/
				 swap_flag = 'T';
				 
 			} /* end if */
	 	} /* end for */
	 } /* end while */

} /* end function */

void print_sorted_grades(int grades[], int num_grades)
{
	
	int x;
	
	/* Print out sorted array */
	printf ("\nThe %i Grades sorted: \n\n", num_grades);
	
 	for (x = 0; x < num_grades; x++) 	/* Start of for loop for printing array values */
 	{
 		
	 	if (x != num_grades - 1)		/* If x is not the last number in the array, print comma */
	 	{
			printf ("%i, ", grades[x]);
	 	}
	 	
	 	else						
			printf ("%i ", grades[x]);

 	} /* end for loop */
 	
} /* end function */

float calc_median(int grades[], int num_grades)
{
	
	float median = 0;
	
	/* Calculating median for odd and even results */
 	if (num_grades % 2 == 0)
 	{	
	 
	 	/* If even, find the value between the two "middle" values, taking into account that array index starts at 0 */
 		median = (float)(grades[(num_grades/2)- 1] + grades[(num_grades/2)])/2; 
 		
 	}
 	
 	else
 	{	
	 
	 	/* If odd, choose the "middle" value */
		median = ((float)grades[(num_grades + 1)/2])-1;
		
 	}
 	
 	return median;
 	
} /* end function */

void print_summary(char class_name[], int grades[], int num_grades, float median, int average)
{
	
	/* Print summary of values */
	 printf("\n\nThe minimum is %i", grades[0]);
	 printf("\nThe maximum is %i", grades[num_grades - 1]);
	 printf("\nThe median grade is %.1f", median);
	 
	 printf("\n\nThe %s class average rounded is %i\n", class_name, average);
	 
} /* end function */
