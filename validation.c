#include <ctype.h>
#include<string.h>
#include <stdbool.h>
#include<stdio.h>
#include"employee.h"

void formatName(char *name)
{
  int i = 0;
  int newWord = 1; // Flag to indicate the start of a new word (name)
  while (name[i])
  {
    if (isspace(name[i]))
    {
      newWord = 1; // Next character is the start of a new word
    }
    else
    {
      if (newWord)
      {
        name[i] = toupper(name[i]); // Capitalize the first character of the word
        newWord = 0; // Reset the new word flag
      }
      else
      {
        name[i] = tolower(name[i]); // Convert to lowercase
      }
    }
    i++;
  }
}

void validateAndAcceptName(char *empName)
{
  bool flagName = true;
  char tempName[100];
  while (flagName)
  {
    printf("\nEnter Employee Name: ");
    scanf(" %99[^\n]%*c", tempName);
    if (strlen(tempName) > 50)
   {
      printf("\nPlease enter the name having max 50 letters");
      continue;
    }
    else
    {
      flagName = false;
      strcpy(empName, tempName);
      formatName(empName);
      break;
    }
  }
}

// Function to accept and validate the date input
void acceptAndValidateDate(struct Date *date) {
  while (1) {
    bool validDate = true;
    printf("Enter Hire Date (dd mm yyyy): ");
    if (scanf("%d %d %d", &date->dd, &date->mm, &date->yy) != 3) {
      // Invalid input format
      validDate = false;
    } else {
      // Check for valid date components
      if (date->dd < 1 || date->dd > 31 || date->mm < 1 || date->mm > 12 || date->yy < 1900 || date->yy > 2100) {
       validDate = false;
      }
    }
    if (!validDate) {
      printf("Invalid date format or out-of-range(1900-2100) values. Please enter a valid date (dd mm yyyy).\n");
      // Clear input buffer to handle incorrect input
      int c;
      while ((c = getchar()) != '\n' && c != EOF);
    } else {
      break; // Exit the loop if a valid date is entered.
    }
  }
}
