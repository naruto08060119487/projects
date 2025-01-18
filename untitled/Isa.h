//
// Created by emmanuel on 03/12/24.
//

#ifndef ISA_H
#define ISA_H
#include "savings_account.h"

//this inherits from the savings account class
class Isa : public savings_account{
    public:
    /*constructor for the isa class
     * parameter the initial balance defaults to zero
     * has interest_rate specific to only isa
     */
    Isa(double balance = 0.0, double isaInterestRate = 1.15) : savings_account(balance), interestRate(isaInterestRate){};

    /*overrides the interestCalculator method inherited from the savings account
     *takes time(years) as the parameter
     *overrides the getAccountType from the savings account too
    */
    void interestCalculator( double time) override;
    string getAccountType() const override;

    private:
    double interestRate; //the interest rate for the isa account
};



#endif //ISA_H
