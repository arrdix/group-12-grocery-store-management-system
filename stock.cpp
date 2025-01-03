#include <iostream>
#include <vector>
#include "global-variables.hpp"
using namespace std;

void adminMenu();
void stockManagement();
void productList();
void lowQtyProductList();
void updateProductQty();
void productQtyHistory();

void stockManagement() {
    int choice = -1;
    bool running = true;

    while (running) {
        cout << endl << "------------------------------";
        cout << endl << "       Stock Management       ";
        cout << endl << "------------------------------";
        cout << endl;
        cout << endl << "1. Product List";
        cout << endl << "2. Low Quantity Product(s)";
        cout << endl << "3. Update Product Quantity";
        cout << endl << "4. Product Quantity History";
        cout << endl;
        cout << endl << "9. Back";

        cout << endl;
        cout << endl << "Select menu (1, 2, 3, 4 or 9): ";
        cin >> choice;

        system("clear");

        switch (choice) {
            case 1:
                productList();
                running = false;
                break;
            case 2:
                lowQtyProductList();
                running = false;
                break;
            case 3:
                updateProductQty();
                running = false;
                break;
            case 4:
                productQtyHistory();
                running = false;
                break;
            case 9:
                adminMenu();
                running = false;
                break;
            default:
                cout << "Input isn't valid. Please provide a valid input." << endl;
        }
    }
}

void productList() {
    int choice = -1;
    bool running = true;

    while (running) {
        cout << endl << "--------------------------";
        cout << endl << "       Product List       ";
        cout << endl << "--------------------------";
        cout << endl;

        for (int i = 0; i < productCount; i++) {
            cout << endl;
            cout << "ID: " << products[i][0] << endl;
            cout << "Name: " << products[i][1] << endl;
            cout << "Price: " << products[i][2] << endl;
            cout << "Qty: " << products[i][3] << endl;
            cout << "Min qty: " << products[i][4] << endl;
        }

        cout << endl << "9. Back";
        cout << endl;

        cout << endl << "Select menu (9): ";
        cin >> choice;

        system("clear");

        switch (choice) {
            case 9:
                stockManagement();
                running = false;
                break;
            default:
                cout << "Input isn't valid. Please provide a valid input." << endl;
        }
    }
}

void lowQtyProductList() {
    int choice = -1;
    bool running = true;

    while (running) {
        cout << endl << "----------------------------------";
        cout << endl << "       Low Qty Product List       ";
        cout << endl << "----------------------------------";
        cout << endl;

        // Only render product where the qty < minQty
        for (int i = 0; i < productCount; i++) {
            if (products[i][3] < products[i][4]) {
                cout << endl;
                cout << "ID: " << products[i][0] << endl;
                cout << "Name: " << products[i][1] << endl;
                cout << "Price: " << products[i][2] << endl;
                cout << "Qty: " << products[i][3] << endl;
                cout << "Min qty: " << products[i][4] << endl;
            }
        }

        cout << endl;
        cout << endl << "9. Back";
        cout << endl;

        cout << endl << "Select menu (9): ";
        cin >> choice;

        system("clear");

        switch (choice) {
            case 9:
                stockManagement();
                running = false;
                break;
            default:
                cout << "Input isn't valid. Please provide a valid input." << endl;
        }
    }
}

void updateProductQty() {
    int choice = -1;
    int newQty;
    double changeMoney = 0;
    bool running = true;
    bool isProductFound = false;
    string selectedProductId;
    string productIdList;

    while (running) {
        cout << endl << "--------------------------------";
        cout << endl << "       Update Product Qty       ";
        cout << endl << "--------------------------------";
        cout << endl;

        cout << endl;
        cout << "Input product ID: ";
        cin >> selectedProductId;

        for (int i = 0; i < productCount; i++) {
            if (selectedProductId == products[i][0]) {
                isProductFound = true;

                cout << "Input new qty: ";
                cin >> newQty;

                // Update qty for the selected product
                products[i][3] = to_string(newQty);

                for (int j = 0; i < stockHistoryCount; i++) {
                    if (selectedProductId == stockHistories[i][0]) {
                        // Update stock history for the selected product
                        stockHistories[i][2] += " -> " + products[i][3];
                    }
                }
            }
        }

        if (!isProductFound) {
            system("clear");

            cout << "Product not found." << endl;
            
            // Restart the menu loop if the productId is not found
            continue;
        }

        system("clear");

        cout << endl << "Product qty updated.";

        cout << endl;
        cout << endl << "Current product status:";

        for (int i = 0; i < productCount; i++) {
            if (selectedProductId == products[i][0]) {
                cout << "ID: " << products[i][0] << endl;
                cout << "Name: " << products[i][1] << endl;
                cout << "Price: " << products[i][2] << endl;
                cout << "Qty: " << products[i][3] << endl;
                cout << "Min qty: " << products[i][4] << endl;
                cout << endl;
            }
        }

        cout << endl << "9. Back";
        cout << endl;

        cout << endl;
        cout << "Select menu (9): ";
        cin >> choice;

        system("clear");

        switch (choice) {
            case 9:
                stockManagement();
                running = false;
                break;
            default:
                cout << "Input isn't valid. Please provide a valid input." << endl;
        }
    }
}

void productQtyHistory() {
    int choice = -1;
    bool running = true;

    while (running) {
        cout << endl << "---------------------------------";
        cout << endl << "       Product Qty History       ";
        cout << endl << "---------------------------------";
        cout << endl;

        for (int i = 0; i < stockHistoryCount; i++) {
            cout << endl;
            cout << endl << "Product ID: " << stockHistories[i][0];
            cout << endl << "Product name: " << stockHistories[i][1];
            cout << endl << "History: " << stockHistories[i][2];
        }

        cout << endl;
        cout << endl << "9. Back";
        cout << endl;

        cout << endl << "Select menu (9): ";
        cin >> choice;

        system("clear");

        switch (choice) {
            case 9:
                stockManagement();
                running = false;
                break;
            default:
                cout << "Input isn't valid. Please provide a valid input." << endl;
        }
    }
}