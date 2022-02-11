#ifdef myClass_H
#define  myClass_H

/*Class definition:*/
class myClass
{
    private:
    protected:
    /*Accesed by everyone:*/
    public:
        /*Member data; underscore is OpenFOAM convention:*/
        int   i_;
        float j_;

        /*Constructor definition:*/
        myClass();
        /*Destructor definition:*/
        ~myClass();
};

/*ifndef/define/endif is added to make sure that the class is not declared*/
/*multiple times, in the case that we #include "myClass.H" several times.*/
#endif
