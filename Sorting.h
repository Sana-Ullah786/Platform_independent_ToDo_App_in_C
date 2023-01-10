#include <stdbool.h>      // Including all the standard boolean functions
#ifndef SORTING_H         // if not defined
#define SORTING_H         // define SORTING_H
#include "DataModeling.h" // Include DataModeling for data models
#include "DataList.h"     // Include DataList for data listing functions

bool isSooner(struct Date *, struct Date *); // boolean function to check whether one date is sooner than the other
void sortOnPriorityAndDate(struct Node **);  // void function to sort a list of tasks on priority and date

#endif // end of SORTING_H