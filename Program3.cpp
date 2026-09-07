#include <stdio.h>

struct Date
{
    int date;
    int month;
    int year;
};

void initDate(struct Date* ptrDate)
{
    ptrDate->date = 1;
    ptrDate->month = 1;
    ptrDate->year = 1800;
}

void printDateOnConsole(struct Date* ptrDate)
{
    printf("%d-%d-%d\n",ptrDate->date,ptrDate->month,ptrDate->year);
}

void acceptDateFromConsole(struct Date* ptrDate)
{
    printf("Give day: ");
    scanf("%d", &ptrDate->date);

    printf("Give Month: ");
    scanf("%d", &ptrDate->month);

    printf("Give Year: ");
    scanf("%d", &ptrDate->year);
}

int isLeapYear(struct Date* ptrDate)
{
    if(ptrDate->year % 400 == 0)
        return 1;

    if(ptrDate->year % 100 == 0)
        return 0;

    if(ptrDate->year % 4 == 0)
        return 1;

    return 0;
}

int main()
{
    struct Date d;

    printf("Please choose:\n");

    int num = 100;

    while(num != 0)
    {
        printf("\n");

        printf("0 to Exit:\n");
        printf("1 to Initialize Date:\n");
        printf("2 for Giving Date:\n");
        printf("3 to print Date:\n");
        printf("4 to check leap year:\n");

        scanf("%d", &num);

        switch(num)
        {
            case 0:
                num = 0;
                break;

            case 1:
                initDate(&d);
                break;

            case 2:
                acceptDateFromConsole(&d);
                break;

            case 3:
                printDateOnConsole(&d);
                break;

            case 4:
            {
                int res = isLeapYear(&d);

                if(res == 1)
                {
                    printf("Leap year\n");
                }
                else
                {
                    printf("Not a leap year\n");
                }

                break;
            }

            default:
                printf("Wrong choice\n");
                break;
        }
    }

    return 0;
}
