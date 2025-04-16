#include <stdio.h>
#include <stdlib.h>
struct Employee {
    int id;
    char name[10];
    int age;
};

int main() {
    struct Employee e1 = {1, "Ali", 22};
    struct Employee *empPtr = &e1;


    empPtr->id = 23;
    strcpy(empPtr->name, "Sheto");
    empPtr->age = 23;

    printf("ID: %i\nName: %s\nAge: %i\n", empPtr->id, empPtr->name, empPtr->age);
    return 0;
}

