#include <iostream>
#include <vector>
#include "global-variables.hpp"
using namespace std;

void mainMenu();
void stockManagement();
void productList();
void lowQtyProductList();
void updateProductQty();
void productQtyHistory();

void stockManagement() {
    int choice = -1;

    while (choice != 0) {
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
        cout << endl << "0. Exit";

        cout << endl << "Select menu (1, 2, 3, 4, 9 or 0): ";
        cin >> choice;

        if (choice > 0 && choice <= 4) {
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
        productList();     
    } else if (choice == 2) {
        lowQtyProductList();
    } else if (choice == 3) {
        updateProductQty();
    } else if (choice == 4) {
        productQtyHistory();
    }
}

void productList() {
    system("clear");

    cout << endl << "--------------------------";
    cout << endl << "       Product List       ";
    cout << endl << "--------------------------";
    cout << endl;

    for (const Product& product : products) {
        cout << endl << "Code: " << product.code;
        cout << endl << "Name: " << product.name;
        cout << endl << "Price: " << product.price;
        cout << endl << "Qty: " << product.qty;
        cout << endl << "Min qty: " << product.minQty;
        cout << endl;
    }

    int choice = -1;

    while (choice != 0) {
        cout << endl;
        cout << endl << "9. Back";
        cout << endl << "0. Exit";
        cout << endl;

        cout << endl << "Select menu (9 or 0): ";
        cin >> choice;

        if (choice == 9) {
            stockManagement();
        } else if (choice == 0) {
            return;
        } else {
            cout << "Input isn't valid. Please provide a valid input.";
        }
    }
}

void lowQtyProductList() {
    system("clear");

    cout << endl << "----------------------------------";
    cout << endl << "       Low Qty Product List       ";
    cout << endl << "----------------------------------";
    cout << endl;

    for (const Product& product : products) {
        if (product.qty < product.minQty) {
            cout << endl << "Code: " << product.code;
            cout << endl << "Name: " << product.name;
            cout << endl << "Price: " << product.price;
            cout << endl << "Qty: " << product.qty;
            cout << endl << "Min qty: " << product.minQty;
            cout << endl;
        }
    }

    int choice = -1;

    while (choice != 0) {
        cout << endl;
        cout << endl << "9. Back";
        cout << endl << "0. Exit";
        cout << endl;

        cout << endl << "Select menu (9 or 0): ";
        cin >> choice;

        if (choice == 9) {
            stockManagement();
        } else if (choice == 0) {
            return;
        } else {
            cout << "Input isn't valid. Please provide a valid input.";
        }
    }
}

void updateProductQty() {
    int choice = -1;
    int newQty;
    double changeMoney = 0;
    bool isProductFound = false;
    string selectedProductCode;
    string productCodeList;
    Product requestedProduct;

    for (const Product& product : products) {
        productCodeList += product.code + " / ";
    };

    while (choice != 0) {
        system("clear");

        cout << endl << "--------------------------------";
        cout << endl << "       Update Product Qty       ";
        cout << endl << "--------------------------------";
        cout << endl;

        cout << "Select product id: " << "(" << productCodeList << "): ";
        cin >> selectedProductCode;

        cout << "Qty: ";
        cin >> newQty;

        for (Product& product : products) {
            if (selectedProductCode == product.code) {
                product.qty += newQty;
                requestedProduct = product;

                isProductFound = true;

                for (StockHistory& history : stockHistories) {
                    if (history.productCode == product.code) {
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
        cout << endl << "Id: " << requestedProduct.code;
        cout << endl << "Name: " << requestedProduct.name;
        cout << endl << "Qty: " << requestedProduct.qty;
        cout << endl << "Min qty: " << requestedProduct.minQty;
        cout << endl;

        cout << endl << "9. Back";
        cout << endl << "0. Exit";
        cout << endl;

        cout << "Select menu (9 or 0): ";
        cin >> choice;

        if (choice == 9) {
            stockManagement();
            break;
        } if (choice == 0) {
            return;
        } else {
            cout << "Input isn't valid. Please provide a valid input.";
        };
    }
}

void productQtyHistory() {
    system("clear");

    cout << endl << "---------------------------------";
    cout << endl << "       Product Qty History       ";
    cout << endl << "---------------------------------";
    cout << endl;

    for (const StockHistory& history : stockHistories) {
        cout << endl << "Product code: " << history.productCode;
        cout << endl << "History: " << history.history;
        cout << endl;
        
    }

    int choice = -1;

    while (choice != 0) {
        cout << endl;
        cout << endl << "9. Back";
        cout << endl << "0. Exit";
        cout << endl;

        cout << endl << "Select menu (9 or 0): ";
        cin >> choice;

        if (choice == 9) {
            stockManagement();
        } else if (choice == 0) {
            return;
        } else {
            cout << "Input isn't valid. Please provide a valid input.";
        }
    }
}