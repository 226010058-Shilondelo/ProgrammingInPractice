#include <stdio.h>
#include <math.h>

#ifndef NUM_EMPLOYEES
#define NUM_EMPLOYEES 50
#endif

void clearInputBuffer(void);
double readSalary(int employeeNumber);
void captureSalaries(double salaries[], int size);
void displaySalaries(const double salaries[], int size);
double calculateTotal(const double salaries[], int size);
double calculateAverage(const double salaries[], int size);
int findHighestIndex(const double salaries[], int size);
int findLowestIndex(const double salaries[], int size);
void searchSalary(const double salaries[], int size);
void sortSalaries(double salaries[], int size);

int main(void)
{
    double salaries[NUM_EMPLOYEES];
    double sorted[NUM_EMPLOYEES];

    printf("========================================\n");
    printf("   EMPLOYEE SALARY MANAGEMENT SYSTEM\n");
    printf("========================================\n\n");

    captureSalaries(salaries, NUM_EMPLOYEES);
    displaySalaries(salaries, NUM_EMPLOYEES);

    double total = calculateTotal(salaries, NUM_EMPLOYEES);
    double average = calculateAverage(salaries, NUM_EMPLOYEES);
    int highest = findHighestIndex(salaries, NUM_EMPLOYEES);
    int lowest = findLowestIndex(salaries, NUM_EMPLOYEES);

    printf("\n--- SALARY STATISTICS ---\n");
    printf("Total Salary Expenditure: %.2f\n", total);
    printf("Average Salary: %.2f\n", average);
    printf("Highest Salary: %.2f (Employee %d)\n", salaries[highest], highest + 1);
    printf("Lowest Salary: %.2f (Employee %d)\n", salaries[lowest], lowest + 1);

    searchSalary(salaries, NUM_EMPLOYEES);

    /* Sort a copy so the original capture order is preserved */
    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
        sorted[i] = salaries[i];
    }
    sortSalaries(sorted, NUM_EMPLOYEES);

    printf("\n--- SALARIES SORTED (LOWEST TO HIGHEST) ---\n");
    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
        printf("%2d. %.2f\n", i + 1, sorted[i]);
    }

    return 0;
}

void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        /* discard remaining characters */
    }
}

double readSalary(int employeeNumber)
{
    double value;

    printf("Enter salary for employee %d: ", employeeNumber);
    while (scanf("%lf", &value) != 1 || value < 0)
    {
        clearInputBuffer();
        printf("Invalid salary. Enter a non-negative number: ");
    }
    clearInputBuffer();

    return value;
}

void captureSalaries(double salaries[], int size)
{
    for (int i = 0; i < size; i++)
    {
        salaries[i] = readSalary(i + 1);
    }
}

void displaySalaries(const double salaries[], int size)
{
    printf("\n--- ALL SALARIES ---\n");
    for (int i = 0; i < size; i++)
    {
        printf("Employee %2d: %.2f\n", i + 1, salaries[i]);
    }
}

double calculateTotal(const double salaries[], int size)
{
    double total = 0;

    for (int i = 0; i < size; i++)
    {
        total += salaries[i];
    }

    return total;
}

double calculateAverage(const double salaries[], int size)
{
    return calculateTotal(salaries, size) / size;
}

int findHighestIndex(const double salaries[], int size)
{
    int highest = 0;

    for (int i = 1; i < size; i++)
    {
        if (salaries[i] > salaries[highest])
        {
            highest = i;
        }
    }

    return highest;
}

int findLowestIndex(const double salaries[], int size)
{
    int lowest = 0;

    for (int i = 1; i < size; i++)
    {
        if (salaries[i] < salaries[lowest])
        {
            lowest = i;
        }
    }

    return lowest;
}

void searchSalary(const double salaries[], int size)
{
    double target;
    int found = 0;

    printf("\nEnter a salary to search for: ");
    while (scanf("%lf", &target) != 1 || target < 0)
    {
        clearInputBuffer();
        printf("Invalid salary. Enter a non-negative number: ");
    }
    clearInputBuffer();

    for (int i = 0; i < size; i++)
    {
        if (fabs(salaries[i] - target) < 0.005)
        {
            printf("Salary %.2f found: Employee %d\n", target, i + 1);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Salary %.2f not found.\n", target);
    }
}

void sortSalaries(double salaries[], int size)
{
    /* Bubble sort, ascending */
    for (int pass = 0; pass < size - 1; pass++)
    {
        for (int i = 0; i < size - pass - 1; i++)
        {
            if (salaries[i] > salaries[i + 1])
            {
                double temp = salaries[i];
                salaries[i] = salaries[i + 1];
                salaries[i + 1] = temp;
            }
        }
    }
}