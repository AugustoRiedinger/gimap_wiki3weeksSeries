/*Read muMag from dictionary:*/
Info << "Reading physicalProperties\n" << endl;

IOdictionary physicalProperties
(
    IOobject
    (
        "physicalProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ,
        IOobject::NO_WRITE
    )
 );

dimensionedScalar muMag
(
    "muMag",
    dimensionSet(1, 1, -2, 0, -2, 0, 0),
    physicalProperties
);

/*Contructing volScalarField sigma:*/
Info << "Reading field sigma\n" << endl;

volScalarField sigma
(
    IOobject
    (
        "sigma",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
     ),
    mesh
);

/*Constructing volScalarField ElPot:*/
Info << "Reading field ElPot\n" << endl;

volScalarField ElPot
(
    IOobject
    (
        "ElPot",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

/*Constructing volVectorField A:*/
Info << "Reading field A\n" << endl;

volVectorField A
(
    IOobject
    (
        "A",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
     ),
    mesh
);

/*Constructing and initializing volVectorField B:*/
Info << "Calculating magnetic field B\n" << endl;

volVectorField B
(
    IOobject
    (
        "B",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
     ),
    fvc::curl(A)
);

/*Constructing and initializing volVectorField Je:*/
Info << "Calculating current Je\n" << endl;

volVectorField Je
(
    IOobject
    (
        "Je",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    fvc::curl(A)
);
