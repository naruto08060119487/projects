//
// Created by emmanuel on 08/11/24.
//
#include <iostream>

#include<iomanip>

using namespace std;

#include "Account.h"

///method to get current account balance
double Account::getBalance() const {
    return balance;
}

///method to handle deposits
double Account :: deposit(double amount) {

    try {
        //check if the deposit amount is a valid number
        if (amount <= 0) {
            cout<<"Invalid input. Please try again.\n";
            return 0; //returns zero for invalid deposit
        }

        //add the deposit amount to the balance
        balance+= amount;

        //create a transaction record for this deposit Adds a tag to specify what type of transaction it is
        Transactions depositTransaction("Deposit", amount, balance);

        //store the recorded deposit in the history vector
        history.push_back(depositTransaction);

        return amount; //return the deposited amount
    }
    catch(invalid_argument &) {
        cout<<"Invalid input. Please try again.\n";
        return 0;
    }

};
///method to handle withdrawals
double Account:: withdraw(double amount) {

    try {
        //check if there are sufficient funds for the withdrawal
        if (amount > balance) {
            cout<< "insufficient balance"<< endl; //print error message
            return 0;
        }

        //subtract the withdrawal amount from the balance
        balance -= amount;

        //create a transaction record for this withdrawal Adds a tag to specify what type of transaction it is
        Transactions withdrawTransaction("Withdrawal", amount, balance);

        // store the withdrawal transaction in the transaction history
        history.push_back(withdrawTransaction);

        return amount;
    }
    catch(invalid_argument &) {
        cout<<"Invalid input. Please try again.\n";
        return 0;
    }

};

///method to display all transactions in the accounts history
void Account::displayTransactionHistory() const {
    //check if the transaction history vector is empty
    if (history.empty()) {
        cout<<"No transactions to list.\n";
        return ;
    }

    //iterate through the transaction history and display each transaction
    for(const auto& transaction : history) {
        transaction.displayTransaction(); //display the details of each transaction
    }
}

///method to search for a specific transaction
void Account :: searchTransactions(double amount) {
    results.clear(); //clear previous search results

    for(const auto& searchCriteria : history) {
        //iterate through the stored transaction vector
        if(searchCriteria.getAmount() == amount) {
            results.push_back(searchCriteria);
            //adds the specific transactions to the result vector
        }
    }
}

///method to display the searched transaction
void Account::displaySearch() const {

    if (results.empty()) {
        cout<<"No transactions to list.\n";
        return ;
    }

    for(const auto& transaction : results) {
        transaction.displayTransaction(); //display each transaction in search criteria
    }
}
