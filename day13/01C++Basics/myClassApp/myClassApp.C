/*Just for cout:*/
#include <iostream>
using namespace std;

/*Add class header file:*/
#include "myClass.H"

int main()
{
    /*Create class objects:*/
    myClass myClassObject;

    /*Operations with object's members i_ and j_:*/
    cout << "myClassObject.i_: " << myClassObject.i_ << endl;
    cout << "myClassObject.j_: " << myClassObject.j_ << endl;

    /*Create another object:*/
    myClass myClassObject2;

    /*i_ member of myClassObject2:*/
    cout << "myClassObject2.i_: " << myClassObject2.i_ << endl;

    /*Edit i_ memeber:*/
    myClassObject2.i_ = 30;
    cout << "myClassObject.i_: " << myClassObject.i_ << endl;
    cout << "myClassObject2.i_: " << myClassObject2.i_ << endl;

    /*End - return nothing:*/
    return 0;
}
