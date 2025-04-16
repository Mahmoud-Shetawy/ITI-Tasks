#include <stdio.h>

struct Employee {
    char name[30];
    float netSalary;
};

void printEmployee(struct Employee e) {
    printf("Employee Name: %s\n", e.name);
    printf("Net Salary: %.2f\n", e.netSalary);
}

int main() {
    struct Employee emp;

    printf("Enter employee name: ");
    gets(emp.name);
    printf("Enter net salary: ");
    scanf("%f", &emp.netSalary);

    printEmployee(emp);

    return 0;
}
