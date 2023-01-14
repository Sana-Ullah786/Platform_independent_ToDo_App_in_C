#include <stdio.h>     // including the std i/o functions
#include <stdbool.h>   // including the stdbool functions
#include <stdlib.h>    // including the stdlib functions
#include <time.h>      // including the time functions
#include "DataList.h"  // include the data list functions and prototypes
#include "Sorting.h"   // include the sorting functions functions
#include "Utilities.h" // include the utility functions

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

bool isEmpty(struct Node **head) // boolean function to check if a head/list is empty
{
    return (*head == NULL); // return true if the head is empty
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void insertTask(struct Node **head, struct Task *task) // function to insert a task into the list of tasks
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // creating a newNode with the memory allocation size of a structure Node
    newNode->task = task;                                              // adding the task in parameter to the newNode->task
    newNode->next = NULL;                                              // adding the newNode to the end of the list
    if (isEmpty(head))                                                 // if head is empty ( list also empty )
    {
        *head = newNode; // adding the newNode to the head (first node of the list)

        return; // returning
    }
    else // if head is not empty
    {
        struct Node *temp = *head; // create a new node pointer "temp" and assign "head"'s pointer to it
        while (temp->next != NULL) // traversing the list of tasks until the temp node is the last Node
        {
            temp = temp->next; // going forward until loop stops
        }
        temp->next = newNode; // assigning the newNode to the "next" of the "temp" Node (last Node)
    }
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void printList(struct Node **todoList, struct Node **doingList, struct Node **doneList) // void function to print all the lists
{
    if (isEmpty(todoList) && isEmpty(doingList) && isEmpty(doneList)) // if all the lists are empty
    {
        printError("Sorry There are No Tasks to Display"); // printing the error message
    }
    else // if not all the lists are empty
    {

        printTable();                        // printing the table of tasks (table and data heading)
        struct Node *todoTemp = *todoList;   // create a new node pointer "todoTemp" and assign "todoList"'s pointer to it
        struct Node *doingTemp = *doingList; // create a new node pointer "doingTemp" and assign "doingList"'s pointer to it
        struct Node *doneTemp = *doneList;   // create a new node pointer "doneTemp" and assign "doneList"'s pointer to it

        while (1) // infinite loop
        {
            if (todoTemp == NULL && doingTemp == NULL && doneTemp == NULL) // if all the lists are empty
            {
                setCyan();             // set color to cyan
                printNtimes('-', 154); // PRINTING THE BOX
                break;                 // break out of the infinite loop
            }
            if (todoTemp) // if todoTemp is not NULL
            {

                if (todoTemp->task->priority == 1) // if the priority is 1 // if the task is TODO
                {
                    setYellow();                                                                                                                // set color to yellow
                    printf("|");                                                                                                                // PRINTING THE BOX
                    setRed();                                                                                                                   // set color to red
                    printf("%-4d ", todoTemp->task->ID);                                                                                        // printing the task ID in a 4 character space
                    setGreen();                                                                                                                 // set color to green
                    printf("|");                                                                                                                // PRINTING THE BOX
                    setRed();                                                                                                                   // set color  to red
                    printf("%-16s ", todoTemp->task->title);                                                                                    // printing the task title in a 16 character space
                    setGreen();                                                                                                                 // set color to green
                    printf("|");                                                                                                                // PRINTING THE BOX
                    setRed();                                                                                                                   // set color to red
                    printf(" %02d/%02d/%04d    ", todoTemp->task->dueDate->day, todoTemp->task->dueDate->month, todoTemp->task->dueDate->year); // printing the due date in a 15 character space
                    setGreen();                                                                                                                 // set color to green
                    printf("|");                                                                                                                // PRINTING THE BOX
                    setRed();                                                                                                                   // set color to red
                    printf("%-10s", "HIGH");                                                                                                    // printing the high priority in 10 character space
                    setYellow();                                                                                                                // set color to yellow
                    printf("|");                                                                                                                // PRINTING THE BOX
                }
                else
                {
                    setYellow();                                                                                                                // set color to yellow
                    printf("|");                                                                                                                // PRINTING THE BOX
                    setYellow();                                                                                                                // set color to yellow
                    printf("%-4d ", todoTemp->task->ID);                                                                                        // printing the task ID in a 4 character space
                    setGreen();                                                                                                                 // set color to green
                    printf("|");                                                                                                                // PRINTING THE BOX
                    setYellow();                                                                                                                // set color to yellow
                    printf("%-16s ", todoTemp->task->title);                                                                                    // printing the task title in a 16 character space
                    setGreen();                                                                                                                 // set color to green
                    printf("|");                                                                                                                // PRINTING THE BOX
                    setYellow();                                                                                                                // set color to yellow
                    printf(" %02d/%02d/%04d    ", todoTemp->task->dueDate->day, todoTemp->task->dueDate->month, todoTemp->task->dueDate->year); // printing the task due daye in a 15 character space
                    setGreen();                                                                                                                 // set color to green
                    printf("|");                                                                                                                // PRINTING THE BOX
                    setYellow();                                                                                                                // set color to yellow
                    printf("%-10s", "LOW");                                                                                                     // printing the low priority in 10 character space
                    setYellow();                                                                                                                // set color to yellow
                    printf("|");                                                                                                                // PRINTING THE BOX
                }
                todoTemp = todoTemp->next; // going forward until loop stops
            }
            else
            {
                setYellow();            // set color to yellow
                printf("|");            // PRINTING THE BOX
                printf("%*s", 50, " "); // printing spaces
                printf("|");            // PRINTING THE BOX
            }
            if (doingTemp) // if doingTemp is not NULL
            {
                if (doingTemp->task->priority == 1) // if priority is 1 // if priority is HIGH
                {
                    setYellow();                                                                                                                   // set color to yellow
                    printf("%-4d ", doingTemp->task->ID);                                                                                          // printing the task ID in a 4 character space
                    setGreen();                                                                                                                    // set color to green
                    printf("|");                                                                                                                   // PRINTING THE BOX
                    setYellow();                                                                                                                   // set color to yellow
                    printf("%-16s ", doingTemp->task->title);                                                                                      // printing the task title in a 16 character space
                    setGreen();                                                                                                                    // set color to green
                    printf("|");                                                                                                                   // PRINTING THE BOX
                    setYellow();                                                                                                                   // set color to yellow
                    printf(" %02d/%02d/%04d    ", doingTemp->task->dueDate->day, doingTemp->task->dueDate->month, doingTemp->task->dueDate->year); // printing the due date in a 15 character space
                    setGreen();                                                                                                                    // set color to green
                    printf("|");                                                                                                                   // PRINTING THE BOX
                    setYellow();                                                                                                                   // set color to yellow
                    printf("%-10s", "HIGH");                                                                                                       // printing the high priority in 10 character space
                    setYellow();                                                                                                                   // set color to yellow
                    printf("|");                                                                                                                   // PRINTING THE BOX
                }
                else
                {
                    setYellow();                                                                                                                   // set color to yellow
                    printf("%-4d ", doingTemp->task->ID);                                                                                          // printing the task ID in a 4 character space
                    setGreen();                                                                                                                    // set color to green
                    printf("|");                                                                                                                   // PRINTING THE BOX
                    setYellow();                                                                                                                   // set color to yellow
                    printf("%-16s ", doingTemp->task->title);                                                                                      // printing the task title in a 16 character space
                    setGreen();                                                                                                                    // set color to green
                    printf("|");                                                                                                                   // PRINTING THE BOX
                    setYellow();                                                                                                                   // set color to yellow
                    printf(" %02d/%02d/%04d    ", doingTemp->task->dueDate->day, doingTemp->task->dueDate->month, doingTemp->task->dueDate->year); // printing the  due date in a 15 character space
                    setGreen();                                                                                                                    // set color to green
                    printf("|");                                                                                                                   // PRINTING THE BOX
                    setYellow();                                                                                                                   // set color to yellow
                    printf("%-10s", "LOW");                                                                                                        // printing the low priority in 10 character space
                    setYellow();                                                                                                                   // set color to yellow
                    printf("|");                                                                                                                   // PRINTING THE BOX
                }

                doingTemp = doingTemp->next; // going forward until loop stops
            }
            else
            {
                printf("%*s", 50, " "); // printing the spaces
                setYellow();            // set color to yellow
                printf("|");            // PRINTING THE BOX
            }
            if (doneTemp) // if doneTemp is not NULL
            {
                if (doneTemp->task->priority == 1) // if priority is 1 // if priority is HIGH
                {
                    setGreen();                                                                                                                 // set color to green
                    printf("%-4d ", doneTemp->task->ID);                                                                                        // printing the task ID in a 4 character space
                    printf("|");                                                                                                                // PRINTING THE BOX
                    printf("%-16s ", doneTemp->task->title);                                                                                    // printing the title in a 16 character
                    printf("|");                                                                                                                // PRINTING THE BOX
                    printf(" %02d/%02d/%04d    ", doneTemp->task->dueDate->day, doneTemp->task->dueDate->month, doneTemp->task->dueDate->year); // printing the due date in a 16 character space
                    printf("|");                                                                                                                // PRINTING THE BOX
                    printf("%-10s", "HIGH");                                                                                                    // printing the high priority in 10 character space
                    setYellow();                                                                                                                // set color to yellow
                    printf("|");                                                                                                                // PRINTING THE BOX
                }
                else
                {
                    setGreen();                                                                                                                 // set color to green
                    printf("%-4d ", doneTemp->task->ID);                                                                                        // printing the task ID in a 4 character space
                    printf("|");                                                                                                                // PRINTING THE BOX
                    printf("%-16s ", doneTemp->task->title);                                                                                    // printing the task title in a 16 character space
                    printf("|");                                                                                                                // PRINTING THE BOX
                    printf(" %02d/%02d/%04d    ", doneTemp->task->dueDate->day, doneTemp->task->dueDate->month, doneTemp->task->dueDate->year); // printing the due date in a 15 character space
                    printf("|");                                                                                                                // PRINTING THE BOX
                    printf("%-10s", "LOW");                                                                                                     // printing the low priority in 10  character space
                    setYellow();                                                                                                                // set color to yellow
                    printf("|");                                                                                                                // PRINTING THE BOX
                }

                doneTemp = doneTemp->next; // going forward until loop stops
            }
            else
            {
                printf("%*s", 50, " "); // printing the spaces
                setYellow();            // set color to yellow
                printf("|");            // PRINTING THE BOX
            }
            printf("\n"); // printing a new line
        }
    }
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

struct Task *findTask(struct Node **head, int targetID) // Task type Function that finds a task by its ID and returns it
{
    if (isEmpty(head)) // if the head is empty
    {
        printError("Sorry List is Empty"); // print that list is empty
    }
    else
    {
        struct Node *temp = *head; // create a new node pointer "temp" and assign "head"'s pointer to it
        while (temp)               // loop till temp is NULL // Traversing the list until temp is the last Node
        {
            if (temp->task->ID == targetID) // if the ID of temp matches the targetID, then
            {
                return temp->task; // return the Task that is present on the 'temp' Node
            }
            temp = temp->next; // going forward until loop stops
        }
    }
    return NULL; // returning NULL if head empty // Condition not satisfied
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void separateOnType(struct Node **head, struct Node **taregtHead, enum TYPE type) // create a Function that separates the head list, by the TYPE
{
    if (isEmpty(head)) // if head is empty, return the function
    {
        return;
    }
    else
    {
        struct Node *temp = *head; // create a new node pointer "temp" and assign "head"'s pointer to it
        while (temp)               // loop till temp is NULL
        {
            if (temp->task->type == type) // if the type of temp matches the target type
            {
                insertTask(taregtHead, temp->task); // insert the Task that is present on the 'temp' Node into the targetHead
            }
            temp = temp->next; // going forward until loop stops
        }
    }
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void printFullData(struct Task *task) // void function to print all the lists
{
    setYellow();                                                                                              // set color to yellow
    printf("|");                                                                                              // PRINTING THE BOX
    setRed();                                                                                                 // set color to red
    printf("%-4d ", task->ID);                                                                                // printing the task ID in a 4 character space
    setYellow();                                                                                              // set color to yellow
    printf("|");                                                                                              // PRINTING THE BOX
    setRed();                                                                                                 // set color to red
    printf("%-18s ", task->title);                                                                            // printing the task Title in an 18 character space
    setYellow();                                                                                              // set color to yellow
    printf("|");                                                                                              // PRINTING THE BOX
    setRed();                                                                                                 // set color to red
    printf("%-35s", task->description);                                                                       // printing the task description in a 35 character space
    setYellow();                                                                                              // set color to yellow
    printf("|");                                                                                              // PRINTING THE BOX
    setRed();                                                                                                 // set color to red
    printf(" %02d/%02d/%04d    ", task->currentDate->day, task->currentDate->month, task->currentDate->year); // printing the due date in a 15 character space
    setYellow();                                                                                              // set color to yellow
    printf("|");                                                                                              // PRINTING THE BOX
    setRed();                                                                                                 // set color to red
    printf(" %02d/%02d/%04d    ", task->dueDate->day, task->dueDate->month, task->dueDate->year);             // printing the due date in a 15 character space
    setYellow();                                                                                              // set color to yellow
    printf("|");                                                                                              // PRINTING THE BOX
    setRed();                                                                                                 // set color to red
    printf("%-12s", task->priority == 0 ? "LOW" : "HIGH");                                                    // printing the task priority in a 12 character space
    setYellow();                                                                                              // set color to yellow
    printf("|");                                                                                              // PRINTING THE BOX
    setRed();                                                                                                 // set color to red
    printf("%-8s", task->type == 0 ? "TODO" : task->type == 1 ? "DOING"                                       // printing the task type in an 8 character space
                                                              : "DONE");                                      // printing the task type in an 8 character space
    setYellow();                                                                                              // set color to yellow
    printf("|\n");                                                                                            // PRINTING THE BOX
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void printIndividualTask(struct Node **head) // void function to print an individual task
{
    if (isEmpty(head)) // if head is empty
    {
        printError("There are No Tasks to Show"); // printing an error
        return;                                   // returning
    }
    printFullDataHeading();    // printing the full data heading
    struct Node *temp = *head; // create a new node pointer "temp" and assign "head"'s pointer to it
    while (temp)               // loop until temp is NULL
    {
        printFullData(temp->task); // print the full data of the task in parameter
        temp = temp->next;         // going forward until loop stops
    }
    printNtimes('-', 117); // PRINTING THE BOX
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int findMaxID(struct Node **head) // int function to find the MaxID of the head, so that we can continue where we left off
{
    if (isEmpty(head)) // if head is empty
    {
        return 0; // returning 0
    }
    else
    {
        struct Node *temp = *head; //
        int max = temp->task->ID;  // set the temp task ID to max
        while (temp)               // loop until temp is NULL
        {
            if (temp->task->ID > max) // if the temp task ID is greater than the max
            {
                max = temp->task->ID; // set the temp task ID to max
            }
            temp = temp->next; // going forward until loop stops
        }
        return max; // returning max ID so that we can use in Main function
    }
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void findTodaysDueTasks(struct Node **head, struct Node **targetHead) // void function to find all the tasks due today, by putting them into a target head
{
    if (isEmpty(head)) // if head is empty then return
    {
        return;
    }
    else
    {
        time_t t = time(NULL);         // get current time
        struct tm tm = *localtime(&t); // get local time
        struct Node *temp = *head;     // create a new node pointer "temp" and assign "head"'s pointer to it
        while (temp)                   // loop until temp is NULL
        {
            if (temp->task->dueDate->day == tm.tm_mday && temp->task->dueDate->month == tm.tm_mon + 1 && temp->task->dueDate->year == tm.tm_year + 1900 && temp->task->type == 0) // check if the task's due date is the current date
            {
                insertTask(targetHead, temp->task); // if it is, then insertTask into the target head
            }
            temp = temp->next; // going forward until loop stops
        }
    }
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void deleteTaskByID(struct Node **head, int targetID) // void function to delete a task by its ID
{
    if (isEmpty(head)) // if the head is empty
    {
        return; // returning
    }
    else
    {
        struct Node *temp = *head; // create a new node pointer "temp" and assign "head"'s pointer to it
        struct Node *prev = NULL;  // create a new node pointer "prev" and assign NULL to it
        while (temp)               // loop until temp is NULL
        {
            if (temp->task->ID == targetID) // if the ID of the task matches the targetID
            {
                if (prev) // if a previous task exists
                {
                    prev->next = temp->next; // then the next pointer of temp becomes the next pointer of the previous, and the temp task is now isolated
                }
                else
                {
                    *head = temp->next; // making the next pointer of head the new head
                }
                free(temp);                                // freeing the temp task, (technically deleting it)
                printSuccess("Task Deleted Successfully"); // printing the success message
                return;                                    // returning
            }
            prev = temp;       // assign temp to prev
            temp = temp->next; // and assign temp->next to temp
        }
    }
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void deallocateList(struct Node **head) // void function to deallocate the lists
{
    // recursive function to deallocate the list
    if (isEmpty(head)) //  if the list is empty
    {
        return; // returning
    }
    else
    {
        struct Node *temp = *head; // create a new node pointer "temp" and assign "head"'s pointer to it
        *head = temp->next;        // assign the head to the next pointer of the temp
        free(temp);                // freeing the temp task
        deallocateList(head);      // recursively deallocating all the lists
    }
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/