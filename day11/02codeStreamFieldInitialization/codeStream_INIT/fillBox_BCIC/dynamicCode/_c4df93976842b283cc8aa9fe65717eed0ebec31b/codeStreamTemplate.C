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
#line 25 "/home/ariedinger/uni/gimap/openfoam/03wiki3weeksSeries/day11/02codeStreamFieldInitialization/codeStream_INIT/fillBox_BCIC/0/alpha.water/#codeStream"
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
    void codeStream_c4df93976842b283cc8aa9fe65717eed0ebec31b
    (
        Ostream& os,
        const dictionary& dict
    )
    {
//{{{ begin code
        #line 43 "/home/ariedinger/uni/gimap/openfoam/03wiki3weeksSeries/day11/02codeStreamFieldInitialization/codeStream_INIT/fillBox_BCIC/0/alpha.water/#codeStream"
const IOdictionary& d = static_cast<const IOdictionary&>(dict);
        const fvMesh& mesh = refCast<const fvMesh>(d.db());
        scalarField alpha(mesh.nCells(), 0.);

        forAll(alpha, i)
        {
            const scalar x = mesh.C()[i][0];
            const scalar y = mesh.C()[i][1];
            const scalar z = mesh.C()[i][2];

            if (y <= 0.2)
            {
                alpha[i] = 1.;
            }
        }

        writeEntry(os, "", alpha);
//}}} end code
    }
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //

