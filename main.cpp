#include <iostream>
#include "stock.cpp"
#include "credit.cpp"
#include "transaction.cpp"
#include "global-variables.hpp"
using namespace std;

vector<Product> products;

void addInitialProduct() {
    products.push_back({ "P001", "Oreo", 10000.0, 50, 5 });
    products.push_back({ "P002", "Bengbeng", 12000.0, 50, 5 });
    products.push_back({ "P003", "Indomie", 9000.0, 50, 5 });
}

int main() {
    addInitialProduct();

    int role = -1;

    while (role != 1 && role != 2) {
        cout << endl;
        cout << endl << "-------------------";
        cout << endl << "       Login       ";
        cout << endl << "-------------------";
        cout << endl;
        cout << endl << "Select your role:";
        cout << endl << "1. Admin";
        cout << endl << "2. Cashier";
        cout << endl;
        cout << endl << "0. Exit";
        cout << endl;

        cout << endl << "Select role (1 or 2): ";
        cin >> role;

        cout << endl;

        if (role == 1) {
            cout << endl << "Hi, Admin!";
        } else if (role == 2) {
            cout << endl << "Hi, Cashier!";
        } else if (role == 0) {
            return 0;
        } else {
            cout << "Input isn't valid. Please provide a valid input.";
        }
    }

    int choice = -1;
    
    while (choice != 0) {
        cout << endl;
        cout << endl << "-----------------------";
        cout << endl << "       Main Menu       ";
        cout << endl << "-----------------------";
        cout << endl;
        cout << endl << "1. Stock Management";
        cout << endl << "2. Credit Management";
        cout << endl << "3. Transaction Management";
        cout << endl;
        cout << endl << "0. Exit";
        cout << endl;

        cout << endl << "Select menu (1, 2, 3 or 0): ";
        cin >> choice;

        if (choice >= 0 && choice <= 3) {
            break;
        } else if (choice == 0) {
            return 0;
        } else {
            cout << "Input isn't valid. Please provide a valid input.";
        }
    };

    if (choice == 1) {
        stockManagement();
    } else if (choice == 2) {
        creditManagement();
    } else {
        transactionManagement();
    }

    return 0;
}