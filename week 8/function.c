#include <stdio.h>

#define VAT_RATE 0.15f

void displayWelcome(void);
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
void clearInputBuffer(void);
float readAmount(const char *prompt);

int main(void)
{
    /* Task 1 - displayWelcome() */
    displayWelcome();

    /* Task 2 - calculateVAT() */
    printf("\n--- TASK 2: VAT ---\n");
    float amount = readAmount("Enter amount: ");
    printf("VAT: %.2f\n", calculateVAT(amount));

    /* Task 3 - calculateSalary() */
    printf("\n--- TASK 3: GROSS SALARY ---\n");
    float basic = readAmount("Basic salary: ");
    float housing = readAmount("Housing allowance: ");
    float transport = readAmount("Transport allowance: ");
    printf("Gross salary: %.2f\n", calculateSalary(basic, housing, transport));

    /* Task 4 - calculateBudget() */
    printf("\n--- TASK 4: BUDGET ---\n");
    float revenue = readAmount("Enter revenue: ");
    float expenses = readAmount("Enter expenses: ");
    float result = calculateBudget(revenue, expenses);

    printf("Result: %.2f\n", result);
    if (result > 0)
    {
        printf("SURPLUS\n");
    }
    else if (result < 0)
    {
        printf("DEFICIT\n");
    }
    else
    {
        printf("BALANCED\n");
    }

    return 0;
}

void displayWelcome(void)
{
    printf("Welcome to the Municipal Financial Management System\n");
}

float calculateVAT(float amount)
{
    return amount * VAT_RATE;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        /* discard remaining characters */
    }
}

float readAmount(const char *prompt)
{
    float value;

    printf("%s", prompt);
    while (scanf("%f", &value) != 1 || value < 0)
    {
        clearInputBuffer();
        printf("Invalid input. Enter a non-negative number: ");
    }
    clearInputBuffer();

    return value;
}