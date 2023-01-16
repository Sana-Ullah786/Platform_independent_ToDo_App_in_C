#include <stdio.h>          // include the std i/o functions
#include <stdlib.h>         // include the stdlib functions
#include <string.h>         // include the string functions
#include <stdbool.h>        // include the boolean functions
#include "fileHandling.h"   // include the file handling functions
#include "DataModeling.h"   // include the datamodels
#include "DataList.h"       // include the data listing functions
#include "DataValidation.h" // include the data validation functions

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

bool isExist(char *fileName) // creating a boolean function that checks if a file exists
{
    FILE *file = fopen(fileName, "r"); // opening the file in "r" mode
    return file != NULL;               // returns true if the file exists
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void readData(char *fileName, struct Node **head) // function for reading the data from the file, and assigning the data to the head
{
    FILE *file = fopen(fileName, "r"); // opening the file in "r" mode

    char *token;                            // creating a character pointer "token" for using atoi later
    char line[1000];                        // creating a "line" character to read the line
    int type;                               // initializing the type of the task
    struct Task *task;                      // creating a task Structure
    while (fgets(line, sizeof(line), file)) // reading the "file" line by line, and setting the line data to "line"
    {

        task = (struct Task *)malloc(sizeof(struct Task));              // assigning memory of a structure Task to the "task"
        task->currentDate = (struct Date *)malloc(sizeof(struct Date)); // assigning memory of a structure Date to the current date of the "task"
        task->dueDate = (struct Date *)malloc(sizeof(struct Date));     // assigning memory of a structure Date to the due date of the "task"
        token = strtok(line, ",");                                      // strtok breaks the line into different parts separated by a comma
        task->ID = atoi(token);                                         // atoi converts the "token" string to an integer and assigns it to the task->ID
        token = strtok(NULL, ",");                                      // goes to the next character in the line after commas
        strcpy(task->title, token);                                     // setting the task->title to the "token" string
        token = strtok(NULL, ",");                                      // goes to the next character in the line after commas
        task->priority = atoi(token);                                   // atoi converts the "token" string to an integer and assigns it to the task->priority
        token = strtok(NULL, ",");                                      // goes to the next character in the line after commas
        strcpy(task->description, token);                               // setting the task->description to the "token" string
        token = strtok(NULL, ",");                                      // goes to the next character in the line commas
        task->currentDate->day = atoi(token);                           // setting the task->currentDate->day to the " token" string
        token = strtok(NULL, ",");                                      // goes to the next character in the line after commas
        task->currentDate->month = atoi(token);                         // setting the task->currentDate->month to the " token" string
        token = strtok(NULL, ",");                                      // goes to the next character in the line after commas
        task->currentDate->year = atoi(token);                          // setting the task->currentDate->year to the " token" string
        token = strtok(NULL, ",");                                      // goes to the next character in the line after commas
        task->dueDate->day = atoi(token);                               // setting the task->dueDate day to the " token" string
        token = strtok(NULL, ",");                                      // goes to the next character in the line  after commas
        task->dueDate->month = atoi(token);                             // setting the task->dueDate month to the " token" string
        token = strtok(NULL, ",");                                      // goes to the next character in the line after commas
        task->dueDate->year = atoi(token);                              // setting the task->dueDate year to the " token" string
        token = strtok(NULL, ",");                                      // goes to the next character in the line  after commas
        type = atoi(token);                                             // setting the task->type to the " token" string
        task->type = type;                                              // setting the task->type to the " token" string
        insertTask(head, task);                                         // adding the task to the head of the list
        task = NULL;                                                    // setting the task to NULL so memory is saved
    }
    fclose(file); // closing the file
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void writeData(char *fileName, struct Node **head) // Function to write the data to the file
{
    FILE *file = fopen(fileName, "w"); // opening the file for writing
    struct Node *temp = *head;         // creating a Node Structure "temp" and setting it to the head of the list
    while (temp)                       // traversing through the list of nodes
    {
        /*ADDING THE DATA IN PROPER FORMAT TO THE FILE< SO THAT IT'S READABLE WHEN WE CALL readData*/
        fprintf(file, "%d,%s,%d,%s,%d,%d,%d,%d,%d,%d,%d", temp->task->ID, temp->task->title, temp->task->priority, temp->task->description, temp->task->currentDate->day, temp->task->currentDate->month, temp->task->currentDate->year, temp->task->dueDate->day, temp->task->dueDate->month, temp->task->dueDate->year, temp->task->type);
        temp = temp->next;   // Traversing to the next Node structure
        fprintf(file, "\n"); // printing newline so file stays in a proper format
    }
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/