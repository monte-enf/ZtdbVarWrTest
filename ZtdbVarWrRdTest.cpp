// ZtdbVarWrRdTest.cpp : Tests ZtdbVarWr  and ZtdbVarRd classes
//

#include <iostream>
#include <vector>

#include "../Zappa/ZtdbVarWr.h"
#include "../Zappa/ZtdbVarRd.h"

int main()
{
    cout << "ZtdbVarWrRdTest: top\n\n";

    vector <ZtdbVar> varsWr;

    varsWr.push_back ( ZtdbVar ( "v1",    10 ) );
    varsWr.push_back ( ZtdbVar ( "v2",    20 ) );
    varsWr.push_back ( ZtdbVar ( "v33",   30 ) );
    varsWr.push_back ( ZtdbVar ( "v4444", 40 ) );
    varsWr.push_back ( ZtdbVar ( "v99",   64 ) );

    ZtdbVarWr::write ( "writeFile", varsWr );

    cout << "ZtdbVarWrRdTest: Write done\n\n";

    // ========================================================================

    vector <ZtdbVar> varsRd;

    ZtdbVarRd::read ( "writeFile", varsRd );


    for ( uint32_t ith = 0; ith < varsRd.size ( ); ith++ ) {
        cout << "ZtdbVarWrRdTest:"
             << " ith=" << ith
             << " name=" << varsRd[ith].mName
             << " size=" << varsRd[ith].mSize << "\n";
    }

    cout << "ZtdbVarWrRdTest: done\n\n";

}
