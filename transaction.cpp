#include <iostream>
#include <cstdlib>
#include "global-variables.hpp"
using namespace std;

void mainMenu();
void productPriceList();
void printReceipt();
void createTransaction();
void transactionManagement();

void transactionManagement() {
    int choice = -1;

    while (choice != 0) {
        system("clear");

        cout << endl << "------------------------------------";
        cout << endl << "       Transaction Management       ";
        cout << endl << "------------------------------------";
        cout << endl;
        cout << endl << "1. Create transaction";
        cout << endl << "2. Product price list";
        cout << endl;
        cout << endl << "9. Back";
        cout << endl << "0. Exit";

        cout << endl << "Select menu (1, 2 or 0): ";
        cin >> choice;

        if (choice > 0 && choice <= 2) {
            break;
        } else if (choice == 9) {
            mainMenu();
        } else if (choice == 0) {
            return;
        } else {
            cout << "Input isn't valid. Please provide a valid input.";
        }
    }

    if (choice == 1) {
        createTransaction();
    } else {
        productPriceList();
    }
}

void createTransaction() {
    Product requestedProduct;
    string productCodeList;
    string selectedProductCode;
    int choice = -1;
    bool isProductFound = false;
    bool isStockEnough = false;
    int qty;


    for (const Product& product : products) {
        productCodeList += product.code + " / ";
    };

    while (choice != 2) {
        cout << "Select product id: " << "(" << productCodeList << "): ";
        cin >> selectedProductCode;

        cout << "Input qty: ";
        cin >> qty;

        for (Product& product : products) {
            if (selectedProductCode == product.code) {
                requestedProduct = product;
                isProductFound = true;

                if (product.qty < qty) {
                    system("clear");

                    cout << endl << "Not enough stock.";
                    cout << endl << "Only " << product.qty << " left in the stock." << endl;
                    cout << endl;
                    break;
                }

                product.qty -= qty;
                isStockEnough = true;
            }
        }

        if (!isProductFound) {
            system("clear");

            cout << "Product not found." << endl;
            continue;
        }

        if (!isStockEnough) {
            continue;
        }

        transactions.push_back({
            requestedProduct.code,
            requestedProduct.name,
            qty,
            requestedProduct.price * qty
        });

        system("clear");

        cout << endl << "Transaction created.";
        cout << endl;
        cout << endl << "Add another transaction?";
        cout << endl << "1. Yes";
        cout << endl << "2. No";
        cout << endl;

        cout << "Select menu (1 or 2): ";
        cin >> choice;


        if (choice == 2) {
            printReceipt();
            break;
        } if (choice == 1) {
            continue;
        } else {
            cout << "Input isn't valid. Please provide a valid input.";
        };
    }
};

void printReceipt() {
    int choice = -1;

    while (choice != 0) {
        system("clear");

        cout << endl << "---------------------";
        cout << endl << "       Receipt       ";
        cout << endl << "---------------------";
        cout << endl;

        for (const Transaction& transaction : transactions) {
            cout << endl << "Product name: " << transaction.productName;
            cout << endl << "Qty: " << transaction.qty;
            cout << endl << "Total: " << transaction.total;
            cout << endl;
        }

        cout << endl;
        cout << endl << "9. Back";
        cout << endl << "0. Exit";
        cout << endl;

        cout << endl << "Select menu (9 or 0): ";
        cin >> choice;

        if (choice == 9) {
            transactionManagement();
        } else if (choice == 0) {
            return;
        } else {
            cout << "Input isn't valid. Please provide a valid input.";
        }
    }
}

void productPriceList() {
    int choice = -1;

    while (choice != 0) {
        system("clear");

        cout << endl << "---------------------------";
        cout << endl << "       Product Price       ";
        cout << endl << "---------------------------";
        cout << endl << endl;

        for (const Product& product : products) {
            cout << product.name << " = " << product.price;
            cout << endl; 
        };

        cout << endl;
        cout << endl << "9. Back";
        cout << endl << "0. Exit";
        cout << endl;

        cout << endl << "Select menu (9 or 0): ";
        cin >> choice;

        if (choice == 9) {
            transactionManagement();
        } else if (choice == 0) {
            return;
        } else {
            cout << "Input isn't valid. Please provide a valid input.";
        }
    }
}