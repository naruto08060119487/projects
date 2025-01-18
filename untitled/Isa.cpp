//
// Created by emmanuel on 03/12/24.
//
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

#include "Isa.h"
///method to calculate and display the projected balance for an isa account
void Isa::interestCalculator(double time) {
    //calculate the final balance using the compound interest formula
    //A = P(1 + r/n)^nt and n=12


    double finalAmount= balance * pow(1 + interestRate/12, 12 * time) ;
    cout << "The projected balance for ISA after " << time << " years is: $" << fixed<<setprecision(2)<< finalAmount<< endl;

}

///function to return the type of account as a string
string Isa::getAccountType() const {
    return "ISA";
}

