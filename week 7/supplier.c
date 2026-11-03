#include <stdio.h>

#define NAME_SIZE 100
#define EMAIL_SIZE 100
#define PHONE_SIZE 20
#define TOWN_SIZE 50

int main(void)
{
    char name[NAME_SIZE];
    char email[EMAIL_SIZE];
    char phone[PHONE_SIZE];
    char town[TOWN_SIZE];

    printf("Enter supplier name: ");
    scanf(" %99[^\n]", name);

    printf("Enter email: ");
    scanf(" %99[^\n]", email);

    /* Phone is stored as text so the leading 0 is kept */
    printf("Enter phone: ");
    scanf(" %19[^\n]", phone);

    printf("Enter town: ");
    scanf(" %49[^\n]", town);

    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town : %s\n", town);

    return 0;
}