//
// Created by emmanuel on 08/11/24.
//

#ifndef CURRENT_ACCOUNT_H
#define CURRENT_ACCOUNT_H
#include "Account.h"
#include "Transactions.h"


class current_account : public Account{
public:
    //constructor to initialize the current account
    current_account( double balance  = 0, double overdraftlimit  = 500): Account(balance ), overdraftlimit(overdraftlimit){};

    //overridden method to deposit inherited from the base account class
    double deposit( double amount) override;

    //overridden method to withdraw inherited from the base account class
    double withdraw(double amount) override;

    //method to return what type of account an account is
    string getAccountType() const override;


private:
    double overdraftlimit;
};



#endif //CURRENT_ACCOUNT_H
