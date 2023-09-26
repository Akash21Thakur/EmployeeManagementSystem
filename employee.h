// Define the Date structure
struct Date
{
    int dd, mm, yy;
};

// Define the Employee structure
struct Employee
{
    int Empno;
    char EmpName[51];
    struct Date hiredate;
    float BasicSalary;
    float NetSalary;
};

// Function prototypes
void calculateNetPay(struct Employee *emp);
void acceptEmployeeData(struct Employee *emp);
void displayEmployeeData(const struct Employee *emp);
int searchEmployee(const struct Employee *employees, int numEmployees, int empNo);
void deleteEmployee(struct Employee *employees, int *numEmployees, int empNo);
