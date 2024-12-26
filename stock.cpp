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
        system("clear");

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

        cout << endl << "Select menu (1, 2, 3, 4 or 9): ";
        cin >> choice;

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
        system("clear");

        cout << endl << "--------------------------";
        cout << endl << "       Product List       ";
        cout << endl << "--------------------------";
        cout << endl;

        for (const Product& product : products) {
            cout << endl << "ID: " << product.id;
            cout << endl << "Name: " << product.name;
            cout << endl << "Price: " << product.price;
            cout << endl << "Qty: " << product.qty;
            cout << endl << "Min qty: " << product.minQty;
            cout << endl;
        }

        cout << endl;
        cout << endl << "9. Back";
        cout << endl;

        cout << endl << "Select menu (9): ";
        cin >> choice;

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
        system("clear");

        cout << endl << "----------------------------------";
        cout << endl << "       Low Qty Product List       ";
        cout << endl << "----------------------------------";
        cout << endl;

        for (const Product& product : products) {
            if (product.qty < product.minQty) {
                cout << endl << "ID: " << product.id;
                cout << endl << "Name: " << product.name;
                cout << endl << "Price: " << product.price;
                cout << endl << "Qty: " << product.qty;
                cout << endl << "Min qty: " << product.minQty;
                cout << endl;
            }
        }

        cout << endl;
        cout << endl << "9. Back";
        cout << endl;

        cout << endl << "Select menu (9): ";
        cin >> choice;

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
    Product requestedProduct;

    for (const Product& product : products) {
        productIdList += product.id + " / ";
    };

    while (running) {
        system("clear");

        cout << endl << "--------------------------------";
        cout << endl << "       Update Product Qty       ";
        cout << endl << "--------------------------------";
        cout << endl;

        cout << "Select product ID: " << "(" << productIdList << "): ";
        cin >> selectedProductId;

        cout << "Qty: ";
        cin >> newQty;

        for (Product& product : products) {
            if (selectedProductId == product.id) {
                product.qty += newQty;
                requestedProduct = product;

                isProductFound = true;

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

        system("clear");

        cout << endl << "Product qty updated.";
        cout << endl;

        cout << endl;
        cout << endl << "Current product status:";
        cout << endl << "ID: " << requestedProduct.id;
        cout << endl << "Name: " << requestedProduct.name;
        cout << endl << "Qty: " << requestedProduct.qty;
        cout << endl << "Min qty: " << requestedProduct.minQty;
        cout << endl;

        cout << endl << "9. Back";
        cout << endl;

        cout << "Select menu (9): ";
        cin >> choice;

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
        system("clear");

        cout << endl << "---------------------------------";
        cout << endl << "       Product Qty History       ";
        cout << endl << "---------------------------------";
        cout << endl;

        for (const StockHistory& history : stockHistories) {
            cout << endl << "Product ID: " << history.productId;
            cout << endl << "Product name: " << history.productName;
            cout << endl << "History: " << history.history;
            cout << endl;
            
        }

        cout << endl;
        cout << endl << "9. Back";
        cout << endl;

        cout << endl << "Select menu (9): ";
        cin >> choice;

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