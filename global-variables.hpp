#ifndef GLOBAL_VARIABLES_HEADER
#define GLOBAL_VARIABLES_HEADER

#include <vector>
#include <string>
using namespace std;

struct Product {
    string id;
    string name;
    double price;
    int qty;
    int minQty;
};

struct StockHistory {
    string productId;
    string productName;
    string history;
};

struct Transaction {
    string productId;
    string productName;
    int qty;
    double total;
};

struct Credit {
    string id;
    string name;
    string dueDate;
    double total;
};

extern vector<Product> products;
extern vector<StockHistory> stockHistories;
extern vector<Transaction> transactions;
extern vector<Credit> credits;

#endif