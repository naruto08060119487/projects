//
// Created by emmanuel on 03/12/24.
//

#ifndef ISA_H
#define ISA_H
#include "savings_account.h"


class Isa : public savings_account{
    public:
    Isa(double balance = 0.0, double isaInterestRate = 1.15) : savings_account(balance), interestRate(isaInterestRate){};
    void interestCalculator( double time) override;
    string getAccountType() const override;

    private:
    double interestRate;
};



#endif //ISA_H
