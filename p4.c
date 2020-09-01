/* -------------------------------------------------------------------
  
Program:    p4.c

Objective:
		This program prompts user to sort information 
		about any number of individuals and print a report accordingly.
		(pointer notation)
---------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h> 

	/* Structure definition */
	/* -------------------- */

 	struct split	/* Structure representing the full name of a person. */
 	{
 		char last[10];
 		char first[10];
 	};
 	
 	struct info		/* Structure representing a person's relevant information. */
  	{
		struct  split name;
	
		char  	address[20];
		char  	city[15];
		char  	state[3];
		long  	zip;
		int   	age;
		char  	gender;

  	};  /* end struct info */



	void sort_them(struct info*, int, char); /* sort prototype */

main()	
{
  	/* Declare variables */
  	/* ----------------- */

  	struct info		people[] =
  	{
  		{"Asimov", "Isaac", "15 Main St", "Worcestor", "MA", 01555, 23, 'M'},
  		{"Smith", "Jane", "17 Make Peace", "Wallham", "ND", 10102, 28, 'F'},
  		{"De Rippa", "Jack", "18 Able Way ", "Boston", "MA", 50503, 74, 'M'},
  		{"Cobb", "Jim", "55 Elm St", "Ware", "MO", 61555, 65, 'M'},
  		{"Kapone", "Al", "15 Morin Ave", "Idunno", "MN", 31333, 34, 'M'},
  		{"Seigel", "Myron", "44 Wing Blvd West", "Sandwich", "WA", 02537, 21, 'M'},
  		{"Thymes", "Mary", "88 Same Place", "Washington", "DC", 90555, 44, 'F'}
  		
  	}, *people_ptr_start, *people_iter_ptr; /* <- Pointer for iterating through list of people using pointer notation */

  	int				i, j, bad_sort;
	int				num_people = sizeof(people) / sizeof(people[0]); /* this will be the count of how many people there are! */
	char 			sort_order;
	char 			big_name[22];
	
	/* you may use array notation between this comment and the next comment to 
   assign pointer addresses, for example:*/
	
	char *big_name_ptr_start;
	
	big_name_ptr_start = big_name;/* Pointer to beginning of character array representing full name */

	people_ptr_start = people; /* Pointer to beginning of struct array of people */

	/*   in Assignment #4 from here down, any references to arrays will be deductions   */ 
			
	printf ("\nWelcome to the People Structure Data Report Program\n");

	do
	{
		bad_sort = 1;
						
		printf ("\nEnter the sort order for the report: ");
		printf ("\n(N=Name, A=Age, S=State, Z=Zip code ' '=no sort)\n ");
			
		/* blank or return is allowed for no sorting of the data */
			
		sort_order = getchar();
		
		fflush(stdin);
		
		if(sort_order == '\n' || sort_order == ' ') break; 
 			
		sort_order = toupper(sort_order);
		
		if ((sort_order == 'N') || (sort_order == 'A') || 
					(sort_order == 'S') || (sort_order == 'Z'))
		  	bad_sort = 0;
		else
		  	printf("\nIncorrect Sort order selected, please re-enter:  ");
		  
	} while (bad_sort == 1); /* end while loop */



	switch (sort_order)
	{
		case 'N':
			printf("Sort by Name  %i People.\n", num_people); 
			break;
		case 'A':
			printf("Sort by Age  %i People.\n", num_people); 
			break;
		case 'S':
			printf("Sort by State  %i People.\n", num_people); 
			break;
		case 'Z':
			printf("Sort by Zip  %i People.\n", num_people); 
			break;
		default:
			printf("No Sort selected  %i People.\n", num_people); 
			break;
	}  /* end cases */
	
	if(sort_order != ' ')
		sort_them(people_ptr_start, num_people, sort_order);

 
  	/* Print Report */
  	/* ------------ */

	printf("\n\n                 The People Report\n\n");

	printf ("\n\n%-20s%-20s %-15s %-5s %-6s %-3s %-6s", 
			"Name", "Address","City","State","Zip","Age","Gender");

/*	printf ("%-20s%-20s %-15s %-5s %-6s %-3s %-6s\n", 
			"----", "------","----","-----","---","---","------");
       the above is an alternative for the underlining below.
*/

	for(i=1; i<=80; i++) printf("%c",196); /* underline the headers */

  	for (people_iter_ptr = people_ptr_start; people_iter_ptr < people_ptr_start + num_people; *people_iter_ptr++)
  	{	
  	
		strcpy(big_name_ptr_start, (people_iter_ptr)->name.last);
		strcat(big_name_ptr_start, ", ");
		
		strcat(big_name_ptr_start, (people_iter_ptr)->name.first);
				
		printf ("%-20s%-20s %-15s  %-4s%.5d    %-3i  %c\n", 
	    		big_name_ptr_start,(people_iter_ptr)->address,(people_iter_ptr)->city,(people_iter_ptr)->state,(people_iter_ptr)->zip,
				(people_iter_ptr)->age,(people_iter_ptr)->gender); 	
			            
	} /* end for loop */

	printf("\n\n");

} /* end main */

void sort_them(struct info *them, int entries, char sort_by)
{

	struct info temp, *them_ptr1, *them_ptr2;
	
	for(them_ptr1 = them; them_ptr1 < them + (entries - 1); ++them_ptr1)
	  		  	
 		for(them_ptr2 = them_ptr1 ; them_ptr2 < them + (entries - 1); ++them_ptr2)
	  	{	
		  
			if(    (sort_by == 'N' && strcmp((them_ptr1)->name.last, (them_ptr2)->name.last)> 0)
				|| (sort_by == 'A' && them_ptr1->age > (them_ptr2)->age)
				|| (sort_by == 'S' && strcmp((them_ptr1)->state, (them_ptr2)->state)> 0)
				|| (sort_by == 'Z' && them_ptr1->zip > (them_ptr2)->zip)  )
			{
				
				temp = *them_ptr1;
              	*them_ptr1 = *them_ptr2;
              	*them_ptr2 = temp;
		    
			}/* end if  */	 
			
	  	} /* end inner for loop  */	
	
};
/* end of sort them 
sample run:

Welcome to the People Structure Data Report Program

Enter the sort order for the report:
(N=Name, A=Age, S=State, Z=Zip code ' '=no sort)
 n
Sort by Name  7 People.


                 The People Report



Name                Address              City            State Zip    Age Gender
--------------------------------------------------------------------------------
Asimov, Isaac       15 Main St           Worcestor        MA  00877    23   M
Cobb, Jim           55 Elm St            Ware             MO  61555    65   M
De Rippa, Jack      18 Able Way          Boston           MA  50503    74   M
Kapone, Al          15 Morin Ave         Idunno           MN  31333    34   M
Seigel, Myron       44 Wing Blvd West    Sandwich         WA  01375    21   M
Smith, Jane         17 Make Peace        Wallham          ND  10102    28   F
Thymes, Mary        88 Same Place        Washington       DC  90555    44   F


Press any key to continue . . .
	
*/
