
//
// Created by emmanuel on 08/11/24.
//
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#include "savings_account.h"

void savings_account :: interestCalculator( double time) {
    //calculates  the projected balance using compound interest formula
    double finalAmount= balance* pow(1 + interestRate/12, 12*time) ;

    //display the projected balance in two decimal places
    cout << "Projected balance £" << fixed<<setprecision(2)<< finalAmount<< endl;

}
//function to display the account type
//overrides the base Account class implementation
string savings_account::getAccountType() const {
    return "Savings";
}
