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

    while (choice != 0) {
        system("clear");

        cout << endl << "------------------------------";
        cout << endl << "       Credit Management       ";
        cout << endl << "------------------------------";
        cout << endl;
        cout << endl << "1. Unpaid Credit List";
        cout << endl << "2. Credit Due Date";
        cout << endl << "3. Pay Credit";
        cout << endl;
        cout << endl << "9. Back";

        cout << endl << "Select menu (1, 2, 3 or 9): ";
        cin >> choice;

        if (choice > 0 && choice <= 3) {
            break;
        } else if (choice == 9) {
            adminMenu();
        } else {
            cout << "Input isn't valid. Please provide a valid input." << endl;
        }
    }

    if (choice == 1) {
        unpaidCredit();     
    } else if (choice == 2) {
        creditDueDate();
    } else {
        payCredit();
    }
}

void unpaidCredit() {
    int choice = -1;

    while (choice != 0) {
        system("clear");

        cout << endl << "---------------------------";
        cout << endl << "       Unpaid Credit       ";
        cout << endl << "---------------------------";
        cout << endl;

        for (const Credit& credit : credits) {
            if (credit.total != 0) {
                cout << endl << "Name: " << credit.name;
                cout << endl << "Unpaid Credit: " << credit.total;
                cout << endl;
            }
        }

        cout << endl << "9. Back";
        cout << endl;

        cout << endl << "Select menu (9): ";
        cin >> choice;

        if (choice == 9) {
            creditManagement();
        } else {
            cout << "Input isn't valid. Please provide a valid input." << endl;
        }
    }
}

void creditDueDate() {
    int choice = -1;

    while (choice != 0) {
        system("clear");

        cout << endl << "-----------------------------";
        cout << endl << "       Credit Due Date       ";
        cout << endl << "------------------------==---";
        cout << endl;

        for (const Credit& credit : credits) {
            if (credit.total != 0) {
                cout << endl << "Name: " << credit.name;
                cout << endl << "Credit due date: " << credit.dueDate;
                cout << endl;
            }
        }

        cout << endl << "9. Back";
        cout << endl;

        cout << endl << "Select menu (9): ";
        cin >> choice;

        if (choice == 9) {
            creditManagement();
        } else {
            cout << "Input isn't valid. Please provide a valid input." << endl;
        }
    }
}

void payCredit() {
    int choice = -1;
    double paidAmount;
    double changeMoney = 0;
    bool isCreditFound = false;
    string selectedCreditId;
    string creditIdList;
    Credit requestedCredit;

    for (const Credit& credit : credits) {
        creditIdList += credit.id + " / ";
    };

    while (choice != 0) {
        system("clear");

        cout << endl << "------------------------";
        cout << endl << "       Pay Credit       ";
        cout << endl << "------------------------";
        cout << endl;

        cout << "Select credit id: " << "(" << creditIdList << "): ";
        cin >> selectedCreditId;

        cout << "Amount: ";
        cin >> paidAmount;

        for (Credit& credit : credits) {
            if (credit.id == selectedCreditId) {
                if (paidAmount > credit.total) {
                    changeMoney = paidAmount - credit.total;
                    credit.total = 0;
                } else {
                    credit.total -= paidAmount;
                }
                
                requestedCredit = credit;
                isCreditFound = true;
            }
        }

        if (!isCreditFound) {
            system("clear");

            cout << "Credit not found." << endl;
            continue;
        }

        system("clear");

        cout << endl << "Credit paid.";

        if (changeMoney != 0) cout << endl << "Change money: " << changeMoney;

        cout << endl;
        cout << endl << "Current credit status:";
        cout << endl << "Name: " << requestedCredit.name;
        cout << endl << "Credit: " << requestedCredit.total;
        cout << endl;

        cout << endl << "9. Back";
        cout << endl;

        cout << "Select menu (9): ";
        cin >> choice;


        if (choice == 9) {
            creditManagement();
            break;
        } else {
            cout << "Input isn't valid. Please provide a valid input." << endl;
        };
    }
}