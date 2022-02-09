/*Declaration of scalar field S1. The solver will read the input file S1 (BC and IC):*/
Info << "Reading field S1 (passive scalar 1)\n" << endl;

volScalarField S1
(
    IOobject
    (
        "S1",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

/*Declaration of S1 IO dictionary file.*/
/*The name of the dictionary is diffusionProperties and is located in /constant/:*/
Info << "Reading diffusionProperties\n" << endl;

IOdictionary diffusionProperties
(
    IOobject
    (
        "diffusionProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

/*Read DT value from the dictionary diffusionProperties:*/
Info << "Reading diffusivity DT\n" << endl;
dimensionedScalar DT
(
    diffusionProperties.lookup("DT")
);

Info<< "Reading transportProperties\n" << endl;

IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

dimensionedScalar nu
(
    "nu",
    dimViscosity,
    transportProperties.lookup("nu")
);

Info<< "Reading field p\n" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


Info<< "Reading field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


#include "createPhi.H"


label pRefCell = 0;
scalar pRefValue = 0.0;
setRefCell(p, mesh.solutionDict().subDict("PISO"), pRefCell, pRefValue);
mesh.setFluxRequired(p.name());
