#ifndef _fraction_
#define _fraction_

typedef long long f_long;   // define the type for numbers in fractions

#include <iostream>
#include <cmath>
#include "fraction_exception.h"
#include <string>
using namespace std;


class fraction{
    private:
        f_long numerator;
        f_long denominator;
        f_long gcd(f_long, f_long);             // greatest common divisor
        f_long lcm(f_long, f_long);             // least common multiple
        void simplify();                        // simplifier
    public:
        fraction();                             // constructor without arg
        fraction(f_long, f_long) throw (FractionException);   
                                                // constructor with args
        ~fraction();                            // deconstructor
        f_long getNumerator();                  // numerator getter
        void setNumerator(f_long);              // numerator setter
        f_long getDenominator();                // denominator getter
        void setDenominator(f_long) throw (FractionException);   
                                                // denominator setter
        double doubleValue();                   // get double value
        fraction operator+(fraction f);         // addition
        fraction operator-(fraction f);         // subtraction
        fraction operator*(fraction f);         // multiplication
        fraction operator/(fraction f) throw (FractionException);   
                                                // division
        bool operator==(fraction f);            // equal
        bool operator!=(fraction f);            // not equal
        string toStr();                         // to string
};
#endif
