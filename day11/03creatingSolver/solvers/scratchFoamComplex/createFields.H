/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

Info<< "Reading field T\n" << endl;

/*Create scalar field T:*/
volScalarField T
(
    /*Create object for input/output operations:*/
    IOobject
    (
        /*Name of the dictionary file to read/write:*/
        "T",
        /*Runtime directory:*/
        runTime.timeName(),
        /*Object registry*/
        mesh,
        /*Read the dictionary in the runtime directory:*/
        IOobject::MUST_READ,
        /*Write the value in the runtime directory:*/
        IOobject::AUTO_WRITE
    ),
    /*Link object to mesh:*/
    mesh
);

/*Non-uniform initialization of the scalar field T:*/
forAll(T,i)
{
    /*Access cell center coordinates.*/
    /*In this case, y and z coordinates are not used:*/
    const scalar x = mesh.C()[i][0];
    const scalar y = mesh.C()[i][1];
    const scalar z = mesh.C()[i][2];

    /*Conditional structure:*/
    if(0.3 < x && x < 0.7)
        T[i] = 1.;
}

/*Write field T.*/
/*As the file createFields.H is outside the time loop,*/
/*the value is saved in the time directory 0:*/
T.write();

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

Info<< "Reading field U\n" << endl;

/*Create vector field U:*/
volVectorField U
(
    /*Create object for input/output operations:*/
    IOobject
    (
        /*Name of the dictionary file to read/write:*/
        "U",
        /*Runtime directory:*/
        runTime.timeName(),
        /*Object registry*/
        mesh,
        /*Read the dictionary in the runtime directory:*/
        IOobject::MUST_READ,
        /*Write the value in the runtime directory:*/
        IOobject::AUTO_WRITE
    ),
    /*Link object to mesh:*/
    mesh
);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

Info<< "Reading transportProperties\n" << endl;

/*Create object transportProperties used to read data::*/
IOdictionary transportProperties
(
    /*Create object for input/output operations:*/
    IOobject
    (
        /*Name of the input dictionary:*/
        "transportProperties",
        /*Location of the input dictionary - in this case is located in constant:*/
        runTime.constant(),
        /*Object registry*/
        mesh,
        /*Re-read data if it is modified:*/
        IOobject::MUST_READ_IF_MODIFIED,
        /*Do not write anything in the dictionary:*/
        IOobject::NO_WRITE
    )
);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

Info << "Reading diffusivity DT\n" << endl;

/*Create scalar DT (diffusion coefficient):*/
dimensionedScalar DT
(
    /*Access value of DT in the object transportProperties:*/
    transportProperties.lookup("DT")
);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

/*Creates and initializes the relative face-flux field phi:*/
#include "createPhi.H"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */
