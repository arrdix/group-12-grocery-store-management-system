#include <iostream>
#include <vector>
#include "global-variables.hpp"
using namespace std;

void stockManagement();
void productList();

void productList() {
    cout << endl;
    cout << endl << "--------------------------";
    cout << endl << "       Product List       ";
    cout << endl << "--------------------------";
    cout << endl;
    cout << endl;

    for (const Product& product : products) {
        cout 
            << "Code: " << product.code 
            << ", Name: " << product.name 
            << ", Price: " << product.price 
            << ", Qty: " << product.qty 
            << ", Min qty: " << product.minQty << "\n";
    }

    int choice = -1;

    while (choice != 0) {
        cout << endl;
        cout << endl << "1. Back";
        cout << endl << "0. Exit";
        cout << endl;

        cout << endl << "Select menu (1 or 0): ";
        cin >> choice;

        if (choice == 1) {
            stockManagement();
        } else if (choice == 0) {
            return;
        } else {
            cout << "Input isn't valid. Please provide a valid input.";
        }
    }
}

void stockManagement() {
    int choice = -1;

    while (choice != 0) {
        cout << endl;
        cout << endl << "------------------------------";
        cout << endl << "       Stock Management       ";
        cout << endl << "------------------------------";
        cout << endl;
        cout << endl << "1. Product List";
        cout << endl << "2. Low Quantity Product(s)";
        cout << endl << "3. Update Product Quantity";
        cout << endl << "4. Product Quantity History";
        cout << endl;
        cout << endl << "0. Exit";

        cout << endl << "Select menu (1, 2, 3, 4 or 0): ";
        cin >> choice;

        if (choice >= 0 && choice <= 3) {
            break;
        } else if (choice == 0) {
            return;
        } else {
            cout << "Input isn't valid. Please provide a valid input.";
        }
    }

    if (choice == 1) {
        productList();     
    }
}