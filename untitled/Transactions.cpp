//
// Created by emmanuel on 13/11/24.
//

#include "Transactions.h"

using namespace std;

//function to display the details of a transaction
//outputs the transaction type, amount and type in a formatted manner
void Transactions::displayTransaction() const {
    cout << "-- "<<type << ": "<< amount<< " on "<< timestamp<<endl;
}

double Transactions::getAmount() const {
    return amount;
}