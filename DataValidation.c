#include <stdbool.h>        // Include all the boolean functions
#include <stdio.h>          // Include the std i/o functions
#include <stdlib.h>         // Include the stdlib functions
#include <string.h>         // Include the string functions
#include <ctype.h>          // Include the character type functions
#include "DataValidation.h" // Include the data validation functions declared in DataValidation.h
#include "Utilities.h"      // Include the utility functions defined in Utilites.c

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void getInput(char *inp, int size) // creqting a function to get the input from the user
{
    setYellow();                  // Set the color to yellow
    fgets(inp, size, stdin);      // get string input from the user of size "size", which is taken as an arguement
    if (!strchr(inp, '\n'))       // checks if there is a new line in the input from the user
    {                             // if there is no new line, we do the following
        discardExtraCharacters(); // Used to discard all the extra characters that are present from the previous input // Garbage values
    }
    inp[strlen(inp) - 1] = '\0';
    reset(); // reset the colors
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

bool isNumber(char ch) // creating a boolean function to check if a character is a number
{
    return isdigit(ch); // using isdigit to check if a character is a number
}

bool isEmptyStr(char *inp) // function  to check if a string is empty
{
    if (strlen(inp) == 0) // checking if the string is empty
    {
        return true; // returns true if the string is empty
    }
    int size = strlen(inp);        // if string is not empty, then assign the size of the string to an int "size"
    for (int i = 0; i < size; i++) // for loop to check if the string is not empty
    {
        if (inp[i] != ' ') // if all the characters are whitespace, it will end, but even if one character is not, it returns false
        {
            return false; // returns false
        }
    }
    return true; // returns true if the string is empty
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

bool checkStr(char *inp) // Function to check if a string is an integer
{

    int index = 0;             // the index of the first character
    while (inp[index] != '\0') // loop till we get to end of line
    {
        if (inp[index] != ' ') // if even one character is not whitespace
        {
            if (!isNumber(inp[index++])) // and also not a number, then return false
            {
                return false; // returns false
            }
        }
        index++; // increment the index of the first character
    }
    return true; // returns true if the string is not whitespace and is an integer
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int convertToNumber(char *inp) // Function to convert a string to a number
{
    return atoi(inp); // returns the string as an integer
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

bool checkLimits(int target, int low, int high) // boolean function to check if a number is less than or equal to the specified number
{
    if (target > low && target < high) // if condition
    {
        return true; // returns true if the condition is true
    }
    return false; // returns false if the condition is false
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void discardExtraCharacters() // Function to discard any extra characters in the input string // Garbage Values
{
    while (getchar() != '\n') // loop to go through the input string
        ;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/