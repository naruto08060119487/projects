
#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include <vector>

#include "Account.h"

using namespace std;


class savings_account : public Account{
public:
    //constructor to initialize a savings account with a balance and interest rate
    //default balance is zero and interets rate is 0.85
    savings_account( double balance  = 0, double interestRate  = 0.85): Account( balance ), interestRate(interestRate){};

    //function to calculate and display the projected balance based on compound interest
    //takes a parameter TIME: represents the number os years for the projection
    virtual void interestCalculator( double time);

    //function to return the account type
    string getAccountType() const override;


private:
    //interest rate for the savings account, default value is 0.85
    double interestRate = 0.85 ;
};



#endif //SAVINGS_ACCOUNT_H
