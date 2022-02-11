/*Add header file:*/
#include "myClass.H"
/*Standar library, just for cout:*/
#include <iostream>
using namespace std;

/*Class constructor:*/
myClass::myClass()
    :
    i_(20),
    j_(21.5)
{
    cout << "i_ = " << i_ << endl;
}
/*Class destructor:*/
myClass::~myClass()
{}
