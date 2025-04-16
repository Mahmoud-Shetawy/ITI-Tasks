#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[30];
    float netSalary;
    int ssn;
};

void printEmployee(struct Employee e) {
    printf("Employee ID: %d\n", e.id);
    printf("Employee Name: %s\n", e.name);
    printf("Net Salary: %.3f\n", e.netSalary);
    printf("SSN: %d\n", e.ssn); //
}

int main() {
    struct Employee employees[10] = {0};
    int index;
    char cont;

    do {
        do {
            printf("Choose index 0-->9: ");
            scanf("%d", &index);
        } while(index < 0 || index > 9);


        int ssn;
        int ssnExists = 0;

        printf("Enter SSN: ");
        scanf("%d", &ssn);

        for (int i = 0; i < 10; i++) {
            if (employees[i].ssn == ssn) {
                printf("SSN already exists! Please enter a unique SSN.\n");
                ssnExists = 1;
                break;
            }
        }

        if (ssnExists) {
            continue;
        }




        employees[index].id = index + 1;
        printf("Enter name: ");
        _flushall();
        fgets(employees[index].name, sizeof(employees[index].name), stdin);
        employees[index].name[strcspn(employees[index].name, "\n")] = 0;

        printf("Enter net salary: ");
        scanf("%f", &employees[index].netSalary);
        employees[index].ssn = ssn;

        printf("Continue (y/n)? ");
        _flushall();
        scanf("%c", &cont);
    } while(cont != 'n');


    for(int i = 0; i < 10; i++) {
        if(employees[i].id != 0) {
            printEmployee(employees[i]);
        }
    }

    return 0;
}
