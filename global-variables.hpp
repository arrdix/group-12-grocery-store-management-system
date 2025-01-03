#ifndef GLOBAL_VARIABLES_HEADER
#define GLOBAL_VARIABLES_HEADER

#include <vector>
#include <string>
using namespace std;

extern const int MAX_ITEM = 10;

extern int productCount;
extern int stockHistoryCount;
extern int transactionCount;
extern int creditCount;

extern string products[MAX_ITEM][5]; // [Id, Name, Price, Qty, Min Qty]
extern string stockHistories[MAX_ITEM][3]; // [Product ID, Product Name, History]
extern string transactions[MAX_ITEM][4]; // [Product ID, Product Name, Qty, Total]
extern string credits[MAX_ITEM][4]; // [ID, Name, Due Date, Total]

#endif