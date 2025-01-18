//
// Created by emmanuel on 13/11/24.
//

#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

class Transactions {
    public:

    Transactions( const string &type, const double amount, const double balance) {
        this->type = type;
        this->amount = amount;
        this->balance = balance;

        time_t now = time(0);
        timestamp = ctime(&now);
        timestamp.pop_back();
    };
    void displayTransaction() const;
private:
    string type;
    double amount;
    double balance;
    string timestamp;


};



#endif //TRANSACTIONS_H
