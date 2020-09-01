/* -------------------------------------------------------------------
  
Program:    perez3.c

Objective:
		A C program that stores and prints out information about up to 10 individuals.
		                     
---------------------------------------------------------------------- */

#include <stdio.h>

/* Struct declarations */

struct information	/* Represents a person's relevant information */
{
	char name[35]; 
	char address[50];
	char city[25];
	char state[3];
	long int zip_code;
	int age;
	char gender;
};

/* Function declarations */

int enter_num_clients(void); /* function for entering the number of clients to be processed */
struct information enter_info(void); /* function for entering the informstion of individual clients */
void print_info(struct information); /* function for printing out the client information in a formatted block */
void safer_gets(char[], int); /* function for obtaining string input safely */
int check_the_state(char[]); /* function for checking if state input matches a list of acceptable states */

int main()
{
	
	/* Variable Declarations */
	
	struct information clients[10]; /* Array of client information */
	int num_clients;
	int x;
	
	printf("Welcome to the Perez database\n\n");
	
	num_clients = enter_num_clients();
	
	for (x = 0; x < num_clients; x++)
	{
		clients[x] = enter_info();
		printf("\n");
	} /* end for loop */
	
	printf("The information you entered is:\n\n");
	
	for (x = 0; x < num_clients; x++)
	{
		print_info(clients[x]);
		printf("\n");
	} /* end for loop*/
	
	return 0;
	
} /* end main */

int enter_num_clients(void)
{
	
	int num_clients = 0;
	
	do	/* Start of do-while loop trap for entering number of clients */
	{	
	
		/* Prompt user for number of clients and gives errors if value is negative or greater than 10 */
		
		printf("Enter the number of clients to input (maximum 10): "); 
		scanf("%d", &num_clients);
		fflush(stdin);			/* Clear input buffer */
		
		printf("\n");			/* Spacing */
		
		if (num_clients < 0) 	/* Error for input of negative value */
			printf("ERROR: Value must be at least zero.\n\n");
			
		if (num_clients > 10)	/* Error for exceeding maximum number of entries */
			printf("ERROR: Value is greater than the maximum number of entries.\n\n");
					
	} while (num_clients < 0 || num_clients > 10);  /* end of do-while loop trap */
	
	return num_clients;
	
} /* end function */

struct information enter_info(void)
{
	struct information client_info;
	int x;
	
	/* vvv User inputs client information below vvv*/
	printf("Enter name: "); 													
	safer_gets(client_info.name, 35);
	
	printf("Enter street address: "); 
	safer_gets(client_info.address, 50);
	
	printf("Enter city: ");
	safer_gets(client_info.city, 25);
	
	do
 	{   		 
 	
		printf ("Enter state: ");
		scanf("%2s", client_info.state);
	 
		fflush(stdin);
		
		for(x = 0; x < 2; x++)
  			client_info.state[x] = toupper(client_info.state[x]); /* Ensures all input is uppercase */
  			 	
 	} /* end do-while loop trap */ while (check_the_state(client_info.state) == 0); /* Checks against list of acceptable state input */

	do
	{
		
		printf("Enter zip code: ");
		scanf("%ld", &client_info.zip_code);
		fflush(stdin);
			
		if (client_info.zip_code < 0) 	/* Error for input of negative value */
			printf("ERROR: Value must be at least 00000.\n\n");
				
		if (client_info.zip_code > 99999)	/* Error for exceeding zip code range */
			printf("ERROR: Value is greater than the accepted range (00000 - 99999).\n\n");
					
	} while (client_info.zip_code < 0 || client_info.zip_code > 99999);  /* end of do-while loop trap */
	
	do
	{
		
		printf("Enter age: ");
		scanf("%d", &client_info.age);
		fflush(stdin);
		
		if (client_info.age < 1) 	/* Error for input of negative value */
			printf("ERROR: Age must be at least 1.\n\n");
				
		if (client_info.age > 120)	/* Error for exceeding maximum age */
			printf("ERROR: Age must be less than 120.\n\n");
		
	} while (client_info.age < 1 || client_info.age > 120); /* end of do-while loop trap */
	
	do
	{
		
		printf("Enter gender (M or F): ");
		fflush(stdin);
		scanf("%c", &client_info.gender);
		fflush(stdin);
		client_info.gender = toupper(client_info.gender); /* Ensures all entries are uppercase */
	
		if (client_info.gender != 'M' && client_info.gender != 'F' && client_info.gender != ' ' && client_info.gender != '\n') /* Gives error if gender entry is not an acceptable value */
			printf("ERROR: Invalid entry, please enter M, F, or leave blank.\n");
	
	} while (client_info.gender != 'M' && client_info.gender != 'F' && client_info.gender != ' ' && client_info.gender != '\n'); /* end of do-while loop trap */

	return client_info;	
	
} /* end function */

void print_info(struct information client_info)
{
	
	/* Prints client information in block format */
	printf("%s \n", client_info.name); 
	printf("%s \n", client_info.address);
	printf("%s, ", client_info.city); 
	printf("%2s ", client_info.state); 
	printf("%.5ld \n", client_info.zip_code);
	
	/* Prints age according to gender */
	
	if (client_info.gender == 'M')
		printf("He is %3d years old. \n", client_info.age);
		
	else if (client_info.gender == 'F')
		printf("She is %3d years old. \n", client_info.age);
		
	else
		printf("Age is %3d.\n", client_info.age);
		
} /* end function */

void safer_gets (char array[], int max_chars)
{
	int i;
	/* Read name from input buffer, character by character, */
	/* up until the maximum number of characters in the array.*/
	/* ------------------------------------------------------ */
	for (i = 0; i < max_chars - 1; i++)
	{
		array[i] = getchar();
		/* If "this" character is the carriage return, */
		/* replace it with a null terminator and exit loop. */
		/* ------------------------------------------------ */
		if (array[i] == '\n')
		{
			array[i] = '\0';
			break;
		}
	} /* end for */
	
	/* If we have pulled out the most we can, */
	/* and, if there are more chars in the buffer, */
	/* clear out the remaining chars in the buffer. */
	/* This is equivalent to the fflush() function. */
	/* -------------------------------------------- */
	if (i == max_chars )
	if (array[i-1] != '\0')
	while (getchar() != '\n');
	
	/* Ensure the last element in the array contains the null
	terminator. */
	/* ------------------------------------------------------------------ */
	array[max_chars-1] = '\0';
	
} /* end safer_gets */

int check_the_state(char stcd[])
{
    int x;

    /* all US States and District of Columbia  */

    char state[51][3] =
     {"AL",    "AK",    "AZ",    "AR",    "CA",    "CO",    "CT",    "DE",    "DC",    
      "FL",    "GA",    "HI",    "ID",    "IL",    "IN",    "IA",    "KS",    "KY",    
      "LA",    "ME",    "MD",    "MA",    "MI",    "MN",    "MS",    "MO",    "MT",    
      "NE",    "NV",    "NH",    "NJ",    "NM",    "NY",    "NC",    "ND",    "OH",    
      "OK",    "OR",    "PA",    "RI",    "SC",    "SD",    "TN",    "TX",    "UT",    
      "VT",    "VA",    "WA",    "WV",    "WI",    "WY"};
    
    /* search for the state entered in the array return 1 if it is found */

    for (x = 0; x < 51; x++)
    {
	   	 if (strcmp(stcd, state[x])== 0)
	   	 return 1;
    }
    printf("\nERROR: State abbreviation is invalid.\n\n");

    return 0;  /* this means the state code was not in the array */

};/* end state code check */

