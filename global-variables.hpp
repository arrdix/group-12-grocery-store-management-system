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

extern vector<Product> products;

#endif