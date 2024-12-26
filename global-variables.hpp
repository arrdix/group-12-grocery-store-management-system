#ifndef GLOBAL_VARIABLES_HEADER
#define GLOBAL_VARIABLES_HEADER

#include <vector>
#include <string>
using namespace std;

struct Product {
    string code;
    string name;
    double price;
    int qty;
    int minQty;
};

struct Transaction {
    string productCode;
    string productName;
    int qty;
    double total;
};

struct Credit {
    string id;
    string name;
    double total;
};

extern vector<Product> products;
extern vector<Transaction> transactions;
extern vector<Credit> credits;

#endif