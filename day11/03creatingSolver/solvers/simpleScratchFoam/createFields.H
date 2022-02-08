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

Info << "Reading diffusivity DT\n" << endl;

/*Create scalar DT (diffusion coefficient):*/
dimensionedScalar DT
(
    /*Access value of DT in the object transportProperties:*/
    transportProperties.lookup("DT")
);

/*Creates and initializes the relative face-flux field phi:*/
#include "createPhi.H"
