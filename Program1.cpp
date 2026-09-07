#include <stdio.h>
struct Date {
	int day;
	int month;
	int year;
};

void initDate(struct Date* ptrDate);
void printDateOnConsole(struct Date* ptrDate);
void acceptDateFromConsole(struct Date* ptrDate);

int main( void ) {
	bool flag=true;
	while(flag) {
		struct Date today;
		int option;
		printf("1. Enter date\n");
		printf("2. Print date\n");
		printf("3. Exit\n");
		printf("Enter option: ");
		scanf("%d", &option);
		switch(option) {
			case 1:
				acceptDateFromConsole(&today);
				initDate(&today);
				break;
			case 2:
				printDateOnConsole(&today);
				break;
			case 3:
				flag=false;
				break;
			default:
				printf("Wrong option\n");
		}
	}
	return 0;
}

void printDateOnConsole(struct Date* ptrDate) {
	printf("%d-%d-%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

void acceptDateFromConsole(struct Date* ptrDate) {
	printf("Enter day: ");
	scanf("%d", &ptrDate->day);
	printf("Enter month: ");
	scanf("%d", &ptrDate->month);
	printf("Enter year: ");
	scanf("%d", &ptrDate->year);
}

void initDate(struct Date* ptrDate) {
	if(ptrDate->day<1 || ptrDate->day>31) {
		printf("Invalid day entered\n");
	} else if(ptrDate->month<1 || ptrDate->month>12) {
		printf("Invalid month entered\n");
	} else if(ptrDate->year<1000 || ptrDate->year>2026) {
		printf("Invalid year entered\n");
	}
}
