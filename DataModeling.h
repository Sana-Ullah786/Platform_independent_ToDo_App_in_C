#ifndef DATAMODELING_H
#define DATAMODELING_H
#define TITLE_SIZE 15
#define DESCRIPTION_SIZE 30 

enum TYPE
{
    TODO,
    DOING,
    DONE,
    EVENT
};

struct Date
{
    int day;
    int month;
    int year;
};

struct Task
{
    int ID;
    int priority;
    char title[TITLE_SIZE];
    char description[DESCRIPTION_SIZE];
    struct Date *currentDate;
    struct Date *dueDate;
    enum TYPE type;
};

#endif