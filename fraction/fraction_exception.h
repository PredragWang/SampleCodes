#ifndef _FractionException_
#define _FractionException_
#include <exception>
using namespace std;
class FractionException: exception{
    virtual const char *what() const throw(){
        return "Invalid denominator";    
    }
};

#endif
