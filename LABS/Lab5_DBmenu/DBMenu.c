#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mina.h"

#define UP 65
#define DOWN 66
#define ENTER 10
#define SKIP 27
#define BACKSPACE 127
#define Q 113
#define HOME 425
#define END 311
#define SIZE 5

typedef struct Employee
{
    char name[20];
    int id;
    int netSalary;
} Employee;

void enterEmployee(Employee e[], int size);
void displayEmployeeInfo(Employee e[], int size);
void modifyEmployeeInfo(Employee e[], int size);
void deleteEMployee(Employee e[], int size);
int isUniqueID(Employee e[], int size, int id);
char isValidName(char name[]);
int isValidNetSalary(int netSalary);

int main()
{
    const int menuSize = 5;

    const char menu[5][8] = {"New", "Display", "Modify", "Delete", "Exit"};
    int selected = 0; // my position
    char ch_in;
    Employee e[SIZE] = {0};
    int size = 0;

    while (1)
    {
        // display menu
        clear();
        for (int i = 0; i < menuSize; i++)
        {
            if (i == selected)
            {
                setTextColor(stdout, TC_BLUE);
                printf("%s\n", menu[i]);
            }
            else
            {
                setTextColor(stdout, TC_WHITE);
                printf("%s\n", menu[i]);
            }
        }

        // begin logic for arrow movement
        ch_in = getch();
        if (ch_in == SKIP)
        {
            getch(); // skip ']'
            switch (getch())
            {
            case UP:                                             // up
                selected = (selected - 1 + menuSize) % menuSize; // new position
                break;
            case DOWN: // down
                selected = (selected + 1) % menuSize;
                break;
            }
        }
        else if (ch_in == ENTER)
        {
            if (selected == 4)
            { // if Exit is selected
                system("clear");
                setTextColor(stdout, TC_WHITE);
                printf("Do you want to Exit? [y,n]\n");
                ch_in = getchar();
                if (ch_in == 'y' || ch_in == 'Y')
                {
                    printf("Exiting program\n");
                    return 1;
                }
                else if (ch_in == 'n' || ch_in == 'N')
                {
                    system("clear");
                }
                if (getch() == BACKSPACE)
                {
                    system("clear");
                }
            }

            if (selected == 0)
            { // new
                system("clear");
                setTextColor(stdout, TC_WHITE);
                printf("New\n");
                printf("Do you want to add new employee? [y,n]\n");
                ch_in = getchar();
                if (ch_in == 'y' || ch_in == 'Y')
                {
                    printf("Enter Number of Employees,\" you can add only 5 employees\": ");
                    scanf("%d", &size);
                    enterEmployee(e, size);
                }

                if (getch() == BACKSPACE)
                {
                    system("clear");
                }
            }

            if (selected == 1)
            { // Dispaly
                system("clear");
                setTextColor(stdout, TC_WHITE);
                displayEmployeeInfo(e, size);
            }

            if (getch() == BACKSPACE)
            {
                system("clear");
            }

            else if (selected == 2)
            { // modify
                system("clear");
                setTextColor(stdout, TC_WHITE);
                modifyEmployeeInfo(e, size);
            }
            if (getch() == BACKSPACE)
            {
                system("clear");
            }

            else if (selected == 3)
            { // delete
                system("clear");
                setTextColor(stdout, TC_WHITE);
                displayEmployeeInfo(e, size);
            }
            if (getch() == BACKSPACE)
            {
                system("clear");
            }
        }
    }

    return 0;
}

void enterEmployee(Employee e[], int size)
{
    if (size > SIZE)
    {
        printf("Data base is full ,you can't add more than 5 employees\n ");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        Employee new_e;
        printf("Enter Employee %d code = ", i + 1);
        scanf("%d", &new_e.id);
        while (!isUniqueID(e, size, new_e.id))
        {
            printf("Invalid: Employee ID %d already exists. Please enter a unique ID.\n", new_e.id);
            printf("Enter Employee %d ID: ", i + 1);
            scanf("%d", &new_e.id);
        }
        printf("Enter Employee %d Name = ", i + 1);
        scanf("%s", new_e.name);
        while (!isValidName(new_e.name))
        {
            printf("Error: Invalid name --> Name should not be empty and should be characters.\n");
            printf("Enter Employee %d Name: ", i + 1);
            scanf("%s", new_e.name);
        }
        printf("Enter Employee %d NetSalary = ", i + 1);
        scanf("%f", &new_e.netSalary);
        while (!isValidNetSalary(new_e.netSalary))
        {
            printf("Error: Invalid salary --> Salary must be a positive float.\n");
            printf("Enter Employee %d NetSalary: ", i + 1);
            scanf("%f", &new_e.netSalary);
        }

        e[i] = new_e;
        // size++;
    }
}
void displayEmployeeInfo(Employee e[], int size)
{

    if (size == 0)
    {
        printf("No employees to display.\n");
        return;
    }
    else
    {
        printf("Employees list:\n");
        for (int i = 0; i < size; i++)
        {
            printf("Employee %d id = %d \n", i + 1, e[i].id);
            printf("Employee %d Name = %s \n", i + 1, e[i].name);
            printf("Employee %d netSalary = %f \n", i + 1, e[i].netSalary);
        }
    }
}
void modifyEmployeeInfo(Employee e[], int size)
{
    if (size == 0)
    {
        printf("No employees to modify.\n");
        return;
    }
    int id;
    printf("Do you want to modify an employee info:[y,n]\n ");
    char ch_in = getchar();
    if (ch_in == 'y' || ch_in == 'Y')
    {
        printf("Enter ID of Employee: ");
        scanf(" %d", &id);
    }
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (e[i].id == id)
        {
            found = 1;
            printf("Employee found: %s, Net Salary: %d\n", e[i].name, e[i].netSalary);
            printf("Enter new name: ");
            getchar();
            scanf(" %d", e[i].name);
            printf("Enter new net salary: ");
            scanf(" %d", &e[i].netSalary);
            printf("Employee details updated successfully.\n");
            return;
        }
    }

    if (!found)
        printf("Employee with ID %d not found.\n", id);
}

void deleteEMployee(Employee e[], int size)
{
    if (size == 0)
    {
        printf("No employees to delete.\n");
        return;
    }

    int id;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (e[i].id == id)
        {
            found = 1;

            // Shift the elements down to delete the employee
            for (int j = i; j < size - 1; j++)
            {
                e[j] = e[j + 1]; // Move the next employee's data to the current position
            }

            size--; // Decrease the employee count
            printf("Employee with ID %d deleted successfully.\n", id);
        }
    }

    if (!found)
    {
        printf("Employee with ID %d not found.\n", id);
    }
}
// check if the employee id is unique
int isUniqueID(Employee e[], int size, int id)
{
    for (int i = 0; i < size; i++)
    {
        if (e[i].id == id)
        {
            return 0; // ID is not unique
        }
    }
    return 1; // ID is unique
}

// check if the employee name is valid
char isValidName(char name[])
{
    // Name should not be empty and must contain A_Z ||a_z
    // check if empty
    if (name[0] == '\0')
    {
        return 0;
    }
    for (int i = 0; name[i] != '\0'; i++)
    {
        // Check if each character is either uppercase (A-Z) or lowercase (a-z)
        if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z')))
        {
            return 0; // invalid
        }
    }

    return 1; // vaild
}
// check if the netsalary is valid
int isValidNetSalary(int netSalary)
{
    char ch;
    if (netSalary <= 0)
    {
        // Clear the input buffer of any invalid data  negative or equal 0
        while (getchar() != '\n')
            ;
        printf("Invalid input! Please enter a valid integer: ");
    }
}
