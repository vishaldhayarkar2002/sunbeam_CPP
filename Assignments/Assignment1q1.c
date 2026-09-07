#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date* ptrDate)
{
    ptrDate->day = 1;
    ptrDate->month = 1;
    ptrDate->year = 2000;
}

void printDateOnConsole(struct Date* ptrDate)
{
    printf("Date: %02d/%02d/%d\n",
           ptrDate->day,
           ptrDate->month,
           ptrDate->year);
}

void acceptDateFromConsole(struct Date* ptrDate)
{
    printf("Enter day: ");
    scanf("%d", &ptrDate->day);

    printf("Enter month: ");
    scanf("%d", &ptrDate->month);

    printf("Enter year: ");
    scanf("%d", &ptrDate->year);
}

int main()
{
    struct Date d;
    int choice;

    do
    {
        printf("\n--- Date Menu ---\n");
        printf("1. Initialize Date\n");
        printf("2. Accept Date\n");
        printf("3. Print Date\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                initDate(&d);
                printf("Date initialized.\n");
                break;

            case 2:
                acceptDateFromConsole(&d);
                break;

            case 3:
                printDateOnConsole(&d);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 0);

    return 0;
}