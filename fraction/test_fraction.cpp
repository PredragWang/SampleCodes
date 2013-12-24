#include "fraction.h"
void test(fraction f1, fraction f2, char op){
    if (op == '+'){
        cout << f1.toStr() << " + " << f2.toStr() << " = " << (f1+f2).toStr() << endl;
        return;
    }
    else if (op == '-'){
        cout << f1.toStr() << " - " << f2.toStr() << " = " << (f1-f2).toStr() << endl;
        return;
    }
    else if (op == '*'){
        cout << f1.toStr() << " * " << f2.toStr() << " = " << (f1*f2).toStr() << endl;
        return;
    }
    else if (op == '/'){
        try{
            f1/f2;
            cout << f1.toStr() << " / " << f2.toStr() << " = " << (f1/f2).toStr() << endl;
        }
        catch (FractionException& e){
            cout << "Exception" << endl;
        }
    }
    else {
        cout << "Invalid op" << endl;
    }
}


int main(){
    // small fractions test
    fraction f1(2, 5);
    fraction f2(3, 4);
    fraction f3(0, 4);
    fraction f4(1, -6);
    fraction f5(-4, 20);
    fraction f6(-3, -7);
	fraction f7(-4, -10);
	fraction f8(-2, 5);
	fraction f9(8, -20);
    test (f1, f2, '+');
    test (f1, f2, '-');
    test (f1, f2, '*');
    test (f1, f3, '*');
    test (f1, f3, '/');
    test (f4, f5, '+');
    test (f4, f6, '-');
    test (f4, f5, '*');
    test (f5, f6, '/');
    test (f3, f5, '+');
    test (f3, f5, '-');
    test (f1, f3, '-');

    // big fractions test
    fraction b1(999934, 10000);
    fraction b2(445238, 1000000);
    fraction b3(99999, 100000);
    fraction b4(100000, 99999);
    fraction b5(21345, 12765890);
    test (b1, b2, '+');
    test (b1, b2, '-');
    test (b3, b4, '*');
    test (b4, b5, '+');
    test (b1, b4, '+');
	cout << (f1 == f2) << endl;
	cout << (f1 != f2) << endl;
	cout << (f1 == f7) << endl;
    cout << (f1 != f7) << endl;
	cout << (f8 == f9) << endl;
    cout << (f8 != f9) << endl;
}
