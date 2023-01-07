#ifndef ENCRYPTION_H // if not defined
#define ENCRYPTION_H // define ENCRYPTION_H

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// DEFINING THE CONSTANTS
#define MAX_FNAME 25   // maximum number of characters in first name
#define MAX_LNAME 25   // maximum number of characters in last name
#define MAX_ORGNAME 52 // maximum number of characters in original name

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void encryptName(char *);                      // void function for encrypting a string
void generateFileName(char *, char *, char *); // void function for generating a file name from a string for the user

#endif // end of ENCRYPTION_H