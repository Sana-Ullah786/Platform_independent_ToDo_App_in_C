#ifndef UTILITIES_H // if not defined
#define UTILITIES_H // define UTILITIES_H

void setRed();    // set color to red
void setYellow(); // set color to yellow
void setBlue();   // set color to blue
void setPurple(); // set color to purple
void setCyan();   // set color to cyan
void setGreen();  // set color to green
void reset();     // reset color

void printError(char *);       // print error message
void printNtimes(char, int);   // print a character/string N number of times
void printSuccess(char *);     // print success message
void printOption(char *);      // print an option message
void setTargetColor(char *);   // set target color
void printAppLogo();           // print the App Logo
void printTime(int, int, int); // print time and quotes
char *findMonthName(int);      // find month name from date string
void printTableHeading();      // print table heading of the list
void printDataHeading();       // print data heading of the list
void printTable();             // print lists in table format
void printFullDataHeading();   //  print full data heading of the list, used for individual task opening

#endif // end of UTILITIES_H