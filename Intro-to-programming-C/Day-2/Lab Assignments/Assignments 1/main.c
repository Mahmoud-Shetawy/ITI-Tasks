#include <stdio.h>

int main() {
    int flag = 1;
    do{

    int year, month, day;

    int currentYear = 2024, currentMonth = 10, currentDay = 16;


    printf("Please, enter your year (1980-2024): ");
    scanf("%i", &year);


    while (year < 1980 || year > 2024) {
        printf("Please enter your year (1980-2024): ");
        scanf("%i", &year);
    }


    printf("Please, enter your month (1-12): ");
    scanf("%i", &month);

    while (month < 1 || month > 12) {
        printf("Please, enter your month (1-12): ");
        scanf("%i", &month);
    }

    int day_Month = 31;

    if (year % 4 == 0 ) {

     if (month == 2) {
        day_Month =  29;
    }
    }


    if(month == 4 ||month == 6 ||month == 9 ||month == 11 ){
        day_Month = 30;
    }

    printf("Please, enter your day: ");
    scanf("%i", &day);

    while (day < 1 || day > day_Month) {

        printf("Please, enter your day: ");
        scanf("%i", &day);
    }

    int Your_Years = currentYear - year;
    int Your_Months = currentMonth - month;
    int Your_Days = currentDay - day;


    if (Your_Days < 0) {

        Your_Days = Your_Days + day_Month;
        Your_Months--;
    }


    if (Your_Months < 0) {

        Your_Months =Your_Months + 12;
        Your_Years--;
    }

    printf("\n \n your Age is \t %i years \t %i months \t  %i days.\n", Your_Years, Your_Months,Your_Days);

    printf("\n \n You want to repeat the operation(yes = 1 or No = 0) : ");
    scanf("%i", &flag);
}while(flag);
    return 0;
}
