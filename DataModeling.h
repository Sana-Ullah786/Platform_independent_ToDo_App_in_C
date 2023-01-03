#ifndef DATAMODELING_H // if not defined,
#define DATAMODELING_H // define DATAMODELING_H

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// DEFINING THE CONSTANTS
#define TITLE_SIZE 15       // Title Size
#define DESCRIPTION_SIZE 30 // Description Size

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

enum TYPE // Creating an enum TYPE, representing the following
{
    TODO,  // When a task is TODO
    DOING, // When a task is DOING
    DONE   // When a task is DONE
};

struct Date // Creating a struct Date for the following
{
    int day;   // the day
    int month; // the month
    int year;  // the year
};

struct Task // Creating a struct Task for the tasks that we will use
{
    int ID;                             // the ID of the task
    int priority;                       // the priority of the task
    char title[TITLE_SIZE];             // the  title of the task
    char description[DESCRIPTION_SIZE]; // the description of the task
    struct Date *currentDate;           // the current date of the  task
    struct Date *dueDate;               // the due date of the task
    enum TYPE type;                     // the type of the task
};

#endif // end of DATAMODELING_H