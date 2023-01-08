#include <stdbool.h>   // including all the boolean functions
#ifndef FILEHANDLING_H // if not defined
#define FILEHANDLING_H // define FILEHANDLING_H
#include "DataList.h"  // Include the DataList functions

bool isExist(char *);                   // bool function to Check if the file exists
void readData(char *, struct Node **);  // void function to read data from the file
void writeData(char *, struct Node **); // void function to write data to the file
#endif                                  // end of FILEHANDLING_H