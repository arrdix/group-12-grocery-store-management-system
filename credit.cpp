#include <iostream>
#include <cstdlib>
#include "global-variables.hpp"
using namespace std;

void adminMenu();
void unpaidCredit();
void payCredit();
void creditManagement();
void creditDueDate();

void creditManagement() {
    int choice = -1;
    bool running = true;

    while (running) {
        cout << endl << "------------------------------";
        cout << endl << "       Credit Management       ";
        cout << endl << "------------------------------";
        cout << endl;
        cout << endl << "1. Unpaid Credit List";
        cout << endl << "2. Credit Due Date";
        cout << endl << "3. Pay Credit";
        cout << endl;
        cout << endl << "9. Back";

        cout << endl;
        cout << endl << "Select menu (1, 2, 3 or 9): ";
        cin >> choice;

        system("clear");

        switch (choice) {
            case 1:
                unpaidCredit();
                running = false;
                break;
            case 2:
                creditDueDate();
                running = false;
                break;
            case 3:
                payCredit();
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

void unpaidCredit() {
    int choice = -1;
    bool running = true;

    while (running) {
        cout << endl << "---------------------------";
        cout << endl << "       Unpaid Credit       ";
        cout << endl << "---------------------------";
        cout << endl;

        // Only render credit where the total != 0
        for (int i = 0; i < creditCount; i++) {
            if (credits[i][3] != "0") {
                cout << endl << "Name: " << credits[i][1];
                cout << endl << "Unpaid Credit: " << credits[i][3];
                cout << endl;
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
                creditManagement();
                running = false;
                break;
            default:
                cout << "Input isn't valid. Please provide a valid input." << endl;
        }
    }
}

void creditDueDate() {
    int choice = -1;
    bool running = true;

    while (running) {
        cout << endl << "-----------------------------";
        cout << endl << "       Credit Due Date       ";
        cout << endl << "-----------------------------";
        cout << endl;

        for (int i = 0; i < creditCount; i++) {
            if (credits[i][3] != "0") {
                cout << endl << "Name: " << credits[i][1];
                cout << endl << "Credit due date: " << credits[i][2];
                cout << endl;
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
                creditManagement();
                running = false;
                break;
            default:
                cout << "Input isn't valid. Please provide a valid input." << endl;
        }
    }
}

void payCredit() {
    int choice = -1;
    double paidAmount;
    double changeMoney = 0;
    bool isCreditFound = false;
    bool running = true;
    string selectedCreditId;
    string creditIdList;

    while (running) {
        cout << endl << "------------------------";
        cout << endl << "       Pay Credit       ";
        cout << endl << "------------------------";
        cout << endl;

        cout << endl;
        cout << "Select credit id: ";
        cin >> selectedCreditId;

        for (int i = 0; i < creditCount; i++) {
            if (selectedCreditId == credits[i][0]) {
                isCreditFound = true;
                
                cout << "Amount: ";
                cin >> paidAmount;

                if (paidAmount > stod(credits[i][3])) {
                    changeMoney = paidAmount - stod(credits[i][3]);
                    credits[i][3] = "0";
                } else {
                    double updatedCredit = stod(credits[i][3]) - paidAmount;
                    credits[i][3] = to_string(updatedCredit);
                }
            }
        }

        if (!isCreditFound) {
            system("clear");

            cout << "Credit not found." << endl;

            // Restart the menu loop if the creditId is not found
            continue;
        }

        system("clear");

        cout << endl << "Credit paid.";

        if (changeMoney != 0) cout << endl << "Change money: " << changeMoney;

        cout << endl;
        cout << endl << "Current credit status:";

        for (int i = 0; i < creditCount; i++) {
            if (selectedCreditId == credits[i][0]) {
                cout << endl << "Name: " << credits[i][1];
                cout << endl << "Credit: " << credits[i][3];
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
                creditManagement();
                running = false;
                break;
            default:
                cout << "Input isn't valid. Please provide a valid input." << endl;
        }
    }
}