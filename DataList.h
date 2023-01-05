#include <stdbool.h>      // including all the boolean functions
#ifndef DATALIST_H        // if not defined
#define DATALIST_H        // define DATALIST_H
#include "DataModeling.h" // includes Data Modeling.H for data models

struct Node // Creating a structure representing Node
{
    struct Task *task; // Containing one Task Structure
    struct Node *next; // and another Node structure which has a pointer *next to the next Node
};

/*
 * Function:  isEmpty
 * --------------------
 *  Checks if the list is empty
 *
 *  list: The list to check
 *
 *  returns: True if the list is empty, false otherwise
 */
bool isEmpty(struct Node **);
/*
 * Function:  insertTask
 * --------------------
 *  Inserts a task into the list
 *
 *  list: The list to insert the task into
 *  task: The task to insert
 */
void insertTask(struct Node **, struct Task *); // Function for inserting a task into the list

void printList(struct Node **, struct Node **, struct Node **); // Function for printing the list

struct Task *findTask(struct Node **, int); // Function for finding the task in the list

void separateOnType(struct Node **, struct Node **, enum TYPE); // Function for splitting the list on types

void printIndividualTask(struct Node **); // Function for printing individual tasks

void printFullData(struct Task *); // Function for printing the full lists

int findMaxID(struct Node **); // Function for finding the maximum ID in the list of tasks

void findTodaysDueTasks(struct Node **, struct Node **); // Function for finding the tasks that are due to the current time period

void deleteTaskByID(struct Node **, int); // Function for deleting the task by the given ID from user

void deallocateList(struct Node **); // Function for deallocating the list

#endif // end of DATALIST_H