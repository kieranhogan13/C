/*Kieran Hogan
C12561353
DT 228/1
Persistent Data Assignment 1*/

/***************************************
****************START******************
***************************************/

//Declaring libraries
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


//Declaring function prototypes
void addEmployee (void);
void deleteEmployee (void);
void listEmployees (void);
void compactRecords (void);

//Initialising Structure for header totals
struct totals
{
    int total_employee_count;
    int total_deleted_count;
    char filler [16];
}header;

//Initialising Structure for employee database
struct employee 
{
    char employee_number[6];
    char surname[16];
    char firstname[16];
    char address[26];
    char department[10];
    char duration[2];
}record;


/***************************************
****************MAIN*******************
***************************************/

int main(void) 
{
    printf("ATTENTION: If running program without an employee.dat,"
        "\nplease press 1 to add at least one employee.\n");
    printf("\nPress enter to continue...");
    getchar();
    int menu;
    //Defaults menu to loop continuously unless case 5 is choosen(5. Exit)
    int loop_menu = 1;
    while (loop_menu==1)
    {
        //Displaying menu
        clrscr();
        printf("---Employee Database---\n\n"); 
        printf("\n1. Add Employee");
        printf("\n2. Delete Employee");
        printf("\n3. List Employees");
        printf("\n4. Compact Records");
        printf("\n5. Exit");
        //Taking menu choice
        printf("\n\nEnter your choice: "); 
        scanf("%d",&menu);
        system("CLS");
        
        //Using switch cases in order to create menu that can be reaccessed
        switch( menu )
        {
         
            case 1:
            {
            //Calling function addEmployee();
            addEmployee();
            break;
            }//end case
         
            case 2:
            {
            //Calling function deleteEmployee();
            deleteEmployee();
            break;
            }//end case
         
            case 3:
            {
            //Calling function listEmployees();
            listEmployees();
            break;
            }//end case
         
            case 4:
            {
            //Calling function compactRecords();
            compactRecords();
            break;
            }//end case
            
            case 5:
            {
            //No function called, just hit enter and return 0 closes program
            printf("\n5.Exit:\n\n");
            printf("\nPress Enter to Exit");
            getchar();
            return 0;
            }//end case
         
            default:
            {
            //Error checking to provide easy menu use
            printf("\nInvalid selection: please enter a valid menu option\nHit enter to continue\n");
            getchar();
            break;
            }//end default case
         
        }//end switch
    }
    //end while
    getchar();
    //fclose(employee);
    getchar();
    return 0;
}


/***************************************
************ADD EMPLOYEE**************
***************************************/
/*The addEmployee() function. This creates a new library file, adds an initialised header record, 
followed by adding all active records found in the original library file. On completion, 
it returns to the start of the new file to overwrite the header record with the correct record count values.
*/

void addEmployee (void)
{ 
    clrscr();
    printf("\n1.Add Employee:\n\n"); 
    
    //Opens the file
    FILE *employee;
    employee = fopen("employee.dat", "ab+");
    
    //Defaults choice to add employee to 1
    int choice = 1;
    char employee_number_found = 'n';
    char check_employee_number[6];
    
        
    while(choice == 1)
    {
        do{
            //Takes employee number for user
            printf("\nEnter 5 digit Employee Number: "); 
            scanf("%s", check_employee_number);
            fflush(stdin);
            //Defaults number found to not found (n)
            employee_number_found = 'n';
            //Positions the file pointer for fread
            fseek(employee, 0, SEEK_SET);
            
            //While loop condition(fread ==1)
            while(fread(&record, sizeof(record), 1, employee) == 1)
            {
                //If check employee number is in record
                if(strcmp(record.employee_number, check_employee_number) == 0)
                {
                    //Employee number found, so offers user chance to try again
                    employee_number_found = 'y';
                    fseek(employee, 0, SEEK_END);
                    printf("\nEmployee number found.Please enter a different one.");
                }
                //end if
            }
            //end nested while
        }while(employee_number_found == 'y');
        //end nested do while
        
        //The employee has not been found, so the employee number has been copied
        printf("\nEmployee number not found. Please continue to enter details.\n");
        strcpy(record.employee_number, check_employee_number);
        
        //Takes the surname from the user
        printf("\nEnter surname: ");
        scanf("%s", record.surname);
        fflush(stdin);
        
        //Takes the firstname from user
        printf("\nEnter firstname: ");
        scanf("%s", record.firstname);
        fflush(stdin);
        
        //Takes the address from user
        printf("\nEnter address: ");
        scanf("%s", record.address);
        fflush(stdin);
        
        //Takes the deptartment from user
        printf("\nEnter department: ");
        scanf("%s", record.department);
        fflush(stdin);
        
        //Takes duration from user
        printf("\nEnter duration in years: ");
        scanf("%s", record.duration);
        fflush(stdin);
        
        //Writes the employee record details to the file
        fwrite(&record, sizeof(record), 1, employee);
        
        clrscr();
        printf("\nRecord successfully created. To complete process, please compact records.\n");
        printf("\nPress enter to continue\n");
        getchar();
        //Allows the user to add another record if they choose
        printf("\n1. Add another Record");
        printf("\n2. Return to menu");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        clrscr();
    } //end while
    //Close file
    fclose(employee);
}



/***************************************
***********DELETE EMPLOYEE************
***************************************/
/*The deleteEmployee() funciton. This allows the user to delete
any employee from the database by submtting the 6 digit or less
employee number. If the number is not found the program will not
delete any employees and displays the error.
*/

void deleteEmployee (void)
{
    clrscr();
    printf("\n2.Delete Employee:\n\n");
    
    //Opens the file
    FILE *employee;
    employee = fopen("employee.dat", "rb+");
    
    //Make asterisk a character so it can be put inside string
    char asterisk = '*';
    
    //Defaulting employee number as not matched
    char employee_number_matched = 'n';
    
    //Making delete the same size as employee number
    char del_employee_number[6];
    
    //Allowing RECSIZE to contain long integer
    long int RECSIZE;
    RECSIZE = sizeof(record);
    
    //While loop condition(fread ==1)
    while(fread(&record, sizeof(record), 1, employee) == 1)
    {
        //Only prints employees without * in front of the number
        if(record.employee_number[0] != '*')
        {
            //Prints the records of each employee
            printf("\n%s | %s | %s | %s | %s | %s\n",
            record.employee_number, record.surname, record.firstname, record.address, 
            record.department, record.duration);
        }
        //end if
    }
    //end while
    
    //Takes employee number
    printf("\nEnter 5 digit employee number for deletion:");
    scanf("%s", del_employee_number);
    fflush(stdin);
    
    fseek(employee, 0, SEEK_SET);
    
    //While loop condition(fread ==1)
    while(fread(&record, sizeof(record), 1, employee) == 1)
    {
        //If the employee number is found
        if(strcmp(record.employee_number, del_employee_number) == 0)
        {
            //Positions the file pointer for fwrite
            fseek(employee, -RECSIZE, SEEK_CUR);
            
            //An asterisk is written to the first part of the string
            fwrite(&asterisk, 1, 1, employee);
            
            //Positions the file pointer to the end
            fseek(employee, 0, SEEK_END);
            
            printf("\nRecord successfully deleted. To completely remove, please compact records.\n");
            employee_number_matched = 'y';
            
            //Increase total deleted counter by 1
            header.total_deleted_count++;
            getchar();
        }
        //end if
    }
    //end while
    
    //If the employee number is not found
    if(employee_number_matched == 'n')
    {
        printf("\nEmployee not found: Press enter to continue\n");
        getchar();
    }
    //end if
    
    //Close file
    fclose(employee);
    
    
}


/***************************************
***********LIST EMPLOYEES*************
***************************************/
/*The listEmployees() function. This reads the database file out in a table of information
regarding all the employees in the database. It also reads the total employees and total
deteled employees.*/

void listEmployees (void)
{
    clrscr();
    printf("\n3.List Employees:\n\n");

    //Opens the file
    FILE *new_employee;
    new_employee = fopen("new_employee.dat", "rb+");

    //Reads from the stream bytes of each element
    fread(&header, sizeof(header), 1, new_employee);
    //Printing total employees and total deleted employees
    printf("\nTotal Employees: %d \n\nTotal Deleted Employees: %d \n\n", 
    header.total_employee_count, header.total_deleted_count);
    
    //Close file
    fclose(new_employee);
    
    //Opens the file
    FILE *employee;
    employee = fopen("employee.dat", "rb+");
    
    //Prints different titles for employee details
    printf("\nEmployee Number | Surname | Firstname | Address | Department | Duration\n");
    printf("\n=======================================================================\n");
    
    //While loop condition(fread ==1)
    while(fread(&record, sizeof(record), 1, new_employee) == 1)
    {
        if(record.employee_number[0] != '*')
        {
            //Printing records of each employee
            printf("\n%s | %s | %s | %s | %s | %s\n",
            record.employee_number, record.surname, record.firstname, record.address, 
            record.department, record.duration);
        }
        //end if
    }
    //end while
    printf("\n=======================================================================\n");
    //Close file
    fclose(employee);
    
    printf("\nRecords displayed: Press enter to continue");
    getchar();
        
}


/***************************************
***********COMPACT RECORDS***********
***************************************/

/*The compaction function. This creates a new library file, adds an initialised header record, 
followed by adding all active records found in the original library file. On completion, 
it returns to the start of the new file to overwrite the header record with the correct record count values.
*/

void compactRecords (void)
{
    clrscr();
    printf("\n4.Compact Records:\n\n");
    
    //Opens the two files
    FILE *employee, *new_employee;
    employee = fopen("employee.dat", "rb+");
    new_employee = fopen("new_employee.dat", "wb+");
    
    //Counting the total employees, relies on function compactRecords();
    int count = 0;
    
    //Makes the counters = 0
    header.total_employee_count = 0;
    
    
    //Write out the header record initialised with a ‘0’ record count values to the new library file
    fwrite(&header, sizeof(header), 1, new_employee);
    
    //Write all active records from the old employee file to the new employee file
    while(fread(&record, sizeof(record), 1, employee) == 1)
    {
        //Only if * found at start of string
        if(record.employee_number[0] != '*')
        {
            fwrite(&record, sizeof(record), 1, new_employee);
            count++;
        }
        //end if
    }
    //end while
    
    //Transfer of active records, go back to the header record and re-write the correct record count
    header.total_employee_count = count;
    fseek(new_employee, 0, SEEK_SET);
    fwrite(&header, sizeof(header), 1, new_employee);
    
    //Close files
    fclose(employee);
    fclose(new_employee);
    
    printf("\nRecords compacted: Press enter to continue");
    getchar();
}



/***************************************
*****************END*******************
***************************************/