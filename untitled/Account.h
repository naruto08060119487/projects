//
// Created by emmanuel on 08/11/24.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <vector>


#include "Transactions.h"
#include "search.h"

using namespace std;
/* base class representing a generic bank account
 * this class defines similar functionalities shared by other class(savings, current and isa accounts)
 */

class Account {
public:
    virtual ~Account() = default; ///virtual destructor to ensure cleanup of derived class objects

    ///constructor to initialize account, (default balance is 0.0)
    Account(double balance = 0.0):  balance(balance) {};

    ///pure virtual function to get account type(implemented in other classes)
    virtual string getAccountType() const = 0;

    ///method to get current account balance
    virtual  double getBalance() const;

    ///method to deposit an amount into the account
    virtual double deposit(double amount);

    ///method to withdraw an amount from the account
    virtual double withdraw(double amount);

    ///method to display the transaction history of the accounts
    void displayTransactionHistory() const;

    ///method to search for a specific transaction
    void searchTransactions(double amount) ;

    ///method to display the transaction
    void displaySearch() const;



    /// stores all the transactions made
    vector<Transactions> history;




protected:
    double balance = 0; ///initial balance of the account
    vector<Transactions>results; /// stores search results
};



#endif //ACCOUNT_H
