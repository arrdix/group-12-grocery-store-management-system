#include <iostream>
#include <cstdlib>
#include "stock.cpp"
#include "credit.cpp"
#include "transaction.cpp"
#include "global-variables.hpp"
using namespace std;

vector<Product> products;
vector<StockHistory> stockHistories;
vector<Transaction> transactions;
vector<Credit> credits;

void addInitialProduct() {
    products.push_back({ "P001", "Oreo", 10000.0, 50, 5 });
    products.push_back({ "P002", "Bengbeng", 12000.0, 50, 5 });
    products.push_back({ "P003", "Indomie", 9000.0, 20, 25 });
}

void addInitialHistory() {
    stockHistories.push_back({ "P001", "0" });
    stockHistories.push_back({ "P002", "0" });
    stockHistories.push_back({ "P003", "0" });

    for (StockHistory& history : stockHistories) {
        for (Product& product : products) {
            if (history.productCode == product.code) {
                history.history += " -> " + to_string(product.qty);
            }
        }
    }
}

void addInitialCredit() {
    credits.push_back({ "C001", "Ardi", 12000 });
    credits.push_back({ "C002", "Emerald", 9000 });
    credits.push_back({ "C003", "Dira", 17000 });
}

int main() {
    addInitialProduct();
    addInitialHistory();
    addInitialCredit();

    int role = -1;

    while (role != 1 && role != 2) {
        system("clear");

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
            mainMenu();
            break;
        } else if (role == 2) {
            mainMenu();
            break;
        } else if (role == 0) {
            return 0;
        } else {
            cout << "Input isn't valid. Please provide a valid input.";
        }
    }

    return 0;
}

void mainMenu() {
    int choice = -1;
    
    while (choice != 0) {
        system("clear");

        cout << endl << "-----------------------";
        cout << endl << "       Main Menu       ";
        cout << endl << "-----------------------";
        cout << endl;
        cout << endl << "1. Stock Management";
        cout << endl << "2. Credit Management";
        cout << endl << "3. Transaction Management";
        cout << endl;
        cout << endl << "9. Logout";
        cout << endl << "0. Exit";
        cout << endl;

        cout << endl << "Select menu (1, 2, 3 or 0): ";
        cin >> choice;

        if (choice >= 0 && choice <= 3) {
            break;
        } else if (choice == 9) {
            main();
        } else if (choice == 0) {
            return;
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
}