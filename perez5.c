/* -------------------------------------------------------------------
  
Program:    perez5.c
Author:     Erik Perez Gonzalez
Objective:	A program that takes information from a .dat file, sorts it, then returns the sorted list
			and makes a file copy of the sorted list.
		
---------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 100		/* Maximum number of individual employees to sort */

	/* Structure definition */
	/* -------------------- */
	
	struct emp 					/* Represents an employee's relevant information */
	{
		int		id_num; 		/* employee number */
		float 	salary; 		/* employee salary */
		char 	first_name[20]; /* employee first name */
		char 	last_name[30]; 	/* employee last name */
	};

	/* Function definitions */
	/* -------------------- */

	void welcome_prompt(char []); 				 /* Function that welcomes the user and prompts for a filename */
	void sort_company(struct emp [], int, char); /* Function that sorts the array of employees */
	int print_report(struct emp [], int); 		 /* Function that prints report of sorted list and makes a file copy */

int main()
{
	
	FILE 	*in_file_ptr;				/* Pointer to an inbound FILE structure */		
	struct 	emp company[100];			/* Array of employee structures */
	char   	file_name[30], sort_order; 	/* Name of file and flag representing the sort order */
	int 	x, emp_count;

	welcome_prompt(file_name);	/* Welcome user and prompt for filename */

	/* Attempt to open inbound file. */

	in_file_ptr = fopen(file_name, "rb");
	if (in_file_ptr == NULL) 	/* Throw error if file pointer is not valid */
	{
		
     	printf("Could not open file %s\n", file_name);
     	return 1;
     	
	} /* end if statement */
	
	for (x = 0; x < MAX; x++) 	/* For loop for reading data from inbound file into array */
	{
		
		fread(&company[x], sizeof(company[x]), 1, in_file_ptr);
		if(feof(in_file_ptr))break;
		
	} /* end for loop */
	
	fclose(in_file_ptr); /* Close inbound file */
	
	emp_count = x; /* Set count of employees */
	
	printf("%i employees\n\n", emp_count);
	
	printf("Sort by: Employee Number(N), Name(A), or Balance(B):\n\n"); /* Prompt the user for a sort option */
	
	sort_order = toupper(getchar()); /* Get sort order input and turn into uppercase */
	fflush(stdin); /* clear buffer */
			
	sort_company(company, emp_count, sort_order); /* Employee array is sorted */
		     
	print_report(company, emp_count); /* Sorted array is printed out and copied to file */
	
	printf("\n(Report has been sent to report5.txt)\n");
 	
 	printf("\nThank you for using the program.\n\n");

	return 0;
	
}/* end main */

void welcome_prompt(char file_name[30])
{
	
	/* Welcome user and prompt for filename. */
	
	printf("Welcome to Employee Center:\n\n");

	printf("Enter File Name: \n\n");
	scanf("%29s", file_name);
	fflush(stdin); /* clear buffer */
	
} /* end function welcome_prompt */

int print_report(struct emp company[100], int emp_count)
{
	
	time_t current_time;/* Time structure */
	char * string_time; /* String form of the current time */
	char big_name[50];  /* Large string for full employee name */
	int x;
	FILE * out_file_ptr;/* Pointer to an outbound FILE structure */	     
		     
	current_time = time(NULL);	     
	string_time = ctime(&current_time);
	
	/* Try to open file for writing */
	
	out_file_ptr = fopen("report5.txt", "wb");
	
	if (out_file_ptr == NULL) /* Throw error if outbound pointer is invalid */
	{
		
     	printf("Could not open report5.txt for writing\n");
     	return 1;
     	
	}	     
	
	printf("Employee Salary Report %s\n", string_time); /* Report of sorted list */
	printf("Employee\n");
	printf("No.  Name\t\tSalary\n\n");	 
	
	fprintf(out_file_ptr, "Employee Salary Report %s\n", string_time); /* Report written to outbound file */
	fprintf(out_file_ptr, "Employee\n");
	fprintf(out_file_ptr, "No.  Name\t\tSalary\n\n");    
	    
	for (x = 0; x < emp_count; x++) /* Display information in table form */
	{
		
		strcpy(big_name, company[x].last_name);
		strcat(big_name, ", ");
		strcat(big_name, company[x].first_name);
		
		printf("%3i  %-15s\t%.2f\n", company[x].id_num, big_name, company[x].salary);
		fprintf(out_file_ptr, "%3i  %-15s\t%.2f\n", company[x].id_num, big_name, company[x].salary);
		
	}	
	
	fclose(out_file_ptr); /* Close outbound file */
	
} /* end function print_report */

void sort_company(struct emp company[100], int emp_count, char sort_order)
{
	int x, i;
	char not_done = 'y';
	struct emp temp;
	
	for(x = 0; x < emp_count ; x++)
      if(not_done == 'y')
  	  {
         not_done = 'n';    
   	 	for(i = 0; i < emp_count - 1; i++)
   	 	{    
	   		 if(
					(sort_order == 'A' && strcmp(company[i].last_name, company[i+1].last_name)> 0)
					|| (sort_order == 'N' && company[i].id_num > company[i+1].id_num)
					|| (sort_order == 'B' && company[i].salary > company[i+1].salary)
				)
	   		 {
	   			 temp = company[i];
	   			 company[i] = company[i+1];
	   			 company[i+1] = temp;
	   		 
	   			 not_done = 'y';    
	   		 }/* end if  */
   		 
		} /* end inner for loop  */
 	}/* end if and outer for loop with no block when not_done = 'n' */
 	
} /* end function sort_company */
