/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) YEAR OpenFOAM Foundation
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

Description
    Template for use with codeStream.

\*---------------------------------------------------------------------------*/

#include "dictionary.H"
#include "Ostream.H"
#include "Pstream.H"
#include "unitConversion.H"

//{{{ begin codeInclude
#line 44 "/home/ariedinger/uni/gimap/openfoam/03wiki3weeksSeries/day11/01codeStreamBC/case/3Delbow_Uparaboloid/0/U/boundaryField/auto3/#codeStream"
#include "fvCFD.H"
//}}} end codeInclude

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

extern "C"
{
    void codeStream_0bcd6e21f5bff7295a537c7d0b93093e24533ad0
    (
        Ostream& os,
        const dictionary& dict
    )
    {
//{{{ begin code
        #line 62 "/home/ariedinger/uni/gimap/openfoam/03wiki3weeksSeries/day11/01codeStreamBC/case/3Delbow_Uparaboloid/0/U/boundaryField/auto3/#codeStream"
const IOdictionary& d = static_cast<const IOdictionary&>
				(
                    dict.parent().parent()
                );
                const fvMesh& mesh = refCast<const fvMesh>(d.db());
                const label id = mesh.boundary().findPatchID("auto3");
                const fvPatch& patch = mesh.boundary()[id];

                vectorField U(patch.size(), vector(0, 0, 0));

                const scalar pi = constant::mathematical::pi;
                const scalar s  = 0.5;	

                forAll(U, i)
                {
                    const scalar x = patch.Cf()[i][0];
                    const scalar y = patch.Cf()[i][1];
                    const scalar z = patch.Cf()[i][2];

		            U[i] = vector(-1*(pow(z/s, 2) + pow((y-s)/s,2) - 1.0), 0, 0);
                }

                writeEntry(os, "", U);
//}}} end code
    }
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //

