#include "fraction.h"

// fraction constructor with empty arguments
fraction::fraction(){
    numerator = 0;
    denominator = 1;
}

// fraction constructor with numerator and denominator
fraction::fraction(f_long fracNumerator, f_long fracDenominator) throw (FractionException){
    if (fracDenominator == 0){
        throw FractionException();
        return;
    }
    numerator = fracNumerator;
    denominator = fracDenominator;
    simplify();
}

// deconstructor
fraction::~fraction(){}

// member function to simplify the fraction
void fraction::simplify(){
    if (numerator != 0) {
        f_long gcdValue = gcd(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;
        if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)){
            numerator = -abs(numerator);
        }
        else {
            numerator = abs(numerator);
        }
        denominator = abs(denominator);
    }
    else {
        denominator = 1;
    }
}

// greatest common divisor, using Euclidean division
f_long fraction::gcd(f_long x, f_long y){
    if (x == 0 || y == 0) return -1;
    x = abs(x);
    y = abs(y);
    int tmp = 0;
    f_long ret = 0;
    while (ret == 0){
        if (x > y){
            if (x % y == 0) ret = y;
            else {
                tmp = y;
                y = x % y;
                x = tmp;
            }
        }
        else {
            if (y % x == 0) ret = x;
            else {
                tmp = x;
                x = y % x;
                y = tmp;
            }
        }
    }
    return ret;
}

// least common multiple
f_long fraction::lcm(f_long x, f_long y){
    if (x == 0 || y == 0) return -1;
    return abs(x * y)/gcd(x, y);
}

// getter of numerator
f_long fraction::getNumerator(){
    return numerator;
}

// setter of numerator
void fraction::setNumerator(f_long fracNumerator){
    numerator = fracNumerator;
    simplify();
}

// getter of denominator
f_long fraction::getDenominator(){
    return denominator;
}

// setter of denominator
void fraction::setDenominator(f_long fracDenominator) throw (FractionException){
    if (fracDenominator ==  0) {
        throw FractionException();
        return;
    }
    denominator =  fracDenominator;
    simplify();
}

// get the value of the fraction in double
double fraction::doubleValue(){
    return (double)numerator/(double)denominator;
}

// addition operation
fraction fraction::operator+(fraction f){
    f_long lcmValue = lcm(denominator, f.getDenominator());
    f_long x1 = lcmValue/denominator, x2 = lcmValue/f.getDenominator();
    f_long newNumerator = numerator * x1 + f.getNumerator() * x2;
    fraction ret(newNumerator, lcmValue);
    return ret;
}


// subtraction operation
fraction fraction::operator-(fraction f){
    f_long lcmValue = lcm(denominator, f.getDenominator());
    f_long x1 = lcmValue/denominator, x2 = lcmValue/f.getDenominator();
    f_long newNumerator = numerator * x1 - f.getNumerator() * x2;
    fraction ret(newNumerator, lcmValue);
    return ret;
}

// multiplication operation
fraction fraction::operator*(fraction f){
    fraction ret;
    if (numerator == 0 || f.getNumerator() == 0){
        ret = fraction(0, 1);
    }
    else {
        f_long gcd1 = gcd(numerator, f.getDenominator());
        f_long gcd2 = gcd(f.getNumerator(), denominator);
        f_long newNumerator = (numerator/gcd1) * (f.getNumerator()/gcd2);
        f_long newDenominator = (denominator/gcd2) * (f.getDenominator()/gcd1);
        ret = fraction(newNumerator, newDenominator);
    }
    return ret;
}

// division operation
fraction fraction::operator/(fraction f) throw (FractionException){
    fraction ret;
    if (f.getNumerator() == 0) {
        throw FractionException();
    }
    else if (numerator == 0){
        ret = fraction(0, 1);
    }
    else {
        f_long gcd1 = gcd(numerator, f.getNumerator());
        f_long gcd2 = gcd(denominator, f.getDenominator());
        f_long newNumerator = (numerator/gcd1) * (f.getDenominator()/gcd2);
        f_long newDenominator = (denominator/gcd2) * (f.getNumerator()/gcd1);
        ret = fraction(newNumerator, newDenominator);
    }
    return ret;
}

// equal operator
bool fraction::operator==(fraction f){
    return numerator == f.getNumerator() && denominator == f.getDenominator();
}

bool fraction::operator!=(fraction f){
    return numerator != f.getNumerator() && denominator != f.getDenominator();
}

// convert the fraction in string
string fraction::toStr(){
    string s("");
    if (numerator == 0){
        s.append(1, '0');
    }
    else if (denominator == 1) {
        s.append(to_string(numerator));
    }
    else {
        s.append(to_string(numerator));
        s.append(1, '/');
        s.append(to_string(denominator));
    }
    return s;
}
