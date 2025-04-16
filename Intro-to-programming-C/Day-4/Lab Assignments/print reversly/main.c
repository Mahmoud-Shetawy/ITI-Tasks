#include <stdio.h>
#include <string.h>

int main() {
    char message[50];
    int length;

    printf("Enter a message: ");
    gets(message);

    length = strlen(message);


    printf("Reversed message: ");
    for(int i = length - 1; i >= 0; i--) {
        printf("%c", message[i]);
    }
    printf("\n");

    return 0;
}
