#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <Windows.h>

using namespace std;




class Employee {
private:
    string name;
    string position;

public:
    Employee(string name, string position) : name(name), position(position) {}

    string getName() const { return name; }
    string getPosition() const { return position; }

    void setName(const string& name) { this->name = name; }
    void setPosition(const string& position) { this->position = position; }
};

class Phone {
private:
    string name;
    int price;

public:
    Phone(string name, int price) : name(name), price(price) {}

    string getName() const { return name; }
    int getPrice() const { return price; }

    void setName(const string& name) { this->name = name; }
    void setPrice(const int& price) { this->price = price; }
};

class Store {
private:
    vector<Phone> phones;
    vector<Employee> employees;

public:
    void addPhone(const Phone& phone) { phones.push_back(phone); }
    void removePhone(const string& name) {
        for (auto it = phones.begin(); it != phones.end(); ++it) {
            if (it->getName() == name) {
                phones.erase(it);
                return;
            }
        }
        cout << "Erroe" << endl;
    }
    void changePhoneName(const string& oldName, const string& newName) {
        for (auto& phone : phones) {
            if (phone.getName() == oldName) {
                phone.setName(newName);
                return;
            }
        }
        cout << "Error" << endl;
    }
    void printPhones() const {
        for (const auto& phone : phones) {
            cout << "Name: " << phone.getName() << ", Price: " << phone.getPrice() << endl;
        }
    }
    void findPhoneByName(const string& name) const {
        for (const auto& phone : phones) {
            if (phone.getName() == name) {
                cout << "Name: " << phone.getName() << ", Price: " << phone.getPrice() << endl;
                return;
            }
        }
        cout << "Error" << endl;
    }
    void findPhoneByPrice(const int& price) const {
        for (const auto& phone : phones) {
            if (phone.getPrice() == price) {
                cout << "Name: " << phone.getName() << ", Price: " << phone.getPrice() << endl;
            }
        }
    }
    void addEmployee(const Employee& employee) { employees.push_back(employee); }
    void removeEmployee(const string& name) {
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (it->getName() == name) {
                employees.erase(it);
                return;
            }
        }
        cout << "Error" << endl;
    }
    
    
};

int main() {
    Store store;
    int choice;

    do {
        cout << "1. Add phone" << endl;
        cout << "2. Remove phone" << endl;
        cout << "3. Change phone name" << endl;
        cout << "4. Print phones" << endl;
        cout << "5. Sort phones by name" << endl;
        cout << "6. Find phone by price" << endl;
        cout << "7. Add employee" << endl;
        cout << "8. Remove employee" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int price;
            cout << "Enter phone name: ";
            cin >> name;
            cout << "Enter phone price: ";
            cin >> price;
            store.addPhone(Phone(name, price));
            cout << "Phone add" << endl;
            break;
        }
        case 2: {
            string name;
            cout << "Enter phone name to remove: ";
            cin >> name;
            store.removePhone(name);
            break;
        }
        case 3: {
            string oldName, newName;
            cout << "Enter old phone name: ";
            cin >> oldName;
            cout << "Enter new phone name: ";
            cin >> newName;
            store.changePhoneName(oldName, newName);
            break;
        }
        case 4: {
            store.printPhones();
            break;
        }
        case 5: {
            string name;
            cout << "Enter phone name to find: ";
            cin >> name;
            store.findPhoneByName(name);
            cout << "Phones sorted by name" << endl;
            break;
        }
        case 6: {
            int price;
            cout << "Enter phone price to find: ";
            cin >> price;
            store.findPhoneByPrice(price);
            break;
        }
        case 7: {
            string name;
            string position;
            cout << "Enter employee name: ";
            cin >> name;
            cout << "Enter employee position: ";
            cin >> position;
            store.addEmployee(Employee(name, position));
            cout << "Employee add" << endl;
            break;
        }
        case 8: {
            string name;
            cout << "Enter employee name to remove: ";
            cin >> name;
            store.removeEmployee(name);
            break;
        }
        case 0: {
            cout << "Exit" << endl;
            break;
        }
        default: {
            cout << "error" << endl;
        }
        }
    } while (choice != 0);

    return 0;
}