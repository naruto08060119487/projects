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

    //constructor to initialize a transaction with type, amount, and balance
    //uses the current time at the point of creation
    Transactions( const string &type, const double amount, const double balance) {
        this->type = type; //type of transaction(deposit, withdrawal)
        this->amount = amount; // amount
        this->balance = balance; //account balance after the transaction

        time_t now = time(0); //get the current time
        timestamp = ctime(&now);
        timestamp.pop_back();
    };

    //method to display the details of the transaction
    void displayTransaction() const;
    double getAmount() const;

private:
    string type; //type of transaction(deposit, withdrawal)
    double amount; // amount
    double balance; //account balance after the transaction
    string timestamp;//timestamp indicating when the transaction occured


};



#endif //TRANSACTIONS_H
