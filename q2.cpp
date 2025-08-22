#include <iostream>
using namespace std;

class Car {
private:
    int car_id;
    string car_company_name;
    string car_color;
    string car_model;
    int car_release_year;

public:
    // Method to input car details
    void setData() {
        cout << "Enter Car ID: ";
        cin >> car_id;
        cin.ignore();

        cout << "Enter Car Company Name: ";
        getline(cin, car_company_name);

        cout << "Enter Car Color: ";
        getline(cin, car_color);

        cout << "Enter Car Model: ";
        getline(cin, car_model);

        cout << "Enter Car Release Year: ";
        cin >> car_release_year;
    }

    // Method to display car details
    void getData() {
        cout << "\nCar ID: " << car_id;
        cout << "\nCompany Name: " << car_company_name;
        cout << "\nColor: " << car_color;
        cout << "\nModel: " << car_model;
        cout << "\nRelease Year: " << car_release_year << endl;
    }
};

int main() {
    const int n = 4;   // number of cars
    Car car[n];

    cout << "Enter details of " << n << " Cars:\n";
    for (int i = 0; i < n; i++) {
        cout << "\n--- Car " << i + 1 << " ---\n";
        car[i].setData();
    }

    cout << "\n===== Car Records =====\n";
    for (int i = 0; i < n; i++) {
        cout << "\n--- Car " << i + 1 << " ---";
        car[i].getData();
    }

    return 0;
}