//
// Created by emmanuel on 03/12/24.
//
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

#include "Isa.h"

void Isa::interestCalculator(double time) {



    double finalAmount= balance * pow(1 + interestRate/12, 12 * time) ;
    cout << "The projected balance for ISA after " << time << " years is: $" << fixed<<setprecision(2)<< finalAmount<< endl;

}
string Isa::getAccountType() const {
    return "ISA";
}

