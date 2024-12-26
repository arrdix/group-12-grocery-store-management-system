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
        system("clear");

        cout << endl << "------------------------------------";
        cout << endl << "       Transaction Management       ";
        cout << endl << "------------------------------------";
        cout << endl;
        cout << endl << "1. Create transaction";
        cout << endl << "2. Product price list";
        cout << endl;
        cout << endl << "9. Back";

        cout << endl << "Select menu (1, 2 or 9): ";
        cin >> choice;

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
    Product requestedProduct;
    string productIdList;
    string selectedProductId;
    int choice = -1;
    bool running = true;
    bool isProductFound = false;
    bool isStockEnough = false;
    int qty;


    for (const Product& product : products) {
        productIdList += product.id + " / ";
    };

    while (running) {
        system("clear");
        cout << endl << "--------------------------------";
        cout << endl << "       Create Transaction       ";
        cout << endl << "--------------------------------";
        cout << endl;
        cout << endl;

        cout << "Select product id: " << "(" << productIdList << "): ";
        cin >> selectedProductId;

        cout << "Input qty: ";
        cin >> qty;

        for (Product& product : products) {
            if (selectedProductId == product.id) {
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

                for (StockHistory& history : stockHistories) {
                    if (history.productId == product.id) {
                        history.history += " -> " + to_string(product.qty);
                    }
                }
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
            requestedProduct.id,
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
        cout << endl;

        cout << endl << "Select menu (9): ";
        cin >> choice;

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
        cout << endl;

        cout << endl << "Select menu (9): ";
        cin >> choice;

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