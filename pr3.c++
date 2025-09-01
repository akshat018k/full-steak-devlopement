#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base Class
class Vehicle {
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;
    static int totalVehicles;

public:
    Vehicle(int id = 0, string manu = "", string mod = "", int yr = 0)
        : vehicleID(id), manufacturer(manu), model(mod), year(yr) {
        totalVehicles++;
    }

    virtual ~Vehicle() {
        totalVehicles--;
    }

    static int getTotalVehicles() {
        return totalVehicles;
    }

    int getVehicleID() { return vehicleID; }
    string getManufacturer() { return manufacturer; }
    string getModel() { return model; }
    int getYear() { return year; }

    virtual void display() {
        cout << "ID: " << vehicleID << ", Manufacturer: " << manufacturer
             << ", Model: " << model << ", Year: " << year;
    }
};

int Vehicle::totalVehicles = 0;

// Derived Classes
class Car : public Vehicle {
protected:
    string fuelType;

public:
    Car(int id = 0, string manu = "", string mod = "", int yr = 0, string fuel = "")
        : Vehicle(id, manu, mod, yr), fuelType(fuel) {}

    void display() override {
        Vehicle::display();
        cout << ", Fuel: " << fuelType;
    }
};

class ElectricCar : public Car {
protected:
    int batteryCapacity;

public:
    ElectricCar(int id = 0, string manu = "", string mod = "", int yr = 0, string fuel = "Electric", int battery = 0)
        : Car(id, manu, mod, yr, fuel), batteryCapacity(battery) {}

    void display() override {
        Car::display();
        cout << ", Battery: " << batteryCapacity << " kWh";
    }
};

class Aircraft {
protected:
    int flightRange;

public:
    Aircraft(int range = 0) : flightRange(range) {}

    virtual void display() {
        cout << ", Flight Range: " << flightRange << " km";
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar(int id = 0, string manu = "", string mod = "", int yr = 0, string fuel = "", int range = 0)
        : Car(id, manu, mod, yr, fuel), Aircraft(range) {}

    void display() override {
        Car::display();
        Aircraft::display();
    }
};

class SportsCar : public ElectricCar {
protected:
    int topSpeed;

public:
    SportsCar(int id = 0, string manu = "", string mod = "", int yr = 0, int battery = 0, int speed = 0)
        : ElectricCar(id, manu, mod, yr, "Electric", battery), topSpeed(speed) {}

    void display() override {
        ElectricCar::display();
        cout << ", Top Speed: " << topSpeed << " km/h";
    }
};

class Sedan : public Car {
public:
    Sedan(int id = 0, string manu = "", string mod = "", int yr = 0, string fuel = "")
        : Car(id, manu, mod, yr, fuel) {}

    void display() override {
        Car::display();
        cout << " (Sedan)";
    }
};

class SUV : public Car {
public:
    SUV(int id = 0, string manu = "", string mod = "", int yr = 0, string fuel = "")
        : Car(id, manu, mod, yr, fuel) {}

    void display() override {
        Car::display();
        cout << " (SUV)";
    }
};

// Vehicle Registry Class
class VehicleRegistry {
    vector<Vehicle*> vehicles;

public:
    void addVehicle(Vehicle* v) {
        vehicles.push_back(v);
    }

    void displayAll() {
        for (auto v : vehicles) {
            v->display();
            cout << endl;
        }
    }

    void searchById(int id) {
        for (auto v : vehicles) {
            if (v->getVehicleID() == id) {
                v->display();
                cout << endl;
                return;
            }
        }
        cout << "Vehicle with ID " << id << " not found.\n";
    }
};

// Main Function
int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "\nVehicle Registry System";
        cout << "\n1. Add Vehicle";
        cout << "\n2. View All Vehicles";
        cout << "\n3. Search by ID";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int type;
            cout << "Select Vehicle Type: 1.Car 2.ElectricCar 3.FlyingCar 4.SportsCar 5.Sedan 6.SUV : \n";
            cin >> type;

            int id, year, battery, speed, range;
            string manu, mod, fuel;

            cout << "Enter ID, Manufacturer, Model, Year: ";
            cin >> id >> manu >> mod >> year;

            switch (type) {
                case 1:
                    cout << "Enter Fuel Type: ";
                    cin >> fuel;
                    registry.addVehicle(new Car(id, manu, mod, year, fuel));
                    break;
                case 2:
                    cout << "Enter Battery Capacity: ";
                    cin >> battery;
                    registry.addVehicle(new ElectricCar(id, manu, mod, year, "Electric", battery));
                    break;
                case 3:
                    cout << "Enter Fuel Type and Flight Range: ";
                    cin >> fuel >> range;
                    registry.addVehicle(new FlyingCar(id, manu, mod, year, fuel, range));
                    break;
                case 4:
                    cout << "Enter Battery Capacity and Top Speed: ";
                    cin >> battery >> speed;
                    registry.addVehicle(new SportsCar(id, manu, mod, year, battery, speed));
                    break;
                case 5:
                    cout << "Enter Fuel Type: ";
                    cin >> fuel;
                    registry.addVehicle(new Sedan(id, manu, mod, year, fuel));
                    break;
                case 6:
                    cout << "Enter Fuel Type: ";
                    cin >> fuel;
                    registry.addVehicle(new SUV(id, manu, mod, year, fuel));
                    break;
            }
        } else if (choice == 2) {
            registry.displayAll();
        } else if (choice == 3) {
            int id;
            cout << "Enter Vehicle ID: ";
            cin >> id;
            registry.searchById(id);
        }

    } while (choice != 4);

    return 0;
}

"""
Vehicle Registry System 
1. Add Vehicle 
2. View All Vehicles 
3. Search by ID
4. Exit
Enter your choice: 1
Select Vehicle Type: 1.Car 2.ElectricCar 3.FlyingCar 4.SportsCar 5.Sedan 6.SUV
1
Enter ID, Manufacturer, Model, Year: 001
mbw m4
2023
Enter Fuel Type: dijal

Vehicle Registry System
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter your choice: 2
ID: 1, Manufacturer: mbw, Model: m4, Year: 2023, Fuel: dijal

Vehicle Registry System
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter your choice: 3
Enter Vehicle ID: 1
ID: 1, Manufacturer: mbw, Model: m4, Year: 2023, Fuel: dijal

Vehicle Registry System
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter your choice: 3
Enter Vehicle ID: 2
Vehicle with ID 2 not found.

Vehicle Registry System
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter your choice: 4
