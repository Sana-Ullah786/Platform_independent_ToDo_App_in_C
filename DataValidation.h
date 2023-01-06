#ifndef DATAVALIDATION_H // if not defined
#define DATAVALIDATION_H // define DATAVALIDATION_H
#include <stdbool.h>     // include for stdbool functions

bool isNumber(char c);           // boolean function for checking if a character is a number
bool checkStr(char *);           // boolean function for checking if a string is a number
int convertToNumber(char *);     // integer function for converting a string to a number
bool checkLimits(int, int, int); // boolean function for checking if a number is less than or equal to the specified number
void discardExtraCharacters();   // void function for discarding extra characters
void getInput(char *, int);      // void function for getting the input string from the user
bool isEmptyStr(char *);         // boolean function for checking if a string is empty

#endif // end of DATAVALIDATION_H