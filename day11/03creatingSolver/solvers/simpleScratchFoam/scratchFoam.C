/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2022 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    scratchFoam

Description

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"

/*Solution control using PISO class:*/
#include "pisoControl.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    /*Set directory structure:*/
    #include "setRootCase.H"
    /*Create time (object runtime):*/
    #include "createTime.H"
    /*Create time (object mesh):*/
    #include "createMesh.H"
    /*Initialize fields:*/
    #include "createFields.H"
    /*Calculates and outputs the Courant Number:*/
    #include "CourantNo.H"
    /*Declare and initialize the cumulative continuity error:*/
    #include "initContinuityErrs.H"

    /*Assign PISO controls to object mesh and create object PISO:*/
    /*Alternatively, you can use the header file createControl.H.*/
    pisoControl piso(mesh);

    Info << "\nStarting time loop\n" << endl;

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
    /*Time loop:*/
    while (runTime.loop()) {
       Info << "Time = " << runTime.timeName() << nl << endl;

       /*Calculates and outputs the Courant Number:*/
       #include "CourantNo.H"

       /*PISO options - correct loop:*/
       while (piso.correct()) {
           /*Non-orthogonal corrections loop:*/
           while (piso.correctNonOrthogonal()) {
               /*Create object TEqn - fvScalarMatrix is an instance of fvMatrix:*/
               fvScalarMatrix TEqn
               (
                   /*Model equation - convection-diffusion.*/
                   /*We need to create scalar field T, vector field U and constant DT.*/
                   /*This variables will be declared in createFields.H.*/
                   /*In fvSchemes, we will need to define how to compute differential operators for this.*/
                   fvm::ddt(T)
                   + fvm::div(phi,T)
                   - fvm::laplacian(DT,T)
               );

               /*Solve TEqn - this object holds the solution:*/
               TEqn.solve();
           }
       }

       /*Compute the continuity errors:*/
       #include "continuityErrs.H"

       /*Write solution in runtime folder.*/
       /*It'll write the data requested in the file createFields.H:*/
       runTime.write();
    }
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    /*Write CPU time at the end of the time loop:*/
    Info << nl << "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
         << " ClockTime = " << runTime.elapsedClockTime() << " s"
         << nl << endl;

    /*Output this message:*/
    Info << "End\n" << endl;

    /*End of the program (exit status):*/
    return 0;
}
// ************************************************************************* //
