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

void login();
void adminMenu();
void cashierMenu();

void addInitialProduct() {
    products.push_back({ "P001", "Oreo", 10000.0, 50, 5 });
    products.push_back({ "P002", "Bengbeng", 12000.0, 50, 5 });
    products.push_back({ "P003", "Indomie", 9000.0, 20, 25 });
}

void addInitialHistory() {
    stockHistories.push_back({ "P001", "Oreo", "0" });
    stockHistories.push_back({ "P002", "Bengbeng", "0" });
    stockHistories.push_back({ "P003", "Indomie", "0" });

    for (StockHistory& history : stockHistories) {
        for (Product& product : products) {
            if (history.productId == product.id) {
                history.history += " -> " + to_string(product.qty);
            }
        }
    }
}

void addInitialCredit() {
    credits.push_back({ "C001", "Ardi", "12 Jan 2025", 12000 });
    credits.push_back({ "C002", "Emerald", "29 Jan 2025", 9000 });
    credits.push_back({ "C003", "Dira", "1 Feb 2025", 17000 });
}

int main() {
    addInitialProduct();
    addInitialHistory();
    addInitialCredit();

    login();

    return 0;
}

void login() {
    int role = -1;
    bool running = true;

    while (running) {
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

        switch (role) {
            case 1:
                adminMenu();
                running = false;
                break;
            case 2:
                cashierMenu();
                running = false;
                break;
            case 0:
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void adminMenu() {
    int choice = -1;
    bool running = true;
    
    while (running) {
        system("clear");

        cout << endl << "------------------------";
        cout << endl << "       Admin Menu       ";
        cout << endl << "------------------------";
        cout << endl;
        cout << endl << "1. Stock Management";
        cout << endl << "2. Credit Management";
        cout << endl;
        cout << endl << "9. Logout";
        cout << endl;

        cout << endl << "Select menu (1, 2 or 9): ";
        cin >> choice;

        switch (choice) {
            case 1:
                stockManagement();
                running = false;
                break;
            case 2:
                creditManagement();
                running = false;
                break;
            case 9:
                login();
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    };
}

void cashierMenu() {
    int choice = -1;
    bool running = true;
    
    while (running) {
        system("clear");

        cout << endl << "--------------------------";
        cout << endl << "       Cashier Menu       ";
        cout << endl << "--------------------------";
        cout << endl;
        cout << endl << "1. Transaction Management";
        cout << endl;
        cout << endl << "9. Logout";
        cout << endl;

        cout << endl << "Select menu (1 or 9): ";
        cin >> choice;

        switch (choice) {
            case 1:
                transactionManagement();
                running = false;
                break;
            case 9:
                login();
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    };
}