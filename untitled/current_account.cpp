
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#include "current_account.h"

///method to handle deposits
double current_account::deposit(double amount) {
//normal deposit method

    try {
        if (amount <= 0) {
            cout << "invalid amount" << endl;
            return 0;
        }
        balance += amount;

        //create a transaction record for this deposit Adds a tag to specify what type of transaction it is

        Transactions depositRecord("Deposit", amount, balance);
        history.push_back(depositRecord);
        //store the recorded deposit in the history vector

        return balance;

    }
    catch (invalid_argument &) {
        cout << "invalid input, enter a numeric value" << endl;
        return 0;
    }



}

///method to handle withdrawals
double current_account::withdraw( double amount) {
//withdrawal method adjusted to support overdraft
    if (amount <=( balance + overdraftlimit)) {
        balance -= amount;

    }
    else {
        cout<< "Requested amount exceeds your overdraft limit"<< endl;
        return -1;
    }

    //create a transaction record for this withdrawal Adds a tag to specify what type of transaction it is
    const Transactions withdrawalRecord("Withdrawal", amount, balance);

    history.push_back(withdrawalRecord);
    //store the recorded withdrawal in the history vector


    return balance;
}
//returns account type
string current_account::getAccountType() const {
    return "Current";
}


