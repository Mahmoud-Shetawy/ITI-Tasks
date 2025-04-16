#include <stdio.h>
#include <string.h>

int main() {
    char firstName[30], lastName[30], fullName[60];

    printf("Enter first name: ");
    gets(firstName);
    printf("Enter last name: ");
    gets(lastName);

    strcpy(fullName, firstName);

    strcat(fullName, " ");

    strcat(fullName, lastName);

    printf("Full Name: %s\n", fullName);

    return 0;
}
