#include <iostream>
using namespace std;

class Employee {
public:   // <--- Make sure everything is public
    int emp_id;
    string emp_name;
    int emp_age;
    string emp_role;
    float emp_salary;
    string emp_city;
    int emp_experience;
    string emp_company_name;

    void inputData() {
        cout << "Enter Employee ID: ";
        cin >> emp_id;
        cin.ignore();

        cout << "Enter Employee Name: ";
        getline(cin, emp_name);

        cout << "Enter Employee Age: ";
        cin >> emp_age;
        cin.ignore();

        cout << "Enter Employee Role: ";
        getline(cin, emp_role);

        cout << "Enter Employee Salary: ";
        cin >> emp_salary;
        cin.ignore();

        cout << "Enter Employee City: ";
        getline(cin, emp_city);

        cout << "Enter Employee Experience (in years): ";
        cin >> emp_experience;
        cin.ignore();

        cout << "Enter Company Name: ";
        getline(cin, emp_company_name);
    }

    void displayData() {
        cout << "\nEmployee ID: " << emp_id;
        cout << "\nName: " << emp_name;
        cout << "\nAge: " << emp_age;
        cout << "\nRole: " << emp_role;
        cout << "\nSalary: " << emp_salary;
        cout << "\nCity: " << emp_city;
        cout << "\nExperience: " << emp_experience << " years";
        cout << "\nCompany Name: " << emp_company_name << endl;
    }
};

int main() {
    const int n = 5;
    Employee emp[n];

    cout << "Enter details of " << n << " Employees:\n";
    for (int i = 0; i < n; i++) {
        cout << "\n--- Employee " << i + 1 << " ---\n";
        emp[i].inputData();
    }

    cout << "\n===== Employee Records =====\n";
    for (int i = 0; i < n; i++) {
        cout << "\n--- Employee " << i + 1 << " ---";
        emp[i].displayData();
    }

    return 0;
}