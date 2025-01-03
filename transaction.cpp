#include <iostream>
#include <cstdlib>
#include "global-variables.hpp"
using namespace std;

void cashierMenu();
void productPriceList();
void printReceipt();
void createTransaction();
void transactionManagement();

void transactionManagement() {
    int choice = -1;
    bool running = true;

    while (running) {
        cout << endl << "------------------------------------";
        cout << endl << "       Transaction Management       ";
        cout << endl << "------------------------------------";
        cout << endl;
        cout << endl << "1. Create transaction";
        cout << endl << "2. Product price list";
        cout << endl;
        cout << endl << "9. Back";

        cout << endl;
        cout << endl << "Select menu (1, 2 or 9): ";
        cin >> choice;

        system("clear");

        switch (choice) {
            case 1:
                createTransaction();
                running = false;
                break;
            case 2:
                productPriceList();
                running = false;
                break;
            case 9:
                cashierMenu();
                running = false;
                break;
            default:
                cout << "Input isn't valid. Please provide a valid input." << endl;
        }
    }
}

void createTransaction() {
    string productIdList;
    string selectedProductId;
    int choice = -1;
    bool running = true;
    int qty;

    while (running) {
        cout << endl << "--------------------------------";
        cout << endl << "       Create Transaction       ";
        cout << endl << "--------------------------------";
        cout << endl;

        cout << endl;
        cout << "Input product id: ";
        cin >> selectedProductId;

        bool isProductFound = false;
        bool isStockEnough = false;

        for (int i = 0; i < productCount; i++) {
            if (selectedProductId == products[i][0]) {
                isProductFound = true;

                cout << "Input qty: ";
                cin >> qty;

                // Check if the available qty of the selected product is more than the qty inputted by the user
                if (stoi(products[i][3]) < qty) {
                    system("clear");

                    cout << endl << "Not enough stock.";
                    cout << endl << "Only " << products[i][3] << " left in the stock." << endl;
                    isStockEnough = false;

                    // Exit the loop as the stock is not enough
                    break; 
                }

                isStockEnough = true;

                // Update qty of the selected product (existing qty - input qty)
                int intUpdatedQty = stoi(products[i][3]) - qty;
                products[i][3] = to_string(intUpdatedQty);

                for (int j = 0; j < stockHistoryCount; j++) {
                    // Update stock history for the selected product
                    if (selectedProductId == stockHistories[j][0]) {
                        stockHistories[j][2] += " -> " + products[i][3];
                    }
                }

                // Calculate the total price based on the input qty (product price * input qty)
                int intTotalPrice = stoi(products[i][2]) * qty;

                // Create new transaction record
                transactions[transactionCount][0] = products[i][0];
                transactions[transactionCount][1] = products[i][1];
                transactions[transactionCount][2] = to_string(qty);
                transactions[transactionCount][3] = to_string(intTotalPrice);

                transactionCount++;
                break;
            }
        }

        if (!isProductFound) {
            system("clear");

            cout << endl << "Product not found." << endl;
            
            // Restart the menu loop if the productId is not found
            continue;
        }

        if (!isStockEnough) {
            // Restart the menu loop if the stock is not enough
            continue;
        }

        cout << endl << "Transaction created.";
        cout << endl;

        cout << endl << "Add another transaction?";
        cout << endl << "1. Yes";
        cout << endl << "2. No";
        cout << endl;

        cout << endl;
        cout << "Select menu (1 or 2): ";
        cin >> choice;

        system("clear");

        switch (choice) {
            case 1:
                running = true;
                break;
            case 2:
                printReceipt();
                running = false;
                break;
            default:
                cout << "Input isn't valid. Please provide a valid input." << endl;
        }
    }
};

void printReceipt() {
    int choice = -1;
    bool running = true;

    while (running) {
        cout << endl << "---------------------";
        cout << endl << "       Receipt       ";
        cout << endl << "---------------------";
        cout << endl;

        for (int i = 0; i < transactionCount; i++) {
            cout << endl << "Product name: " << transactions[i][1];
            cout << endl << "Qty: " << transactions[i][2];
            cout << endl << "Total: " << transactions[i][3];
            cout << endl;
        }

        cout << endl;
        cout << endl << "9. Back";
        cout << endl;

        cout << endl << "Select menu (9): ";
        cin >> choice;

        system("clear");


        switch (choice) {
            case 9:
                transactionManagement();
                running = true;
                break;
            default:
                cout << "Input isn't valid. Please provide a valid input." << endl;
        }
    }
}

void productPriceList() {
    int choice = -1;
    bool running = true;

    while (running) {
        cout << endl << "---------------------------";
        cout << endl << "       Product Price       ";
        cout << endl << "---------------------------";
        cout << endl << endl;

        for (int i = 0; i < productCount; i++) {
            cout << products[i][1] << " = " << products[i][2];
            cout << endl;
        }

        cout << endl;
        cout << endl << "9. Back";
        cout << endl;

        cout << endl << "Select menu (9): ";
        cin >> choice;

        system("clear");

        switch (choice) {
            case 9:
                transactionManagement();
                running = true;
                break;
            default:
                cout << "Input isn't valid. Please provide a valid input." << endl;
        }
    }
}