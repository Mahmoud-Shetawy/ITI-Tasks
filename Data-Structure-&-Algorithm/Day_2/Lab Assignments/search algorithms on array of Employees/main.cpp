#include <iostream>
using namespace std;

struct Employee {
private:
    int id;
    string name;
public:
    // Constructor افتراضي
    Employee() : id(0), name("") {}

    // Constructor اللي بيأخذ بارامترات
    Employee(int _id, string _name) {
        id = _id;
        name = _name;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    void setName(string _name) {
        name = _name;
    }

    void setId(int _id) {
        id = _id;
    }
};

int main() {
    // Array of Employee
    Employee emp[4] = {
        Employee(1, "John Doe"),
        Employee(2, "Jane Doe"),
        Employee(3, "Alice"),
        Employee(4, "Bob")
    };

    // طباعة بيانات أول موظف
    cout << "Employee ID: " << emp[0].getId() << ", Name: " << emp[0].getName() << endl;

    return 0;
}
