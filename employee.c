#include "employee.h"
#include "validation.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Function to calculate net pay
void calculateNetPay(struct Employee *emp)
{
  // Define percentage constants
  const float DA_PERCENT = 0.40; // DA is 40% of Basic Salary
  const float TA_PERCENT = 0.10; // TA is 10% of Basic Salary
  const float PF_PERCENT = 0.05; // PF is 5% of Basic Salary

  // Calculate DA, TA, and PF
  float DA = DA_PERCENT * emp->BasicSalary;
  float TA = TA_PERCENT * emp->BasicSalary;
  float PF = PF_PERCENT * emp->BasicSalary;

  // Calculate Net Salary
  emp->NetSalary = emp->BasicSalary + DA + TA - PF;
}

// Function to accept employee data with validation
void acceptEmployeeData(struct Employee *emp)
{
  static int empCount = 1; // Static variable to generate unique employee numbers
  emp->Empno = empCount++;
  validateAndAcceptName(emp->EmpName);
  acceptAndValidateDate(&emp->hiredate);
  printf("Enter Basic Salary: ");
  scanf("%f", &emp->BasicSalary);

  // Validate Basic Salary
  if (emp->BasicSalary < 0)
  {
    printf("Basic Salary cannot be negative. Please enter a valid amount.\n");
    return;
  }

  // Calculate Net Pay
  calculateNetPay(emp);
  printf("Employee added successfully.\n");
}

// Function to display employee data
void displayEmployeeData(const struct Employee *emp)
{
  printf("\nEmployee Number: %d\n", emp->Empno);
  printf("Employee Name: %s\n", emp->EmpName);
  printf("Hire Date: %02d/%02d/%04d\n", emp->hiredate.dd, emp->hiredate.mm, emp->hiredate.yy);
  printf("Basic Salary: %.2f\n", emp->BasicSalary);
  printf("Net Salary: %.2f\n", emp->NetSalary);
}

// Function to search for an employee by employee number
int searchEmployee(const struct Employee *employees, int numEmployees, int empNo)
{
  for (int i = 0; i < numEmployees; i++)
  {
    if (employees[i].Empno == empNo)
    {
      return i; // Employee found, return the index
    }
  }
  return -1; // Employee not found
}

// Function to delete an employee by employee number
void deleteEmployee(struct Employee *employees, int *numEmployees, int empNo)
{
  int index = searchEmployee(employees, *numEmployees, empNo);
  if (index != -1)
  {
    // Shift the remaining elements to fill the gap
    for (int i = index; i < (*numEmployees - 1); i++)
    {
      employees[i] = employees[i + 1];
    }
    (*numEmployees)--;
    printf("Employee with Employee Number %d deleted.\n", empNo);
  }
  else
  {
    printf("Employee with Employee Number %d not found.\n", empNo);
  }
}
