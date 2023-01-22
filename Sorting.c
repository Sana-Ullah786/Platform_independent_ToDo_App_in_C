#include <stdlib.h>  // Include standard library functions
#include <stdbool.h> // Include standard boolean functions
#include "Sorting.h" // Include header information on Sorting

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

bool isSooner(struct Date *d1, struct Date *d2) // Creating a function to check which of two dates is sooner
{                                               // We Pass Two Date Structures as arguements
    if (d1->year < d2->year)                    // checking two years
    {
        return true; // returning true if the first date is earlier
    }
    else if (d1->year == d2->year) // if the year is same
    {
        if (d1->month < d2->month) // checking two months
        {
            return true; // returning true if the first date is earlier
        }
        else if (d1->month == d2->month) // if the month is same
        {
            if (d1->day < d2->day) // checking two dates
            {
                return true; // returning true if the first date is earlier
            }
        }
    }
    return false; // returning false if no condition satisfied
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void sortOnPriorityAndDate(struct Node **head) // Create a function to sort the head list on priority and date
{
    if (isEmpty(head)) // if the head is empty then returning the function
    {
        return;
    }
    else
    {
        struct Node *current = *head; // making a node structure and setting it to the head pointer
        struct Node *index = NULL;    // making an index node structure and setting it to NULL
        while (current)               // creating a loop to sort the cuurent list
        {
            index = current->next; // setting index as current->next
            while (index)          // creating a loop to sort the index relatively to the current list
            {
                if (current->task->priority < index->task->priority) // setting on priority first
                {
                    struct Task *temp = current->task; // creating a temp Task structure for sorting
                    current->task = index->task;       // substituting using a buffer
                    index->task = temp;                // completing the substitution
                }
                else if (current->task->priority == index->task->priority) // if priority is same then sort by date
                {
                    if (!isSooner(current->task->dueDate, index->task->dueDate)) // checking if the first date is later, if it is, then substitute
                    {
                        struct Task *temp = current->task; // creating a temp Task structure for sorting
                        current->task = index->task;       // substituting using a buffer
                        index->task = temp;                // completing the substitution
                    }
                }
                index = index->next; // setting index as the next head for next iteration
            }
            current = current->next; // setting current as next head for next iteration
        }
    }
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/