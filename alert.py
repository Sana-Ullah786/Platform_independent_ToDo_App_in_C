# Import required Modules
import sys
import datetime
from plyer import notification


def sendNotification(message):
    """
    This function sends a notification to the user
    :param message: The message to be displayed in the notification
    :return: None
    """
    notification.notify(
        title="Today's Due Tasks",
        message=message,
    )  # send Notification


def getCurrentDate():
    """
    This function returns the current date
    :return: The current date
    """
    now = datetime.datetime.now()  # get current Date
    return now.day, now.month, now.year  # return current day, month and year


def checkDate(day, month, year, type):
    """
    This function checks if the task is due today
    :param day: The day of the task
    :param month: The month of the task
    :param year: The year of the task
    :param type: The type of the task
    :return: True if the task is due today, False otherwise
    """
    currentDay, currentMonth, currentYear = getCurrentDate()  # get Current Date
    # compare the task's due date and Type
    if day == currentDay and month == currentMonth and year == currentYear and type == 0:
        return True
    else:
        return False


def generateMessage(dueTasksList):
    """
    This function generates the message to be displayed in the notification
    :param dueTasksList: The list of tasks due today
    :return: The message to be displayed in the notification
    """
    message = str(len(dueTasksList)) + \
        " Tasks Due Today\n"  # Determine Number of Tasks due today

    for i in range(len(dueTasksList)):
        """
        Generate the message to be displayed in the notification
        by Looping all over the due tasks and append them in the Message String
        """
        tokens = dueTasksList[i].split(',')  # tokenize the Task Line
        # append Number and Task Title
        message += "Task " + str(i+1) + ": " + tokens[1] + "\n"
    return message


def main():
    """
    This function is the main function of the program
    :return: None
    """
    fileName = sys.argv[1:]  # get filename from command Line
    dueTasksList = []  # create an empty list of dueTasks
    with open(fileName[0], 'r') as f:  # Open file in Reading Mode
        for line in f:  # Loop over file lines
            tokens = line.split(',')  # tokenize each Line
            # check if the Task is due today and Type is todo
            if checkDate(int(tokens[7]), int(tokens[8]), int(tokens[9]), int(tokens[10])):
                dueTasksList.append(line)  # append it in the List
    # remove new line characters
    dueTasksList = [x.strip() for x in dueTasksList]
    if (len(dueTasksList) != 0):  # if there is even 1 Task due todya
        # generate Message and send Notification
        sendNotification(generateMessage(dueTasksList))


if __name__ == '__main__':
    main()