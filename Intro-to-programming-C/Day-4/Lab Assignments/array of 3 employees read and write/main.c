#include <stdio.h>
#include <string.h>

struct Employee {
    int ssn;
    char name[50];
    int age;
    float salary;
    float commission;
    float deduction;
};

void printEmployeeNetSalary(struct Employee e) {
    float netSalary = e.salary + e.commission - e.deduction;
    printf("Employee Name: %s\n", e.name);
    printf("Net Salary: %.2f\n", netSalary);
}

int isSSNExists(struct Employee employees[], int count, int ssn) {
    for (int i = 0; i < count; i++) {
        if (employees[i].ssn == ssn) {
            return 1;
        }
    }
    return 0;
}

void readEmployeeData(struct Employee employees[], int index, int count) {
    int ssn;


    do {
        printf("Enter employee SSN : ");
        while (scanf("%d", &ssn) != 1) {
            printf("Invalid SSN! Please enter a valid number: ");

        }
        if (isSSNExists(employees, count, ssn)) {
            printf("SSN already exists! Please enter a unique SSN.\n");
        }
    } while (isSSNExists(employees, count, ssn));

    employees[index].ssn = ssn;

    printf("Enter employee name: ");
    getchar();
    gets(employees[index].name);

    printf("Enter employee age: ");
    scanf("%d", &employees[index].age);

    printf("Enter employee salary: ");
    scanf("%f", &employees[index].salary);

    printf("Enter employee commission: ");
    scanf("%f", &employees[index].commission);

    printf("Enter employee deduction: ");
    scanf("%f", &employees[index].deduction);
}

int main() {
    struct Employee employees[3];

    for (int i = 0; i < 3; i++) {
        printf("\nEnter data for employee %d\n", i + 1);
        readEmployeeData(employees, i, i);
    }

    for (int i = 0; i < 3; i++) {
        printf("\nEmployee %d details:\n", i + 1);
        printEmployeeNetSalary(employees[i]);
    }

    return 0;
}
