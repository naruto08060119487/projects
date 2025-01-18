
#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include <vector>

#include "Account.h"

using namespace std;


class savings_account : public Account{
public:
    savings_account( double balance  = 0, double interestRate  = 0.85): Account( balance ), interestRate(interestRate){};
    virtual void interestCalculator( double time);
    string getAccountType() const override;


private:
    double interestRate = 0.85 ;
};



#endif //SAVINGS_ACCOUNT_H
