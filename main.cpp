#include <iostream>
#include <cstdlib>
#include "stock.cpp"
#include "credit.cpp"
#include "transaction.cpp"
#include "global-variables.hpp"
using namespace std;

int productCount = 3;
int stockHistoryCount = 3;
int transactionCount = 0;
int creditCount = 3;

string products[MAX_ITEM][5]; // [Id, Name, Price, Qty, Min Qty]
string stockHistories[MAX_ITEM][3]; // [Product ID, Product Name, History]
string transactions[MAX_ITEM][4]; // [Product ID, Product Name, Qty, Total]
string credits[MAX_ITEM][4]; // [ID, Name, Due Date, Total]

void login();
void adminMenu();
void cashierMenu();

void addInitialProduct() {
    products[0][0] = "P001";
    products[0][1] = "Oreo";
    products[0][2] = "10000";
    products[0][3] = "50";
    products[0][4] = "5";
    
    products[1][0] = "P002";
    products[1][1] = "Bengbeng";
    products[1][2] = "11000";
    products[1][3] = "50";
    products[1][4] = "5";
    
    products[2][0] = "P003";
    products[2][1] = "Indomie";
    products[2][2] = "13000";
    products[2][3] = "20";
    products[2][4] = "25";
}

void addInitialHistory() {
    stockHistories[0][0] = "P001";
    stockHistories[0][1] = "Oreo";
    stockHistories[0][2] = "0";
    
    stockHistories[1][0] = "P002";
    stockHistories[1][1] = "Bengbeng";
    stockHistories[1][2] = "0";
    
    stockHistories[2][0] = "P003";
    stockHistories[2][1] = "Indomie";
    stockHistories[2][2] = "0";

    // Loop over stockHistories
    for (int i = 0; i < stockHistoryCount; i++) {
        // Loop over products
        for (int j = 0; j < productCount; j++) {
            if (stockHistories[i][0] == products[j][0]) {
                // Set initial history based on matching productId
                stockHistories[i][2] += " -> " + products[j][3];
            }
        }
    }
}

void addInitialCredit() {
    credits[0][0] = "C001";
    credits[0][1] = "Ardi";
    credits[0][2] = "12 Jan 2025";
    credits[0][3] = "12000";

    credits[1][0] = "C002";
    credits[1][1] = "Dira";
    credits[1][2] = "29 Jan 2025";
    credits[1][3] = "17000";

    credits[2][0] = "C003";
    credits[2][1] = "Emeral";
    credits[2][2] = "1 Feb 2025";
    credits[2][3] = "9000";
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

        system("clear");

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

        system("clear");

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

        system("clear");

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