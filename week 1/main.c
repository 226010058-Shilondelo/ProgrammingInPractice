#include <stdio.h>

#define NAME_SIZE 100

int main(void)
{
    char municipalityName[NAME_SIZE];
    char mayorName[NAME_SIZE];
    long population;

    printf("========================================\n");
    printf("   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("Welcome to Windhoek Municipality\n\n");

    printf("Enter Municipality Name: ");
    scanf(" %99[^\n]", municipalityName);

    printf("Enter Mayor's Name: ");
    scanf(" %99[^\n]", mayorName);

    printf("Enter Population: ");
    while (scanf("%ld", &population) != 1 || population < 0)
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
            /* discard the rest of the bad input */
        }
        printf("Invalid population. Enter a non-negative number: ");
    }

    printf("\n========================================\n");
    printf("        MUNICIPALITY INFORMATION\n");
    printf("========================================\n");
    printf("%-20s: %s\n", "Municipality Name", municipalityName);
    printf("%-20s: %s\n", "Mayor's Name", mayorName);
    printf("%-20s: %ld\n", "Population", population);
    printf("========================================\n");

    return 0;
}