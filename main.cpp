#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class Employee {
    int id;
    string name;
    double salary;
public:
    Employee(int employeeId, string employeeName, double employeeSalary)
        : id(employeeId), name(employeeName), salary(employeeSalary) {}

    void display() const {
        cout << "ID: " << id << " | Name: " << name
             << " | Salary: " << salary << endl;
    }
};

int main() {
    vector<Employee> employees;
    int choice;

    while (true) {
        cout << "\n--- Employee Management System ---\n";
        cout << "1. Add Employee\n2. View Employees\n3. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) break;

        if (choice == 1) {
            int id;
            string name;
            double salary;

            cout << "Enter employee ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter employee name: ";
            getline(cin, name);

            cout << "Enter salary: ";
            cin >> salary;

            employees.emplace_back(id, name, salary);
            cout << "Employee added successfully.\n";
        } else if (choice == 2) {
            if (employees.empty()) {
                cout << "No employee records found.\n";
            } else {
                for (const Employee& employee : employees)
                    employee.display();
            }
        } else if (choice == 3) {
            cout << "Exiting system.\n";
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
